
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

ImplementCreator(Score)

Score::Score()
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
	m_gs.Add();
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
	if(Score::highestscore_i < m_gs.score_i)
	{
		Score::highestscore_i = m_gs.score_i;
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
	return m_gs.score_i;
}
/////////////


#define MAXLIFE 2000
#define DIV		100


const char	IndividualScore::score_str[]="+100";
const int	IndividualScore::score_i=100;


Text::Text(const char* s, hb::Pointu32 sp):screenPos(sp)
{
	strncpy(str,s,MAXSTRSZ-1);
	life=MAXLIFE;
}

IndividualScore::IndividualScore()
{
	Reset();
}

IndividualScore::~IndividualScore()
{
	scores.clear();
}

void IndividualScore::Update()
{
	for(deque<Text>::iterator it=scores.begin();it!=scores.end(); ++it)
	{
		if(it->life>=0)
		{
			if(it->life % DIV == 0)				
				it->screenPos.y+=4;
			--it->life;
		}
	}
}

void IndividualScore::Add(hb::Pointu32 sp)
{
	sp=sp+hb::Pointu32(Square::e_Height>>2,Square::e_Height>>1);

	for(deque<Text>::iterator it=scores.begin();it!=scores.end(); ++it)
	{
		if(it->life<=0)
		{
			strncpy(it->str, IndividualScore::score_str, MAXSTRSZ-1);
			it->life=MAXLIFE;
			it->screenPos=sp;
			return;
		}
	}
	
	scores.push_back(Text(IndividualScore::score_str,sp));

}

void IndividualScore::Draw()
{
	glColor3f(.0f,.0f,.0f);

	for(deque<Text>::iterator it=scores.begin();it!=scores.end(); ++it)
	{
		if(it->life>=0)
		{
			glRasterPos2f(it->screenPos.x, it->screenPos.y);
			char* p = (char*) (*it).str;
			while (*p != '\0') glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
		}
	}
}

void IndividualScore::Reset()
{
	scores.clear();
}
////////////////

GlobalScore::GlobalScore():r(ObjectsRectangles[e_rect_score])
										
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

void GlobalScore::Add()
{
	score_i += IndividualScore::score_i;
	_itoa(score_i,score_str,10);
}

void GlobalScore::Draw()
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
	glRasterPos2f(r.l+30, r.t-50);

	char* p = (char*) score_str;
	while (*p != '\0') glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
										//GLUT_BITMAP_TIMES_ROMAN_24
		
}
#if 0
void GlobalScore::Draw()
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

	char* p = (char*) score_str;
	while (*p != '\0') glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
}
#endif
void GlobalScore::Reset()
{
	score_str[0]='0';
	score_str[1]=0;
	score_i=0;
}
