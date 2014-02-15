

#include "fsm.h"
#include "object.h"
#include "common.h"

#ifdef _use_smart_ptr_
//#include <memory> 
//#include "smartptrs/autoptr.h"

#include "smartptrs/scoped_ptr.hpp"
#endif 

class Board;
class TimeCounter;
class Score;



class game : public Object
{
#ifdef _use_smart_ptr_
	
	boost::scoped_ptr<Board>		board;
	boost::scoped_ptr<TimeCounter>	timer;
	boost::scoped_ptr<Score>		score;
	/*
	hb::auto_ptr<Board>		board;
	hb::auto_ptr<TimeCounter>	timer;
	hb::auto_ptr<Score>		score;
	*/
#else
	Board	*board;
	TimeCounter *timer;
	Score	*score;
#endif //use_smart_ptr

private:
	game(const game &);
	game & operator=(const game&);

private:
	State 	m_state;
	void (game::*m_currentbehavior)(void);

	void Behavior_intro();
	void Behavior_countdown();
	void Behavior_playing();
	void Behavior_timeout();
	
public:
	game();
	~game();

	void Draw();
	void Update();
	void WhenPushed();

	//Board * GetBoard() {return board;}
	void OnClick(uint32 x, uint32 y);



};