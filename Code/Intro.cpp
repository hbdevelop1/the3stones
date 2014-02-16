
#include "Intro.h"
#include "objectsmanager.h"
#include "classids.h"
#include "objectsrectangles.h"
#include "TexturesManager.h"
#include "common.h"

#include "MemNew.h"


ImplementCreator(Intro)

const char *Introtextmsgs[]=
{
	"Rules of the game :",
	"Arrange three tiles of the same color",
	"to win 100 points.",
};


Intro::Intro():r(ObjectsRectangles[e_rect_Intro]),
					rplay(ObjectsRectangles[e_rect_Intro_start])
{
	SetFlag(e_FLAG_MASTER);

	m_texObj=TexturesManager::GetInstance().GetTextureObj(e_tex_Intro);
}

Intro::~Intro()
{
}

void Intro::Update()
{
	;
}

void Intro::Draw()
{
	const hb::Rectangle & rDim(ObjectsRectangles[e_rect_board]);
	
	glEnable(GL_BLEND); 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	
	glColor4f (0.0, 0.0, 0.0,.25);

	glBegin(GL_POLYGON);
        glVertex2f (rDim.l, rDim.b);
        glVertex2f (rDim.r, rDim.b);
        glVertex2f (rDim.r, rDim.t);
        glVertex2f (rDim.l, rDim.t);
    glEnd();

	glDisable(GL_BLEND); 


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

	glColor3f (0.0, 0.0, 1.0);


	
	unsigned int line,column_left; 

	line=r.t-30;
	column_left=r.l+25;
	
	hb::DrawText(Introtextmsgs[e_msg_rules],column_left, line);

	line-=30;
	hb::DrawText(Introtextmsgs[e_msg_arrange],column_left, line);
		
	line-=30;
	hb::DrawText(Introtextmsgs[e_msg_win],column_left, line);



	//button

    glColor3f (1.0, 1.0, 0.2);

    glBegin(GL_POLYGON);
        glVertex2f (rplay.l, rplay.b);
        glVertex2f (rplay.r, rplay.b);
        glVertex2f (rplay.r, rplay.t);
        glVertex2f (rplay.l, rplay.t);
    glEnd();

	glColor3f (0.0, 0.0, 1.0);
	hb::DrawText("Start",rplay.l+10, rplay.b+(rplay.t-rplay.b)/2);



}

void Intro::OnClick(uint32 x,uint32 y)
{
	if(rplay.l<=x && x<=rplay.r && rplay.b<=y && y<=rplay.t)
	{
		ObjectsManager::GetInstance().Pop(this);
	}

}