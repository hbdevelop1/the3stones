
#include "common.h"
#include "rectangle.h"

#include "MemNew.h"


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