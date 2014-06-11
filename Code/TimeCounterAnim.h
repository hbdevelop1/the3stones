#ifdef _testingthenewspriteobjectclass_


#ifndef _TIMECOUNTERANIM_
#define _TIMECOUNTERANIM_

#include "common.h"
#include "rectangle.h"
#include "object.h"
#include "graphic\sprite.h"

#include <time.h>

class TimeCounterAnim : public Object//, public Sprite3
{
	boost::scoped_ptr<AnimatedSprite3>	m_animsprite;

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
	TimeCounterAnim(const TimeCounterAnim &);
	TimeCounterAnim & operator=(const TimeCounterAnim &);
	*/
public:
	TimeCounterAnim();
	~TimeCounterAnim();

	void Update();
	void Draw();
	
	void Start();
	void Stop();
	void Reset();

	friend class game;
};


#endif _TIMECOUNTERANIM_

#endif //_testingthenewspriteobjectclass_
