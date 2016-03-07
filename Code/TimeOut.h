
#ifndef _TIMEOUT_
#define _TIMEOUT_


#include "rectangle.h"
#include "object.h"
#include "graphic\sprite.h"


class TimeOut : public Object, public Sprite
{
	const hb::Rectangle * m_rplay;
	const hb::Rectangle * m_rquit;


	enum
	{
		e_max_chars=5, //highest score is 6000 points -> char[5] is enough to hold the scores.
	};
	char	m_scoretxt[e_max_chars];
	char	m_hscoretxt[e_max_chars];

	
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

	void OnClick(unsigned int x,unsigned int y);
};

#endif //_TIMEOUT_