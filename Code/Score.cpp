
#include "common.h"

#include "Score.h"
#include "board.h"
#include "ObjectsManager.h"
#include "classids.h"
#include "graphic/TexturesManager.h"
#include "ObjectsRectangles.h"
#include "Encouragement.h"
#include "Settings.h"

#include "xml/xml.h"
#include <string>
using namespace std;

#pragma warning (disable:4996)

uint32	Score::highestscore_i=0;


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

uint32 Score::GetHighestScore()
{
	return Score::highestscore_i;
}

uint32 Score::GetScore()
{
	return m_gs.m_score_i;
}
/////////////


#define MAXLIFE 2000
#define DIV		100


const char	IndividualScore::ms_score_str[]="+100";
const int	IndividualScore::ms_score_i=100;

float Text::stept=.05f;

Text::Text()
	:t(0)
	,tmNcrg(tm=clock())
	,end(false)
	,gs(NULL)
	,encouraged(false)
{
}

Text::Text(const char* s, hb::Pointu32 sp, GlobalScore & gs)
	:initialPos(sp)
	,currentPos(sp)
	,controlPoint(sp.x,ObjectsRectangles[e_rect_window].t)
	,landingPoint(ObjectsRectangles[e_rect_score].l,ObjectsRectangles[e_rect_score].b)
	,t(0)
	,tmNcrg(tm=clock())
	,end(false)
	,gs(&gs)
	,encouraged(false)
{
	strncpy(str,s,MAXSTRSZ-1);
}

Text::~Text()
{
}

void Text::Reset(const char* s, hb::Pointu32 sp)
{
	currentPos=sp;
	initialPos=sp;
	controlPoint=hb::Pointu32(sp.x,ObjectsRectangles[e_rect_window].t);
	landingPoint=hb::Pointu32(ObjectsRectangles[e_rect_score].l,ObjectsRectangles[e_rect_score].b);

	t=0;
	tmNcrg=tm=clock();
	end=false;
	encouraged=false;

	strncpy(str,s,MAXSTRSZ-1);
}

void Text::Update()
{
	clock_t tempt=clock();

	if(tempt-tm >= Settings::TimeOfIndividualTextScoreUpdate)
	{
		tm=tempt;

		if(t>=1.f)
		{
			gs->Increment();
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

		currentPos.x=static_cast<uint32>(x);
		currentPos.y=static_cast<uint32>(y);
		t+=Text::stept;
	}
}

IndividualScore::IndividualScore(GlobalScore & gs):m_gs(gs)
{
	Reset();
}

IndividualScore::~IndividualScore()
{
	for(auto it=m_texts.begin(); it!=m_texts.end();)
	{
		it=m_texts.erase(it);
	}
}

void IndividualScore::Reset()
{
	m_texts.clear();
}


void IndividualScore::Update()
{
	for(auto it=m_texts.begin(); it!=m_texts.end();)
	{
		if(!it->end)
		{
			it->Update();
			++it;
		}
		else
		{
			it=m_texts.erase(it);
		}
	}
}
void IndividualScore::Add(hb::Pointu32 sp)
{
	sp=sp+hb::Pointu32(Square::e_Height>>2,Square::e_Height>>1);

	for(hb::list::iterator it=m_texts.begin();it!=m_texts.end(); ++it)
	{
		if(it->end)
		{
			it->Reset(IndividualScore::ms_score_str,sp);
			return;
		}
	}

	m_texts.push_back(Text(IndividualScore::ms_score_str,sp,m_gs));
}
void IndividualScore::Draw()
{
	glColor3f(.0f,.0f,.0f);

	for(hb::list::iterator it=m_texts.begin();it!=m_texts.end(); ++it)
	{
		if(!it->end && it->t!=0 /*to avoid drawing a static text*/)
		{
			hb::DrawText((*it).str,it->currentPos.x, it->currentPos.y);
		}
	}
}

////////////////

GlobalScore::GlobalScore():Sprite(& ObjectsRectangles[e_rect_score], e_tex_score)
{
	Reset();
}

GlobalScore::~GlobalScore()
{
	listOfTimesNcrgd.clear();
}


void GlobalScore::Update()
{
	ConfirmEncouragement confirmNcrg;

	if (auto encourg=dynamic_cast<Encouragement*>(ObjectsManager::GetInstance().GetGlobalObject(CLASSID_Encouragement)))
	{
		int i=0;

		for(auto rit=listOfTimesNcrgd.rbegin(), end=listOfTimesNcrgd.rend(); rit!=end; ++i,++rit)
		{
#define threshold_wow 4
#define threshold_good 2

			if(i== threshold_wow-1)
			{
				clock_t diff=listOfTimesNcrgd.rbegin()->time - rit->time;
				if( diff< 1400)
				{
					encourg->Display(e_ncrg_wow);
					listOfTimesNcrgd.clear();
					break;
				}
			}
			else if(i== threshold_good-1 && !rit->encouraged)
			{
				confirmNcrg.Add( &(*rit) );

				clock_t diff=listOfTimesNcrgd.rbegin()->time - rit->time;
				if( diff< 1000)
				{
					encourg->Display(e_ncrg_good);
					confirmNcrg.confirm=true;
					break;
				}
			}
		}
	}
}

void GlobalScore::Increment()
{
	listOfTimesNcrgd.push_back(TimeNcrgd());

	m_score_i += IndividualScore::ms_score_i;
	_itoa(m_score_i,m_score_str,10);
}

void GlobalScore::Draw()
{
	Sprite::Draw();


	glColor3f (1.0f, 1.0f, 0.0f);

	hb::DrawText(m_score_str,m_rect->l+30, m_rect->t-50);
}

void GlobalScore::Reset()
{
	m_score_str[0]='0';
	m_score_str[1]=0;
	m_score_i=0;
}
