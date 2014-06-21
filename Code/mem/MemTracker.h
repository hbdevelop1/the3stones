

#ifndef _MEMTRACKER_
#define _MEMTRACKER_

#include "boost/checked_delete.hpp"


void * operator new(size_t  size, char *filename, int line);
void * operator new[](size_t size, char * filename, int line);
void   operator delete(void *p, char *filename, int line);
void   operator delete[](void *p, char *filename, int line);
void operator delete(void *p);
void operator delete[](void *p);

namespace hb
{
bool RemoveTrack(long addr);
void DumpUnfreed();
}

#endif //_MEMTRACKER_
