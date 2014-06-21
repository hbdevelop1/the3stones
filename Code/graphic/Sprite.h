
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

	const hb::Rectangle	*m_rect;
	unsigned int		m_texObj;

public:
	Sprite(const hb::Rectangle * rect, int itex);

	virtual ~Sprite();

	void Draw();
};

class AnimatedSprite: public Sprite
{
	hb::Points32				m_offset[4];
	boost::scoped_ptr<Anim>	m_anim;
public:
	AnimatedSprite(const hb::Rectangle *,int,const char *);

	void Update();
	void Draw();
};

class AnimatedSpriteNcrg: public AnimatedSprite
{
	const unsigned int	m_texObj1;
	const unsigned int	m_texObj2;
	int					m_image;
public:
	AnimatedSpriteNcrg(const hb::Rectangle *,int,int,const char *);
	void SetImage(int type);
	void Draw();
};

#endif _SPRITE_H_