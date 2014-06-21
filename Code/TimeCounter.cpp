
#include "TimeCounter.h"
#include <stdio.h>
#include "objectsmanager.h"
#include "graphic/TexturesManager.h"
#include "ObjectsRectangles.h"
#include "common.h"

#include "Mem/MemNew.h"

#pragma warning (disable:4996)

TimeCounter::TimeCounter():m_timeout(true),Sprite(& ObjectsRectangles[e_rect_timecounter], e_tex_timecounter)
{
}

TimeCounter::~TimeCounter()
{
}

void TimeCounter::Update()
{
	if(m_timeout)
		return;

	time_t t=time(0);

	t=t-m_startTime;
	long m=t/60;
	long s=t%60;

	sprintf(m_time_str,"%01d:%02d",m,s);

	if(s>=13)
	{
		//m_timeout=true;
	}
	if(m>=1)
	{
		m_timeout=true;
	}
}

void TimeCounter::Draw()
{
	Sprite::Draw();

	glColor3f (1.0, 1.0, 0.0);

	glRasterPos2f(m_rect->l +30, m_rect->t-50);

	char* p = (char*) m_time_str;
	while (*p != '\0') glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
}

void TimeCounter::Start()
{
	m_startTime=time(0);
	m_timeout=false;
}
void TimeCounter::Stop()
{
	m_timeout=true;
}
void TimeCounter::Reset()
{
	sprintf(m_time_str,"0:00");
	m_timeout=true;
}
