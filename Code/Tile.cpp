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



//const unsigned int Tile::SpeedOfSwapping=Settings::SpeedOfSwapping;   //rank 10
//const unsigned int Tile::NbrOfFramesBeforeDestruction=Settings::NbrOfFramesBeforeDestruction;

Tile::type Tile::current_t=e_type1;
Board * Tile::board=NULL;

Tile::type & operator++(Tile::type & a)
{
	a=static_cast<Tile::type>(a+1); 
	if (a>Tile::e_type5) 
		a=Tile::e_type1;
	return a;
}

Tile::Tile():pFreePositionToMoveTo(NULL),selected(false),visible(false),active(false)
	//,m_previousbehavior(NULL)
	,todestroy(false),toswap(false)
{
	Reset(e_type1);
}
Tile::Tile(type _t,hb::Pointu8 p):t(_t),loc(p),pFreePositionToMoveTo(NULL),selected(false),visible(false) //visible should be set explicitly to true to indicate the tile is correctly initialized.
	,active(false)
	//,m_previousbehavior(NULL)
	,todestroy(false),toswap(false)
{
	Reset(_t);
}

void Tile::Reset(type _t)
{
	selected=false;
	visible=true;
	active=true;
	todestroy=false;
	toswap=false;
	pFreePositionToMoveTo=NULL;

	SetType(_t);
	START_BEHAVIOR(Tile,Behavior_Resting);
}


void Tile::SetType(type _t)
{
	hbassert(e_type1<=_t && _t<=e_type5);
	t=_t;
}

void Tile::Set(PositionInBoard * p, type t)
{
	hbassert(p);
	pCurrentPosition=p;
	loc=pCurrentPosition->point;

	
	hb::Rectangle rb=
		//dynamic_cast<game*>(ObjectsManager::GetInstance().GetGlobalObject(CLASSID_game))->GetBoard().GetRectangle();
		Tile::board->GetRectangle();
	r=hb::Rectangle(rb.l+loc.x*Square::e_Width,		rb.b+loc.y*Square::e_Height,
					rb.l+(loc.x+1)*Square::e_Width, rb.b+(loc.y+1)*Square::e_Height);

	visible=true;
	active=true;
	SetType(t);
	//todo:Set SetType are virtual. it this necessary ?
}

Tile::~Tile() 
{
}



void Tile::Draw()
{
	glBegin(GL_POLYGON);
        glVertex2f (r.l, r.b);
        glVertex2f (r.r, r.b);
        glVertex2f (r.r, r.t);
        glVertex2f (r.l, r.t);
    glEnd();
}

void Tile::Update()
{
	if(!active)
		return;
	
	(this->*m_currentbehavior)();

}

bool Tile::SetSelected(bool s)
{
	selected=false; //this will unselect the tile if it is.
	//but selecting it will depend on its current behavior
	if(m_currentbehavior==&Tile::Behavior_Resting) //a tile can be selected only when in Behavior_Resting
	{
		selected=s;
		return true;
	}
	return false;
}

void Destroy(Tile* a, Tile* b, Tile* c)
{
	hbassert(a->todestroy==false && b->todestroy==false && c->todestroy==false);

	a->todestroy=true;
	b->todestroy=true;
	c->todestroy=true;

	dynamic_cast<Score*>(ObjectsManager::GetInstance().GetGlobalObject(CLASSID_Score))->Add(hb::Pointu32(b->r.l,b->r.b));
}

void Swap(Tile* a, Tile* b)
{
	a->toswap=true;
	a->pFreePositionToMoveTo=b->pCurrentPosition;
	a->loc=a->pFreePositionToMoveTo->point;

	b->toswap=true;
	b->pFreePositionToMoveTo=a->pCurrentPosition;
	b->loc=b->pFreePositionToMoveTo->point;






}

