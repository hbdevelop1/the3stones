#include <stdio.h>

#include "TexturesManager.h"
#include "CTargaImage.h"
#include "../Common.h"
#include "../mem/MemNew.h"

TexturesManager::TexturesManager()
{
	TexInit();
	/*
	hb::scoped_array<unsigned int>	texObj;
	texObj.reset(new unsigned int[e_tex_nbrofTextures]);
	*/
}

TexturesManager::~TexturesManager()
{
	TexUninit();
}
	/*
int GetTexId(char * filefname)
{
	it=textures.find(filefname);
	if (it==textures.end())
	{
		CTargaImage j;
		j.Load(filename);

		int v;
		glGenTextures(1, &v);

		// bind the texture object
		glBindTexture(GL_TEXTURE_2D, v);

		// minimum required to set the min and mag texture filters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		// now that the texture object is bound, specify a texture for it
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, j.GetWidth(), j.GetHeight(),
						0, GL_RGB, GL_UNSIGNED_BYTE, j.GetImage());


		textures.insert(pair<>(filename,v));
	}
}
	*/


bool TexturesManager::TexInit()
{
	
	//m_tex = new CTargaImage[e_tex_nbrofTextures];
	m_tex.reset(new CTargaImage[e_tex_nbrofTextures]);

	unsigned int i=0;
	// load texture image data
	if (!m_tex[e_tex_tile_blue		].Load("data/tile_blue.tga")) return false;
	if (!m_tex[e_tex_tile_green		].Load("data/tile_green.tga")) return false;
	if (!m_tex[e_tex_tile_purple	].Load("data/tile_purple.tga")) return false;
	if (!m_tex[e_tex_tile_red		].Load("data/tile_red.tga")) return false;
	if (!m_tex[e_tex_tile_yellow	].Load("data/tile_yellow.tga")) return false;
	if (!m_tex[e_tex_score			].Load("data/score.tga")) return false;
	if (!m_tex[e_tex_timecounter	].Load("data/timecounter.tga")) return false;
	if (!m_tex[e_tex_timeout		].Load("data/timeout.tga")) return false;	
	if (!m_tex[e_tex_countdown		].Load("data/countdown.tga")) return false;	
	if (!m_tex[e_tex_countdown		].SetOpaqueColor(0,0,0)) return false;
	if (!m_tex[e_tex_encrg_good		].Load("data/Encrg-Good.tga")) return false;	
	if (!m_tex[e_tex_encrg_wow		].Load("data/Encrg-Wow.tga")) return false;	
	

	//m_texObj = new unsigned int[e_tex_nbrofTextures];
	m_texObj.reset(new unsigned int[e_tex_nbrofTextures]);

	for(unsigned int i=0; i<e_tex_nbrofTextures; ++i)
	{
		glGenTextures(1, &m_texObj[i]);

		// bind the texture object
		glBindTexture(GL_TEXTURE_2D, m_texObj[i]);

		// minimum required to set the min and mag texture filters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		// now that the texture object is bound, specify a texture for it
		if(i==e_tex_countdown)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_tex[i].GetWidth(), m_tex[i].GetHeight(),
					 0, GL_RGBA, GL_UNSIGNED_BYTE, m_tex[i].GetImage());
		}
		else
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_tex[i].GetWidth(), m_tex[i].GetHeight(),
						 0, GL_RGB, GL_UNSIGNED_BYTE, m_tex[i].GetImage());
		}
	}



	return true;
}

void TexturesManager::TexUninit()
{
	for(unsigned int i=0; i<e_tex_nbrofTextures; ++i)
		glDeleteTextures(1, &m_texObj[i]);

//	for(unsigned int i=0; i<e_tex_nbrofTextures; ++i) m_tex[i].Release();

	////delete [] m_tex;
	//deletea<CTargaImage>(m_tex);

	////delete [] m_texObj;
	//deleteo<unsigned int>(m_texObj);

}

unsigned int TexturesManager::GetTextureObj(unsigned int i)
{
	assert(0<=i && i<e_tex_nbrofTextures);
	return m_texObj[i];
}