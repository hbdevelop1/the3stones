
#include "smartptrs/scoped_array.hpp"

class CTargaImage;

class TexturesManager
{
	boost::scoped_array<CTargaImage>	m_tex;
	boost::scoped_array<unsigned int>	m_texObj;

	
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