#ifdef _use_my_mem_tracker_

#ifndef _MEMTRACKER_
#define _MEMTRACKER_

#include "boost/checked_delete.hpp"


void * operator new(size_t  size, char *filename, int line);
void * operator new[](size_t size, char * filename, int line);
void   operator delete(void *p, char *filename, int line);
void   operator delete[](void *p, char *filename, int line);
void operator delete(void *p);
void operator delete[](void *p);

namespace hbhash
{
bool RemoveTrack(long addr);
void DumpUnfreed();
}
#if 0

template<class T> void deleteo(T *p)
{
	if (p==0)
		return;//prevent RemoveTrack from asserting on a null pointer 

	if(hbhash::RemoveTrack((long)p))
	//if ( RemoveTrack((long)p) )
	{
		delete p;
	}
	else
		assert(0);
};

template<class T> void deletea(T *p)
{
	if (p==0)
		return;//prevent RemoveTrack from asserting on a null pointer 

	if(hbhash::RemoveTrack((long)p - sizeof(unsigned int)))
	//if ( RemoveTrack((long)p - sizeof(unsigned int)) )
	{
		delete [] p;
	}
	else
		assert(0);
};

template<class T> void deleteo4boost(T *p) //boost uses boost::checked_delete, so i should use it
{
	if (p==0)
		return;//prevent RemoveTrack from asserting on a null pointer 

	if(hbhash::RemoveTrack((long)p))
	//if ( RemoveTrack((long)p) )
	{
		boost::checked_delete( p );
	}
	else
		assert(0);
};

template<class T> void deletea4boost(T *p) //boost uses boost::checked_delete, so i should use it
{
	if (p==0)
		return;//prevent RemoveTrack from asserting on a null pointer 

	if(hbhash::RemoveTrack((long)p - sizeof(unsigned int)))
	//if ( RemoveTrack((long)p - sizeof(unsigned int)) )
	{
		boost::checked_array_delete( p );
	}
	else
		assert(0);
};

#endif //0

#endif //_MEMTRACKER_

#endif //_use_my_mem_tracker_
