#include <iostream>
#include "CTargaImage.h"
#include "common.h"

#ifdef _use_smart_ptr_
//#include <memory> //to use auto_ptr for assignement to scoped_ptr, as there is no function in the later for that effect
//#include "smartptrs/autoptr.h"
#endif

#if _use_my_mem_tracker_
#define new new(__FILE__,__LINE__)
#endif //_use_my_mem_tracker_

#pragma warning (disable:4996)

CTargaImage::CTargaImage() : m_pImageData(NULL)
{
}

CTargaImage::~CTargaImage()
{
	Release();
}

void CTargaImage::SwapRedBlue()
{
	switch (m_colorDepth)
	{
	case 32:
		{
			unsigned char temp;
			rgba_t* source = (rgba_t*)m_pImageData.get();

			for (int pixel = 0; pixel < (m_width * m_height); ++pixel)
			{
				temp = source[pixel].b;
				source[pixel].b = source[pixel].r;
				source[pixel].r = temp;
			}
		} break;
	case 24:
		{
			unsigned char temp;
			rgb_t* source = (rgb_t*)m_pImageData.get();

			for (int pixel = 0; pixel < (m_width * m_height); ++pixel)
			{
				temp = source[pixel].b;
				source[pixel].b = source[pixel].r;
				source[pixel].r = temp;
			}
		} break;
	default:
		// ignore other color depths
		break;
	}
}

bool CTargaImage::Load(const char *filename)
{
	FILE *pFile = fopen(filename, "rb");

	if (!pFile)
		return false;

	tgaheader_t tgaHeader;

	// read the TGA header
	fread(&tgaHeader, 1, sizeof(tgaheader_t), pFile);

	// see if the image type is one that we support (RGB, RGB RLE, GRAYSCALE, GRAYSCALE RLE)
	if ( ((tgaHeader.imageTypeCode != TGA_RGB) && (tgaHeader.imageTypeCode != TGA_GRAYSCALE) && 
		 (tgaHeader.imageTypeCode != TGA_RGB_RLE) && (tgaHeader.imageTypeCode != TGA_GRAYSCALE_RLE)) ||
		 tgaHeader.colorMapType != 0)
	{
		fclose(pFile);
		return false;
	}

	// get image width and height
	m_width = tgaHeader.width;
	m_height = tgaHeader.height;

	// colormode -> 3 = BGR, 4 = BGRA
	int colorMode = tgaHeader.bpp / 8;

	// we don't handle less than 24 bit
	if (colorMode < 3)
	{
		fclose(pFile);
		return false;
	}

	m_imageSize = m_width * m_height * colorMode;

	// allocate memory for TGA image data
#ifdef _use_smart_ptr_
	m_pImageData.reset(new unsigned char[m_imageSize] );
	/*
	std::auto_ptr<unsigned char> imgd( new unsigned char[m_imageSize] );
	m_pImageData.reset(imgd.release());
	*/
#else
	m_pImageData = new unsigned char[m_imageSize];
#endif

	// skip past the id if there is one
	if (tgaHeader.idLength > 0)
		fseek(pFile, SEEK_CUR, tgaHeader.idLength);

	// read image data
	if (tgaHeader.imageTypeCode == TGA_RGB || tgaHeader.imageTypeCode == TGA_GRAYSCALE)
	{
		fread(m_pImageData.get(), 1, m_imageSize, pFile);
	}
	else 
	{
		// this is an RLE compressed image
		unsigned char id;
		unsigned char length;
		rgba_t color = { 0, 0, 0, 0 };
		unsigned int i = 0;

		while (i < m_imageSize)
		{
			id = fgetc(pFile);

			// see if this is run length data
			if (id >= 128)// & 0x80)
			{
				// find the run length
				length = (unsigned char)(id - 127);

				// next 3 (or 4) bytes are the repeated values
				color.b = (unsigned char)fgetc(pFile);
				color.g = (unsigned char)fgetc(pFile);
				color.r = (unsigned char)fgetc(pFile);

				if (colorMode == 4)
					color.a = (unsigned char)fgetc(pFile);

				unsigned char *pImgData=m_pImageData.get();
				// save everything in this run
				while (length > 0)
				{
					pImgData[i++] = color.b;
					pImgData[i++] = color.g;
					pImgData[i++] = color.r;

					if (colorMode == 4)
						pImgData[i++] = color.a;

					--length;
				}
			}
			else
			{
				// the number of non RLE pixels
				length = unsigned char(id + 1);
				unsigned char *pImgData=m_pImageData.get();

				while (length > 0)
				{
					color.b = (unsigned char)fgetc(pFile);
					color.g = (unsigned char)fgetc(pFile);
					color.r = (unsigned char)fgetc(pFile);

					if (colorMode == 4)
						color.a = (unsigned char)fgetc(pFile);

					pImgData[i++] = color.b;
					pImgData[i++] = color.g;
					pImgData[i++] = color.r;

					if (colorMode == 4)
						pImgData[i++] = color.a;

					--length;
				}
			}
		}
	}

	fclose(pFile);

	switch(tgaHeader.imageTypeCode)
	{
	case TGA_RGB:
	case TGA_RGB_RLE:
		if (3 == colorMode)
		{
			m_imageDataFormat = IMAGE_RGB;
			m_imageDataType = IMAGE_DATA_UNSIGNED_BYTE;
			m_colorDepth = 24;
		}
		else
		{
			m_imageDataFormat = IMAGE_RGBA;
			m_imageDataType = IMAGE_DATA_UNSIGNED_BYTE;
			m_colorDepth = 32;
		}
		break;

	case TGA_GRAYSCALE:
	case TGA_GRAYSCALE_RLE:
		m_imageDataFormat = IMAGE_LUMINANCE;
		m_imageDataType = IMAGE_DATA_UNSIGNED_BYTE;
		m_colorDepth = 8;
		break;
	}

	if ((tgaHeader.imageDesc & TOP_LEFT) == TOP_LEFT)
		FlipVertical();

	// swap the red and blue components in the image data
	SwapRedBlue();

	return (m_pImageData.get() != NULL);
}

