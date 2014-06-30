

#include "fsm.h"
#include "object.h"
#include "common.h"


#include <boost/smart_ptr/scoped_ptr.hpp>

class Board;
class TimeCounter;
class Score;
class Encouragement;

class Game : public Object
{
	
	boost::scoped_ptr<Board>			board;
	boost::scoped_ptr<TimeCounter>		timer;
	boost::scoped_ptr<Score>			score;
	boost::scoped_ptr<Encouragement>	encouragement;


private:
	State 	m_state;
	void (Game::*m_currentbehavior)(void);

	void Behavior_intro();
	void Behavior_countdown();
	void Behavior_playing();
	void Behavior_timeout();
	
public:
	Game();
	~Game();

	void Draw();
	void Update();
//	void WhenPushed();

	void OnClick(unsigned int x, unsigned int y);



};