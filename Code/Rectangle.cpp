
#include "common.h"
#include "rectangle.h"

#include "Mem/MemNew.h"


namespace hb
{

Rectangle operator+(const Rectangle & e, const signedRectangle & f)
{
	return Rectangle(f.l+e.l, f.b+e.b, f.r+e.r, f.t+e.t );
}



}