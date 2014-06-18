#ifndef _SCORE_
#define _SCORE_


#include "common.h"
#include "rectangle.h"
#include "object.h"
#include "Mem/allocator.h"
#include "graphic\sprite.h"

#include <queue>
#include <list>
using namespace std;

class Score;
struct GlobalScore;



#define MAXSTRSZ 20

#include "time.h"

struct Text
{
	char			str[MAXSTRSZ ];
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
	GlobalScore *	gs;

	Text();
	~Text();
	Text(const char*, hb::Pointu32 sp,GlobalScore & gs);
	void Update();
	void Reset(const char* s, hb::Pointu32 sp);

	//watch out:no cc for Text
};

namespace hb
{
typedef std::deque<Text,hb::allocator<Text> > deque;
}

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

struct GlobalScore : public Sprite
{
	uint32			m_score_i;
	char			m_score_str[10];

	enum
	{
		e_Height=64,//64*4,
		e_Width=128
	};

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