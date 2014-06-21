#ifndef _COMMON_
#define _COMMON_


#include <windows.h>
#include <GL/gl.h>
#include <glut\glut.h>
#include <assert.h>


typedef unsigned int	uint32;
typedef signed int		sint32;
typedef unsigned char	uint8;
typedef signed char		sint8;


namespace hb
{
void DrawText(const char *txt, signed int x=-1, signed int y=-1);
}


#include "Mem/MemTracker.h"

enum
{
	e_ncrg_good,
	e_ncrg_wow,

	e_ncrg_MAX
};


#endif //_COMMON_
