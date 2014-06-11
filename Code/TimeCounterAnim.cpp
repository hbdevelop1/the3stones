#ifdef _testingthenewspriteobjectclass_

#include "TimeCounterAnim.h"
#include <stdio.h>
#include "objectsmanager.h"
#include "graphic/TexturesManager.h"
#include "objectsrectangles.h"
#include "common.h"

#include "Mem/MemNew.h"

#pragma warning (disable:4996)

TimeCounterAnim::TimeCounterAnim()
{
	m_animsprite.reset(new AnimatedSprite3(& ObjectsRectangle2[1], e_tex_timecounter, "data/anim1.xml"));
}

TimeCounterAnim::~TimeCounterAnim()
{
}

void TimeCounterAnim::Update()
{
	m_animsprite->Update();
}

void TimeCounterAnim::Draw()
{
	m_animsprite->Draw();
}

void TimeCounterAnim::Start()
{
	starttime=time(0);
	m_timeout=false;
}
void TimeCounterAnim::Stop()
{
	m_timeout=true;
}
void TimeCounterAnim::Reset()
{
	sprintf(time_str,"0:00");
	m_timeout=true;
}

#endif //_testingthenewspriteobjectclass_
