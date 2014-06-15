
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

const hb::stRectangle2 ObjectsRectangles2[]=
{
	/*
	{
		hb::Points32(ObjectsRectangles[e_rect_timecounter].l, ObjectsRectangles[e_rect_timecounter].b-5-TimeCounter::e_Height), 
		hb::Points32(ObjectsRectangles[e_rect_timecounter].l+TimeCounter::e_Width,ObjectsRectangles[e_rect_timecounter].b-5-TimeCounter::e_Height), 
		hb::Points32(ObjectsRectangles[e_rect_timecounter].l+TimeCounter::e_Width,ObjectsRectangles[e_rect_timecounter].b-5), 
		hb::Points32(ObjectsRectangles[e_rect_timecounter].l, ObjectsRectangles[e_rect_timecounter].b-5)
	},
	{
		hb::Points32(ObjectsRectangles2[0].lb.x, ObjectsRectangles2[0].lb.y-5-TimeCounter::e_Height),
		hb::Points32(ObjectsRectangles2[0].rb.x, ObjectsRectangles2[0].lb.y-5-TimeCounter::e_Height),
		hb::Points32(ObjectsRectangles2[0].rb.x, ObjectsRectangles2[0].lb.y-5),
		hb::Points32(ObjectsRectangles2[0].lb.x, ObjectsRectangles2[0].lb.y-5),
	},*/

	//windowRectangle
	{
		hb::Points32(0, 0), 
		hb::Points32(Board::e_ColumnSize*Square::e_Width+140,0), 
		hb::Points32(Board::e_ColumnSize*Square::e_Width+140,Board::e_RowSize*Square::e_Height+10), 
		hb::Points32(0,Board::e_RowSize*Square::e_Height+10)
	},
//board
	{
		hb::Points32(ObjectsRectangles2[e_rect_window].rb.x-Board::e_ColumnSize*Square::e_Width-5, ObjectsRectangles2[e_rect_window].lt.y-Board::e_RowSize*Square::e_Height-5), 
		hb::Points32(ObjectsRectangles2[e_rect_window].rb.x-5,ObjectsRectangles2[e_rect_window].lt.y-Board::e_RowSize*Square::e_Height-5), 
		hb::Points32(ObjectsRectangles2[e_rect_window].rb.x-5,ObjectsRectangles2[e_rect_window].rt.y-5), 
		hb::Points32(ObjectsRectangles2[e_rect_window].rb.x-Board::e_ColumnSize*Square::e_Width-5,ObjectsRectangles2[e_rect_window].rt.y-5)
	},
//e_rect_score,
	{
		hb::Points32(ObjectsRectangles2[e_rect_window].lb.x+5, ObjectsRectangles2[e_rect_window].lt.y-5-GlobalScore::e_Height), 
		hb::Points32(ObjectsRectangles2[e_rect_window].lb.x+5+GlobalScore::e_Width,ObjectsRectangles2[e_rect_window].lt.y-5-GlobalScore::e_Height), 
		hb::Points32(ObjectsRectangles2[e_rect_window].lb.x+5+GlobalScore::e_Width,ObjectsRectangles2[e_rect_window].lt.y-5), 
		hb::Points32(ObjectsRectangles2[e_rect_window].lb.x+5,ObjectsRectangles2[e_rect_window].lt.y-5)
	},

//e_rect_timecounter,
	{
		hb::Points32(ObjectsRectangles2[e_rect_score].lb.x,ObjectsRectangles2[e_rect_score].lb.y-5-TimeCounter::e_Height), 
		hb::Points32(ObjectsRectangles2[e_rect_score].lb.x+TimeCounter::e_Width,ObjectsRectangles2[e_rect_score].lb.y-5-TimeCounter::e_Height), 
		hb::Points32(ObjectsRectangles2[e_rect_score].lb.x+TimeCounter::e_Width,ObjectsRectangles2[e_rect_score].lb.y-5), 
		hb::Points32(ObjectsRectangles2[e_rect_score].lb.x,ObjectsRectangles2[e_rect_score].lb.y-5)
	},


//countdown
	{
		hb::Points32(ObjectsRectangles2[e_rect_board].lb.x+90,ObjectsRectangles2[e_rect_board].lb.y+(ObjectsRectangles2[e_rect_board].rt.y-ObjectsRectangles2[e_rect_board].rb.y)/2-CountDown::e_Height/2), 
		hb::Points32(ObjectsRectangles2[e_rect_board].lb.x-90,ObjectsRectangles2[e_rect_board].lb.y+(ObjectsRectangles2[e_rect_board].rt.y-ObjectsRectangles2[e_rect_board].rb.y)/2-CountDown::e_Height/2), 
		hb::Points32(ObjectsRectangles2[e_rect_board].lb.x-90,ObjectsRectangles2[e_rect_board].lb.y+(ObjectsRectangles2[e_rect_board].rt.y-ObjectsRectangles2[e_rect_board].rb.y)/2+CountDown::e_Height/2), 
		hb::Points32(ObjectsRectangles2[e_rect_board].lb.x+90,ObjectsRectangles2[e_rect_board].lb.y+(ObjectsRectangles2[e_rect_board].rt.y-ObjectsRectangles2[e_rect_board].rb.y)/2+CountDown::e_Height/2)
	},

//e_rect_timeout
	{
		hb::Points32(ObjectsRectangles2[e_rect_board].lb.x+90,ObjectsRectangles2[e_rect_board].lb.y+(ObjectsRectangles2[e_rect_board].rt.y-ObjectsRectangles2[e_rect_board].rb.y)/2-TimeOut::e_Height/2), 
		hb::Points32(ObjectsRectangles2[e_rect_board].rb.x-90,ObjectsRectangles2[e_rect_board].lb.y+(ObjectsRectangles2[e_rect_board].rt.y-ObjectsRectangles2[e_rect_board].rb.y)/2-TimeOut::e_Height/2), 
		hb::Points32(ObjectsRectangles2[e_rect_board].rb.x-90,ObjectsRectangles2[e_rect_board].lb.y+(ObjectsRectangles2[e_rect_board].rt.y-ObjectsRectangles2[e_rect_board].rb.y)/2+TimeOut::e_Height/2), 
		hb::Points32(ObjectsRectangles2[e_rect_board].lb.x+90,ObjectsRectangles2[e_rect_board].lb.y+(ObjectsRectangles2[e_rect_board].rt.y-ObjectsRectangles2[e_rect_board].rb.y)/2+TimeOut::e_Height/2)
	},
//e_rect_timeout_playagain
	{
		hb::Points32(ObjectsRectangles2[e_rect_timeout].lb.x+20,ObjectsRectangles2[e_rect_timeout].lb.y+10), 
		hb::Points32(ObjectsRectangles2[e_rect_timeout].lb.x+20+128,ObjectsRectangles2[e_rect_timeout].lb.y+10), 
		hb::Points32(ObjectsRectangles2[e_rect_timeout].lb.x+20+128,ObjectsRectangles2[e_rect_timeout].lb.y+55), 
		hb::Points32(ObjectsRectangles2[e_rect_timeout].lb.x+20,ObjectsRectangles2[e_rect_timeout].lb.y+55) 
	},
//e_rect_timeout_quitgame
	{
		hb::Points32(ObjectsRectangles2[e_rect_timeout_playagain].lb.x+20+128,	ObjectsRectangles2[e_rect_timeout_playagain].lb.y), 
		hb::Points32(ObjectsRectangles2[e_rect_timeout_playagain].rb.x+20+128,	ObjectsRectangles2[e_rect_timeout_playagain].lb.y), 
		hb::Points32(ObjectsRectangles2[e_rect_timeout_playagain].rb.x+20+128,	ObjectsRectangles2[e_rect_timeout_playagain].rt.y), 
		hb::Points32(ObjectsRectangles2[e_rect_timeout_playagain].lb.x+20+128,	ObjectsRectangles2[e_rect_timeout_playagain].rt.y) 
	},
//e_rect_Intro
	{
		hb::Points32(ObjectsRectangles2[e_rect_board].lb.x-20,	ObjectsRectangles2[e_rect_board].lb.y+(ObjectsRectangles2[e_rect_board].rt.y-ObjectsRectangles2[e_rect_board].rb.y)/2-TimeOut::e_Height/2), 
		hb::Points32(ObjectsRectangles2[e_rect_board].rb.x-10,	ObjectsRectangles2[e_rect_board].lb.y+(ObjectsRectangles2[e_rect_board].rt.y-ObjectsRectangles2[e_rect_board].rb.y)/2-TimeOut::e_Height/2), 
		hb::Points32(ObjectsRectangles2[e_rect_board].rb.x-10,	ObjectsRectangles2[e_rect_board].lb.y+(ObjectsRectangles2[e_rect_board].rt.y-ObjectsRectangles2[e_rect_board].rb.y)/2+TimeOut::e_Height/2), 
		hb::Points32(ObjectsRectangles2[e_rect_board].lb.x-20,	ObjectsRectangles2[e_rect_board].lb.y+(ObjectsRectangles2[e_rect_board].rt.y-ObjectsRectangles2[e_rect_board].rb.y)/2+TimeOut::e_Height/2)
	},
//e_rect_Intro_startbutton
	{
		hb::Points32(ObjectsRectangles2[e_rect_Intro].lb.x+(ObjectsRectangles2[e_rect_Intro].rb.x-ObjectsRectangles2[e_rect_Intro].lb.x)/2-Intro::e_width/2, ObjectsRectangles2[e_rect_Intro].lb.y+10), 
		hb::Points32(ObjectsRectangles2[e_rect_Intro].rb.x-(ObjectsRectangles2[e_rect_Intro].rb.x-ObjectsRectangles2[e_rect_Intro].lb.x)/2+Intro::e_width/2, ObjectsRectangles2[e_rect_Intro].lb.y+10),
		hb::Points32(ObjectsRectangles2[e_rect_Intro].rb.x-(ObjectsRectangles2[e_rect_Intro].rb.x-ObjectsRectangles2[e_rect_Intro].lb.x)/2+Intro::e_width/2, ObjectsRectangles2[e_rect_Intro].lb.y+55),
		hb::Points32(ObjectsRectangles2[e_rect_Intro].lb.x+(ObjectsRectangles2[e_rect_Intro].rb.x-ObjectsRectangles2[e_rect_Intro].lb.x)/2-Intro::e_width/2, ObjectsRectangles2[e_rect_Intro].lb.y+55)
	},

};
#endif _OBJECTSRECTANGLES_