
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

TimeOut::TimeOut():Sprite(&ObjectsRectangles[e_rect_timeout],e_tex_timeout),
					rplay(&ObjectsRectangles[e_rect_timeout_playagain]),
					rquit(&ObjectsRectangles[e_rect_timeout_quitgame])
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

	line=m_rect->t-30;
	column_left=m_rect->l+40;
	column_right=m_rect->r-70;
	
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
        glVertex2f (rplay->l, rplay->b);
        glVertex2f (rplay->r, rplay->b);
        glVertex2f (rplay->r, rplay->t);
        glVertex2f (rplay->l, rplay->t);
    glEnd();

	glColor3f (0.0, 0.0, 1.0);
	hb::DrawText("play again",rplay->l+10, rplay->b+(rplay->t-rplay->b)/2);


    glColor3f (1.0, 1.0, 0.2);

    glBegin(GL_POLYGON);
        glVertex2f (rquit->l, rquit->b);
        glVertex2f (rquit->r, rquit->b);
        glVertex2f (rquit->r, rquit->t);
        glVertex2f (rquit->l, rquit->t);
    glEnd();

	glColor3f (0.0, 0.0, 1.0);
	hb::DrawText("quit game",rquit->l+10, rquit->b+(rquit->t-rquit->b)/2);


}


void TimeOut::OnClick(unsigned int x,unsigned int y)
{
	if(rplay->l<=x && x<=rplay->r && rplay->b<=y && y<=rplay->t)
	{
		dynamic_cast<Score*>(ObjectsManager::GetInstance().GetGlobalObject(CLASSID_Score))->UpdateHighestScore();

		ObjectsManager::GetInstance().Pop(this,false);
	}
	else if(rquit->l<=x && x<=rquit->r && rquit->b<=y && y<=rquit->t)
	{
		exit ( 0 );
	}

}