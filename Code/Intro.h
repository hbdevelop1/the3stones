
#ifndef _INTRO_
#define _INTRO_

#include <stdio.h>
#include "rectangle.h"
#include "object.h"
#include "graphic\sprite.h"

class Intro : public Object, public Sprite
{
	const hb::Rectangle *rplay;

	enum
	{
		e_msg_rules,
		e_msg_arrange,
		e_msg_position,
		e_msg_if,
		e_msg_win,

		e_msg_nbroftextmsgs
	};

public:
	enum
	{
		e_width=100,
		e_height=60,
	};
public:
	Intro();
	~Intro();

	void Update();
	void Draw();

	void OnClick(unsigned int x,unsigned int y);
};

#endif //_Intro_