void Tile::Behavior_Resting()
{
	CONSTRUCT_BEHAVIOR_BEGIN
		toswap=false;
		todestroy=false;
	CONSTRUCT_BEHAVIOR_END
	UPDATE_BEHAVIOR_BEGIN
		
		if(todestroy)
		{
			todestroy=false;
			CHANGE_BEHAVIOR(Tile,Behavior_Destroying);
		}
		else if(toswap)
		{
			toswap=false;
			hbassert(pFreePositionToMoveTo!=pCurrentPosition);
			CHANGE_BEHAVIOR(Tile,Behavior_Swapping);
			//no code should run after calling CHANGE_BEHAVIOR
		}
		else
		{
			pFreePositionToMoveTo=Tile::board->GetFreePositionBelow(loc);
			if (pFreePositionToMoveTo)//check if next position is free. if yes move to it.
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
	if(pCurrentPosition)
		pCurrentPosition->tile = NULL;	//position is free. another tile can take it. 
										//freeing a position early in the moving out process lets 
										//a tile above start moving immediately. otherwise, it will 
										//start moving only when the first tile has arived to its final position.
	hbassert(pFreePositionToMoveTo);
	hbassert(loc.y > pFreePositionToMoveTo->point.y);

	pCurrentPosition = pFreePositionToMoveTo;
	pCurrentPosition->tile = this;

	paceoffall=Settings::SpeedOfFalling;
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
		if(--paceoffall>0)
			return;

		paceoffall=Settings::SpeedOfFalling;

		r.b--; r.t--;
		//r.b-=2; r.t-=2;
		if(r.b == pCurrentPosition->r.b)//todo:see 12
		{
			hbassert(r==pCurrentPosition->r);
			hbassert(loc.x==pCurrentPosition->point.x);

			loc.y=pCurrentPosition->point.y;

			pFreePositionToMoveTo=Tile::board->GetFreePositionBelow(loc);
			if (pFreePositionToMoveTo)
			{
				//stay in this behavior
				PrepareMoving();
			}
			else
			{
					//pFreePositionToMoveTo is set to NULL at the call to b.GetFreePositionBelow
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
	delta = pFreePositionToMoveTo->point - pCurrentPosition->point; //test this
	hbassert(delta.x==-1 || delta.x==1 || delta.x==0);
	hbassert(delta.y==-1 || delta.y==1 || delta.y==0);
	hbassert((delta.x && delta.y==0) || (delta.y && delta.x==0));
	paceofswap=Settings::SpeedOfSwapping;
}
CONSTRUCT_BEHAVIOR_END

UPDATE_BEHAVIOR_BEGIN
{
	//if(pFreePositionToMoveTo!=NULL)//when a tile is in place, pFreePositionToMoveTo <- NULL
	
	paceofswap--; //tile moves each other Settings::SpeedOfSwapping frames.

	if(paceofswap<=0)
	{
		paceofswap=Settings::SpeedOfSwapping;

		if(delta.x)
		{
			r.r=r.r+delta.x;
			r.l=r.l+delta.x;
		}
		else
		{
			r.b=r.b+delta.y;
			r.t=r.t+delta.y;
		}

		if(r == pFreePositionToMoveTo->r)
		{
			pFreePositionToMoveTo->tile=this;
			pCurrentPosition=pFreePositionToMoveTo;
			pFreePositionToMoveTo=NULL;

#ifdef _gettiming_
			printf("Tile has finished swapping (0x%08X) at %d\n",this,g_currentframe);
#endif //_gettiming_

			CHANGE_BEHAVIOR(Tile,Behavior_Resting); //there is no danger that a click happens. because the board does not receive events
		}
	}
}
UPDATE_BEHAVIOR_END

DESTRUCT_BEHAVIOR_BEGIN
{
	//m_previousbehavior=&Tile::Behavior_Swapping;
	delta = hb::Points8(0,0);
	paceofswap=0;
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
		if(pFreePositionToMoveTo!=NULL) //when a tile is in place, pFreePositionToMoveTo <- NULL
										//pFreePositionToMoveTo <- NOT NULL if Swap was called
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
		//visible=false;
		nbrOfFramesBeforeDestruction=Settings::NbrOfFramesBeforeDestruction;
		todestroy=false;
	CONSTRUCT_BEHAVIOR_END

	UPDATE_BEHAVIOR_BEGIN
	{
		if(nbrOfFramesBeforeDestruction>0)
			nbrOfFramesBeforeDestruction--;
		else
		{
			pCurrentPosition->tile=NULL; //position is free. can be taken by another tile
			pCurrentPosition=NULL;
			//visible=false; //not visible but active

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
		r = Tile::board->positions[loc.x][Board::e_RowSize].r;
		loc=Tile::board->positions[loc.x][Board::e_RowSize].point;
		hbassert(loc==hb::Pointu8(loc.x,Board::e_RowSize));
		SetType(++Tile::current_t);
	}
	CONSTRUCT_BEHAVIOR_END

	UPDATE_BEHAVIOR_BEGIN
	{
		pFreePositionToMoveTo=Tile::board->GetFreePositionBelow(loc);
		if (pFreePositionToMoveTo)
		{
			visible=true;
			CHANGE_BEHAVIOR(Tile,Behavior_Moving); //pCurrentPosition and pCurrentPosition->tile = this are done now. this prevents another tile from taking it.
		}

	}
	UPDATE_BEHAVIOR_END

	DESTRUCT_BEHAVIOR_BEGIN
	DESTRUCT_BEHAVIOR_END
}



bool Tile::CheckMatches()
{
	if(todestroy)
		return false;
	//no already to destroy tiles are to be involved in a match

	sint32 x=static_cast<sint32>(loc.x);
	sint32 y=static_cast<sint32>(loc.y);

	Board * b=Tile::board;

//	Tile::type t=b.positions[x][y].tile->t;

	if(y-1>=0 && b->positions[x][y-1].tile->t==t && b->positions[x][y-1].tile->todestroy==false)
	{
		if(y-2>=0 && b->positions[x][y-2].tile->t==t && b->positions[x][y-2].tile->todestroy==false)
		{
			Destroy(b->positions[x][y-2].tile, b->positions[x][y-1].tile, b->positions[x][y].tile);
			return true;
		}
		if(y+1<=Board::e_RowSize-1 && b->positions[x][y+1].tile->t==t && b->positions[x][y+1].tile->todestroy==false)
		{//2067
			Destroy(b->positions[x][y-1].tile, b->positions[x][y].tile, b->positions[x][y+1].tile);
			return true;
		}
	}

	if(y+1<=Board::e_RowSize-1 && b->positions[x][y+1].tile->t==t && b->positions[x][y+1].tile->todestroy==false) //todo:possibility to optimize out this test, by reusing the result in the previous test
	{

		if(y+2<=Board::e_RowSize-1 && b->positions[x][y+2].tile->t==t && b->positions[x][y+2].tile->todestroy==false)
		{
			Destroy(b->positions[x][y].tile, b->positions[x][y+1].tile, b->positions[x][y+2].tile);
			return true;
		}
	}

	if(x-1>=0 && b->positions[x-1][y].tile->t==t && b->positions[x-1][y].tile->todestroy==false)
	{
		if(x-2>=0 && b->positions[x-2][y].tile->t==t && b->positions[x-2][y].tile->todestroy==false)
		{
			Destroy(b->positions[x-2][y].tile, b->positions[x-1][y].tile, b->positions[x][y].tile);
			return true;
		}
		if(x+1<=Board::e_ColumnSize-1 && b->positions[x+1][y].tile->t==t && b->positions[x+1][y].tile->todestroy==false)
		{//2066
			Destroy(b->positions[x-1][y].tile, b->positions[x][y].tile, b->positions[x+1][y].tile);
			return true;
		}
	}

	if(x+1<=Board::e_ColumnSize-1 && b->positions[x+1][y].tile->t==t && b->positions[x+1][y].tile->todestroy==false)
	{

		if(x+2<=Board::e_RowSize-1 && b->positions[x+2][y].tile->t==t && b->positions[x+2][y].tile->todestroy==false)
		{
			Destroy(b->positions[x][y].tile, b->positions[x+1][y].tile, b->positions[x+2][y].tile);
			return true;
		}
	}
	
	return false;
}


TileColored::TileColored()
{
}

TileColored::TileColored(type _t,hb::Pointu8 p):Tile(_t,p)
{
	SetType(t);	
}

TileColored::~TileColored()
{
}

void TileColored::Draw()
{
	if(!visible || !active)
		return;

	if(selected)
		glColor3f (color.r-.2f, color.g-.2f, color.b-.2f);
	else
		glColor3f (color.r, color.g, color.b);

	Tile::Draw();
}

void TileColored::SetType(type _t)
{
	Tile::SetType(_t);

	if (t==e_type1)
	{
		color.r=1.f;
		color.g=1.f;
		color.b=0.f;
	}
	else if (t==e_type2)
	{
		color.r=0.f;
		color.g=0.f;
		color.b=1.f;
	}
	else if (t==e_type3)
	{
		color.r=0.f;
		color.g=1.f;
		color.b=0.f;
	}
	else if (t==e_type4)
	{
		color.r=1.f;
		color.g=0.f;
		color.b=0.f;
	}
	else if (t==e_type5)
	{
		color.r=0.f;
		color.g=1.f;
		color.b=1.f;
	}
	else
		hbassert(0);
}





TileTex::TileTex()
{
}

TileTex::TileTex(type _t,hb::Pointu8 p):Tile(_t,p)
{
	SetType(t);	
}

TileTex::~TileTex()
{
}

void TileTex::Draw()
{
	if(!visible || !active)
		return;


	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	if(selected)
	{
		glRotatef(180,0.f,0.f,1.f);
	}
	glMatrixMode(GL_MODELVIEW);

	glBindTexture(GL_TEXTURE_2D, m_texObj);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 

	glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex2f (r.l, r.b);
        glTexCoord2f(1, 0); glVertex2f (r.r, r.b);
        glTexCoord2f(1, 1); glVertex2f (r.r, r.t);
        glTexCoord2f(0, 1); glVertex2f (r.l, r.t);
    glEnd();
}

void TileTex::SetType(type _t)
{
	Tile::SetType(_t);

	m_texObj=TexturesManager::GetInstance().GetTextureObj(_t);

}

