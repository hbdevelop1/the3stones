
#ifdef _use_my_mem_tracker_

#include <stdio.h>
#define avoiderrorC2660inVC2010
#ifdef avoiderrorC2660inVC2010
//error C2660: 'operator new[]' : function does not take 1 arguments
#include <new>
#else
#include <stdlib.h>
#endif
#include "../common.h"

#pragma warning (disable:4996)

#define FILENAMELEN	63





namespace hb
{
#define MAX_allocations 0xff

struct lALLOC_INFO
{
//	long number;
	long address;
	long size;
	char file[FILENAMELEN+1];
	long line;
	lALLOC_INFO * next;
} ;

static struct AllocationInfo
{
	lALLOC_INFO * next;
	unsigned int	nbrOfCollisions;
	static unsigned int	nbrOfCollisionsMax;
	static unsigned int	positionMaxCollisions;

	AllocationInfo():next(NULL),nbrOfCollisions(0)
	{
	}

} g_allocations[MAX_allocations];

unsigned int AllocationInfo::nbrOfCollisionsMax=0;
unsigned int AllocationInfo::positionMaxCollisions=0;

long getHashValue0(long addr)
{
	long t=addr & 0x0000ffff;
	long t1=(t>>12)+((t>>8) & 0x0000000f)+((t>>4) & 0x0000000f)+(t & 0x0000000f);
	return t1;
}
long getHashValue1(long addr)
{
	return addr & 0x000000ff;
}

long getHashValue2(long addr)
{
	char a=0;
	for(char i=0; i<8; ++i )
	{
		a |= (addr & (1<<(4*i)))>>((4*i)-i);
		//printf("a=0x%02X  ",a);
	}

	//printf("\n");

	return a;
}

char getHashValue3(long addr)
{
	register char *k=(char*)&addr;
   register char a;
//   a = 0xb9;  /* the golden ratio; an arbitrary value */
a=(char )0xff;//cast to avoid warning C4309: '=' : truncation of constant value

   a=a^k[3]; 
   a=a^k[2];
   a=a^k[1];
   a=a^k[0];
     
   return a;
}


void AddTrack(long addr, long asize, char *filename, int line)
{
	long t1=getHashValue1(addr);
	long t2=getHashValue2(addr);
	char t3=getHashValue3(addr);

	printf("0x%08X->0x%02X:0x%02X:0x%02X\n",addr,t1,t2,t3);


	lALLOC_INFO * info= (lALLOC_INFO *)malloc(sizeof(lALLOC_INFO));
	info->address = addr;
	info->size = asize;
	info->next=0;
	{
		int sz=strlen(filename);
		char *p;
		if(sz<=FILENAMELEN)
		{
			p=filename;
		}
		else
		{
			p=filename+sz-FILENAMELEN;
		}
		strcpy(info->file,p);

		info->line=line;
	}

	if(0<=t1 && t1<MAX_allocations)
	{

		lALLOC_INFO ** p=&g_allocations[t1].next;

		while(*p)
		{
			p=&((*p)->next);
		}
		*p=info;

		++g_allocations[t1].nbrOfCollisions;
		if(AllocationInfo::nbrOfCollisionsMax<g_allocations[t1].nbrOfCollisions)
		{
			AllocationInfo::nbrOfCollisionsMax=g_allocations[t1].nbrOfCollisions;
			AllocationInfo::positionMaxCollisions=t1;
		}

		if(g_allocations[t1].nbrOfCollisions>2)
		{
			printf("more than 2 collisions at %d (%d)\n",t1,g_allocations[t1].nbrOfCollisions);
		}
		
	}
	else
	{
		assert(0);
	}

};

bool RemoveTrack(long addr)
{
	long t1=getHashValue1(addr);
	printf("deleting 0x%08X->0x%02X\n",addr,t1);
	bool bFound = false;

	lALLOC_INFO ** p=&g_allocations[t1].next;

	while(*p != 0)
	{
		if((*p)->address != addr)
			p=&((*p)->next);
		else
		{
			bFound=true;
			break;
		}
	}


	if(bFound)
	{
		lALLOC_INFO *f =*p;
		*p=(*p)->next;
		free(f);

		--g_allocations[t1].nbrOfCollisions;
	}
	else
	{
		//Deque uses the standard global operator new, no the overloaded one. so it does not get registered.
		//but at deletion, the overload global operator delete is used. which leads to this assert
		assert( bFound ); 
	}

	
	return bFound;
};


void DumpUnfreed()
{
	long totalSize = 0;
	printf("-------------------- Allocations ----------------------\n");
	for(int i = 0; i < MAX_allocations; i++) 
	{
		lALLOC_INFO *pInfo = g_allocations[i].next;
		while(pInfo)
		{
			printf("ADDRESS %x\t Size: %d unfreed - file %s at %d\n", pInfo->address, pInfo->size, pInfo->file, pInfo->line);
			totalSize += pInfo->size;

			pInfo=pInfo->next;
		}

	}
	printf("------------------------------------------------------\n");

	printf("AllocationInfo::nbrOfCollisionsMax == %d at %d \n", AllocationInfo::nbrOfCollisionsMax,AllocationInfo::positionMaxCollisions);
	printf("Total Unfreed: %d bytes\n\n\n", totalSize);


};

}//namespace hash


void * operator new(size_t  size, char *filename, int line)
{
	void *ptr = ::operator new(size);

	hb::AddTrack((long)ptr, size,filename, line);
	return(ptr);
};

//inline 
void * operator new[](size_t size, char *filename, int line)
{
	void *ptr = ::operator new[](size);

	hb::AddTrack((long)ptr, size,filename, line);
	return(ptr);
};

//inline 
void operator delete(void *p, char *filename, int line)
{
	delete p;
};

//inline 
void operator delete[](void *p, char *filename, int line)
{
	delete [] p;
};

void operator delete(void *p)
{
	if(p)
		hb::RemoveTrack((long)p);

	free(p);
};

void operator delete[](void *p)
{
	if(p)
		hb::RemoveTrack((long)p);

	free(p);
};

#endif //_use_my_mem_tracker_
