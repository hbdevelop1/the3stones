#ifndef _TILE_
#define _TILE_


#include "rectangle.h"
#include "fsm.h"

//namespace hb{

struct PositionInBoard;
class Board;
class CTargaImage;

struct Tile
{
	hb::Rectangle r;
	static Board * board;

	enum type
	{
		e_type1,
		e_type2,
		e_type3,
		e_type4,
		e_type5,
		e_typeMax
	};

	static type	current_t;	//type for tiles going back into the board
	type	t;	//type for color/type
	hb::Pointu8	loc; //position in the board. loc.x can be in the range [0, e_ColumnSize-1] with the step of 1, and loc.y can be in the range [0, e_RowSize-1] with the step of 1
	PositionInBoard *pCurrentPosition;
	PositionInBoard *pFreePositionToMoveTo;
	hb::Points8	delta;
	sint32	iTimeBeforeDestruction;
	bool	visible;
	bool	active;
	bool	selected;//to indicate if the tile is selected
	bool	todestroy;
	bool	toswap;
	int		paceofswap;
	static const unsigned int speedofswap;

	State 	m_state;
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
//	void Set(type _t, Pointi p);

	virtual ~Tile();
	virtual void Draw()=0;
	virtual void SetType(type t);

	void Reset(type _t);
	void Update();
	void Set(PositionInBoard * p, type t);
	bool SetSelected(bool s);

	bool CheckMatches();
	//static void SetBoard(Board *);


	friend void Swap(Tile*, Tile*);
	friend void Destroy(Tile*, Tile*, Tile*);
	friend class Board;
};

struct TileColored : public Tile
{
	Color	color;
public:
	TileColored ();
	TileColored (type _t,hb::Pointu8 p);

	~TileColored ();
	void Draw();
	void SetType(type t);
	//void Set(PositionInBoard * p, type t);
};

struct TileTex : public Tile
{
	unsigned int m_texObj;

public:
	TileTex ();
	TileTex (type _t,hb::Pointu8 p);

	~TileTex ();
	void Draw();
	void SetType(type t);
	//void Set(PositionInBoard * p, type t);
};

//}




#endif _TILE_