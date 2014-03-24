#ifndef _SCORE_
#define _SCORE_


#include "common.h"
#include "rectangle.h"
#include "object.h"

#include <queue>
using namespace std;

class Score;
struct GlobalScore;


#define _bezierinscore_ 1



#define MAXSTRSZ 20

#if _bezierinscore_==1

#include "time.h"

struct Text
{
	char str[MAXSTRSZ ];
	bool			end;
	hb::Pointu32	initialPos;			//A factor in the function
	hb::Pointu32	controlPoint;		//B factor in the function
	hb::Pointu32	landingPoint;		//C factor in the function

	hb::Pointu32	currentPos;
	float			t; //goes from 0 to 1
	static float	stept;
	clock_t			tm;
	GlobalScore &	m_gs;

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
class IndividualScore
{
	deque<Text>		m_scores; //watch out:no cc for Text
	GlobalScore &	m_gs;

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