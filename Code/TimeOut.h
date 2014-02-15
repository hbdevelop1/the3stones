
#ifndef _TIMEOUT_
#define _TIMEOUT_


#include "rectangle.h"
#include "object.h"



class TimeOut : public Object
{
	const hb::Rectangle & r;
	hb::Rectangle rplay;
	hb::Rectangle rquit;

	unsigned int m_texObj;

	enum
	{
		e_max_chars=10, //highest score is 6000 points -> char[5] is enough to hold the scores.
	};
	char	scoretxt[e_max_chars];
	char	hscoretxt[e_max_chars];

	bool clicked;

	
	enum
	{
		e_msg_yourscore,
		e_msg_highestscoreis,
		e_msg_highestscorewas,
		e_msg_congratulation1,
		e_msg_congratulation2,

		e_msg_nbroftextmsgs
	};


public:
	enum
	{
		e_Height=100*2,//64*4,
		e_Width=100*4
	};

public:
	TimeOut();
	~TimeOut();

	void Update();
	void Draw();

	void OnClick(uint32 x,uint32 y);
};

#endif //_TIMEOUT_