#include "common.h"

#include "tile.h"
#include "board.h"
#include <assert.h>

#include "Score.h"

#include "ObjectsManager.h"
#include "classids.h"
#include "graphic/TexturesManager.h"

#include "settings.h"

#include "Mem/MemNew.h"


Tile::type Tile::m_currentType=e_type1;
Board * Tile::m_board=NULL;
int	Tile::ms_paceOfDisplacement=Square::e_Width>>4; //I consider Square::e_Width == Square::e_Width


Tile::type & operator++(Tile::type & a)
{
	a=static_cast<Tile::type>(a+1); 
	if (a>Tile::e_type5) 
		a=Tile::e_type1;
	return a;
}

Tile::Tile():m_freePositionToMoveTo(NULL),m_selected(false),m_visible(false),m_active(false)
	//,m_previousbehavior(NULL)
	,m_toDestroy(false),m_toSwap(false)
{
	Reset(e_type1);
}
Tile::Tile(type _t,hb::Pointu8 p):m_type(_t),m_loc(p),m_freePositionToMoveTo(NULL),m_selected(false),m_visible(false) //m_visible should be set explicitly to true to indicate the tile is correctly initialized.
	,m_active(false)
	//,m_previousbehavior(NULL)
	,m_toDestroy(false),m_toSwap(false)
{
	Reset(_t);
}

void Tile::Reset(type _t)
{
	m_selected=false;
	m_visible=true;
	m_active=true;
	m_toDestroy=false;
	m_toSwap=false;
	m_freePositionToMoveTo=NULL;

	SetType(_t);
	START_BEHAVIOR(Tile,Behavior_Resting);
}


void Tile::SetType(type _t)
{
	assert(e_type1<=_t && _t<=e_type5);
	m_type=_t;
	m_texObj=TexturesManager::GetInstance().GetTextureObj(_t);
}

void Tile::Set(PositionInBoard * p, type t)
{
	assert(p);
	m_currentPosition=p;
	m_loc=m_currentPosition->point;

	
	const hb::Rectangle *rb=
		//dynamic_cast<game*>(ObjectsManager::GetInstance().GetGlobalObject(CLASSID_game))->GetBoard().GetRectangle();
		Tile::m_board->GetRectangle();
	m_rect=hb::Rectangle(rb->l+m_loc.x*Square::e_Width,		rb->b+m_loc.y*Square::e_Height,
					rb->l+(m_loc.x+1)*Square::e_Width, rb->b+(m_loc.y+1)*Square::e_Height);

	m_visible=true;
	m_active=true;
	SetType(t);
	//todo:Set SetType are virtual. it this necessary ?
}

Tile::~Tile() 
{
}



void Tile::Draw()
{
	if(!m_visible || !m_active)
		return;


	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	if(m_selected)
	{
		glRotatef(180,0.f,0.f,1.f);
	}
	glMatrixMode(GL_MODELVIEW);

	glBindTexture(GL_TEXTURE_2D, m_texObj);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 

	glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex2f (m_rect.l, m_rect.b);
        glTexCoord2f(1, 0); glVertex2f (m_rect.r, m_rect.b);
        glTexCoord2f(1, 1); glVertex2f (m_rect.r, m_rect.t);
        glTexCoord2f(0, 1); glVertex2f (m_rect.l, m_rect.t);
    glEnd();
}


void Tile::Update()
{
	if(!m_active)
		return;
	
	(this->*m_currentbehavior)();

}

bool Tile::SetSelected(bool s)
{
	m_selected=false; //this will unselect the tile if it is.
	//but selecting it will depend on its current behavior
	if(m_currentbehavior==&Tile::Behavior_Resting) //a tile can be m_selected only when in Behavior_Resting
	{
		m_selected=s;
		return true;
	}
	return false;
}

void Destroy(Tile* a, Tile* b, Tile* c)
{
	assert(a->m_toDestroy==false && b->m_toDestroy==false && c->m_toDestroy==false);

	a->m_toDestroy=true;
	b->m_toDestroy=true;
	c->m_toDestroy=true;

	dynamic_cast<Score*>(ObjectsManager::GetInstance().GetGlobalObject(CLASSID_Score))->Add(hb::Pointu32(b->m_rect.l,b->m_rect.b));
}

