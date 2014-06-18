
#include "Intro.h"
#include "objectsmanager.h"
#include "classids.h"
#include "ObjectsRectangles.h"
#include "graphic/TexturesManager.h"
#include "common.h"




ImplementCreator(Intro)

const char *Introtextmsgs[]=
{
	"Rules of the game :",

	"Click on one tile, then click on a neigbooring one to swap",
	"their positions.",
	"If three tiles of the same color are lined up, vertically",
	"or horizontally, you win 100 points.",
};

Intro::Intro():
	Sprite(& ObjectsRectangles[e_rect_Intro], e_tex_Intro)
	,rplay(& ObjectsRectangles[e_rect_Intro_startbutton])
{
	SetFlag(e_FLAG_MASTER);
}

Intro::~Intro()
{
}


void Intro::Update()
{
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

	Sprite::Draw();

	glColor3f (0.0, 0.0, 1.0);


	
	unsigned int line,column_left; 

	line=m_rect->t-30;
	column_left=m_rect->l+25;


	int i=e_msg_rules;
	hb::DrawText(Introtextmsgs[i++],column_left, line);
	
	line-=30;
	hb::DrawText(Introtextmsgs[i++],column_left, line);
	line-=20;
	hb::DrawText(Introtextmsgs[i++],column_left, line);
		
	line-=30;
	hb::DrawText(Introtextmsgs[i++],column_left, line);
	line-=20;
	hb::DrawText(Introtextmsgs[i++],column_left, line);



	//button

    glColor3f (1.0, 1.0, 0.2);

    glBegin(GL_POLYGON);
        glVertex2f (rplay->l, rplay->b);
        glVertex2f (rplay->r, rplay->b);
        glVertex2f (rplay->r, rplay->t);
        glVertex2f (rplay->l, rplay->t);
    glEnd();

	glColor3f (0.0, 0.0, 1.0);
	hb::DrawText("Start",rplay->l+10, rplay->b+(rplay->t-rplay->b)/2);



}

void Intro::OnClick( unsigned int x, unsigned int y)
{
	if(rplay->l<=x && x<=rplay->r && rplay->b<=y && y<=rplay->t)
	{
		ObjectsManager::GetInstance().Pop(this,false);
	}
}