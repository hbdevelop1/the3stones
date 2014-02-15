#ifndef _SCORE_
#define _SCORE_


#include "common.h"
#include "rectangle.h"
#include "object.h"

#include <queue>
using namespace std;

class Score;

#define MAXSTRSZ 20

struct Text
{
	char str[MAXSTRSZ ];
	sint32	life;
	//hb::Pointu8	screenPos;
	hb::Pointu32	screenPos;

	Text(const char*, hb::Pointu32 sp);

	//watch out:no cc for Text
};

class IndividualScore
{
	deque<Text> scores; //watch out:no cc for Text
public:
	static const char	score_str[5];
	static const int	score_i;

public:
	IndividualScore();
	~IndividualScore();

	void Update();
	void Draw();
	void Add(hb::Pointu32 screenPos);
	void Reset();

};

struct GlobalScore
{
	const hb::Rectangle	& r;
	unsigned int m_texObj;

	uint32			score_i;
	char			score_str[10];

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