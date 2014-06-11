
#ifndef _OBJECTSRECTANGLES_
#define _OBJECTSRECTANGLES_


#include "rectangle.h"
#include "board.h"
#include "Score.h"
#include "TimeCounter.h"
#include "timeout.h"
#include "countdown.h"
#include "intro.h"

enum
{
	e_rect_window,
	e_rect_board,
	e_rect_score,
	e_rect_timecounter,
	e_rect_countdown,
	e_rect_timeout,
	e_rect_timeout_playagain,
	e_rect_timeout_quitgame,
	e_rect_Intro,
	e_rect_Intro_startbutton,
#ifdef _testingthenewspriteobjectclass_
	e_rect_timecounter2,
#endif //_testingthenewspriteobjectclass_

	e_rect_nbrofrectangles
};

//extern hb::Rectangle windowRectangle;

const hb::Rectangle ObjectsRectangles[]=
{

	//windowRectangle
	hb::Rectangle(0.0, 0.0, 
					Board::e_ColumnSize*Square::e_Width+140, Board::e_RowSize*Square::e_Height+10),
//board
	hb::Rectangle(ObjectsRectangles[e_rect_window].r-Board::e_ColumnSize*Square::e_Width-5,
				ObjectsRectangles[e_rect_window].t-Board::e_RowSize*Square::e_Height-5,
				ObjectsRectangles[e_rect_window].r-5,
				ObjectsRectangles[e_rect_window].t-5),
//e_rect_score,
	hb::Rectangle(ObjectsRectangles[e_rect_window].l+5,ObjectsRectangles[e_rect_window].t-GlobalScore::e_Height-5,
				ObjectsRectangles[e_rect_window].l+GlobalScore::e_Width+5,ObjectsRectangles[e_rect_window].t-5),
//e_rect_timecounter,
	hb::Rectangle(ObjectsRectangles[e_rect_score].l, ObjectsRectangles[e_rect_score].b-5-TimeCounter::e_Height,
				ObjectsRectangles[e_rect_score].l+TimeCounter::e_Width, ObjectsRectangles[e_rect_score].b-5),
//countdown
	hb::Rectangle(ObjectsRectangles[e_rect_board].l+90, 
			ObjectsRectangles[e_rect_board].b+(ObjectsRectangles[e_rect_board].t-ObjectsRectangles[e_rect_board].b)/2-CountDown::e_Height/2,
				  ObjectsRectangles[e_rect_board].r-90, 
			ObjectsRectangles[e_rect_board].b+(ObjectsRectangles[e_rect_board].t-ObjectsRectangles[e_rect_board].b)/2+CountDown::e_Height/2),

//e_rect_timeout
	hb::Rectangle(ObjectsRectangles[e_rect_board].l+90, 
			ObjectsRectangles[e_rect_board].b+(ObjectsRectangles[e_rect_board].t-ObjectsRectangles[e_rect_board].b)/2-TimeOut::e_Height/2,
				  ObjectsRectangles[e_rect_board].r-90, 
			ObjectsRectangles[e_rect_board].b+(ObjectsRectangles[e_rect_board].t-ObjectsRectangles[e_rect_board].b)/2+TimeOut::e_Height/2),
//e_rect_timeout_playagain
	hb::Rectangle(ObjectsRectangles[e_rect_timeout].l+20, ObjectsRectangles[e_rect_timeout].b+10, 
				ObjectsRectangles[e_rect_timeout].l+20+128, ObjectsRectangles[e_rect_timeout].b+5+10+40),
//e_rect_timeout_quitgame
	hb::Rectangle(ObjectsRectangles[e_rect_timeout_playagain]+hb::Rectangle(128+20,0,128+20,0)),
//e_rect_Intro
	hb::Rectangle(ObjectsRectangles[e_rect_board].l-20, 
			ObjectsRectangles[e_rect_board].b+(ObjectsRectangles[e_rect_board].t-ObjectsRectangles[e_rect_board].b)/2-TimeOut::e_Height/2,
				  ObjectsRectangles[e_rect_board].r-10, 
			ObjectsRectangles[e_rect_board].b+(ObjectsRectangles[e_rect_board].t-ObjectsRectangles[e_rect_board].b)/2+TimeOut::e_Height/2),
//e_rect_Intro_startbutton
	hb::Rectangle( 
		ObjectsRectangles[e_rect_Intro].l + (ObjectsRectangles[e_rect_Intro].r -ObjectsRectangles[e_rect_Intro].l)/2 -Intro::e_width/2,
		ObjectsRectangles[e_rect_Intro].b+10, 
		ObjectsRectangles[e_rect_Intro].r - (ObjectsRectangles[e_rect_Intro].r -ObjectsRectangles[e_rect_Intro].l)/2 +Intro::e_width/2,
		ObjectsRectangles[e_rect_Intro].b+5+10+40),

#ifdef _testingthenewspriteobjectclass_
//e_rect_timecounter2,
	hb::Rectangle(ObjectsRectangles[e_rect_timecounter].l, ObjectsRectangles[e_rect_timecounter].b-5-TimeCounter::e_Height,
				ObjectsRectangles[e_rect_timecounter].l+TimeCounter::e_Width, ObjectsRectangles[e_rect_timecounter].b-5),
#endif //_testingthenewspriteobjectclass_

};

struct stRectangle2
{
	hb::Points32 lb;
	hb::Points32 rb;
	hb::Points32 rt;
	hb::Points32 lt;
};
const stRectangle2 ObjectsRectangle2[]=
{
	{
		hb::Points32(ObjectsRectangles[e_rect_timecounter].l, ObjectsRectangles[e_rect_timecounter].b-5-TimeCounter::e_Height), 
		hb::Points32(ObjectsRectangles[e_rect_timecounter].l+TimeCounter::e_Width,ObjectsRectangles[e_rect_timecounter].b-5-TimeCounter::e_Height), 
		hb::Points32(ObjectsRectangles[e_rect_timecounter].l+TimeCounter::e_Width,ObjectsRectangles[e_rect_timecounter].b-5), 
		hb::Points32(ObjectsRectangles[e_rect_timecounter].l, ObjectsRectangles[e_rect_timecounter].b-5)
	},
	{
		hb::Points32(ObjectsRectangle2[0].lb.x, ObjectsRectangle2[0].lb.y-5-TimeCounter::e_Height),
		hb::Points32(ObjectsRectangle2[0].rb.x, ObjectsRectangle2[0].lb.y-5-TimeCounter::e_Height),
		hb::Points32(ObjectsRectangle2[0].rb.x, ObjectsRectangle2[0].lb.y-5),
		hb::Points32(ObjectsRectangle2[0].lb.x, ObjectsRectangle2[0].lb.y-5),
	},
};
#endif _OBJECTSRECTANGLES_