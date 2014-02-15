
#ifdef _use_smart_ptr_
#include "smartptrs/scoped_array.hpp"
//#include "CTargaImage.h"
#endif

class CTargaImage;

class TexturesManager
{
#ifdef _use_smart_ptr_
	boost::scoped_array<CTargaImage>	m_tex;
	boost::scoped_array<unsigned int>	m_texObj;
#else
	CTargaImage				*m_tex;
	unsigned int			*m_texObj;
#endif

	
private:
	TexturesManager();
	TexturesManager(const TexturesManager &);
	TexturesManager & operator=(const TexturesManager&);


	bool TexInit();
	void TexUninit();

public:

	~TexturesManager();
	static TexturesManager & GetInstance() 
	{
		static TexturesManager instance;
		return instance;
	}
	unsigned int GetTextureObj(unsigned int i);
};

enum
{
	e_tex_tile_blue,
	e_tex_tile_green,
	e_tex_tile_purple,
	e_tex_tile_red,
	e_tex_tile_yellow,
	e_tex_score,
	e_tex_timecounter,
	e_tex_timeout,
	e_tex_Intro=e_tex_timeout,
	e_tex_countdown,

	e_tex_nbrofTextures
};