bool CTargaImage::FlipVertical()
{
	if (!m_pImageData.get())
		return false;

	if (m_colorDepth == 32)
	{
#ifdef _use_smart_ptr_
		//hb::auto_ptr<rgba_t> 
		boost::scoped_ptr<rgba_t> 
			auto_tmpBits( new rgba_t[m_width] );
		rgba_t* tmpBits = auto_tmpBits.get();
#else
		rgba_t* tmpBits = new rgba_t[m_width];
#endif

		if (!tmpBits)
			return false;

		int lineWidth = m_width * 4;

		rgba_t* top = (rgba_t*)m_pImageData.get();
		rgba_t* bottom = (rgba_t*)(m_pImageData.get() + lineWidth*(m_height-1));

		for (int i = 0; i < (m_height / 2); ++i)
		{
			memcpy(tmpBits, top, lineWidth); 
			memcpy(top, bottom, lineWidth);
			memcpy(bottom, tmpBits, lineWidth);

			top = (rgba_t*)((unsigned char*)top + lineWidth);
			bottom = (rgba_t* )((unsigned char*)bottom - lineWidth);
		}

#ifdef _use_smart_ptr_
#elif //_use_my_mem_tracker_
		deleteo<rgba_t>(tmpBits);
#else //_use_my_mem_tracker_
		delete [] tmpBits;
#endif //_use_my_mem_tracker_

		tmpBits = 0;
	}
	else if (m_colorDepth == 24)
	{
#ifdef _use_smart_ptr_
		//hb::auto_ptr<rgb_t> 
		boost::scoped_ptr<rgb_t> 
			auto_tmpBits( new rgb_t[m_width] );
		rgb_t* tmpBits = auto_tmpBits.get();
#else
		rgb_t* tmpBits = new rgb_t[m_width];
#endif
		if (!tmpBits)
			return false;

		int lineWidth = m_width * 3;

		rgb_t* top = (rgb_t*)m_pImageData.get();
		rgb_t* bottom = (rgb_t*)(m_pImageData.get() + lineWidth*(m_height-1));

		for (int i = 0; i < (m_height / 2); ++i)
		{
			memcpy(tmpBits, top, lineWidth); 
			memcpy(top, bottom, lineWidth);
			memcpy(bottom, tmpBits, lineWidth);

			top = (rgb_t*)((unsigned char*)top + lineWidth);
			bottom = (rgb_t*)((unsigned char*)bottom - lineWidth);
		}

#ifdef _use_smart_ptr_
#elif _use_my_mem_tracker_
		deleteo<rgb_t>(tmpBits);
#else //_use_my_mem_tracker_
		delete [] tmpBits;
#endif //_use_my_mem_tracker_

		tmpBits = 0;
	}

	return true;
}

void CTargaImage::Release()
{
#ifdef _use_smart_ptr_
//	delete m_pImageData.release(); //CTargaImage::Release is called in destructor only. so let auto_ptr desctructor deallocate memory allocated to the image data
#elif //_use_my_mem_tracker_
	deleteo<unsigned char>(m_pImageData);
	m_pImageData = NULL;
#else //_use_my_mem_tracker_
	delete [] m_pImageData;
	m_pImageData = NULL;
#endif //_use_my_mem_tracker_
}

