#ifndef _BOARD_
#define _BOARD_


#include "common.h"
#include "fsm.h"
#include "rectangle.h"
#include "object.h"
test
#ifdef _use_smart_ptr_
#include "smartptrs/scoped_array.hpp"
#endif 

struct Tile;
struct TileColored;
struct TileTex;

//namespace hb{

struct Event
{
	hb::Pointu8 p;
	bool notprocessed;
};

namespace Square
{
	enum
	{
		e_Height=64,
		e_Width=64
	};
}

struct PositionInBoard
{
	hb::Pointu8	point;
	Tile		*tile;
	hb::Rectangle r;

public:
	PositionInBoard();
	~PositionInBoard();
	bool operator==(PositionInBoard );
};


class Board : public Object
{
public:
	enum
	{
		e_RowSize=8,
		e_ColumnSize=8
	};
private:
	//std::vector<std::vector<Square> > 
	//SquareColored squares[e_RowSize][e_ColumnSize];
	PositionInBoard positions[e_ColumnSize][e_RowSize+1];
	//TileColored 
#ifdef _use_smart_ptr_
	boost::scoped_array<TileTex> tiles;
#else
	TileTex * tiles;
#endif
	const hb::Rectangle & r;
	Event		click;
	hb::Pointu8	SelectedTilesPosition;

	int nbrofframes2waitafterswap;

private:
	Board(const Board &);
	Board & operator=(const Board&);

private:
	State 	m_state;
	void (Board::*m_currentbehavior)(void);

	void Behavior_Stable();
	void Behavior_InTransition();
	void Behavior_Swapping();
	void Behavior_SwappingBack();
	

	bool TexInit();
	void TexUninit();

	//helpers
	bool NextToEachOther(hb::Pointu8, hb::Pointu8);
	bool CheckMatchFor(Tile *p);

public:
	Board();
	~Board();

	hb::Rectangle GetRectangle() {return r;}
	void Draw();
	void Update();
	PositionInBoard * GetFreePositionBelow(hb::Pointu8 l);
	void OnClick(uint32 x, uint32 y);
	void Reset();

	void test();

	friend struct Tile;
};

//}//namespace hb

#endif //_BOARD_
