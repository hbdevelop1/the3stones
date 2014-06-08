#ifndef _SCORE_
#define _SCORE_


#include "common.h"
#include "rectangle.h"
#include "object.h"
#include "Mem/allocator.h"

#include <queue>
#include <list>
using namespace std;

class Score;
struct GlobalScore;


#define _bezierinscore_ 1
#define _encrg_version_ 2
//#define _comparedifferentdrawing_
/*
after match found, it takes some time before the +100 appears and starts traveling. why ?
to answer this, i am making the time line in the doc
to troubleshoot this I am using _comparedifferentdrawing_
finally it was _gettiming_ that gave me the hint. which was to reduce NbrOfFramesToWaitToCheckMatchesAfterSwap.
*/



#define MAXSTRSZ 20

#if _bezierinscore_==1

#include "time.h"

struct Text
{
	char str[MAXSTRSZ ];
	bool			end;
	bool			encouraged;
	hb::Pointu32	initialPos;			//A factor in the function
	hb::Pointu32	controlPoint;		//B factor in the function
	hb::Pointu32	landingPoint;		//C factor in the function

	hb::Pointu32	currentPos;
	float			t; //goes from 0 to 1
	static float	stept;
	clock_t			tm;
	clock_t			tmNcrg;
	GlobalScore *	m_gs;

	Text();
	~Text();
	Text(const char*, hb::Pointu32 sp,GlobalScore & gs);
	void Update();
	void Reset(const char* s, hb::Pointu32 sp);

	//watch out:no cc for Text
};
#else 
struct Text
{
	char str[MAXSTRSZ ];
	sint32	life;
	hb::Pointu32	currentPos;

	Text(const char*, hb::Pointu32 sp);

	//watch out:no cc for Text
};
#endif

namespace hb
{
typedef std::deque<Text,hb::allocator<Text> > deque;
}

class IndividualScore2
{
	hb::deque		m_texts; //watch out:no cc for Text

	GlobalScore &	m_gs;

public:
	static const char	ms_score_str[5];
	static const int	ms_score_i;

public:
	IndividualScore2(GlobalScore &);
	~IndividualScore2();

	void Update();
	void Draw();
	void Add(hb::Pointu32 initialPos);
	void Reset();

};
class IndividualScore
{
	hb::deque		m_texts; //watch out:no cc for Text
	GlobalScore &	m_gs;

#ifdef _comparedifferentdrawing_ 
	IndividualScore2		m_is2;
#endif

public:
	static const char	ms_score_str[5];
	static const int	ms_score_i;

public:
	IndividualScore(GlobalScore & gs);
	~IndividualScore();

	void Update();
	void Draw();
	void Add(hb::Pointu32 initialPos);
	void Reset();

};

struct GlobalScore
{
	const hb::Rectangle	& m_r;
	unsigned int m_texObj;

	uint32			m_score_i;
	char			m_score_str[10];

	enum
	{
		e_Height=64,//64*4,
		e_Width=128
	};

#if _encrg_version_==2
	struct TimeNcrgd
	{
		clock_t	time;
		bool	encouraged;

		TimeNcrgd():encouraged(false),time(clock())
		{
		}
	};

	std::list<TimeNcrgd,hb::allocator<TimeNcrgd> > listOfTimesNcrgd;
	
	struct ConfirmEncouragement
	{
	#define maxsizece 4 
		//const int max_size;
		TimeNcrgd * a[maxsizece];
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

		void Add(TimeNcrgd *p)
		{
			if(currentsize<maxsizece)
			{
				a[currentsize++]=p;
			}
		}
		
	};
	
#endif //_encrg_version_==2
public:
	GlobalScore();
	~GlobalScore();

	void Update();
	void Draw();
	void Add();
	void Reset();
	void Increment();

	friend class Score;
};

class Score : public Object
{
	GlobalScore		m_gs;
	IndividualScore m_is;

	static uint32	highestscore_i;

private:
	Score(const Score &);
	Score & operator=(const Score &);
public:
	Score();
	~Score();

	void Update();
	void Draw();
	void Add(hb::Pointu32);
	void Reset();
	void WhenDeactivated();
	unsigned int GetScore();


	bool UpdateHighestScore();
	unsigned int GetHighestScore();

	
};


#endif _SCORE_