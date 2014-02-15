
#ifndef _INTRO_
#define _INTRO_


#include "rectangle.h"
#include "object.h"



class Intro : public Object
{
	const hb::Rectangle & r;
	hb::Rectangle rplay;

	unsigned int m_texObj;

	enum
	{
		e_msg_rules,
		e_msg_arrange,
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

	void OnClick(uint32 x,uint32 y);
};

#endif //_Intro_