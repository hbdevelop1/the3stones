
#include "common.h"
#include "board.h"
#include "tile.h"
#include <assert.h>

#include "objectsmanager.h"
#include "objectsrectangles.h"

#ifdef _use_smart_ptr_
#include "smartptrs/scoped_ptr.hpp"
#endif 


#ifdef _use_my_mem_tracker_
#define new new(__FILE__,__LINE__)
#endif



PositionInBoard::PositionInBoard():tile(NULL)
{
	;
}

PositionInBoard::~PositionInBoard()
{
}

bool PositionInBoard::operator==(PositionInBoard  b)
{
	return r==b.r;
}


//#define _testingclick_ 2

Board::Board():r(ObjectsRectangles[e_rect_board]),
				SelectedTilesPosition(hb::Pointu8::Invalid)
{

	Tile::board=this;
	click.notprocessed=false;

#ifdef _use_smart_ptr_
	tiles.reset(new TileTex [e_RowSize*e_ColumnSize]);
#else
	tiles=new TileTex [e_RowSize*e_ColumnSize];
#endif
	
	
	for(uint8 i=0; i<e_ColumnSize; ++i)
	{
		for(uint8 j=0; j<e_RowSize+1; ++j)
		{
			positions[i][j].point=hb::Pointu8(i,j);
			positions[i][j].r=hb::Rectangle(r.l+i*Square::e_Width,		r.b+j*Square::e_Height,
											r.l+(i+1)*Square::e_Width,	r.b+(j+1)*Square::e_Height);
		}
	}

	Reset();


#if (_testingclick_==2)
	{
		test();
	}
#endif //#if (_testingmove_=2)

}

void Board::Reset()
{
	SelectedTilesPosition=hb::Pointu8::Invalid;

	click.notprocessed=false;

	Tile::type t=Tile::e_type1;
	
	for(uint8 i=0; i<e_ColumnSize; ++i)
	{
		for(uint8 j=0; j<e_RowSize; ++j)
		{
			positions[i][j].tile=&tiles[i*e_RowSize+j];
			t=static_cast<Tile::type>(t+1); if (t>Tile::e_type5) t=Tile::e_type1;
			tiles[i*e_RowSize+j].Set(&positions[i][j],t);
		}
	}

	//the last row on top of the board where destroyed tiles are located waiting for their return into the board
	//used in Tile::Behavior_WaitingToGoIntoBoard
	for(uint8 i=0; i<e_ColumnSize; ++i)
	{
		uint8 j=e_RowSize;

		positions[i][j].tile=NULL;
	}
	

	{//set map
		Tile::type g[][e_RowSize]={
			{ Tile::e_type4, Tile::e_type2, Tile::e_type5, Tile::e_type3, Tile::e_type1, Tile::e_type4, Tile::e_type2, Tile::e_type5},
			{ Tile::e_type4, Tile::e_type1, Tile::e_type4, Tile::e_type2, Tile::e_type5, Tile::e_type3, Tile::e_type1, Tile::e_type5},
			{ Tile::e_type2, Tile::e_type4, Tile::e_type3, Tile::e_type1, Tile::e_type3, Tile::e_type2, Tile::e_type5, Tile::e_type3},
			{ Tile::e_type3, Tile::e_type4, Tile::e_type2, Tile::e_type5, Tile::e_type3, Tile::e_type1, Tile::e_type4, Tile::e_type2},
			{ Tile::e_type5, Tile::e_type3, Tile::e_type5, Tile::e_type3, Tile::e_type5, Tile::e_type5, Tile::e_type3, Tile::e_type1},
			{ Tile::e_type4, Tile::e_type2, Tile::e_type5, Tile::e_type3, Tile::e_type1, Tile::e_type4, Tile::e_type2, Tile::e_type1},
			{ Tile::e_type3, Tile::e_type3, Tile::e_type4, Tile::e_type2, Tile::e_type5, Tile::e_type3, Tile::e_type1, Tile::e_type4},
			{ Tile::e_type2, Tile::e_type5, Tile::e_type3, Tile::e_type1, Tile::e_type4, Tile::e_type2, Tile::e_type1, Tile::e_type3}
		};

		for(uint8 i=0; i<e_ColumnSize; ++i)
		{
			for(uint8 j=0; j<e_RowSize; ++j)
			{
				tiles[i*e_RowSize+j].Reset(g[i][j]);
			}
		}
	}


	START_BEHAVIOR(Board, Behavior_Stable);
}

