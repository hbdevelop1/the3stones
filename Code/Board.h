#ifndef _BOARD_
#define _BOARD_


#include "common.h"
#include "fsm.h"
#include "rectangle.h"
#include "object.h"
#include <time.h>


#include <boost/smart_ptr/scoped_array.hpp>



class Tile;

//namespace hb{

struct Event
{
	hb::Pointu8 p;
	bool		notprocessed;
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
	hb::Rectangle	rect;

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
	PositionInBoard			m_positions[e_ColumnSize][e_RowSize+1];

	boost::scoped_array<Tile> m_tiles;

	const hb::Rectangle *	m_rect;
	Event					m_click;
	hb::Pointu8				m_selectedTilesPosition;

#ifdef _timeinsteadofframes_
	clock_t					m_time2WaitAfterSwap;
#else
	int						m_nbrOfFrames2WaitAfterSwap;
#endif

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

	const hb::Rectangle * GetRectangle() {return m_rect;}
	void Draw();
	void Update();
	PositionInBoard * GetFreePositionBelow(hb::Pointu8 l);
	void OnClick(unsigned int x, unsigned int y);
	void Reset();

	void test();

	friend class Tile;
};

//}//namespace hb

#endif //_BOARD_
