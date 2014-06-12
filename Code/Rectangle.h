#ifndef _RECTANGLE_
#define _RECTANGLE_

#include "common.h"

namespace hb
{
template <typename T1, typename T2=T1> struct Point
{
	T1 x;
	T1 y;
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
typedef Point<sint32,sint32> Points32;


/*
struct Point
{
	float x,y;
public:
	Point(float x,float y);
};
*/

template<class T> struct stRectangle
{
	T l;
	T b;
	T r;
	T t; //optim:members are defined in the order of the access
public:
	stRectangle();
	stRectangle(T _l, T _b, T _r, T _t);
	bool operator==(const stRectangle<T> & r);
	stRectangle<T> operator+(const stRectangle<T> & e) const;

};

template<class T> stRectangle<T>::stRectangle()
{
}


template<class T> stRectangle<T>::stRectangle(T _l, T _b, T _r, T _t):l(_l),b(_b), r(_r),t(_t)
{
}

template<class T> bool stRectangle<T>::operator==(const stRectangle<T> & e)
{
	return (l==e.l && b==e.b && r==e.r && t==e.t );
}

template<class T> stRectangle<T> stRectangle<T>::operator+(const stRectangle<T> & e) const
{
	return stRectangle<T>(l+e.l, b+e.b, r+e.r, t+e.t );
}

typedef stRectangle<uint32> Rectangle;
typedef stRectangle<sint32> signedRectangle;


struct stRectangle2
{
	hb::Points32 lb;
	hb::Points32 rb;
	hb::Points32 rt;
	hb::Points32 lt;
};


}

#endif _RECTANGLE_