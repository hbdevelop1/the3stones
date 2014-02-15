
#ifndef _COUNTDOWN_
#define _COUNTDOWN_


#include "common.h"
#include "rectangle.h"
#include "object.h"




class CountDown : public Object
{
	const hb::Rectangle & r;
	hb::Rectangle rf;
	Color figures[3];
	int		counter;
	int		color_index;
	unsigned int m_texObj;

	DWORD t0;
	char currentframe;
	char currentfigure;
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