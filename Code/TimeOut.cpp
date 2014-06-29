
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
					m_rplay(&ObjectsRectangles[e_rect_timeout_playagain]),
					m_rquit(&ObjectsRectangles[e_rect_timeout_quitgame])
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
        glVertex2i (rDim.l, rDim.b);
        glVertex2i (rDim.r, rDim.b);
        glVertex2i (rDim.r, rDim.t);
        glVertex2i (rDim.l, rDim.t);
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

		sprintf(m_scoretxt,"%4d",s);
		hb::DrawText(m_scoretxt,column_right, line);

		line-=30;
		hb::DrawText(textmsgs[e_msg_highestscoreis],column_left, line);
		
		sprintf(m_hscoretxt,"%4d",hs);
		hb::DrawText(m_hscoretxt,column_right, line);
	}
	else
	{
		hb::DrawText(textmsgs[e_msg_congratulation1],column_left, line);
		line-=20;
		hb::DrawText(textmsgs[e_msg_congratulation2],column_left, line);

		line-=30;
		hb::DrawText(textmsgs[e_msg_highestscorewas],column_left, line);
		sprintf(m_hscoretxt,"%4d",hs); 
		hb::DrawText(m_hscoretxt,column_right, line);

		line-=30;
		hb::DrawText(textmsgs[e_msg_yourscore],column_left, line);

		sprintf(m_scoretxt,"%4d",s);
		hb::DrawText(m_scoretxt,column_right, line);
	}


    glColor3f (1.f, 1.f, 0.2f);

    glBegin(GL_POLYGON);
        glVertex2i (m_rplay->l, m_rplay->b);
        glVertex2i (m_rplay->r, m_rplay->b);
        glVertex2i (m_rplay->r, m_rplay->t);
        glVertex2i (m_rplay->l, m_rplay->t);
    glEnd();

	glColor3f (0.0, 0.0, 1.0);
	hb::DrawText("play again",m_rplay->l+10, m_rplay->b+(m_rplay->t-m_rplay->b)/2);


    glColor3f (1.0f, 1.0f, 0.2f);

    glBegin(GL_POLYGON);
        glVertex2i (m_rquit->l, m_rquit->b);
        glVertex2i (m_rquit->r, m_rquit->b);
        glVertex2i (m_rquit->r, m_rquit->t);
        glVertex2i (m_rquit->l, m_rquit->t);
    glEnd();

	glColor3f (0.0, 0.0, 1.0);
	hb::DrawText("quit game",m_rquit->l+10, m_rquit->b+(m_rquit->t-m_rquit->b)/2);


}


void TimeOut::OnClick(unsigned int x,unsigned int y)
{
	if(m_rplay->l<=x && x<=m_rplay->r && m_rplay->b<=y && y<=m_rplay->t)
	{
		dynamic_cast<Score*>(ObjectsManager::GetInstance().GetGlobalObject(CLASSID_Score))->UpdateHighestScore();

		ObjectsManager::GetInstance().Pop(this,false);
	}
	else if(m_rquit->l<=x && x<=m_rquit->r && m_rquit->b<=y && y<=m_rquit->t)
	{
		exit ( 0 );
	}

}