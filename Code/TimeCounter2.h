#ifdef _testingthenewspriteobjectclass_


#ifndef _TIMECOUNTER2_
#define _TIMECOUNTER2_

#include "common.h"
#include "rectangle.h"
#include "object.h"
#include "graphic\sprite.h"

#include <time.h>

class TimeCounter2 : public Object, public Sprite
{
	//Sprite	m_sprite;

	bool	m_timeout;
	time_t	starttime;
	char	time_str[20];

public:
	enum
	{
		e_Height=64,
		e_Width=128
	};
	/*
private:
	TimeCounter2(const TimeCounter2 &);
	TimeCounter2 & operator=(const TimeCounter2 &);
	*/
public:
	TimeCounter2();
	~TimeCounter2();

	void Update();
	void Draw();
	
	void Start();
	void Stop();
	void Reset();

	friend class game;
};


#endif _TIMECOUNTER2_

#endif //_testingthenewspriteobjectclass_
