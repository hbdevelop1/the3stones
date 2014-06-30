
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


ImplementCreator(Game)

Game::Game()
{

	SetFlag(e_FLAG_MASTER);

	ObjectsManager::GetInstance().RegisterGlobalObject(this,CLASSID_Game);

	board.reset(new Board );
	score.reset( new Score );
	timer.reset( new TimeCounter);

	encouragement.reset( new Encouragement("data/goodNwow.xml") );

	ObjectsManager::GetInstance().PushBack(board.get(),false);
	ObjectsManager::GetInstance().PushBack(score.get(),false);
	ObjectsManager::GetInstance().PushBack(timer.get(),false);
	ObjectsManager::GetInstance().PushBack(encouragement.get(),false);


	START_BEHAVIOR(Game, Behavior_intro);
}

Game::~Game()
{
	ObjectsManager::GetInstance().UnRegisterGlobalObject(this);
}

/*
void Game::WhenPushed()
{
	ObjectsManager::GetInstance().PushBack(board.get());
	ObjectsManager::GetInstance().PushBack(score.get());
	ObjectsManager::GetInstance().PushBack(timer.get());
}
*/
void Game::Update()
{
	(this->*m_currentbehavior)();
}

void Game::Draw()
{
}

void Game::Behavior_intro()
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
		CHANGE_BEHAVIOR(Game,Behavior_countdown);
	}
	UPDATE_BEHAVIOR_END

	DESTRUCT_BEHAVIOR_BEGIN
	{
	}
	DESTRUCT_BEHAVIOR_END

}
void Game::Behavior_countdown()
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
		CHANGE_BEHAVIOR(Game,Behavior_playing);
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
void Game::Behavior_playing()
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
			CHANGE_BEHAVIOR(Game,Behavior_timeout);
	}
	UPDATE_BEHAVIOR_END

	DESTRUCT_BEHAVIOR_BEGIN
	{
	}
	DESTRUCT_BEHAVIOR_END

}
void Game::Behavior_timeout()
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
		CHANGE_BEHAVIOR(Game,Behavior_countdown);
	}
	UPDATE_BEHAVIOR_END

	DESTRUCT_BEHAVIOR_BEGIN
	{
	}
	DESTRUCT_BEHAVIOR_END
}

void Game::OnClick(unsigned int x, unsigned int y)
{
	if(m_currentbehavior == &Game::Behavior_playing)
		board->OnClick(x,y);
}
