
#include "common.h"

#include "Score.h"
#include "board.h"
#include "ObjectsManager.h"
#include "classids.h"
#include "TexturesManager.h"
#include "objectsrectangles.h"

#include "MemNew.h"

#pragma warning (disable:4996)

uint32	Score::highestscore_i=0;

#define _animateglobalscore_


ImplementCreator(Score)

Score::Score():m_is(m_gs)
{
	ObjectsManager::GetInstance().RegisterGlobalObject(this,CLASSID_Score);
}

Score::~Score()
{
	ObjectsManager::GetInstance().UnRegisterGlobalObject(this);
}

void Score::Update()
{
	m_gs.Update();
	m_is.Update();
}

void Score::Add(hb::Pointu32 sp)
{
#ifdef _animateglobalscore_
#else
	m_gs.Add();
#endif
	m_is.Add(sp);
}

void Score::Draw()
{
	m_gs.Draw();
	m_is.Draw();
}

void Score::Reset()
{
	m_gs.Reset();
	m_is.Reset();
}

void Score::WhenDeactivated()
{//to remove animated individual score when timeout pops up.
	m_is.Reset();
}

bool Score::UpdateHighestScore()
{
	if(Score::highestscore_i < m_gs.m_score_i)
	{
		Score::highestscore_i = m_gs.m_score_i;
		return true;//new score
	}
	return false;//no new score
}

unsigned int Score::GetHighestScore()
{
	return Score::highestscore_i;
}

unsigned int Score::GetScore()
{
	return m_gs.m_score_i;
}
/////////////


#define MAXLIFE 2000
#define DIV		100


const char	IndividualScore::ms_score_str[]="+100";
const int	IndividualScore::ms_score_i=100;



#if _bezierinscore_==1

float Text::stept=.05f;

Text::Text(const char* s, hb::Pointu32 sp, GlobalScore & gs)
	:initialPos(sp)
	,currentPos(sp)
	,controlPoint(sp.x,ObjectsRectangles[e_rect_window].t)
	,landingPoint(ObjectsRectangles[e_rect_score].l,ObjectsRectangles[e_rect_score].b)
	,t(0)
	,tm(clock())
	,end(false)
	,m_gs(gs)
{
	strncpy(str,s,MAXSTRSZ-1);
}

void Text::Reset(const char* s, hb::Pointu32 sp)
{
	currentPos=sp;
	initialPos=sp;
	controlPoint=hb::Pointu32(sp.x,ObjectsRectangles[e_rect_window].t);
	landingPoint=hb::Pointu32(ObjectsRectangles[e_rect_score].l,ObjectsRectangles[e_rect_score].b);
	t=0;
	tm=clock();
	end=false;

	strncpy(str,s,MAXSTRSZ-1);
}

void Text::Update()
{
	if(clock()-tm >= 50)
	{
		tm=clock();

		if(t>=1.f)
		{
			m_gs.Increment();
			end=true;
		}

		float _1_t = 1-t;
		float _1_t__2 = _1_t * _1_t;
		float t2=t * t;
			
		float C=t2;
		float B=2 * _1_t * t;
		float A=_1_t__2;

		float x=A*initialPos.x+B*controlPoint.x+C*landingPoint.x;
		float y=A*initialPos.y+B*controlPoint.y+C*landingPoint.y;

		currentPos.x=x;
		currentPos.y=y;
		t+=Text::stept;
	}		
}


#elif _bezierinscore_==0
Text::Text(const char* s, hb::Pointu32 sp):initialPos(sp),life(MAXLIFE)
{
	strncpy(str,s,MAXSTRSZ-1);
}
#endif _bezierinscore_

IndividualScore::IndividualScore(GlobalScore & gs):m_gs(gs)
{
	//assert(m_gs);
	Reset();
}

IndividualScore::~IndividualScore()
{
	m_scores.clear();
}

void IndividualScore::Reset()
{
	m_scores.clear();
}

