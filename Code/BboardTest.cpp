
#include "common.h"
#include "board.h"
#include "tile.h"
#include <assert.h>

#include "Mem/MemNew.h"

//#define _testingmove_ 1  //for a first test of movement
//#define _testingmove_ 2 //for a move developed test of movement


//#define _testingclick_ 1
//#define _testingclick_ 2



void Board::test()
{

#if (_testingclick_==2)


m_currentbehavior = &Board::Behavior_Stable;
m_state = e_Ticking;
/*
Board::Board():r(5.0f,  5.0f,
				5.0f+Board::e_ColumnSize*Square::e_Width,
				5.0f+Board::e_RowSize*Square::e_Height)
				*/
OnClick(-1,-1);
OnClick(0,0);
OnClick(4,4);
OnClick(4,10);

OnClick(5,5);
OnClick(5,10);
OnClick(5.0f+Board::e_ColumnSize*Square::e_Width,0);
OnClick(5.0f+Board::e_ColumnSize*Square::e_Width,5);
OnClick(5.0f,5.0f+Board::e_RowSize*Square::e_Height);
OnClick(5.0f+Board::e_ColumnSize*Square::e_Width,5.0f+Board::e_RowSize*Square::e_Height);

OnClick(5,5); assert(click.p==hb::Pointu8(0,0));
OnClick(5+Square::e_Width-1,5+Square::e_Height-1); assert(click.p==hb::Pointu8(0,0));
OnClick(5+Square::e_Width  ,5+Square::e_Height); assert(click.p==hb::Pointu8(1,1));

OnClick(5,5+Square::e_Height-1);assert(click.p==hb::Pointu8(0,0));//0,0
OnClick(5,5+Square::e_Height);assert(click.p==hb::Pointu8(0,1));//0,1

OnClick(5+Square::e_Width-1,4);
OnClick(5+Square::e_Width-1,5);assert(click.p==hb::Pointu8(0,0));//0,0
OnClick(5+Square::e_Width  ,5);assert(click.p==hb::Pointu8(1,0));//1,0

OnClick(5+Square::e_Width-1,5+Square::e_Height);assert(click.p==hb::Pointu8(0,1));//0,1
OnClick(5+Square::e_Width  ,5+Square::e_Height-1);assert(click.p==hb::Pointu8(1,0));//1,0

#endif //(_testingclick_==2)

#if (_testingclick_==1)
m_currentbehavior = &Board::Behavior_Stable;
m_state = e_Ending;
OnClick(1,1);

m_currentbehavior = &Board::Behavior_Stable;
m_state = e_Ticking;
OnClick(1,1);

m_currentbehavior = &Board::Behavior_InTransition;
m_state = e_Ending;
OnClick(1,1);

m_currentbehavior = &Board::Behavior_InTransition;
m_state = e_Starting;
OnClick(1,1);
#endif //(_testingclick_==1)

#if _testingmove_==2
	uint i,j;

	for(uint i=0; i<e_ColumnSize; ++i)
	{
		for(uint j=0; j<e_RowSize; ++j)
		{
			positions[i][j].point=hb::Pointu8(i,j);
			positions[i][j].r=hb::Rectangle(r.l+i*Square::e_Width,		r.b+j*Square::e_Height,
											r.l+(i+1)*Square::e_Width,	r.b+(j+1)*Square::e_Height);
			positions[i][j].tile=NULL;
		}
	}
//		for(uint i=0; i<e_RowSize; ++i)
//		for(uint j=0; j<e_ColumnSize; ++j)
	{
		i=e_ColumnSize-1;
		j=e_RowSize-1;
		Tile::type t=Tile::e_type1;
		for(i=0; i<e_RowSize; ++i)
		{
			positions[i][j].tile=&tiles[i*e_RowSize+j];
			t=static_cast<Tile::type>(t+1); if (t>Tile::e_type5) t=Tile::e_type1;
			tiles[i*e_RowSize+j].Set(&positions[i][j],t);
		}
		i=3;j=3;
		{
			positions[i][j].tile=&tiles[i*e_RowSize+j];
			t=static_cast<Tile::type>(t); if (t>Tile::e_type5) t=Tile::e_type1;
			tiles[i*e_RowSize+j].Set(&positions[i][j],t);
		}
	}

#endif //#if (_testingmove_=2)

}