void Swap(Tile* a, Tile* b)
{
	a->m_toSwap=true;
	a->m_freePositionToMoveTo=b->m_currentPosition;
	a->m_loc=a->m_freePositionToMoveTo->point;

	b->m_toSwap=true;
	b->m_freePositionToMoveTo=a->m_currentPosition;
	b->m_loc=b->m_freePositionToMoveTo->point;

}

void Tile::Behavior_Resting()
{
	CONSTRUCT_BEHAVIOR_BEGIN
		m_toSwap=false;
		m_toDestroy=false;
	CONSTRUCT_BEHAVIOR_END
	UPDATE_BEHAVIOR_BEGIN
		
		if(m_toDestroy)
		{
			m_toDestroy=false;
			CHANGE_BEHAVIOR(Tile,Behavior_Destroying);
		}
		else if(m_toSwap)
		{
			m_toSwap=false;
			assert(m_freePositionToMoveTo!=m_currentPosition);
			CHANGE_BEHAVIOR(Tile,Behavior_Swapping);
			//no code should run after calling CHANGE_BEHAVIOR
		}
		else
		{
			m_freePositionToMoveTo=Tile::m_board->GetFreePositionBelow(m_loc);
			if (m_freePositionToMoveTo)//check if next position is free. if yes move to it.
			{
				CHANGE_BEHAVIOR(Tile,Behavior_Moving);
			}
		}
	UPDATE_BEHAVIOR_END

	DESTRUCT_BEHAVIOR_BEGIN
		//m_previousbehavior=NULL;
	DESTRUCT_BEHAVIOR_END

}

void Tile::PrepareMoving()
{
	if(m_currentPosition)
		m_currentPosition->tile = NULL;	//position is free. another tile can take it. 
										//freeing a position early in the moving out process lets 
										//a tile above start moving immediately. otherwise, it will 
										//start moving only when the first tile has arived to its final position.
	assert(m_freePositionToMoveTo);
	assert(m_loc.y > m_freePositionToMoveTo->point.y);

	m_currentPosition = m_freePositionToMoveTo;
	m_currentPosition->tile = this;
#ifdef _timeinsteadofframes_
	//m_timePaceOfDisplacement=Settings::TimeSpeedOfFalling;
#else
	m_paceOfFall=Settings::SpeedOfFalling;
#endif
}

