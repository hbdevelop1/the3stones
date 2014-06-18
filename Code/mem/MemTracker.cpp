
#ifdef _use_my_mem_tracker_

#include <stdio.h>
#define avoiderrorC2660inVC2010
#ifdef avoiderrorC2660inVC2010
//error C2660: 'operator new[]' : function does not take 1 arguments
#include <new>
#else
#include <stdlib.h>
#endif
#include "../common.h" //for assert

#pragma warning (disable:4996)

#define FILENAMELEN	63





namespace hbhash
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

struct 
{
	lALLOC_INFO * next;
} allocations[MAX_allocations];

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

		lALLOC_INFO ** p=&allocations[t1].next;

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
	long t1=getHashValue1(addr);
	printf("deleting 0x%08X->0x%02X\n",addr,t1);
	bool bFound = false;

	lALLOC_INFO ** p=&allocations[t1].next;

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
		lALLOC_INFO *pInfo = allocations[i].next;
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



/*
typedef struct 
{
	long number;
	long address;
	long size;
	char file[FILENAMELEN+1];
	long line;
} lALLOC_INFO;

lALLOC_INFO *allocations[ 100000 ];
int nPos = 0;

void AddTrack(long addr, long asize, char *filename, int line)
{
	lALLOC_INFO * info= (lALLOC_INFO *)malloc(sizeof(lALLOC_INFO));
	info->address = addr;
	info->size = asize;


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


	info->number = nPos;
	allocations[nPos] = info;
	nPos ++;
};

bool RemoveTrack(long addr)
{
	bool bFound = false;
	for(int i = 0; i != nPos; i++)
	{
		if(allocations[i]->address == addr)
		{
			// Okay, delete this one.
			free( allocations[i] );
			bFound = true;
			// And copy the rest down to it.
			for ( int j=i; j<nPos-1; ++j )
				allocations[j] = allocations[j+1];
			nPos --;
			break;
		}
	}
	assert( bFound );

	return bFound;
};


void DumpUnfreed()
{
long totalSize = 0;
printf("-------------------- Allocations ----------------------\n");
for(int i = 0; i < nPos; i++) 
{
lALLOC_INFO *pInfo = allocations[i];
printf("(%ld) ADDRESS %x\t Size: %d unfreed - file %s at %d\n", pInfo->number, pInfo->address, pInfo->size, pInfo->file, pInfo->line);
totalSize += pInfo->size;
}
printf("------------------------------------------------------\n");
printf("Total Unfreed: %d bytes\n\n\n", totalSize);
};
*/

//inline 
void * operator new(size_t  size, char *filename, int line)
{
	void *ptr = //(void *)malloc(size);
		::operator new(size);

	//AddTrack((long)ptr, size,filename, line);
	hbhash::AddTrack((long)ptr, size,filename, line);
	return(ptr);
};

//inline 
void * operator new[](size_t size, char *filename, int line)
{
	void *ptr = //(void *)malloc(size);
		::operator new[](size);

	//AddTrack((long)ptr, size,filename, line);
	hbhash::AddTrack((long)ptr, size,filename, line);
	return(ptr);
};

//inline 
void operator delete(void *p, char *filename, int line)
{
	//if ( hbhash::RemoveTrack((long)p))
	//if ( RemoveTrack((long)p) )
		//free(p);
		delete p;
};

//inline 
void operator delete[](void *p, char *filename, int line)
{
	//if ( hbhash::RemoveTrack((long)p))
	//if ( RemoveTrack((long)p) )
		//free(p);
		delete [] p;
};

void operator delete(void *p)
{
	if(p)
		hbhash::RemoveTrack((long)p);

	free(p);
	/*
	if ( hbhash::RemoveTrack((long)p))
	//if ( RemoveTrack((long)p) )
		//free(p);
		delete p;
		*/
};

void operator delete[](void *p)
{
	if(p)
		hbhash::RemoveTrack((long)p);

	free(p);
};

#ifdef testingnewdelete
void * operator new(size_t  size)
{
	void *ptr = (void *)malloc(size);

	AddTrack((long)ptr, size,"", 0);
	return(ptr);
};

//inline 
void * operator new[](size_t size)
{
	void *ptr = (void *)malloc(size);

	AddTrack((long)ptr, size,"",0);
	return(ptr);
};

//inline 
void operator delete(void *p)
{
	if ( RemoveTrack((long)p) )
		free(p);
};

//inline 
void operator delete[](void *p)
{
	if ( RemoveTrack((long)p) )
		free(p);
};

template<class T> void deleteo2(T *p)
{
	if ( RemoveTrack((long)p) )
	{
		delete p;
	}
	else
		assert(0);
};

template<class T> void deletea2(T *p)
{
	if ( RemoveTrack((long)p - sizeof(unsigned int)) )
	{
		delete [] p;
	}
	else
		assert(0);
};

struct O11
{
	//unsigned int m_texObj;

public:
	//O11 (){}

	~O11 (){}
};

void main1()
{
	char *c=new char;
	delete c;

	char *c2=new char[3];
	delete c2;  //<---- note : i am not using delete[]

	char *c3=new char[3];
	delete [] c3;

	O11 *o=new O11;
	delete o;

	O11 *o1=new O11[10];
	delete [] o1;


	{
#define new new(__FILE__,__LINE__)

	char *c=new char;
	deleteo<char>(c);

	char *c2=new char[3];
	deleteo<char>(c2);  //<---- note : i am not using deletea

	char *c3=new char[3];
	deleteo<char>(c3);

	O11 *o=new O11;
	deleteo<O11>(o);

	O11 *o1=new O11[10];
	deletea<O11>(o1);
	}

}
#endif //testingnewdelete


#endif //_use_my_mem_tracker_
