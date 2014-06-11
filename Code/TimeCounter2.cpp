#ifdef _testingthenewspriteobjectclass_

#include "TimeCounter2.h"
#include <stdio.h>
#include "objectsmanager.h"
#include "graphic/TexturesManager.h"
#include "objectsrectangles.h"
#include "common.h"

#include "Mem/MemNew.h"

#pragma warning (disable:4996)

//TimeCounter2::TimeCounter2():m_sprite(& ObjectsRectangle2[0], e_tex_timecounter)
TimeCounter2::TimeCounter2():Sprite3(& ObjectsRectangle2[0], e_tex_timecounter)
{
	Sprite3 s(*this);
}

TimeCounter2::~TimeCounter2()
{
}

void TimeCounter2::Update()
{

	//Sprite3::Draw();
}

void TimeCounter2::Draw()
{
	Sprite3::Draw();
	//m_sprite.Draw();

#if 0
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
#endif //0
}

#if 0
void TimeCounter2::Draw()
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

void TimeCounter2::Start()
{
	starttime=time(0);
	m_timeout=false;
}
void TimeCounter2::Stop()
{
	m_timeout=true;
}
void TimeCounter2::Reset()
{
	sprintf(time_str,"0:00");
	m_timeout=true;
}

#endif //_testingthenewspriteobjectclass_
