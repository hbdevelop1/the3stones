#ifndef _COMMON_
#define _COMMON_


#include <windows.h>
#include <GL/gl.h>
#include <assert.h>

#include "Mem/MemTracker.h"



namespace hb
{
void DrawText(const char *txt, signed int x=-1, signed int y=-1);
}

enum
{
	e_ncrg_good,
	e_ncrg_wow,

	e_ncrg_MAX
};


#endif //_COMMON_
