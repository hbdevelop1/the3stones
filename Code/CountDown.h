
#ifndef _COUNTDOWN_
#define _COUNTDOWN_


#include "common.h"
#include "rectangle.h"
#include "object.h"




class CountDown : public Object
{
	const hb::Rectangle & m_rect;
	unsigned int		m_texObj;

	DWORD				m_t0;
	char				m_currentframe;
	char				m_currentfigure;
	enum
	{
		e_nbrframes=5,
		e_tilewidth=128,
		e_tileheight=128,
		e_imagewidth=128*e_nbrframes,
		e_imageheight=128*3,
		e_timeperframe=150,
	};
public:
	enum 
	{
		e_Height=100*2,
	};

public:
	CountDown();
	~CountDown();

	void Update();
	void Draw();
	void reset();

	void Animate();

};

#endif //_COUNTDOWN_