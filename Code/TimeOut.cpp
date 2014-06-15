
#include "timeout.h"
#include "objectsmanager.h"
#include "classids.h"
#include "ObjectsRectangles.h"
#include "graphic/TexturesManager.h"
#include "common.h"

#include "Mem/MemNew.h" 

#pragma warning (disable:4996)

ImplementCreator(TimeOut)

const char *textmsgs[]=
{
	"Your score is",
	"The highest score is",
	"The highest score was",
	"Congratulation !",
	"You have achieved a new score.",
};
/*
const char yourscore[]=			"Your score is................ ";
const char highestscore[]=		"The highest score is......... ";
const char highestscorewas[]=	"The highest score was........ ";
const char congratulation[]=	"Congratulation ! The highest score was........ ";
*/

TimeOut::TimeOut():Sprite(&ObjectsRectangles2[e_rect_timeout],e_tex_timeout),
					rplay(&ObjectsRectangles2[e_rect_timeout_playagain]),
					rquit(&ObjectsRectangles2[e_rect_timeout_quitgame])
{
	SetFlag(e_FLAG_MASTER);

	ObjectsManager::GetInstance().RegisterGlobalObject(this, CLASSID_TimeOut);

}

TimeOut::~TimeOut()
{
	ObjectsManager::GetInstance().UnRegisterGlobalObject(this);
}

void TimeOut::Update()
{
	;
}

void TimeOut::Draw()
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

	Score * score=dynamic_cast<Score*>(ObjectsManager::GetInstance().GetGlobalObject(CLASSID_Score));
	unsigned int hs=score->GetHighestScore();
	unsigned int s=score->GetScore();
	
	unsigned int line,column_left,column_right;

	line=m_rect->lt.y-30;
	column_left=m_rect->lt.x+40;
	column_right=m_rect->rt.x-70;
	
	if(s<=hs)
	{
		hb::DrawText(textmsgs[e_msg_yourscore],column_left, line);

		sprintf(scoretxt,"%4d",s);
		hb::DrawText(scoretxt,column_right, line);

		line-=30;
		hb::DrawText(textmsgs[e_msg_highestscoreis],column_left, line);
		
		sprintf(hscoretxt,"%4d",hs);
		hb::DrawText(hscoretxt,column_right, line);
	}
	else
	{
		hb::DrawText(textmsgs[e_msg_congratulation1],column_left, line);
		line-=20;
		hb::DrawText(textmsgs[e_msg_congratulation2],column_left, line);

		line-=30;
		hb::DrawText(textmsgs[e_msg_highestscorewas],column_left, line);
		sprintf(hscoretxt,"%4d",hs); 
		hb::DrawText(hscoretxt,column_right, line);

		line-=30;
		hb::DrawText(textmsgs[e_msg_yourscore],column_left, line);

		sprintf(scoretxt,"%4d",s);
		hb::DrawText(scoretxt,column_right, line);
	}


    glColor3f (1.0, 1.0, 0.2);

    glBegin(GL_POLYGON);
        glVertex2f (rplay->lb.x, rplay->lb.y);
        glVertex2f (rplay->rt.x, rplay->lb.y);
        glVertex2f (rplay->rt.x, rplay->rt.y);
        glVertex2f (rplay->lb.x, rplay->rt.y);
    glEnd();

	glColor3f (0.0, 0.0, 1.0);
	hb::DrawText("play again",rplay->lb.x+10, rplay->lb.y+(rplay->rt.y-rplay->rb.y)/2);


    glColor3f (1.0, 1.0, 0.2);

    glBegin(GL_POLYGON);
        glVertex2f (rquit->lb.x, rquit->lb.y);
        glVertex2f (rquit->rt.x, rquit->lb.y);
        glVertex2f (rquit->rt.x, rquit->rt.y);
        glVertex2f (rquit->lb.x, rquit->rt.y);
    glEnd();

	glColor3f (0.0, 0.0, 1.0);
	hb::DrawText("quit game",rquit->lb.x+10, rquit->lb.y+(rquit->rt.y-rquit->rb.y)/2);


}


/*	
void TimeOut::Draw()
{
    glColor3f (1.0, 0.0, 0.0);

    glBegin(GL_POLYGON);
        glVertex2f (r.l, r.b);
        glVertex2f (r.r, r.b);
        glVertex2f (r.r, r.t);
        glVertex2f (r.l, r.t);
    glEnd();

    glColor3f (0.0, 0.0, 1.0);
	char* p;

	glRasterPos2f(r.l+10, r.t-10);
	p= (char*) textmsgs[e_msg_yourscore];
	while (*p != '\0') glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);

	glRasterPos2f(r.l+10, r.t-30);
	p= (char*) textmsgs[e_msg_highestscoreis];
	while (*p != '\0') glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
}
*/
void TimeOut::OnClick(int x,int y)
{
	if(rplay->lb.x<=x && x<=rplay->rb.x && rplay->rb.y<=y && y<=rplay->rt.y)
	{
		dynamic_cast<Score*>(ObjectsManager::GetInstance().GetGlobalObject(CLASSID_Score))->UpdateHighestScore();

	//	game->reset();
		ObjectsManager::GetInstance().Pop(this,false);
	}
	else if(rquit->lb.x<=x && x<=rquit->rb.x && rquit->rb.y<=y && y<=rquit->rt.y)
	{
//		game *g=dynamic_cast<game*>(ObjectsManager::GetInstance().GetGlobalObject(CLASSID_game));
	//	game->reset();
		//ObjectsManager::GetInstance().Pop(this);
		
		//ObjectsManager::GetInstance().Pop(this,true); will be popped and removed by ObjectsManager::Clear()
		//just like Intro, CountDown are popped and removed
		exit ( 0 );
	}

}