bool CTargaImage::ConvertRGBToRGBA(unsigned char alphaValue)
{
	if ((m_colorDepth == 24) && (m_imageDataFormat == IMAGE_RGB))
	{
#ifdef _use_smart_ptr_
		//hb::auto_ptr<unsigned char> 
		boost::scoped_ptr<unsigned char> 
			auto_newImage(new unsigned char[sizeof(rgba_t)* m_width * m_height]);
		rgba_t *newImage = reinterpret_cast<rgba_t *>(auto_newImage.get());
#else 
		rgba_t *newImage = new rgba_t[m_width * m_height];
#endif  //

		if (!newImage)
			return false;

		rgba_t *dest = newImage;
		rgb_t *src = (rgb_t*)m_pImageData.get();

		for (int x = 0; x < m_height; x++)
		{
			for (int y = 0; y < m_width; y++)
			{
				dest->r = src->r;
				dest->g = src->g;
				dest->b = src->b;
				dest->a = alphaValue;

				++src;
				++dest;
			}
		}

#ifdef _use_smart_ptr_
		//m_pImageData = auto_newImage;
		m_pImageData.swap(auto_newImage);
#elif _use_my_mem_tracker_
		deleteo<unsigned char>(m_pImageData);
		m_pImageData = (unsigned char*)newImage;
#else //_use_my_mem_tracker_
		delete [] m_pImageData;
		m_pImageData = (unsigned char*)newImage;
#endif //_use_my_mem_tracker_

		m_colorDepth = 32;
		m_imageDataType = IMAGE_DATA_UNSIGNED_BYTE;
		m_imageDataFormat = IMAGE_RGBA;
		
		return true;
	}

	return false;
}

bool CTargaImage::ConvertRGBAToRGB()
{
	if ((m_colorDepth == 32) && (m_imageDataFormat == IMAGE_RGBA))
	{
#ifdef _use_smart_ptr_
		//hb::auto_ptr<unsigned char> 
		boost::scoped_ptr<unsigned char> 
			auto_newImage(new unsigned char[sizeof(rgb_t) * m_width * m_height]);
		rgb_t *newImage = reinterpret_cast<rgb_t *>(auto_newImage.get());
#else 
		rgb_t *newImage = new rgb_t[m_width * m_height];
#endif 

		if (!newImage)
			return false;

		rgb_t *dest = newImage;
		rgba_t *src = (rgba_t*)m_pImageData.get();

		for (int x = 0; x < m_height; x++)
		{
			for (int y = 0; y < m_width; y++)
			{
				dest->r = src->r;
				dest->g = src->g;
				dest->b = src->b;

				++src;
				 ++dest;
			}
		}


#ifdef _use_smart_ptr_
		//m_pImageData = auto_newImage;
		m_pImageData.swap(auto_newImage);
#elif _use_my_mem_tracker_
		deleteo<unsigned char>(m_pImageData);
		m_pImageData = (unsigned char*)newImage;
#else //_use_my_mem_tracker_
		delete [] m_pImageData;
		m_pImageData = (unsigned char*)newImage;
#endif //_use_my_mem_tracker_


		m_colorDepth = 24;
		m_imageDataType = IMAGE_DATA_UNSIGNED_BYTE;
		m_imageDataFormat = IMAGE_RGB;

		return true;
	}

	return false;
}


bool CTargaImage::SetOpaqueColor(unsigned char r,unsigned char g,unsigned char b)
{
	if ((m_colorDepth == 24) && (m_imageDataFormat == IMAGE_RGB))
	{
#ifdef _use_smart_ptr_
		//hb::auto_ptr<unsigned char> 
		boost::scoped_ptr<unsigned char> 
			auto_newImage(new unsigned char[sizeof(rgba_t)* m_width * m_height]);
		rgba_t *newImage = reinterpret_cast<rgba_t *>(auto_newImage.get());
#else 
		rgba_t *newImage = new rgba_t[m_width * m_height];
#endif

		if (!newImage)
			return false;

		rgba_t *dest = newImage;
		rgb_t *src = (rgb_t*)m_pImageData.get();

		for (int x = 0; x < m_height; x++)
		{
			for (int y = 0; y < m_width; y++)
			{
				dest->r = src->r;
				dest->g = src->g;
				dest->b = src->b;
		
				if(src->r == r && src->g == g && src->b == b)
				{
					dest->a = 0xff;
				}
				else
				{
					dest->a = 0;
				}

				++src;
				++dest;
			}
		}

#ifdef _use_smart_ptr_
		//m_pImageData = auto_newImage;
		m_pImageData.swap(auto_newImage);
#elif _use_my_mem_tracker_
		deleteo<unsigned char>(m_pImageData);
		m_pImageData = (unsigned char*)newImage;
#else //_use_my_mem_tracker_
		delete [] m_pImageData;
		m_pImageData = (unsigned char*)newImage;
#endif //_use_my_mem_tracker_


		m_colorDepth = 32;
		m_imageDataType = IMAGE_DATA_UNSIGNED_BYTE;
		m_imageDataFormat = IMAGE_RGBA;
		
		return true;
	}

	return false;
}