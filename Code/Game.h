

#include "fsm.h"
#include "object.h"
#include "common.h"


#include <boost/smart_ptr/scoped_ptr.hpp>

class Board;
class TimeCounter;
class Score;
class  Encouragement;


class game : public Object
{
	
	boost::scoped_ptr<Board>			board;
	boost::scoped_ptr<TimeCounter>		timer;
	boost::scoped_ptr<Score>			score;
	boost::scoped_ptr<Encouragement>	encouragement;

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