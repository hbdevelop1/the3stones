
#include "vector.h"
#include <math.h>

namespace hb
{
#define TOLERANCE	1.e-3

float Vector::Distance()
{
	float s=x*x + y*y;

	if (fabs(s)<TOLERANCE)
		return 0;
	if (fabs(s-1)<TOLERANCE)
		return 0;

	s=sqrt(s);

	return s;
}

}