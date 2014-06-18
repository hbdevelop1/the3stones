#ifndef _TILE_
#define _TILE_


#include "rectangle.h"
#include "fsm.h"

//namespace hb{

struct PositionInBoard;
class Board;
class CTargaImage;

class Tile
{
	hb::Rectangle	m_rect;
	unsigned int	m_texObj;
	static Board *	m_board;

public:
	enum type
	{
		e_type1,
		e_type2,
		e_type3,
		e_type4,
		e_type5,
		e_typeMax
	};
private:

	static type		m_currentType;	//type for tiles going back into the board
	type			m_type;	//type for color/type
	hb::Pointu8		m_loc; //position in the board. loc.x can be in the range [0, e_ColumnSize-1] with the step of 1, and loc.y can be in the range [0, e_RowSize-1] with the step of 1
	PositionInBoard *m_currentPosition;
	PositionInBoard *m_freePositionToMoveTo;
	hb::Points8		m_delta;
	signed int		m_nbrOfFramesBeforeDestruction;
	bool			m_visible;
	bool			m_active;
	bool			m_selected;//to indicate if the tile is selected
	bool			m_toDestroy;
	bool			m_toSwap;
	int				m_paceOfSwap;
	int				m_paceOfFall;


	//static const unsigned int SpeedOfSwapping;
	//static const unsigned int NbrOfFramesBeforeDestruction;

	State 			m_state;
	void (Tile::*m_currentbehavior)(void);

//	void (Tile::*m_previousbehavior)(void);


private:

	void Behavior_Resting();
	void Behavior_Moving();
	void Behavior_Destroying();
	void Behavior_Swapping();
	void Behavior_WaitForMatchDecision();
	void Behavior_WaitingToGoIntoBoard();

	//helpers
	void PrepareMoving();

public:
	Tile();
	Tile(type _t, hb::Pointu8);

	virtual ~Tile();
	void Draw();
	void SetType(type t);

	void Reset(type _t);
	void Update();
	void Set(PositionInBoard * p, type t);
	bool SetSelected(bool s);

	bool CheckMatches();

	friend void Swap(Tile*, Tile*);
	friend void Destroy(Tile*, Tile*, Tile*);
	friend class Board;
};
//}




#endif _TILE_