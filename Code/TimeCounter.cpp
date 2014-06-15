
#include "TimeCounter.h"
#include <stdio.h>
#include "objectsmanager.h"
#include "graphic/TexturesManager.h"
#include "ObjectsRectangles.h"
#include "common.h"

#include "Mem/MemNew.h"

#pragma warning (disable:4996)

TimeCounter::TimeCounter():m_timeout(true),Sprite(& ObjectsRectangles2[e_rect_timecounter], e_tex_timecounter)
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

	t=t-starttime;
	long m=t/60;
	long s=t%60;
	/*
	char m_str[4];
	_itoa(m,m_str,10);

	char s_str[4];
	_itoa(s,s_str,10);
	*/
	sprintf(time_str,"%01d:%02d",m,s);

	if(s>=13)
	{
		m_timeout=true;
	}
	if(m>=1)
	{
		//m_timeout=true;
	}
}

void TimeCounter::Draw()
{
	Sprite::Draw();

	glColor3f (1.0, 1.0, 0.0);

	glRasterPos2f(m_rect->lt.x +30, m_rect->lt.y-50);

	char* p = (char*) time_str;
	while (*p != '\0') glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
}
#if 0
void TimeCounter::Draw()
{
    glColor3f (1.0, 0.0, 1.0);

    glBegin(GL_POLYGON);
        glVertex2f (r.l, r.b);
        glVertex2f (r.r, r.b);
        glVertex2f (r.r, r.t);
        glVertex2f (r.l, r.t);
    glEnd();

	glColor3f (0.0, 0.0, 0.0);
	glRasterPos2f(r.l+30, r.t-50);

	char* p = (char*) time_str;
	while (*p != '\0') glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
}
#endif

void TimeCounter::Start()
{
	starttime=time(0);
	m_timeout=false;
}
void TimeCounter::Stop()
{
	m_timeout=true;
}
void TimeCounter::Reset()
{
	sprintf(time_str,"0:00");
	m_timeout=true;
}
