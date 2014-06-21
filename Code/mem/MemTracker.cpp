
#include <stdio.h>
#include <new>
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

	AllocationInfo():next(NULL),nbrOfCollisions(0)
	{
	}

} g_allocations[MAX_allocations];


unsigned char getHashValue(long addr)
{
	unsigned char  *k=(unsigned char *)&addr;
	unsigned char a=0xb9;  /* an arbitrary value */

   a=a^k[3]; 
   a=a^k[2];
   a=a^k[1];
   a=a^k[0];
    
   if(a==0xff)
		a=0;
	else if(a== 0)
		a=0xfe;

   return a;
}

void AddTrack(long addr, long asize, char *filename, int line)
{

	unsigned char t1=getHashValue(addr);

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
	}
	else
	{
		assert(0);
	}

};

bool RemoveTrack(long addr)
{
	long t1=getHashValue(addr);
	
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
	}
	else
	{
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

	printf("Total Unfreed: %d bytes\n\n\n", totalSize);


};

}//namespace hash


void * operator new(size_t  size, char *filename, int line)
{
	void *ptr = ::operator new(size);

	hb::AddTrack((long)ptr, size,filename, line);
	return(ptr);
}

void * operator new[](size_t size, char *filename, int line)
{
	void *ptr = ::operator new[](size);

	hb::AddTrack((long)ptr, size,filename, line);
	return(ptr);
}

void operator delete(void *p, char *filename, int line)
{
	delete p;
}

void operator delete[](void *p, char *filename, int line)
{
	delete [] p;
}

void operator delete(void *p)
{
	if(p)
		hb::RemoveTrack((long)p);

	free(p);
}

void operator delete[](void *p)
{
	if(p)
		hb::RemoveTrack((long)p);

	free(p);
}