#if _bezierinscore_==1
void IndividualScore::Update()
{
	for(deque<Text>::iterator it=m_scores.begin();it!=m_scores.end(); ++it)
	{
		if(!it->end)
		{
			it->Update();
		}
	}
}
void IndividualScore::Add(hb::Pointu32 sp)
{
	sp=sp+hb::Pointu32(Square::e_Height>>2,Square::e_Height>>1);

	for(deque<Text>::iterator it=m_scores.begin();it!=m_scores.end(); ++it)
	{
		if(it->end)
		{
			/*
			Text *pUnused = &(*it);
			new (pUnused) Text(IndividualScore::score_str,sp);
			placement new spits an error in vs2010:it doesn't like a variable next to the new keyword but expects a data type.
			*/
			it->Reset(IndividualScore::ms_score_str,sp);
			return;
		}
	}
	
	m_scores.push_back(Text(IndividualScore::ms_score_str,sp,m_gs));

}
void IndividualScore::Draw()
{
	glColor3f(.0f,.0f,.0f);

	for(deque<Text>::iterator it=m_scores.begin();it!=m_scores.end(); ++it)
	{
		if(!it->end && it->t!=0 /*to avoid drawing a static text*/)
		{
			glRasterPos2f(it->currentPos.x, it->currentPos.y);
			char* p = (char*) (*it).str;
			while (*p != '\0') glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
		}
	}
}

#elif _bezierinscore_==0
void IndividualScore::Update()
{
	for(deque<Text>::iterator it=m_scores.begin();it!=m_scores.end(); ++it)
	{
		if(it->life>=0)
		{
			if(it->life % DIV == 0)				
				it->currentPos.y+=4;
			--it->life;
		}
	}
}
void IndividualScore::Add(hb::Pointu32 sp)
{
	sp=sp+hb::Pointu32(Square::e_Height>>2,Square::e_Height>>1);

	for(deque<Text>::iterator it=m_scores.begin();it!=m_scores.end(); ++it)
	{
		if(it->life<=0)
		{
			strncpy(it->str, IndividualScore::score_str, MAXSTRSZ-1);
			it->life=MAXLIFE;
			it->currentPos=sp;
			return;
		}
	}
	int u=deque<Text>::_EEM_DS;
	m_scores.push_back(Text(IndividualScore::score_str,sp));

}

void IndividualScore::Draw()
{
	glColor3f(.0f,.0f,.0f);

	for(deque<Text>::iterator it=m_scores.begin();it!=m_scores.end(); ++it)
	{
		if(it->life>=0)
		{
			glRasterPos2f(it->currentPos.x, it->currentPos.y);
			char* p = (char*) (*it).str;
			while (*p != '\0') glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
		}
	}
}
#endif _bezierinscore_
////////////////

GlobalScore::GlobalScore():m_r(ObjectsRectangles[e_rect_score])
										
{
	m_texObj=TexturesManager::GetInstance().GetTextureObj(e_tex_score);

	Reset();
}

GlobalScore::~GlobalScore()
{
}

void GlobalScore::Update()
{
}

#ifdef _animateglobalscore_
void GlobalScore::Increment()
{
	m_score_i += IndividualScore::ms_score_i;
	_itoa(m_score_i,m_score_str,10);
}
#else
void GlobalScore::Add()
{
	m_score_i += IndividualScore::ms_score_i;
	_itoa(m_score_i,m_score_str,10);
}
#endif

void GlobalScore::Draw()
{
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, m_texObj);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 

	glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex2f (m_r.l, m_r.b);
        glTexCoord2f(1, 0); glVertex2f (m_r.r, m_r.b);
        glTexCoord2f(1, 1); glVertex2f (m_r.r, m_r.t);
        glTexCoord2f(0, 1); glVertex2f (m_r.l, m_r.t);
    glEnd();
	
	
	glDisable(GL_TEXTURE_2D);

	glColor3f (1.0, 1.0, 0.0);
	glRasterPos2f(m_r.l+30, m_r.t-50);

	char* p = (char*) m_score_str;
	while (*p != '\0') glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
										//GLUT_BITMAP_TIMES_ROMAN_24
		
}
#if 0
void GlobalScore::Draw()
{
    glColor3f (1.0, 0.0, 1.0);

    glBegin(GL_POLYGON);
        glVertex2f (m_r.l, m_r.b);
        glVertex2f (m_r.r, m_r.b);
        glVertex2f (m_r.r, m_r.t);
        glVertex2f (m_r.l, m_r.t);
    glEnd();

	glColor3f (0.0, 0.0, 0.0);
	glRasterPos2f(m_r.l+30, m_r.t-50);

	char* p = (char*) score_str;
	while (*p != '\0') glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
}
#endif
void GlobalScore::Reset()
{
	m_score_str[0]='0';
	m_score_str[1]=0;
	m_score_i=0;
}
