#ifndef _TIMECOUNTER_
#define _TIMECOUNTER_

#include "common.h"
#include "rectangle.h"
#include "object.h"

#include <time.h>

class TimeCounter : public Object
{
	bool	m_timeout;
	time_t	starttime;
	char	time_str[20];
	const hb::Rectangle & r;
	unsigned int m_texObj;

public:
	enum
	{
		e_Height=64,
		e_Width=128
	};

private:
	TimeCounter(const TimeCounter &);
	TimeCounter & operator=(const TimeCounter &);
public:
	TimeCounter();
	~TimeCounter();

	void Update();
	void Draw();
	
	void Start();
	void Stop();
	void Reset();

	friend class game;
};


#endif _TIMECOUNTER_