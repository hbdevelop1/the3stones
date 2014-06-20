
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

unsigned char getHashValue3(long addr)
{
	unsigned char  *k=(unsigned char *)&addr;
	unsigned char a=0xb9;  /* an arbitrary value */

   a=a^k[3]; 
   a=a^k[2];
   a=a^k[1];
   a=a^k[0];
    
   if(a==0xff)
	   a=0;
	if(a== 0)
		a=0xfe;

   return a;
}

unsigned char getHashValue4(long addr)
{
	unsigned char a=(addr>>4 & 0x0f)<<4;
	unsigned char b=addr>>8 & 0x0f;
	a |= b;
	
	if(a== 0xff)
		a=0;
	if(a== 0)
		a=0xfe;

	return a;
}

unsigned char getHashValue5(long addr)
{
	unsigned char a=addr>>4 & 0xff;
	unsigned char *b=(unsigned char *)&addr;

	unsigned char c=0;
	c ^= b[0];
	c ^= b[1];
	c ^= b[3];
	c ^= b[4];

	return a;
}


#if 0

long getHahsValue4(long adr)
{
typedef  unsigned long int  u4;   /* unsigned 4-byte type */
typedef  unsigned     char  u1;   /* unsigned 1-byte type */

/* The mixing step */
#define mix(a,b,c) \
{ \
  a=a-b;  a=a-c;  a=a^(c>>13); \
  b=b-c;  b=b-a;  b=b^(a<<8);  \
  c=c-a;  c=c-b;  c=c^(b>>13); \
  a=a-b;  a=a-c;  a=a^(c>>12); \
  b=b-c;  b=b-a;  b=b^(a<<16); \
  c=c-a;  c=c-b;  c=c^(b>>5);  \
  a=a-b;  a=a-c;  a=a^(c>>3);  \
  b=b-c;  b=b-a;  b=b^(a<<10); \
  c=c-a;  c=c-b;  c=c^(b>>15); \
}

/* The whole new hash function */
//u4 hash( k, length, initval)
register u1 *k=(u1 *)&adr;        /* the key */
u4           length=4;   /* the length of the key in bytes */
u4           initval=0;  /* the previous hash, or an arbitrary value */
{
   register u4 a,b,c;  /* the internal state */
   u4          len;    /* how many key bytes still need mixing */

   /* Set up the internal state */
   len = length;
   a = b = 0x9e3779b9;  /* the golden ratio; an arbitrary value */
   c = initval;         /* variable initialization of internal state */

   /*---------------------------------------- handle most of the key */
   while (len >= 12)
   {
      a=a+(k[0]+((u4)k[1]<<8)+((u4)k[2]<<16) +((u4)k[3]<<24));
      b=b+(k[4]+((u4)k[5]<<8)+((u4)k[6]<<16) +((u4)k[7]<<24));
      c=c+(k[8]+((u4)k[9]<<8)+((u4)k[10]<<16)+((u4)k[11]<<24));
      mix(a,b,c);
      k = k+12; len = len-12;
   }

   /*------------------------------------- handle the last 11 bytes */
   c = c+length;
   switch(len)              /* all the case statements fall through */
   {
   case 11: c=c+((u4)k[10]<<24);
   case 10: c=c+((u4)k[9]<<16);
   case 9 : c=c+((u4)k[8]<<8);
      /* the first byte of c is reserved for the length */
   case 8 : b=b+((u4)k[7]<<24);
   case 7 : b=b+((u4)k[6]<<16);
   case 6 : b=b+((u4)k[5]<<8);
   case 5 : b=b+k[4];
   case 4 : a=a+((u4)k[3]<<24);
   case 3 : a=a+((u4)k[2]<<16);
   case 2 : a=a+((u4)k[1]<<8);
   case 1 : a=a+k[0];
     /* case 0: nothing left to add */
   }
   mix(a,b,c);
   /*-------------------------------------------- report the result */
   return c;
}

}

#endif 0

unsigned char (*currenthash)(long addr) = NULL;

void AddTrack(long addr, long asize, char *filename, int line)
{
	if(currenthash == NULL)
		currenthash = getHashValue3;
	/*
	long s0=getHashValue0(addr);
	long s1=getHashValue1(addr);
	long s2=getHashValue2(addr);
	char s3=getHashValue3(addr);
	char s4=getHashValue4(addr);
	*/
	unsigned char t1=currenthash(addr);


	//printf("0x%08X->0x%02X:0x%02X:0x%02X\n",addr,s0,s1,s2,s3);


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

		if(g_allocations[t1].nbrOfCollisions>3)
		{
			printf("more than 3 collisions at %d (%d)\n",t1,g_allocations[t1].nbrOfCollisions);
		}
		
	}
	else
	{
		assert(0);
	}

};

bool RemoveTrack(long addr)
{
	long t1=currenthash(addr);
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
