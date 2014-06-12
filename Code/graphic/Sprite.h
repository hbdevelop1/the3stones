
#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "../common.h"
#include <list>
#include "../rectangle.h"
#include <boost/smart_ptr/scoped_ptr.hpp>
#include "anim.h"


class Sprite
{
protected:
	hb::Points32	m_r[4];
	hb::Points32	m_offset[4];
	//hb::Rectangle	m_r;
	unsigned int	m_texObj;
	boost::scoped_ptr<stAnim2>	m_anim;


public:
	Sprite(){}
	//Sprite(hb::Points32 _r[], const char * texname,const char * animationfilename);
	Sprite(hb::Points32 _r[],const char * animationfilename, const int itex);
	Sprite(const Sprite &);
	//~Sprite(){} //i need this mainly so Sprite array is coherent with scoped_array
	//Sprites are maintained in a list, in the Encouragement class, not in scoped_array

	virtual ~Sprite();

	void Draw();
	void Update();
	void Reset();

};

class Sprite2: public Sprite
{
	unsigned int	m_texObj2;
	int				m_image;
public:
	Sprite2(){}
	//Sprite(hb::Points32 _r[], const char * texname,const char * animationfilename);
	Sprite2(hb::Points32 _r[], const char * animationfilename, const int itex, const int itex2);
	Sprite2(const Sprite2 &);
	//~Sprite(){} //i need this mainly so Sprite array is coherent with scoped_array
	//Sprites are maintained in a list, in the Encouragement class, not in scoped_array

	void Draw();
	void SetImage(int type);
};

struct stRectangle2;
class Sprite3
{
protected:
	const hb::stRectangle2	m_rect;
	//hb::Points32	(& m_r2)[4];
	//const 
		unsigned int	m_texObj; //can not be const as it is modifiable in derived class

public:
	Sprite3(const hb::stRectangle2 * rect, int itex);

	virtual ~Sprite3();

	void Draw();
};

class AnimatedSprite3: public Sprite3
{
	hb::Points32				m_offset[4];
	boost::scoped_ptr<stAnim2>	m_anim;
public:
	AnimatedSprite3(const hb::stRectangle2 *,int,const char *);

	void Update();
	void Draw();
};

class AnimatedSpriteNcrg: public AnimatedSprite3
{
	const unsigned int	m_texObj1;
	const unsigned int	m_texObj2;
	int					m_image;
public:
	AnimatedSpriteNcrg(const hb::stRectangle2 *,int,int,const char *);
	void SetImage(int type);
	void Draw();
};

#endif _SPRITE_H_