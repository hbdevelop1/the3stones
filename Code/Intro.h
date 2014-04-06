
#ifndef _INTRO_
#define _INTRO_


#include "rectangle.h"
#include "object.h"

#define _anim_ 0

#if _anim_==1
#include <vector>
using namespace std;
#endif _anim_==1



class Intro : public Object
{
#if _anim_>0
	hb::Points32 r[4];
#else
	const hb::Rectangle & r;
#endif

	hb::Rectangle rplay;

	unsigned int m_texObj;

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

	void OnClick(uint32 x,uint32 y);
};

#endif //_Intro_