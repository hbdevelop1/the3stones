
#include "common.h"
#include "rectangle.h"

#ifdef _use_my_mem_tracker_
#define new new(__FILE__,__LINE__)
#endif //_use_my_mem_tracker_


namespace hb
{


Rectangle::Rectangle()
{
}


Rectangle::Rectangle(uint32 _l, uint32 _b, uint32 _r, uint32 _t):l(_l),b(_b), r(_r),t(_t)
{
}

bool Rectangle::operator==(const Rectangle & e)
{
	return (l==e.l && b==e.b && r==e.r && t==e.t );
}

Rectangle Rectangle::operator+(const Rectangle & e) const
{
	return Rectangle(l+e.l, b+e.b, r+e.r, t+e.t );
}


}