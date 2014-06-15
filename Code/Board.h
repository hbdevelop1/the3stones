#ifndef _BOARD_
#define _BOARD_


#include "common.h"
#include "fsm.h"
#include "rectangle.h"
#include "object.h"


#include <boost/smart_ptr/scoped_array.hpp>

#define _bezier_ 0

#if _bezier_ > 0
#include "time.h"
#endif _bezier_ > 0


class Tile;
#ifndef _use_sprite_
struct TileColored;
struct TileTex;
#endif //_use_sprite_
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
	hb::Pointu8		point;
	Tile			*tile;
	hb::Rectangle rect;

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

	boost::scoped_array<Tile> tiles;

#if _bezier_ == 1
	hb::Pointu32	m_bzP[4];
	hb::Pointu32	m_txtpos;
	float			m_t; //goes from 0 to 1
	float		m_stept; //=0.1 => will take 8 postions for the text to travel to its resting position
	clock_t		m_tm;
#endif _bezier_ == 1

#if _bezier_ == 2
	hb::Pointu32	m_bzP[3];
	hb::Pointu32	m_txtpos;
	float			m_t; //goes from 0 to 1
	float		m_stept;
	clock_t		m_tm;
#endif _bezier_ == 1

	const hb::stRectangle2 * m_rect;
	Event		click;
	hb::Pointu8	SelectedTilesPosition;

	int nbrofframes2waitafterswap;
	//static const int nbrOfFrames2WaitAfterSwap;

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

	const hb::Rectangle GetRectangle() {return hb::Rectangle(m_rect->lb.x, m_rect->lb.y, m_rect->rt.x, m_rect->rt.y);}
	void Draw();
	void Update();
	PositionInBoard * GetFreePositionBelow(hb::Pointu8 l);
	void OnClick(int x, int y);
	void Reset();

	void test();

	friend class Tile;
};

//}//namespace hb

#endif //_BOARD_
