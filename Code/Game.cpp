
#include "game.h"
#include "common.h"
#include "objectsmanager.h"
#include "classids.h"
#include "board.h"
#include "timecounter.h"
#include "score.h"
#include "encouragement.h"
#include "graphic\TexturesManager.h"
#include <new>


ImplementCreator(Game)

Game::Game()
{

	SetFlag(e_FLAG_MASTER);

	ObjectsManager::GetInstance().RegisterGlobalObject(this,CLASSID_Game);

	m_board.reset(new Board );
	m_score.reset( new Score );
	m_timer.reset( new TimeCounter);

	m_encouragement.reset( new Encouragement("data/goodNwow.xml") );

	ObjectsManager::GetInstance().PushBack(m_board.get(),false);
	ObjectsManager::GetInstance().PushBack(m_score.get(),false);
	ObjectsManager::GetInstance().PushBack(m_timer.get(),false);
	ObjectsManager::GetInstance().PushBack(m_encouragement.get(),false);


	START_BEHAVIOR(Game, Behavior_intro);
}

Game::~Game()
{
	ObjectsManager::GetInstance().UnRegisterGlobalObject(this);
}

/*
void Game::WhenPushed()
{
	ObjectsManager::GetInstance().PushBack(m_board.get());
	ObjectsManager::GetInstance().PushBack(m_score.get());
	ObjectsManager::GetInstance().PushBack(m_timer.get());
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
			m_timer->Reset();
			m_board->Reset();
			m_score->Reset();

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
		m_timer->Reset();
		m_board->Reset();
		m_score->Reset();

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
		m_timer->Start();

	}
	CONSTRUCT_BEHAVIOR_END

	UPDATE_BEHAVIOR_BEGIN
	{
		if(m_timer->m_timeout)
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
		m_board->OnClick(x,y);
}
