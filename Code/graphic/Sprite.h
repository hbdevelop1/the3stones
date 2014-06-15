
#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "../common.h"
#include <list>
#include "../rectangle.h"
#include <boost/smart_ptr/scoped_ptr.hpp>
#include "anim.h"


struct stRectangle2;
class Sprite
{
protected:
	const hb::stRectangle2	*m_rect;
	//hb::Points32	(& m_r2)[4];
	//const 
		unsigned int	m_texObj; //can not be const as it is modifiable in derived class

public:
	Sprite(const hb::stRectangle2 * rect, int itex);

	virtual ~Sprite();

	void Draw();
};

class AnimatedSprite: public Sprite
{
	hb::Points32				m_offset[4];
	boost::scoped_ptr<stAnim2>	m_anim;
public:
	AnimatedSprite(const hb::stRectangle2 *,int,const char *);

	void Update();
	void Draw();
};

class AnimatedSpriteNcrg: public AnimatedSprite
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