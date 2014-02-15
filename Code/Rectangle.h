#ifndef _RECTANGLE_
#define _RECTANGLE_

#include "common.h"

namespace hb
{
template <typename T1, typename T2=T1> struct Point
{
	T1 x,y;
public:
	static Point<T1, T2> Invalid;

	Point();
	Point(T1 x,T1 y);
	void operator=(const Point<T1, T2> & p);
	bool operator==(const Point<T1, T2> & p);
	Point<T2> operator-(const Point<T1, T2> & a);
	Point<T1, T2> operator+(const Point<T1, T2> & a);
};


template <typename T1,  typename T2> Point<T1, T2>::Point()
{
}

template <typename T1,  typename T2> Point<T1, T2>::Point(T1 _x,T1 _y):x(_x),y(_y)
{
}

template <typename T1,  typename T2> void Point<T1, T2>::operator=(const Point<T1, T2> & p)
{
	x=p.x;
	y=p.y;
}

template <typename T1,  typename T2> bool Point<T1, T2>::operator==(const Point<T1, T2> & p)
{
	return (x==p.x && y==p.y);
}

template <typename T1,  typename T2> Point<T2> Point<T1, T2>::operator-(const Point<T1, T2> & a)
{
	return Point<T2>(x-a.x, y-a.y);
}

template <typename T1,  typename T2> Point<T1,T2> Point<T1, T2>::operator+(const Point<T1, T2> & a)
{
	return Point<T1,T2>(x+a.x, y+a.y);
}


//typedef Point<float> Pointf;
typedef Point<uint8,sint8> Pointu8;
//extern Pointi Pointi_Invalid;
Pointu8 Pointu8::Invalid(0xFF,0xFF);
typedef Point<sint8> Points8;
typedef Point<uint32,sint32> Pointu32;


/*
struct Point
{
	float x,y;
public:
	Point(float x,float y);
};
*/

struct Rectangle
{
	uint32 l;  //correct the type fields
	uint32 b;
	uint32 r;
	uint32 t; //optim:members are defined in the order of the access
public:
	Rectangle();
	Rectangle(uint32 _l, uint32 _b, uint32 _r, uint32 _t);
	bool operator==(const Rectangle & r);
	Rectangle operator+(const Rectangle & e) const;

};

}

#endif _RECTANGLE_