Board::~Board()
{
#ifdef _use_smart_ptr_
#elif _use_my_mem_tracker_
	deletea<TileTex>(tiles);
#else
	delete [] tiles;
#endif 
}
void Board::Draw()
{
    glColor3f (0.0, 0.0, 0.0);

    glBegin(GL_POLYGON);
        glVertex2f (r.l, r.b);
        glVertex2f (r.r, r.b);
        glVertex2f (r.r, r.t);
        glVertex2f (r.l, r.t);
    glEnd();
#if (_testingmove_==1)
			tiles[0].Draw();
			tiles[2].Draw();
			return;
#endif //_testingmove_==1

	glEnable(GL_TEXTURE_2D);

	//tiles can be considered independent objects and be draw on their own and not be tide to Board::Draw 
	for(int i=0; i<e_ColumnSize; ++i)
	{
		for(int j=0; j<e_RowSize; ++j)
		{
			tiles[i*e_RowSize+j].Draw();
		}
	}

	glDisable(GL_TEXTURE_2D);

}

void Board::Update()
{

	(this->*m_currentbehavior)();


#if (_testingmove_==1)
			tiles[0].Tick();
			tiles[2].Tick();
			return;
#endif //_testingmove_==1
	//tiles can be considered independent objects and be ticked on their own and not be tide to Board::Update
	for(int i=0; i<e_ColumnSize; ++i)
	{
		for(int j=0; j<e_RowSize; ++j)
		{
			tiles[i*e_RowSize+j].Update();
		}
	}
}

PositionInBoard * Board::GetFreePositionBelow(hb::Pointu8 l)
{
	//'l' could be row 3 and column 6 -> check row 2 and column 6
	if (l.y>0)
		if (positions[l.x][l.y-1].tile == NULL)
			return &positions[l.x][l.y-1];
	return NULL;
}


void Board::OnClick(uint32 x, uint32 y)
{
	hb::Pointu8 p(hb::Pointu8::Invalid);

	if(m_currentbehavior == &Board::Behavior_Stable && m_state != e_Ending)
	{
		if(r.l<=x && x<=r.r && r.b<=y && y<=r.t)
		{
			//determine if it's a tile the 
			click.notprocessed = true;
			click.p.x=(x-r.l)/Square::e_Width;
			click.p.y=(y-r.b)/Square::e_Height;
		}
	}
}


void Board::Behavior_Stable()
{

CONSTRUCT_BEHAVIOR_BEGIN
{
	SelectedTilesPosition=hb::Pointu8::Invalid;
}
CONSTRUCT_BEHAVIOR_END

UPDATE_BEHAVIOR_BEGIN
{
	if(click.notprocessed)
	{
		click.notprocessed=false;

		if(SelectedTilesPosition==hb::Pointu8::Invalid)//the first click goes into SelectedTilesPosition
		{
			if(positions[click.p.x][click.p.y].tile->SetSelected(true)) //a tile can be selected only when in Behavior_Resting
				SelectedTilesPosition=click.p;
		}
		else if(NextToEachOther(SelectedTilesPosition,click.p))
		{
			positions[SelectedTilesPosition.x][SelectedTilesPosition.y].tile->SetSelected(false);
			CHANGE_BEHAVIOR(Board,Behavior_Swapping);
		}
		else//if the tiles are not next to each others. 
		//note:the board can not receive a third click as it will be in Behavior_Swapping right after the second one.
		{
			positions[SelectedTilesPosition.x][SelectedTilesPosition.y].tile->SetSelected(false);
			SelectedTilesPosition=hb::Pointu8::Invalid;
		}
	}
}
UPDATE_BEHAVIOR_END

DESTRUCT_BEHAVIOR_BEGIN
{
}
DESTRUCT_BEHAVIOR_END

}


