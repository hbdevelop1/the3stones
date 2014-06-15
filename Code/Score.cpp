
#include "common.h"

#include "Score.h"
#include "board.h"
#include "ObjectsManager.h"
#include "classids.h"
#include "graphic/TexturesManager.h"
#include "ObjectsRectangles.h"
#include "Encouragement.h"

#include "xml/xml.h"
#include <string>
using namespace std;

//#define testing

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

Text::Text()
	:t(0)
	,tmNcrg(tm=clock())
	,end(false)
	,m_gs(NULL)
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
	,m_gs(&gs)
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

#ifdef _gettiming_
int Text_timing=8;
#endif //_gettiming_

void Text::Update()
{
	if(clock()-tm >= 50)
	{
#ifdef _gettiming_
		if(--Text_timing > 0)
			printf("Text::Update() (0x%08X) at %d\n",this,g_currentframe);
#endif //_gettiming_

		tm=clock();

		if(t>=1.f)
		{
			m_gs->Increment();
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
	/*
	hb::Vector vector(landingPoint-currentPos);
	hb::Points32 distance=vector.GetDistance();

	
	get distance from destination point;
	if(distance<10)
	{
		activate transparency computing;

	}
	*/
}


#elif _bezierinscore_==0
Text::Text(const char* s, hb::Pointu32 sp):initialPos(sp),life(MAXLIFE)
{
	strncpy(str,s,MAXSTRSZ-1);
}
#endif _bezierinscore_

IndividualScore::IndividualScore(GlobalScore & gs):m_gs(gs)
#ifdef _comparedifferentdrawing_
	,m_is2(gs)
#endif //_comparedifferentdrawing_
{
	//assert(m_gs);
	Reset();

}

IndividualScore::~IndividualScore()
{
//	m_texts.clear();
//	for(hb::deque::reverse_iterator it=m_texts.rbegin(), end=m_texts.rend();it!=end; )
		for(hb::deque::reverse_iterator rit=m_texts.rbegin();rit!=m_texts.rend(); )
	{
		rit=std::reverse_iterator<hb::deque::iterator>(m_texts.erase((rit+1).base()));
	}
	
/*
	for(hb::deque::iterator it=m_texts.begin();it!=m_texts.end();)
	{
		it=m_texts.erase(it);
	}
	*/
}

void IndividualScore::Reset()
{
#ifdef _comparedifferentdrawing_
	m_is2.Reset();
#endif

	m_texts.clear();


#ifdef testing
//	load xml data into individual score;

	hb::Pointu32 ps;
	m_texts.push_back(Text(IndividualScore::ms_score_str,ps,m_gs));
	m_texts.push_back(Text(IndividualScore::ms_score_str,ps,m_gs));
	m_texts.push_back(Text(IndividualScore::ms_score_str,ps,m_gs));
	m_texts.push_back(Text(IndividualScore::ms_score_str,ps,m_gs));
	m_texts.push_back(Text(IndividualScore::ms_score_str,ps,m_gs));

	for(hb::deque::reverse_iterator it=m_texts.rbegin();it!=m_texts.rend(); ++it)
	{
		printf("it->tmNcrg==%d\n",it->tmNcrg);
	}

#endif //testing
}

#if _encrg_version_==1	
struct ConfirmEncouragement
{
#define max_size 4 
	//const int max_size;
	Text * a[max_size];
	bool confirm;
	int currentsize;
	
	ConfirmEncouragement():confirm(false),currentsize(0)//,max_size(4)
	{
		a[0]=0;
		a[1]=0;
		a[2]=0;
		a[3]=0;
	}

	~ConfirmEncouragement() 
	{
		if(confirm)
		{
			for(int i=0; i<currentsize; ++i)
				a[i]->encouraged=true;
		}
	}

	void Add(Text *p)
	{
		if(currentsize<max_size)
		{
			a[currentsize++]=p;
		}
	}
};
#endif //_encrg_version_==1	
clock_t g_v;
bool g=false;

#if _bezierinscore_==1
void IndividualScore::Update()
{
#ifdef _comparedifferentdrawing_
	m_is2.Update();
#endif

#ifdef testing
	//play the list and print whether to encourage or not;


	auto encourg=dynamic_cast<Encouragement*>(ObjectsManager::GetInstance().GetGlobalObject(CLASSID_Encouragement));
	ConfirmEncouragement confirmNcrg;
	int i=0;

	for(hb::deque::reverse_iterator it=m_texts.rbegin();it!=m_texts.rend(); ++it,++i)
	{
		if(!it->end)
		{
			it->Update();
		}
		
		if(encourg)
		{
#define threshold 3

			if(i<=threshold)
			{
				confirmNcrg.Add( &(*it) );

				if(!it->encouraged)
					if(i==threshold)
					{
						printf("threshold hit\n");
						clock_t t=clock();
						if(g)
						{
							t=g_v;
						}
						
						printf("t==%d   it->tmNcrg==%d\n",t,it->tmNcrg);

						if(t-it->tmNcrg < 1500)
						{
							confirmNcrg.confirm=true;
							encourg->Display();
						}
					}
			}
		}
	}
#else

#if _encrg_version_==1
	auto encourg=dynamic_cast<Encouragement*>(ObjectsManager::GetInstance().GetGlobalObject(CLASSID_Encouragement));
	ConfirmEncouragement confirmNcrg;
	hb::deque::reverse_iterator it2;
#endif _encrg_version_==1
	int i=0;


	for(hb::deque::reverse_iterator rit=m_texts.rbegin(); rit!=m_texts.rend(); ++i)
	{
//		hb::deque::iterator it1=rit.base();		it2=std::reverse_iterator<hb::deque::iterator>(it1);

		if(!rit->end)
		{
			rit->Update();
		}
#if _encrg_version_==1	
		
		if(encourg)
		{
#define threshold 4

			if(i<=(threshold-1))
			{
				confirmNcrg.Add( &(*rit) );

				if(i==(threshold-1))
				{
					if(!rit->encouraged)
					{
						printf("threshold hit and not encouraged\n");
						clock_t t=clock();
						if(t-rit->tmNcrg < 1000)
						{
							printf("position = %d\n",i);
							confirmNcrg.confirm=true;
							encourg->Display();
						}
					}
				}
			}
		}
		
		if(rit->end)
		{
			//int r = m_texts.size();
			//printf("(%d) deleting it->tmNcrg=%d  corresponding to it.base()->tmNcrg=%d\n",r,it->tmNcrg,it.base()->tmNcrg);
			//hb::deque::iterator it1=;
			//r = m_texts.size();
			rit=std::reverse_iterator<hb::deque::iterator>(m_texts.erase((rit+1).base()));
			//printf("(%d) using it->tmNcrg=%d  corresponding to it1->tmNcrg=%d\n",r,it->tmNcrg,it1->tmNcrg);
		}
		else
#endif //#if _encrg_version_==1	
		{
			++rit;
		}
	}
#endif //testing
}
void IndividualScore::Add(hb::Pointu32 sp)
{
#ifdef _comparedifferentdrawing_ 
	m_is2.Add(sp);
#endif

#ifdef testing
	//move on to the next list; or wrap around;
#else

	sp=sp+hb::Pointu32(Square::e_Height>>2,Square::e_Height>>1);
#if _encrg_version_!=1	
	for(hb::deque::iterator it=m_texts.begin();it!=m_texts.end(); ++it)
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
#endif //#if _encrg_version_!=1	
	m_texts.push_back(Text(IndividualScore::ms_score_str,sp,m_gs));
	//printf("nbr of indiv. scores == %d\n",m_texts.size());

#endif //testing

}
void IndividualScore::Draw()
{

#ifdef _comparedifferentdrawing_ 
	m_is2.Draw();
#endif

#ifdef testing
	//do nothing;
#else

	glColor3f(.0f,.0f,.0f);

	for(hb::deque::iterator it=m_texts.begin();it!=m_texts.end(); ++it)
	{
		if(!it->end && it->t!=0 /*to avoid drawing a static text*/)
		{
			glRasterPos2f(it->currentPos.x, it->currentPos.y);
			char* p = (char*) (*it).str;
			while (*p != '\0') glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
		}
	}
#endif //testing
}

#elif _bezierinscore_==0
void IndividualScore::Update()
{
	for(deque<Text>::iterator it=m_texts.begin();it!=m_texts.end(); ++it)
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

	for(deque<Text>::iterator it=m_texts.begin();it!=m_texts.end(); ++it)
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
	m_texts.push_back(Text(IndividualScore::score_str,sp));

}

void IndividualScore::Draw()
{
	glColor3f(.0f,.0f,.0f);

	for(deque<Text>::iterator it=m_texts.begin();it!=m_texts.end(); ++it)
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

#if _encrg_version_==2
/*	get time, and store it;
	check the third one from the end;
	if  ! encrg and time diff is < 1000
		encourg;
		confirm; or remove;
	if(beyond threshold) remove;
	if(very old) remove;

	at GlobalScore::~GlobalScore
		free the list;
		*/
#endif //_encrg_version_==2

GlobalScore::GlobalScore():Sprite(& ObjectsRectangles2[e_rect_score], e_tex_score)
{
	Reset();
}

GlobalScore::~GlobalScore()
{
	listOfTimesNcrgd.clear();
}


void GlobalScore::Update()
{
#if _encrg_version_==2

	ConfirmEncouragement confirmNcrg;

	if (auto encourg=dynamic_cast<Encouragement*>(ObjectsManager::GetInstance().GetGlobalObject(CLASSID_Encouragement)))
	{
		int i=0;
	/*
algo:
the following figures reprent times.
020 100  110 : the last two times are < 11 and never encouraged -> good
020 100  110  112 : the last four times are > 16 -> no wow
					the last two times are < 11 but one was encouraged -> good
020 100  110  112  114 :the last four times are > 16 -> wow + destruction
						the last two times do not exist.
*/

		for(auto rit=listOfTimesNcrgd.rbegin(), end=listOfTimesNcrgd.rend(); rit!=end; ++i,++rit)
		{
#define threshold_wow 4
#define threshold_good 2

			if(i== threshold_wow-1)
			//if(std::distance(listOfTimesNcrgd.rbegin(),rit)==(threshold-1)) TODO
			{
				clock_t diff=listOfTimesNcrgd.rbegin()->time - rit->time;
//TODO				//if( diff< 1050) sometimes this condition is true. other times it is not !!! 
				//how come the frame rate is not constant ?
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
					//listOfTimesNcrgd.clear();
					break;
				}
			}
		}
	}

#endif //_encrg_version_==2
}

#ifdef _animateglobalscore_

void GlobalScore::Increment()
{
#if _encrg_version_==2
	listOfTimesNcrgd.push_back(TimeNcrgd());
#endif //_encrg_version_==2

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
	Sprite::Draw();


	glColor3f (1.0, 1.0, 0.0);
	glRasterPos2f(m_rect->lt.x+30, m_rect->lt.y-50);

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

///////////////////////

#ifdef _comparedifferentdrawing_

IndividualScore2::IndividualScore2(GlobalScore & gs):m_gs(gs)
{
	//assert(m_gs);
	Reset();


}

IndividualScore2::~IndividualScore2()
{
//	m_texts.clear();
//	for(hb::deque::reverse_iterator it=m_texts.rbegin(), end=m_texts.rend();it!=end; )
		for(hb::deque::reverse_iterator rit=m_texts.rbegin();rit!=m_texts.rend(); )
	{
		rit=std::reverse_iterator<hb::deque::iterator>(m_texts.erase((rit+1).base()));
	}
	
/*
	for(hb::deque::iterator it=m_texts.begin();it!=m_texts.end();)
	{
		it=m_texts.erase(it);
	}
	*/
}

void IndividualScore2::Reset()
{
	m_texts.clear();


#ifdef testing
//	load xml data into individual score;

	hb::Pointu32 ps;
	m_texts.push_back(Text(IndividualScore::ms_score_str,ps,m_gs));
	m_texts.push_back(Text(IndividualScore::ms_score_str,ps,m_gs));
	m_texts.push_back(Text(IndividualScore::ms_score_str,ps,m_gs));
	m_texts.push_back(Text(IndividualScore::ms_score_str,ps,m_gs));
	m_texts.push_back(Text(IndividualScore::ms_score_str,ps,m_gs));

	for(hb::deque::reverse_iterator it=m_texts.rbegin();it!=m_texts.rend(); ++it)
	{
		printf("it->tmNcrg==%d\n",it->tmNcrg);
	}

#endif //testing
}


void IndividualScore2::Update()
{

#ifdef testing
	//play the list and print whether to encourage or not;


	auto encourg=dynamic_cast<Encouragement*>(ObjectsManager::GetInstance().GetGlobalObject(CLASSID_Encouragement));
	ConfirmEncouragement confirmNcrg;
	int i=0;

	for(hb::deque::reverse_iterator it=m_texts.rbegin();it!=m_texts.rend(); ++it,++i)
	{
		if(!it->end)
		{
			it->Update();
		}
		
		if(encourg)
		{
#define threshold 3

			if(i<=threshold)
			{
				confirmNcrg.Add( &(*it) );

				if(!it->encouraged)
					if(i==threshold)
					{
						printf("threshold hit\n");
						clock_t t=clock();
						if(g)
						{
							t=g_v;
						}
						
						printf("t==%d   it->tmNcrg==%d\n",t,it->tmNcrg);

						if(t-it->tmNcrg < 1500)
						{
							confirmNcrg.confirm=true;
							encourg->Display();
						}
					}
			}
		}
	}
#else

	int i=0;


	for(hb::deque::reverse_iterator rit=m_texts.rbegin(); rit!=m_texts.rend(); ++i)
	{
//		hb::deque::iterator it1=rit.base();		it2=std::reverse_iterator<hb::deque::iterator>(it1);

		if(!rit->end)
		{
			rit->Update();
		}
		{
			++rit;
		}
	}
#endif //testing
}
void IndividualScore2::Add(hb::Pointu32 sp)
{
	sp=sp+hb::Pointu32((Square::e_Height>>2)+3,(Square::e_Height>>1)+3);

#if _encrg_version_!=1	
	for(hb::deque::iterator it=m_texts.begin();it!=m_texts.end(); ++it)
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
#endif //#if _encrg_version_!=1	
	m_texts.push_back(Text(IndividualScore::ms_score_str,sp,m_gs));

}
void IndividualScore2::Draw()
{


	glColor3f(.0f,.0f,1.0f);

	for(hb::deque::iterator it=m_texts.begin();it!=m_texts.end(); ++it)
	{
		if(!it->end /*&& it->t!=0 *//*to avoid drawing a static text*/)
		{
			glRasterPos2f(it->currentPos.x, it->currentPos.y);
			char* p = (char*) (*it).str;
			while (*p != '\0') glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
		}
	}

}

#endif //_comparedifferentdrawing_