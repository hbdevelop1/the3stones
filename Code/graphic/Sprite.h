

#include "../common.h"
#include <list>
#include "../rectangle.h"
#include <boost/smart_ptr/scoped_ptr.hpp>
#include "anim.h"


class Sprite
{
	hb::Points32	m_r[4];
	hb::Points32	m_offset[4];
	//hb::Rectangle	m_r;
	unsigned int	m_texObj;
	boost::scoped_ptr<stAnim2>	m_anim;


public:
	Sprite();
	//Sprite(hb::Points32 _r[], const char * texname,const char * animationfilename);
	Sprite(hb::Points32 _r[], const int itex,const char * animationfilename);
	Sprite(const Sprite &);
	//~Sprite(){} //i need this mainly so Sprite array is coherent with scoped_array
	//Sprites are maintained in a list, in the Encouragement class, not in scoped_array

	~Sprite();

	void Draw();
	void Update();

};