void Board::Behavior_Swapping()
{

CONSTRUCT_BEHAVIOR_BEGIN
{
	Swap(positions[click.p.x][click.p.y].tile,positions[SelectedTilesPosition.x][SelectedTilesPosition.y].tile);
	nbrofframes2waitafterswap=50;
}
CONSTRUCT_BEHAVIOR_END

UPDATE_BEHAVIOR_BEGIN
{
	//wait for the swapping to finish;
	if(positions[click.p.x][click.p.y].tile->pFreePositionToMoveTo==NULL && 
		positions[SelectedTilesPosition.x][SelectedTilesPosition.y].tile->pFreePositionToMoveTo==NULL)
	{
		if(nbrofframes2waitafterswap>0)
			--nbrofframes2waitafterswap;
		else
		{
			//check for matches from each tile's side, horizontally and vertically
			if(positions[click.p.x][click.p.y].tile->CheckMatches() || 
				positions[SelectedTilesPosition.x][SelectedTilesPosition.y].tile->CheckMatches()
				)
			{
				CHANGE_BEHAVIOR(Board,Behavior_InTransition);//the board is closed to interaction
			}
			else
				CHANGE_BEHAVIOR(Board,Behavior_SwappingBack);
		}
	}




}
UPDATE_BEHAVIOR_END

DESTRUCT_BEHAVIOR_BEGIN
{
}
DESTRUCT_BEHAVIOR_END

}


void Board::Behavior_SwappingBack()
{

CONSTRUCT_BEHAVIOR_BEGIN
{
	Swap(positions[click.p.x][click.p.y].tile,positions[SelectedTilesPosition.x][SelectedTilesPosition.y].tile);
	nbrofframes2waitafterswap=0;
}
CONSTRUCT_BEHAVIOR_END

UPDATE_BEHAVIOR_BEGIN
{
	//wait for the swap-back to finish;
	if(positions[click.p.x][click.p.y].tile->pFreePositionToMoveTo==NULL && 
		positions[SelectedTilesPosition.x][SelectedTilesPosition.y].tile->pFreePositionToMoveTo==NULL)
	{
		if(nbrofframes2waitafterswap>0)
			--nbrofframes2waitafterswap;
		else
		{
			SelectedTilesPosition=hb::Pointu8::Invalid;
			CHANGE_BEHAVIOR(Board,Behavior_Stable);
		}
	}

}
UPDATE_BEHAVIOR_END

DESTRUCT_BEHAVIOR_BEGIN
{
}
DESTRUCT_BEHAVIOR_END

}


void Board::Behavior_InTransition()
{

CONSTRUCT_BEHAVIOR_BEGIN
{
}
CONSTRUCT_BEHAVIOR_END

UPDATE_BEHAVIOR_BEGIN
{
	for(uint8 i=0; i<e_ColumnSize; ++i)
	{
		for(uint8 j=0; j<e_RowSize; ++j)
		{
			if(positions[i][j].tile==NULL || positions[i][j].tile->m_currentbehavior != &Tile::Behavior_Resting)
				return; // no need to go any further. there is a tile not in Behavior_Resting
		}
	}
	bool someMatchesFound=false;
	for(uint8 i=0; i<e_ColumnSize; ++i)
	{
		for(uint8 j=0; j<e_RowSize; ++j)
		{
			someMatchesFound |= positions[i][j].tile->CheckMatches();
		}
	}
	if(someMatchesFound==false)
	{
		CHANGE_BEHAVIOR(Board,Behavior_Stable);
	}
}
UPDATE_BEHAVIOR_END

DESTRUCT_BEHAVIOR_BEGIN
{
}
DESTRUCT_BEHAVIOR_END

}

bool Board::NextToEachOther(hb::Pointu8 p1, hb::Pointu8 p2)
{
	return (p1.x==p2.x && (p1.y==p2.y-1 || p1.y==p2.y+1)) || (p1.y==p2.y && (p1.x==p2.x-1 || p1.x==p2.x+1));
}


//}//namespace hb
