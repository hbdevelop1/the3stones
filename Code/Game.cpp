
#include "game.h"
#include "common.h"
#include "objectsmanager.h"
#include "classids.h"
#include "board.h"
#include "timecounter.h"
#include "score.h"
#include "Encouragement.h"
#include "graphic\TexturesManager.h"
#include <new>


ImplementCreator(game)

game::game()
{

	SetFlag(e_FLAG_MASTER);

	ObjectsManager::GetInstance().RegisterGlobalObject(this,CLASSID_game);

	board.reset(new Board );
	score.reset( new Score );
	timer.reset( new TimeCounter);

	encouragement.reset( new Encouragement("data/goodNwow.xml") );

	ObjectsManager::GetInstance().PushBack(board.get(),false);
	ObjectsManager::GetInstance().PushBack(score.get(),false);
	ObjectsManager::GetInstance().PushBack(timer.get(),false);
	ObjectsManager::GetInstance().PushBack(encouragement.get(),false);


	START_BEHAVIOR(game, Behavior_intro);
}

game::~game()
{
	ObjectsManager::GetInstance().UnRegisterGlobalObject(this);
}

/*
void game::WhenPushed()
{
	ObjectsManager::GetInstance().PushBack(board.get());
	ObjectsManager::GetInstance().PushBack(score.get());
	ObjectsManager::GetInstance().PushBack(timer.get());
}
*/
void game::Update()
{
	(this->*m_currentbehavior)();
}

void game::Draw()
{
}

void game::Behavior_intro()
{
	CONSTRUCT_BEHAVIOR_BEGIN
	{
			timer->Reset();
			board->Reset();
			score->Reset();

		ObjectsManager::GetInstance().PushBack(CLASSID_Intro,false);
	}
	CONSTRUCT_BEHAVIOR_END

	UPDATE_BEHAVIOR_BEGIN
	{
		CHANGE_BEHAVIOR(game,Behavior_countdown);
	}
	UPDATE_BEHAVIOR_END

	DESTRUCT_BEHAVIOR_BEGIN
	{
	}
	DESTRUCT_BEHAVIOR_END

}
void game::Behavior_countdown()
{
	CONSTRUCT_BEHAVIOR_BEGIN
	{
		timer->Reset();
		board->Reset();
		score->Reset();

		ObjectsManager::GetInstance().PushBack(CLASSID_CountDown,false);
	}
	CONSTRUCT_BEHAVIOR_END

	UPDATE_BEHAVIOR_BEGIN
	{
		CHANGE_BEHAVIOR(game,Behavior_playing);
	}
	UPDATE_BEHAVIOR_END

	DESTRUCT_BEHAVIOR_BEGIN
	{
	}
	DESTRUCT_BEHAVIOR_END
		/*
	show countdown;
	when done,
	Behavior_playing;
	*/
}
void game::Behavior_playing()
{
/*
	when timeout;
		Behavior_timeout;
		*/
	CONSTRUCT_BEHAVIOR_BEGIN
	{
		timer->Start();

	}
	CONSTRUCT_BEHAVIOR_END

	UPDATE_BEHAVIOR_BEGIN
	{
		if(timer->m_timeout)
			CHANGE_BEHAVIOR(game,Behavior_timeout);
	}
	UPDATE_BEHAVIOR_END

	DESTRUCT_BEHAVIOR_BEGIN
	{
	}
	DESTRUCT_BEHAVIOR_END

}
void game::Behavior_timeout()
{
	/*
	show button to restart;
	go to Behavior_countdown;
	*/
	CONSTRUCT_BEHAVIOR_BEGIN
	{
		ObjectsManager::GetInstance().PushBack(CLASSID_TimeOut,false);
	}
	CONSTRUCT_BEHAVIOR_END

	UPDATE_BEHAVIOR_BEGIN
	{
		CHANGE_BEHAVIOR(game,Behavior_countdown);
	}
	UPDATE_BEHAVIOR_END

	DESTRUCT_BEHAVIOR_BEGIN
	{
	}
	DESTRUCT_BEHAVIOR_END
}

void game::OnClick(unsigned int x, unsigned int y)
{
	if(m_currentbehavior == &game::Behavior_playing)
		board->OnClick(x,y);
}