void Tile::Behavior_Moving()
{
	CONSTRUCT_BEHAVIOR_BEGIN
	{
		PrepareMoving();
	}
	CONSTRUCT_BEHAVIOR_END

	UPDATE_BEHAVIOR_BEGIN
	{
#ifdef _timeinsteadofframes_
/*		clock_t tempt=clock();
		if( tempt-m_timePaceOfDisplacement<Settings::TimeSpeedOfFalling)
			return;
			
		m_timePaceOfDisplacement=tempt;*/
		m_rect.b-=Tile::ms_paceOfDisplacement; m_rect.t-=Tile::ms_paceOfDisplacement;
		if(m_rect.b == m_currentPosition->rect.b)//todo:see 12
		{
#else
		if(--m_paceOfFall>0)
			return;

		m_paceOfFall=Settings::SpeedOfFalling;
		m_rect.b--; m_rect.t--;
		//m_rect.b-=2; m_rect.t-=2;
		if(m_rect.b == m_currentPosition->rect.b)//todo:see 12
		{
#endif
			assert(m_rect==m_currentPosition->rect);
			assert(m_loc.x==m_currentPosition->point.x);

			m_loc.y=m_currentPosition->point.y;

			m_freePositionToMoveTo=Tile::m_board->GetFreePositionBelow(m_loc);
			if (m_freePositionToMoveTo)
			{
				//stay in this behavior
				PrepareMoving();
			}
			else
			{
					//m_freePositionToMoveTo is set to NULL at the call to b.GetFreePositionBelow
					CHANGE_BEHAVIOR(Tile,Behavior_Resting);
			}
		}


	}
	UPDATE_BEHAVIOR_END

	DESTRUCT_BEHAVIOR_BEGIN
	DESTRUCT_BEHAVIOR_END

}

void Tile::Behavior_Swapping() //when a tile is in this behavior, board is not receiving events(Board::Behavior_Swapping)
{

CONSTRUCT_BEHAVIOR_BEGIN
{
	m_delta = m_freePositionToMoveTo->point - m_currentPosition->point; //test this
	assert(m_delta.x==-1 || m_delta.x==1 || m_delta.x==0);
	assert(m_delta.y==-1 || m_delta.y==1 || m_delta.y==0);
	assert((m_delta.x && m_delta.y==0) || (m_delta.y && m_delta.x==0));
#ifdef _timeinsteadofframes_
	//m_timePaceOfDisplacement=clock();
	m_delta.x = m_delta.x * Tile::ms_paceOfDisplacement;
	m_delta.y = m_delta.y * Tile::ms_paceOfDisplacement;
#else
	m_paceOfSwap=Settings::SpeedOfSwapping;
#endif
}
CONSTRUCT_BEHAVIOR_END

UPDATE_BEHAVIOR_BEGIN
{
	//if(m_freePositionToMoveTo!=NULL)//when a tile is in place, m_freePositionToMoveTo <- NULL
	
#ifdef _timeinsteadofframes_
/*	clock_t tempt =clock();
	if(tempt-m_timePaceOfDisplacement > Settings::TimeSpeedOfSwapping)
	{
		m_timePaceOfDisplacement=tempt;*/
	{
		if(m_delta.x)
		{
			m_rect.r+=m_delta.x;
			m_rect.l+=m_delta.x;
		}
		else
		{
			m_rect.b+=m_delta.y;
			m_rect.t+=m_delta.y;
		}

#else
	m_paceOfSwap--; //tile moves each other Settings::SpeedOfSwapping frames.

	if(m_paceOfSwap<=0)
	{
		m_paceOfSwap=Settings::SpeedOfSwapping;

		if(m_delta.x)
		{
			m_rect.r=m_rect.r+m_delta.x;
			m_rect.l=m_rect.l+m_delta.x;
		}
		else
		{
			m_rect.b=m_rect.b+m_delta.y;
			m_rect.t=m_rect.t+m_delta.y;
		}
#endif

		if(m_rect == m_freePositionToMoveTo->rect)
		{
			m_freePositionToMoveTo->tile=this;
			m_currentPosition=m_freePositionToMoveTo;
			m_freePositionToMoveTo=NULL;

			CHANGE_BEHAVIOR(Tile,Behavior_Resting); //there is no danger that a click happens. because the board does not receive events
		}
	}
}
UPDATE_BEHAVIOR_END

DESTRUCT_BEHAVIOR_BEGIN
{
	//m_previousbehavior=&Tile::Behavior_Swapping;
	m_delta = hb::Points8(0,0);
#ifndef _timeinsteadofframes_
	m_paceOfSwap=0;
#endif
}
DESTRUCT_BEHAVIOR_END

}

void Tile::Behavior_WaitForMatchDecision()
{
	CONSTRUCT_BEHAVIOR_BEGIN
	{
	}
	CONSTRUCT_BEHAVIOR_END

	UPDATE_BEHAVIOR_BEGIN
	{
		if(m_freePositionToMoveTo!=NULL) //when a tile is in place, m_freePositionToMoveTo <- NULL
										//m_freePositionToMoveTo <- NOT NULL if Swap was called
		{
			CHANGE_BEHAVIOR(Tile,Behavior_Swapping);
		}

	}
	UPDATE_BEHAVIOR_END

	DESTRUCT_BEHAVIOR_BEGIN
	{
	}
	DESTRUCT_BEHAVIOR_END
}

void Tile::Behavior_Destroying()
{
	CONSTRUCT_BEHAVIOR_BEGIN
		//m_visible=false;
#ifdef _timeinsteadofframes_
		m_time2WaitBeforeDestruction=clock();
#else
		m_nbrOfFramesBeforeDestruction=Settings::NbrOfFramesBeforeDestruction;
#endif
		m_toDestroy=false;
	CONSTRUCT_BEHAVIOR_END

	UPDATE_BEHAVIOR_BEGIN
	{
#ifdef _timeinsteadofframes_
		clock_t tempt=clock();
		if(tempt-m_time2WaitBeforeDestruction >= Settings::TimeToWaitBeforeDestruction)
		{
			m_time2WaitBeforeDestruction=tempt;
#else

		if(m_nbrOfFramesBeforeDestruction>0)
			m_nbrOfFramesBeforeDestruction--;
		else
		{

#endif
			m_currentPosition->tile=NULL; //position is free. can be taken by another tile
			m_currentPosition=NULL;
			//m_visible=false; //not m_visible but m_active

			CHANGE_BEHAVIOR(Tile,Behavior_WaitingToGoIntoBoard);
		}
	}
	UPDATE_BEHAVIOR_END

	DESTRUCT_BEHAVIOR_BEGIN
	DESTRUCT_BEHAVIOR_END
}

void Tile::Behavior_WaitingToGoIntoBoard()
{
	CONSTRUCT_BEHAVIOR_BEGIN
	{
		//all disappeared tiles in a column have the same rectangle, waiting to get into the board
		m_rect = Tile::m_board->m_positions[m_loc.x][Board::e_RowSize].rect;
		m_loc=Tile::m_board->m_positions[m_loc.x][Board::e_RowSize].point;
		assert(m_loc==hb::Pointu8(m_loc.x,Board::e_RowSize));
		SetType(++Tile::m_currentType);
	}
	CONSTRUCT_BEHAVIOR_END

	UPDATE_BEHAVIOR_BEGIN
	{
		m_freePositionToMoveTo=Tile::m_board->GetFreePositionBelow(m_loc);
		if (m_freePositionToMoveTo)
		{
			m_visible=true;
			CHANGE_BEHAVIOR(Tile,Behavior_Moving); //m_currentPosition and m_currentPosition->tile = this are done now. this prevents another tile from taking it.
		}

	}
	UPDATE_BEHAVIOR_END

	DESTRUCT_BEHAVIOR_BEGIN
	DESTRUCT_BEHAVIOR_END
}



bool Tile::CheckMatches()
{
	if(m_toDestroy)
		return false;
	//no already to destroy tiles are to be involved in a match

	sint32 x=static_cast<sint32>(m_loc.x);
	sint32 y=static_cast<sint32>(m_loc.y);

	Board * b=Tile::m_board;

//	Tile::type t=b.positions[x][y].tile->t;

	if(y-1>=0 && b->m_positions[x][y-1].tile->m_type==m_type && b->m_positions[x][y-1].tile->m_toDestroy==false)
	{
		if(y-2>=0 && b->m_positions[x][y-2].tile->m_type==m_type && b->m_positions[x][y-2].tile->m_toDestroy==false)
		{
			Destroy(b->m_positions[x][y-2].tile, b->m_positions[x][y-1].tile, b->m_positions[x][y].tile);
			return true;
		}
		if(y+1<=Board::e_RowSize-1 && b->m_positions[x][y+1].tile->m_type==m_type && b->m_positions[x][y+1].tile->m_toDestroy==false)
		{//2067
			Destroy(b->m_positions[x][y-1].tile, b->m_positions[x][y].tile, b->m_positions[x][y+1].tile);
			return true;
		}
	}

	if(y+1<=Board::e_RowSize-1 && b->m_positions[x][y+1].tile->m_type==m_type && b->m_positions[x][y+1].tile->m_toDestroy==false) //todo:possibility to optimize out this test, by reusing the result in the previous test
	{

		if(y+2<=Board::e_RowSize-1 && b->m_positions[x][y+2].tile->m_type==m_type && b->m_positions[x][y+2].tile->m_toDestroy==false)
		{
			Destroy(b->m_positions[x][y].tile, b->m_positions[x][y+1].tile, b->m_positions[x][y+2].tile);
			return true;
		}
	}

	if(x-1>=0 && b->m_positions[x-1][y].tile->m_type==m_type && b->m_positions[x-1][y].tile->m_toDestroy==false)
	{
		if(x-2>=0 && b->m_positions[x-2][y].tile->m_type==m_type && b->m_positions[x-2][y].tile->m_toDestroy==false)
		{
			Destroy(b->m_positions[x-2][y].tile, b->m_positions[x-1][y].tile, b->m_positions[x][y].tile);
			return true;
		}
		if(x+1<=Board::e_ColumnSize-1 && b->m_positions[x+1][y].tile->m_type==m_type && b->m_positions[x+1][y].tile->m_toDestroy==false)
		{//2066
			Destroy(b->m_positions[x-1][y].tile, b->m_positions[x][y].tile, b->m_positions[x+1][y].tile);
			return true;
		}
	}

	if(x+1<=Board::e_ColumnSize-1 && b->m_positions[x+1][y].tile->m_type==m_type && b->m_positions[x+1][y].tile->m_toDestroy==false)
	{

		if(x+2<=Board::e_RowSize-1 && b->m_positions[x+2][y].tile->m_type==m_type && b->m_positions[x+2][y].tile->m_toDestroy==false)
		{
			Destroy(b->m_positions[x][y].tile, b->m_positions[x+1][y].tile, b->m_positions[x+2][y].tile);
			return true;
		}
	}
	
	return false;
}
