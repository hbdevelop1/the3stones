
#include "TimeCounter.h"
#include <stdio.h>
#include "objectsmanager.h"
#include "TexturesManager.h"
#include "objectsrectangles.h"
#include "common.h"

#include "MemNew.h"

#pragma warning (disable:4996)

TimeCounter::TimeCounter():m_timeout(true),r(ObjectsRectangles[e_rect_timecounter])
{
	m_texObj=TexturesManager::GetInstance().GetTextureObj(e_tex_timecounter);
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

	if(s>=3)
	{
		m_timeout=true;
	}
	if(m>=1)
	{
		m_timeout=true;
	}
}

void TimeCounter::Draw()
{
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, m_texObj);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 

	glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex2f (r.l, r.b);
        glTexCoord2f(1, 0); glVertex2f (r.r, r.b);
        glTexCoord2f(1, 1); glVertex2f (r.r, r.t);
        glTexCoord2f(0, 1); glVertex2f (r.l, r.t);
    glEnd();
	
	
	glDisable(GL_TEXTURE_2D);

	glColor3f (1.0, 1.0, 0.0);
	glRasterPos2f(r.r-80, r.t-50);

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
