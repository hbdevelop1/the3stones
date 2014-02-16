
#include "game.h"
#include "common.h"
#include "objectsmanager.h"
#include "classids.h"
#include "board.h"
#include "timecounter.h"
#include "score.h"


#include "MemNew.h"



ImplementCreator(game)

game::game()
{

	SetFlag(e_FLAG_MASTER);

//	ObjectsManager::GetInstance().PushBack(this); supposed to be done in game_init
	ObjectsManager::GetInstance().RegisterGlobalObject(this,CLASSID_game);


	board.reset(new Board );
	score.reset( new Score );
	timer.reset( new TimeCounter);

	//ObjectsManager::GetInstance().PushBack(board,false);
	//ObjectsManager::GetInstance().PushBack(CLASSID_Score);
	//ObjectsManager::GetInstance().PushBack(score,false);
//	ObjectsManager::GetInstance().PushBack(timer,false);



	START_BEHAVIOR(game, 
		Behavior_intro
		//Behavior_countdown
		//Behavior_timeout
		);
}

game::~game()
{
	ObjectsManager::GetInstance().UnRegisterGlobalObject(this);



}

void game::WhenPushed()
{
	ObjectsManager::GetInstance().PushBack(board.get());
	ObjectsManager::GetInstance().PushBack(score.get());
	ObjectsManager::GetInstance().PushBack(timer.get());
}

void game::Update()
{
	/*
	board.Update();
	score.Update();
	timer.Update();
	*/

	(this->*m_currentbehavior)();

}

void game::Draw()
{
/*
	drawing depends on the behavior

	board.Draw();
	score.Draw();
	timer.Draw();
	*/
}

void game::Behavior_intro()
{
CONSTRUCT_BEHAVIOR_BEGIN
{
		timer->Reset();
		board->Reset();
		score->Reset();

	ObjectsManager::GetInstance().PushBack(CLASSID_Intro);
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

		ObjectsManager::GetInstance().PushBack(CLASSID_CountDown);
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
		ObjectsManager::GetInstance().PushBack(CLASSID_TimeOut);
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

void game::OnClick(uint32 x, uint32 y)
{
	if(m_currentbehavior == &game::Behavior_playing)
		board->OnClick(x,y);
/*
	if(m_currentbehavior == &game::Behavior_timeout)
		//dynamic_cast<TimeOut*>(
		ObjectsManager::GetInstance().GetGlobalObject(CLASSID_TimeOut)->OnClick(x,y);
		*/
}
