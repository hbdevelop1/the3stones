#line 1 "d:\\hassan\\devs\\solarsystem\\trunk\\engine\\xml\\xml.h"






#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\string"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\string"



#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\istream"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\istream"



#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\ostream"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\ostream"



#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\ios"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\ios"



#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\streambuf"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\streambuf"



#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocnum"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocnum"



#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\cerrno"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\cerrno"








 #line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\errno.h"
















#pragma once
#line 19 "c:\\program files\\microsoft visual studio\\vc98\\include\\errno.h"






#line 26 "c:\\program files\\microsoft visual studio\\vc98\\include\\errno.h"



extern "C" {
#line 31 "c:\\program files\\microsoft visual studio\\vc98\\include\\errno.h"


















#line 50 "c:\\program files\\microsoft visual studio\\vc98\\include\\errno.h"

















#line 68 "c:\\program files\\microsoft visual studio\\vc98\\include\\errno.h"
 extern int errno;
#line 70 "c:\\program files\\microsoft visual studio\\vc98\\include\\errno.h"
















































}
#line 120 "c:\\program files\\microsoft visual studio\\vc98\\include\\errno.h"

#line 122 "c:\\program files\\microsoft visual studio\\vc98\\include\\errno.h"
#line 15 "c:\\program files\\microsoft visual studio\\vc98\\include\\cerrno"
#line 16 "c:\\program files\\microsoft visual studio\\vc98\\include\\cerrno"
#line 17 "c:\\program files\\microsoft visual studio\\vc98\\include\\cerrno"





#line 10 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocnum"
#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\climits"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\climits"



#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\limits.h"















#pragma once
#line 18 "c:\\program files\\microsoft visual studio\\vc98\\include\\limits.h"






#line 25 "c:\\program files\\microsoft visual studio\\vc98\\include\\limits.h"













#line 39 "c:\\program files\\microsoft visual studio\\vc98\\include\\limits.h"
















#line 56 "c:\\program files\\microsoft visual studio\\vc98\\include\\limits.h"





#line 62 "c:\\program files\\microsoft visual studio\\vc98\\include\\limits.h"





#line 68 "c:\\program files\\microsoft visual studio\\vc98\\include\\limits.h"








#line 77 "c:\\program files\\microsoft visual studio\\vc98\\include\\limits.h"








#line 86 "c:\\program files\\microsoft visual studio\\vc98\\include\\limits.h"
































#line 119 "c:\\program files\\microsoft visual studio\\vc98\\include\\limits.h"
#line 10 "c:\\program files\\microsoft visual studio\\vc98\\include\\climits"
#line 11 "c:\\program files\\microsoft visual studio\\vc98\\include\\climits"





#line 11 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocnum"
#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\cstdio"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\cstdio"








 #line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"















#pragma once
#line 18 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"






#line 25 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"







#pragma pack(push,8)
#line 34 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"


extern "C" {
#line 38 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"


















#line 57 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"


























typedef wchar_t wint_t;
typedef wchar_t wctype_t;

#line 87 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"
#line 88 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"









typedef char *  va_list;
#line 99 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"

#line 101 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"






#line 108 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"

#line 110 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"






























#line 141 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"





struct _iobuf {
        char *_ptr;
        int   _cnt;
        char *_base;
        int   _flag;
        int   _file;
        int   _charbuf;
        int   _bufsiz;
        char *_tmpfname;
        };
typedef struct _iobuf FILE;

#line 159 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"












#line 172 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"












#line 185 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"



































 extern FILE _iob[];
#line 222 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"









#line 232 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"


typedef __int64 fpos_t;







#line 243 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"
#line 244 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"


#line 247 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"




























 int __cdecl _filbuf(FILE *);
 int __cdecl _flsbuf(int, FILE *);




 FILE * __cdecl _fsopen(const char *, const char *, int);
#line 283 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"

 void __cdecl clearerr(FILE *);
 int __cdecl fclose(FILE *);
 int __cdecl _fcloseall(void);




 FILE * __cdecl _fdopen(int, const char *);
#line 293 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"

 int __cdecl feof(FILE *);
 int __cdecl ferror(FILE *);
 int __cdecl fflush(FILE *);
 int __cdecl fgetc(FILE *);
 int __cdecl _fgetchar(void);
 int __cdecl fgetpos(FILE *, fpos_t *);
 char * __cdecl fgets(char *, int, FILE *);




 int __cdecl _fileno(FILE *);
#line 307 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"

 int __cdecl _flushall(void);
 FILE * __cdecl fopen(const char *, const char *);
 int __cdecl fprintf(FILE *, const char *, ...);
 int __cdecl fputc(int, FILE *);
 int __cdecl _fputchar(int);
 int __cdecl fputs(const char *, FILE *);
 size_t __cdecl fread(void *, size_t, size_t, FILE *);
 FILE * __cdecl freopen(const char *, const char *, FILE *);
 int __cdecl fscanf(FILE *, const char *, ...);
 int __cdecl fsetpos(FILE *, const fpos_t *);
 int __cdecl fseek(FILE *, long, int);
 long __cdecl ftell(FILE *);
 size_t __cdecl fwrite(const void *, size_t, size_t, FILE *);
 int __cdecl getc(FILE *);
 int __cdecl getchar(void);
 int __cdecl _getmaxstdio(void);
 char * __cdecl gets(char *);
 int __cdecl _getw(FILE *);
 void __cdecl perror(const char *);
 int __cdecl _pclose(FILE *);
 FILE * __cdecl _popen(const char *, const char *);
 int __cdecl printf(const char *, ...);
 int __cdecl putc(int, FILE *);
 int __cdecl putchar(int);
 int __cdecl puts(const char *);
 int __cdecl _putw(int, FILE *);
 int __cdecl remove(const char *);
 int __cdecl rename(const char *, const char *);
 void __cdecl rewind(FILE *);
 int __cdecl _rmtmp(void);
 int __cdecl scanf(const char *, ...);
 void __cdecl setbuf(FILE *, char *);
 int __cdecl _setmaxstdio(int);
 int __cdecl setvbuf(FILE *, char *, int, size_t);
 int __cdecl _snprintf(char *, size_t, const char *, ...);
 int __cdecl sprintf(char *, const char *, ...);
 int __cdecl sscanf(const char *, const char *, ...);
 char * __cdecl _tempnam(const char *, const char *);
 FILE * __cdecl tmpfile(void);
 char * __cdecl tmpnam(char *);
 int __cdecl ungetc(int, FILE *);
 int __cdecl _unlink(const char *);
 int __cdecl vfprintf(FILE *, const char *, va_list);
 int __cdecl vprintf(const char *, va_list);
 int __cdecl _vsnprintf(char *, size_t, const char *, va_list);
 int __cdecl vsprintf(char *, const char *, va_list);








#line 363 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"




 FILE * __cdecl _wfsopen(const wchar_t *, const wchar_t *, int);
#line 369 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"

 wint_t __cdecl fgetwc(FILE *);
 wint_t __cdecl _fgetwchar(void);
 wint_t __cdecl fputwc(wint_t, FILE *);
 wint_t __cdecl _fputwchar(wint_t);
 wint_t __cdecl getwc(FILE *);
 wint_t __cdecl getwchar(void);
 wint_t __cdecl putwc(wint_t, FILE *);
 wint_t __cdecl putwchar(wint_t);
 wint_t __cdecl ungetwc(wint_t, FILE *);

 wchar_t * __cdecl fgetws(wchar_t *, int, FILE *);
 int __cdecl fputws(const wchar_t *, FILE *);
 wchar_t * __cdecl _getws(wchar_t *);
 int __cdecl _putws(const wchar_t *);

 int __cdecl fwprintf(FILE *, const wchar_t *, ...);
 int __cdecl wprintf(const wchar_t *, ...);
 int __cdecl _snwprintf(wchar_t *, size_t, const wchar_t *, ...);
 int __cdecl swprintf(wchar_t *, const wchar_t *, ...);
 int __cdecl vfwprintf(FILE *, const wchar_t *, va_list);
 int __cdecl vwprintf(const wchar_t *, va_list);
 int __cdecl _vsnwprintf(wchar_t *, size_t, const wchar_t *, va_list);
 int __cdecl vswprintf(wchar_t *, const wchar_t *, va_list);
 int __cdecl fwscanf(FILE *, const wchar_t *, ...);
 int __cdecl swscanf(const wchar_t *, const wchar_t *, ...);
 int __cdecl wscanf(const wchar_t *, ...);






 FILE * __cdecl _wfdopen(int, const wchar_t *);
 FILE * __cdecl _wfopen(const wchar_t *, const wchar_t *);
 FILE * __cdecl _wfreopen(const wchar_t *, const wchar_t *, FILE *);
 void __cdecl _wperror(const wchar_t *);
 FILE * __cdecl _wpopen(const wchar_t *, const wchar_t *);
 int __cdecl _wremove(const wchar_t *);
 wchar_t * __cdecl _wtempnam(const wchar_t *, const wchar_t *);
 wchar_t * __cdecl _wtmpnam(wchar_t *);



#line 414 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"
#line 415 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"


#line 418 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"
































 int __cdecl fcloseall(void);
 FILE * __cdecl fdopen(int, const char *);
 int __cdecl fgetchar(void);
 int __cdecl fileno(FILE *);
 int __cdecl flushall(void);
 int __cdecl fputchar(int);
 int __cdecl getw(FILE *);
 int __cdecl putw(int, FILE *);
 int __cdecl rmtmp(void);
 char * __cdecl tempnam(const char *, const char *);
 int __cdecl unlink(const char *);

#line 463 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"


}
#line 467 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"


#pragma pack(pop)
#line 471 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"

#line 473 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdio.h"
#line 15 "c:\\program files\\microsoft visual studio\\vc98\\include\\cstdio"
#line 16 "c:\\program files\\microsoft visual studio\\vc98\\include\\cstdio"
#line 17 "c:\\program files\\microsoft visual studio\\vc98\\include\\cstdio"





#line 12 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocnum"
#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\cstdlib"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\cstdlib"








 
#line 16 "c:\\program files\\microsoft visual studio\\vc98\\include\\cstdlib"
#line 17 "c:\\program files\\microsoft visual studio\\vc98\\include\\cstdlib"





#line 13 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocnum"
#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\xiosbase"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\xiosbase"



#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocale"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocale"




#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\cstring"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\cstring"








 #line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\string.h"















#pragma once
#line 18 "c:\\program files\\microsoft visual studio\\vc98\\include\\string.h"






#line 25 "c:\\program files\\microsoft visual studio\\vc98\\include\\string.h"



extern "C" {
#line 30 "c:\\program files\\microsoft visual studio\\vc98\\include\\string.h"

















#line 48 "c:\\program files\\microsoft visual studio\\vc98\\include\\string.h"























#line 72 "c:\\program files\\microsoft visual studio\\vc98\\include\\string.h"




#line 77 "c:\\program files\\microsoft visual studio\\vc98\\include\\string.h"
























        void *  __cdecl memcpy(void *, const void *, size_t);
        int     __cdecl memcmp(const void *, const void *, size_t);
        void *  __cdecl memset(void *, int, size_t);
        char *  __cdecl _strset(char *, int);
        char *  __cdecl strcpy(char *, const char *);
        char *  __cdecl strcat(char *, const char *);
        int     __cdecl strcmp(const char *, const char *);
        size_t  __cdecl strlen(const char *);
#line 110 "c:\\program files\\microsoft visual studio\\vc98\\include\\string.h"
 void *  __cdecl _memccpy(void *, const void *, int, unsigned int);
 void *  __cdecl memchr(const void *, int, size_t);
 int     __cdecl _memicmp(const void *, const void *, unsigned int);





 void *  __cdecl memmove(void *, const void *, size_t);
#line 120 "c:\\program files\\microsoft visual studio\\vc98\\include\\string.h"


 char *  __cdecl strchr(const char *, int);
 int     __cdecl _strcmpi(const char *, const char *);
 int     __cdecl _stricmp(const char *, const char *);
 int     __cdecl strcoll(const char *, const char *);
 int     __cdecl _stricoll(const char *, const char *);
 int     __cdecl _strncoll(const char *, const char *, size_t);
 int     __cdecl _strnicoll(const char *, const char *, size_t);
 size_t  __cdecl strcspn(const char *, const char *);
 char *  __cdecl _strdup(const char *);
 char *  __cdecl _strerror(const char *);
 char *  __cdecl strerror(int);
 char *  __cdecl _strlwr(char *);
 char *  __cdecl strncat(char *, const char *, size_t);
 int     __cdecl strncmp(const char *, const char *, size_t);
 int     __cdecl _strnicmp(const char *, const char *, size_t);
 char *  __cdecl strncpy(char *, const char *, size_t);
 char *  __cdecl _strnset(char *, int, size_t);
 char *  __cdecl strpbrk(const char *, const char *);
 char *  __cdecl strrchr(const char *, int);
 char *  __cdecl _strrev(char *);
 size_t  __cdecl strspn(const char *, const char *);
 char *  __cdecl strstr(const char *, const char *);
 char *  __cdecl strtok(char *, const char *);
 char *  __cdecl _strupr(char *);
 size_t  __cdecl strxfrm (char *, const char *, size_t);














 void * __cdecl memccpy(void *, const void *, int, unsigned int);
 int __cdecl memicmp(const void *, const void *, unsigned int);
 int __cdecl strcmpi(const char *, const char *);
 int __cdecl stricmp(const char *, const char *);
 char * __cdecl strdup(const char *);
 char * __cdecl strlwr(char *);
 int __cdecl strnicmp(const char *, const char *, size_t);
 char * __cdecl strnset(char *, int, size_t);
 char * __cdecl strrev(char *);
        char * __cdecl strset(char *, int);
 char * __cdecl strupr(char *);

#line 174 "c:\\program files\\microsoft visual studio\\vc98\\include\\string.h"







 wchar_t * __cdecl wcscat(wchar_t *, const wchar_t *);
 wchar_t * __cdecl wcschr(const wchar_t *, wchar_t);
 int __cdecl wcscmp(const wchar_t *, const wchar_t *);
 wchar_t * __cdecl wcscpy(wchar_t *, const wchar_t *);
 size_t __cdecl wcscspn(const wchar_t *, const wchar_t *);
 size_t __cdecl wcslen(const wchar_t *);
 wchar_t * __cdecl wcsncat(wchar_t *, const wchar_t *, size_t);
 int __cdecl wcsncmp(const wchar_t *, const wchar_t *, size_t);
 wchar_t * __cdecl wcsncpy(wchar_t *, const wchar_t *, size_t);
 wchar_t * __cdecl wcspbrk(const wchar_t *, const wchar_t *);
 wchar_t * __cdecl wcsrchr(const wchar_t *, wchar_t);
 size_t __cdecl wcsspn(const wchar_t *, const wchar_t *);
 wchar_t * __cdecl wcsstr(const wchar_t *, const wchar_t *);
 wchar_t * __cdecl wcstok(wchar_t *, const wchar_t *);

 wchar_t * __cdecl _wcsdup(const wchar_t *);
 int __cdecl _wcsicmp(const wchar_t *, const wchar_t *);
 int __cdecl _wcsnicmp(const wchar_t *, const wchar_t *, size_t);
 wchar_t * __cdecl _wcsnset(wchar_t *, wchar_t, size_t);
 wchar_t * __cdecl _wcsrev(wchar_t *);
 wchar_t * __cdecl _wcsset(wchar_t *, wchar_t);

 wchar_t * __cdecl _wcslwr(wchar_t *);
 wchar_t * __cdecl _wcsupr(wchar_t *);
 size_t __cdecl wcsxfrm(wchar_t *, const wchar_t *, size_t);
 int __cdecl wcscoll(const wchar_t *, const wchar_t *);
 int __cdecl _wcsicoll(const wchar_t *, const wchar_t *);
 int __cdecl _wcsncoll(const wchar_t *, const wchar_t *, size_t);
 int __cdecl _wcsnicoll(const wchar_t *, const wchar_t *, size_t);







 wchar_t * __cdecl wcsdup(const wchar_t *);
 int __cdecl wcsicmp(const wchar_t *, const wchar_t *);
 int __cdecl wcsnicmp(const wchar_t *, const wchar_t *, size_t);
 wchar_t * __cdecl wcsnset(wchar_t *, wchar_t, size_t);
 wchar_t * __cdecl wcsrev(wchar_t *);
 wchar_t * __cdecl wcsset(wchar_t *, wchar_t);
 wchar_t * __cdecl wcslwr(wchar_t *);
 wchar_t * __cdecl wcsupr(wchar_t *);
 int __cdecl wcsicoll(const wchar_t *, const wchar_t *);

#line 228 "c:\\program files\\microsoft visual studio\\vc98\\include\\string.h"


#line 231 "c:\\program files\\microsoft visual studio\\vc98\\include\\string.h"

#line 233 "c:\\program files\\microsoft visual studio\\vc98\\include\\string.h"


}
#line 237 "c:\\program files\\microsoft visual studio\\vc98\\include\\string.h"

#line 239 "c:\\program files\\microsoft visual studio\\vc98\\include\\string.h"
#line 15 "c:\\program files\\microsoft visual studio\\vc98\\include\\cstring"
#line 16 "c:\\program files\\microsoft visual studio\\vc98\\include\\cstring"
#line 17 "c:\\program files\\microsoft visual studio\\vc98\\include\\cstring"





#line 11 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocale"
#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdexcept"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdexcept"



#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\exception"
















#pragma once
#line 19 "c:\\program files\\microsoft visual studio\\vc98\\include\\exception"



#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\xstddef"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\xstddef"




 #line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\yvals.h"



#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\use_ansi.h"















#pragma once
#line 18 "c:\\program files\\microsoft visual studio\\vc98\\include\\use_ansi.h"






















#pragma comment(lib,"libcpd")


#line 44 "c:\\program files\\microsoft visual studio\\vc98\\include\\use_ansi.h"
#line 45 "c:\\program files\\microsoft visual studio\\vc98\\include\\use_ansi.h"

#line 47 "c:\\program files\\microsoft visual studio\\vc98\\include\\use_ansi.h"
#line 5 "c:\\program files\\microsoft visual studio\\vc98\\include\\yvals.h"











#pragma pack(push,8)
#line 18 "c:\\program files\\microsoft visual studio\\vc98\\include\\yvals.h"

 #pragma warning(4: 4018 4114 4146 4244 4245)
 #pragma warning(4: 4663 4664 4665)
 #pragma warning(disable: 4237 4284 4290 4514)
		
 
  
  
  
  
 



#line 33 "c:\\program files\\microsoft visual studio\\vc98\\include\\yvals.h"
namespace std {
		
 
typedef bool _Bool;
 #line 38 "c:\\program files\\microsoft visual studio\\vc98\\include\\yvals.h"
		



		






		
 
  
  
 


#line 57 "c:\\program files\\microsoft visual studio\\vc98\\include\\yvals.h"

		
 
class  _Lockit
	{	
public:
  




   
	_Lockit()
		{}
	~_Lockit()
		{}
  #line 74 "c:\\program files\\microsoft visual studio\\vc98\\include\\yvals.h"
	};
 #line 76 "c:\\program files\\microsoft visual studio\\vc98\\include\\yvals.h"
		




};

#pragma pack(pop)
#line 85 "c:\\program files\\microsoft visual studio\\vc98\\include\\yvals.h"

#line 87 "c:\\program files\\microsoft visual studio\\vc98\\include\\yvals.h"





#line 11 "c:\\program files\\microsoft visual studio\\vc98\\include\\xstddef"
#line 12 "c:\\program files\\microsoft visual studio\\vc98\\include\\xstddef"
#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\cstddef"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\cstddef"




 
 #line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\stddef.h"















#pragma once
#line 18 "c:\\program files\\microsoft visual studio\\vc98\\include\\stddef.h"






#line 25 "c:\\program files\\microsoft visual studio\\vc98\\include\\stddef.h"



extern "C" {
#line 30 "c:\\program files\\microsoft visual studio\\vc98\\include\\stddef.h"

















#line 48 "c:\\program files\\microsoft visual studio\\vc98\\include\\stddef.h"































#line 80 "c:\\program files\\microsoft visual studio\\vc98\\include\\stddef.h"
 extern int errno;
#line 82 "c:\\program files\\microsoft visual studio\\vc98\\include\\stddef.h"





typedef int ptrdiff_t;

#line 90 "c:\\program files\\microsoft visual studio\\vc98\\include\\stddef.h"






















}
#line 114 "c:\\program files\\microsoft visual studio\\vc98\\include\\stddef.h"

#line 116 "c:\\program files\\microsoft visual studio\\vc98\\include\\stddef.h"
#line 12 "c:\\program files\\microsoft visual studio\\vc98\\include\\cstddef"
 


#line 16 "c:\\program files\\microsoft visual studio\\vc98\\include\\cstddef"
#line 17 "c:\\program files\\microsoft visual studio\\vc98\\include\\cstddef"





#line 13 "c:\\program files\\microsoft visual studio\\vc98\\include\\xstddef"











#pragma pack(push,8)
#line 26 "c:\\program files\\microsoft visual studio\\vc98\\include\\xstddef"
namespace std {
		
 
 
 
 
 
 
 
 
 
		
		
 
 
		


 
 
 
 
 
		
enum _Uninitialized {_Noinit};
		
 void __cdecl _Nomemory();
};

#pragma pack(pop)
#line 57 "c:\\program files\\microsoft visual studio\\vc98\\include\\xstddef"

#line 59 "c:\\program files\\microsoft visual studio\\vc98\\include\\xstddef"





#line 23 "c:\\program files\\microsoft visual studio\\vc98\\include\\exception"
#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\eh.h"













#pragma once
#line 16 "c:\\program files\\microsoft visual studio\\vc98\\include\\eh.h"






#line 23 "c:\\program files\\microsoft visual studio\\vc98\\include\\eh.h"





#pragma pack(push,8)
#line 30 "c:\\program files\\microsoft visual studio\\vc98\\include\\eh.h"


























typedef void (__cdecl *terminate_function)();
typedef void (__cdecl *unexpected_function)();
typedef void (__cdecl *terminate_handler)();
typedef void (__cdecl *unexpected_handler)();


struct _EXCEPTION_POINTERS;
typedef void (__cdecl *_se_translator_function)(unsigned int, struct _EXCEPTION_POINTERS*);
#line 65 "c:\\program files\\microsoft visual studio\\vc98\\include\\eh.h"


 __declspec(noreturn) void __cdecl terminate(void);
 __declspec(noreturn) void __cdecl unexpected(void);



#line 73 "c:\\program files\\microsoft visual studio\\vc98\\include\\eh.h"

 terminate_function __cdecl set_terminate(terminate_function);
 unexpected_function __cdecl set_unexpected(unexpected_function);

 _se_translator_function __cdecl _set_se_translator(_se_translator_function);
#line 79 "c:\\program files\\microsoft visual studio\\vc98\\include\\eh.h"


#pragma pack(pop)
#line 83 "c:\\program files\\microsoft visual studio\\vc98\\include\\eh.h"

#line 85 "c:\\program files\\microsoft visual studio\\vc98\\include\\eh.h"
#line 24 "c:\\program files\\microsoft visual studio\\vc98\\include\\exception"


#pragma pack(push,8)
#line 28 "c:\\program files\\microsoft visual studio\\vc98\\include\\exception"

 

#line 32 "c:\\program files\\microsoft visual studio\\vc98\\include\\exception"















typedef const char *__exString;

class  exception
{
public:
    exception();
    exception(const __exString&);
    exception(const exception&);
    exception& operator= (const exception&);
    virtual ~exception();
    virtual __exString what() const;
private:
    __exString _m_what;
    int _m_doFree;
};
namespace std {
using ::exception;

		
class  bad_exception : public exception {
public:
	bad_exception(const char *_S = "bad exception") throw ()
		: exception(_S) {}
	virtual ~bad_exception() throw ()
		{}
protected:
	virtual void _Doraise() const
		{throw (*this); }
	};

 bool __cdecl uncaught_exception();

};






#pragma pack(pop)
#line 88 "c:\\program files\\microsoft visual studio\\vc98\\include\\exception"

#line 90 "c:\\program files\\microsoft visual studio\\vc98\\include\\exception"






#line 10 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdexcept"
#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\xstring"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\xstring"



#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\xmemory"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\xmemory"




#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\new"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\new"






#pragma pack(push,8)
#line 14 "c:\\program files\\microsoft visual studio\\vc98\\include\\new"
namespace std {
		
class  bad_alloc : public exception {
public:
	bad_alloc(const char *_S = "bad allocation") throw ()
		: exception(_S) {}
	virtual ~bad_alloc() throw ()
		{}
protected:
	virtual void _Doraise() const
		{throw (*this); }
	};
		
struct nothrow_t {};
extern  const nothrow_t nothrow;
};

typedef void (__cdecl *new_handler)();

		
void __cdecl operator delete(void *) throw ();
void *__cdecl operator new("c:\\program files\\microsoft visual studio\\vc98\\include\\new", 35)(size_t) throw (std::bad_alloc);
void *__cdecl operator new("c:\\program files\\microsoft visual studio\\vc98\\include\\new", 36)(size_t, const std::nothrow_t&)
	throw ();



inline void *__cdecl operator new("c:\\program files\\microsoft visual studio\\vc98\\include\\new", 41)(size_t, void *_P)
	{return (_P); }

inline void __cdecl operator delete(void *, void *)
	{return; }
#line 47 "c:\\program files\\microsoft visual studio\\vc98\\include\\new"
#line 48 "c:\\program files\\microsoft visual studio\\vc98\\include\\new"



#line 52 "c:\\program files\\microsoft visual studio\\vc98\\include\\new"
	new_handler __cdecl set_new_handler(new_handler) throw ();


#pragma pack(pop)
#line 57 "c:\\program files\\microsoft visual studio\\vc98\\include\\new"

#line 59 "c:\\program files\\microsoft visual studio\\vc98\\include\\new"





#line 11 "c:\\program files\\microsoft visual studio\\vc98\\include\\xmemory"


#pragma pack(push,8)
#line 15 "c:\\program files\\microsoft visual studio\\vc98\\include\\xmemory"
 #line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\utility"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\utility"



#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\iosfwd"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\iosfwd"





#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\cwchar"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\cwchar"




 
 #line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"


















#pragma once
#line 21 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"









#line 31 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"



#pragma pack(push,8)
#line 36 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"


extern "C" {
#line 40 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"

























#line 66 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"


















typedef long time_t;

#line 87 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"






















































typedef unsigned long _fsize_t; 

#line 144 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"



struct _wfinddata_t {
        unsigned attrib;
        time_t   time_create;   
        time_t   time_access;   
        time_t   time_write;
        _fsize_t size;
        wchar_t  name[260];
};



struct _wfinddatai64_t {
        unsigned attrib;
        time_t   time_create;   
        time_t   time_access;   
        time_t   time_write;
        __int64  size;
        wchar_t  name[260];
};
#line 167 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"
#line 168 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"


#line 171 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"













 extern unsigned short _ctype[];
 extern unsigned short *_pctype;

 extern wctype_t *_pwctype;
#line 189 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"
#line 190 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"








                                
















 int __cdecl iswalpha(wint_t);
 int __cdecl iswupper(wint_t);
 int __cdecl iswlower(wint_t);
 int __cdecl iswdigit(wint_t);
 int __cdecl iswxdigit(wint_t);
 int __cdecl iswspace(wint_t);
 int __cdecl iswpunct(wint_t);
 int __cdecl iswalnum(wint_t);
 int __cdecl iswprint(wint_t);
 int __cdecl iswgraph(wint_t);
 int __cdecl iswcntrl(wint_t);
 int __cdecl iswascii(wint_t);
 int __cdecl isleadbyte(int);

 wchar_t __cdecl towupper(wchar_t);
 wchar_t __cdecl towlower(wchar_t);

 int __cdecl iswctype(wint_t, wctype_t);


 int __cdecl is_wctype(wint_t, wctype_t);



#line 240 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"





 int __cdecl _wchdir(const wchar_t *);
 wchar_t * __cdecl _wgetcwd(wchar_t *, int);
 wchar_t * __cdecl _wgetdcwd(int, wchar_t *, int);
 int __cdecl _wmkdir(const wchar_t *);
 int __cdecl _wrmdir(const wchar_t *);


#line 253 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"





 int __cdecl _waccess(const wchar_t *, int);
 int __cdecl _wchmod(const wchar_t *, int);
 int __cdecl _wcreat(const wchar_t *, int);
 long __cdecl _wfindfirst(wchar_t *, struct _wfinddata_t *);
 int __cdecl _wfindnext(long, struct _wfinddata_t *);
 int __cdecl _wunlink(const wchar_t *);
 int __cdecl _wrename(const wchar_t *, const wchar_t *);
 int __cdecl _wopen(const wchar_t *, int, ...);
 int __cdecl _wsopen(const wchar_t *, int, int, ...);
 wchar_t * __cdecl _wmktemp(wchar_t *);


 long __cdecl _wfindfirsti64(wchar_t *, struct _wfinddatai64_t *);
 int __cdecl _wfindnexti64(long, struct _wfinddatai64_t *);
#line 273 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"


#line 276 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"





 wchar_t * __cdecl _wsetlocale(int, const wchar_t *);


#line 285 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"





 int __cdecl _wexecl(const wchar_t *, const wchar_t *, ...);
 int __cdecl _wexecle(const wchar_t *, const wchar_t *, ...);
 int __cdecl _wexeclp(const wchar_t *, const wchar_t *, ...);
 int __cdecl _wexeclpe(const wchar_t *, const wchar_t *, ...);
 int __cdecl _wexecv(const wchar_t *, const wchar_t * const *);
 int __cdecl _wexecve(const wchar_t *, const wchar_t * const *, const wchar_t * const *);
 int __cdecl _wexecvp(const wchar_t *, const wchar_t * const *);
 int __cdecl _wexecvpe(const wchar_t *, const wchar_t * const *, const wchar_t * const *);
 int __cdecl _wspawnl(int, const wchar_t *, const wchar_t *, ...);
 int __cdecl _wspawnle(int, const wchar_t *, const wchar_t *, ...);
 int __cdecl _wspawnlp(int, const wchar_t *, const wchar_t *, ...);
 int __cdecl _wspawnlpe(int, const wchar_t *, const wchar_t *, ...);
 int __cdecl _wspawnv(int, const wchar_t *, const wchar_t * const *);
 int __cdecl _wspawnve(int, const wchar_t *, const wchar_t * const *,
        const wchar_t * const *);
 int __cdecl _wspawnvp(int, const wchar_t *, const wchar_t * const *);
 int __cdecl _wspawnvpe(int, const wchar_t *, const wchar_t * const *,
        const wchar_t * const *);
 int __cdecl _wsystem(const wchar_t *);


#line 312 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"





















inline int __cdecl iswalpha(wint_t _C) {return (iswctype(_C,(0x0100|0x1|0x2))); }
inline int __cdecl iswupper(wint_t _C) {return (iswctype(_C,0x1)); }
inline int __cdecl iswlower(wint_t _C) {return (iswctype(_C,0x2)); }
inline int __cdecl iswdigit(wint_t _C) {return (iswctype(_C,0x4)); }
inline int __cdecl iswxdigit(wint_t _C) {return (iswctype(_C,0x80)); }
inline int __cdecl iswspace(wint_t _C) {return (iswctype(_C,0x8)); }
inline int __cdecl iswpunct(wint_t _C) {return (iswctype(_C,0x10)); }
inline int __cdecl iswalnum(wint_t _C) {return (iswctype(_C,(0x0100|0x1|0x2)|0x4)); }
inline int __cdecl iswprint(wint_t _C)
        {return (iswctype(_C,0x40|0x10|(0x0100|0x1|0x2)|0x4)); }
inline int __cdecl iswgraph(wint_t _C)
        {return (iswctype(_C,0x10|(0x0100|0x1|0x2)|0x4)); }
inline int __cdecl iswcntrl(wint_t _C) {return (iswctype(_C,0x20)); }
inline int __cdecl iswascii(wint_t _C) {return ((unsigned)(_C) < 0x80); }


inline int __cdecl isleadbyte(int _C)
        {return (_pctype[(unsigned char)(_C)] & 0x8000); }
#line 352 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"
#line 353 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"

#line 355 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"







typedef unsigned short _ino_t;      


typedef unsigned short ino_t;
#line 367 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"

#line 369 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"


typedef unsigned int _dev_t;        


typedef unsigned int dev_t;
#line 376 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"

#line 378 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"


typedef long _off_t;                


typedef long off_t;
#line 385 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"

#line 387 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"



struct _stat {
        _dev_t st_dev;
        _ino_t st_ino;
        unsigned short st_mode;
        short st_nlink;
        short st_uid;
        short st_gid;
        _dev_t st_rdev;
        _off_t st_size;
        time_t st_atime;
        time_t st_mtime;
        time_t st_ctime;
        };



struct stat {
        _dev_t st_dev;
        _ino_t st_ino;
        unsigned short st_mode;
        short st_nlink;
        short st_uid;
        short st_gid;
        _dev_t st_rdev;
        _off_t st_size;
        time_t st_atime;
        time_t st_mtime;
        time_t st_ctime;
        };
#line 420 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"


struct _stati64 {
        _dev_t st_dev;
        _ino_t st_ino;
        unsigned short st_mode;
        short st_nlink;
        short st_uid;
        short st_gid;
        _dev_t st_rdev;
        __int64 st_size;
        time_t st_atime;
        time_t st_mtime;
        time_t st_ctime;
        };
#line 436 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"


#line 439 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"






 int __cdecl _wstat(const wchar_t *, struct _stat *);


 int __cdecl _wstati64(const wchar_t *, struct _stati64 *);
#line 450 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"


#line 453 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"

#line 455 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"








































































































#line 560 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"






























































struct tm {
        int tm_sec;     
        int tm_min;     
        int tm_hour;    
        int tm_mday;    
        int tm_mon;     
        int tm_year;    
        int tm_wday;    
        int tm_yday;    
        int tm_isdst;   
        };

#line 635 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"





 wchar_t * __cdecl _wasctime(const struct tm *);
 wchar_t * __cdecl _wctime(const time_t *);
 size_t __cdecl wcsftime(wchar_t *, size_t, const wchar_t *,
        const struct tm *);
 wchar_t * __cdecl _wstrdate(wchar_t *);
 wchar_t * __cdecl _wstrtime(wchar_t *);


#line 649 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"



typedef int mbstate_t;
typedef wchar_t _Wint_t;

 wint_t __cdecl btowc(int);
 size_t __cdecl mbrlen(const char *, size_t, mbstate_t *);
 size_t __cdecl mbrtowc(wchar_t *, const char *, size_t, mbstate_t *);
 size_t __cdecl mbsrtowcs(wchar_t *, const char **, size_t, mbstate_t *);

 size_t __cdecl wcrtomb(char *, wchar_t, mbstate_t *);
 size_t __cdecl wcsrtombs(char *, const wchar_t **, size_t, mbstate_t *);
 int __cdecl wctob(wint_t);


inline int fwide(FILE *, int _M)
        {return (_M); }
inline int mbsinit(const mbstate_t *)
        {return (1); }
inline const wchar_t *wmemchr(const wchar_t *_S, wchar_t _C, size_t _N)
        {for (; 0 < _N; ++_S, --_N)
                if (*_S == _C)
                        return (_S);
        return (0); }
inline int wmemcmp(const wchar_t *_S1, const wchar_t *_S2, size_t _N)
        {for (; 0 < _N; ++_S1, ++_S2, --_N)
                if (*_S1 != *_S2)
                        return (*_S1 < *_S2 ? -1 : +1);
        return (0); }
inline wchar_t *wmemcpy(wchar_t *_S1, const wchar_t *_S2, size_t _N)
        {wchar_t *_Su1 = _S1;
        for (; 0 < _N; ++_Su1, ++_S2, --_N)
                *_Su1 = *_S2;
        return (_S1); }
inline wchar_t *wmemmove(wchar_t *_S1, const wchar_t *_S2, size_t _N)
        {wchar_t *_Su1 = _S1;
        if (_S2 < _Su1 && _Su1 < _S2 + _N)
                for (_Su1 += _N, _S2 += _N; 0 < _N; --_N)
                        *--_Su1 = *--_S2;
        else
                for (; 0 < _N; --_N)
                        *_Su1++ = *_S2++;
        return (_S1); }
inline wchar_t *wmemset(wchar_t *_S, wchar_t _C, size_t _N)
        {wchar_t *_Su = _S;
        for (; 0 < _N; ++_Su, --_N)
                *_Su = _C;
        return (_S); }
}       
inline wchar_t *wmemchr(wchar_t *_S, wchar_t _C, size_t _N)
        {return ((wchar_t *)wmemchr((const wchar_t *)_S, _C, _N)); }
inline wchar_t *wcschr(wchar_t *_S, wchar_t _C)
        {return ((wchar_t *)wcschr((const wchar_t *)_S, _C)); }
inline wchar_t *wcspbrk(wchar_t *_S, const wchar_t *_P)
        {return ((wchar_t *)wcspbrk((const wchar_t *)_S, _P)); }
inline wchar_t *wcsrchr(wchar_t *_S, wchar_t _C)
        {return ((wchar_t *)wcsrchr((const wchar_t *)_S, _C)); }
inline wchar_t *wcsstr(wchar_t *_S, const wchar_t *_P)
        {return ((wchar_t *)wcsstr((const wchar_t *)_S, _P)); }
#line 710 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"


#pragma pack(pop)
#line 714 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"

#line 716 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"













#line 730 "c:\\program files\\microsoft visual studio\\vc98\\include\\wchar.h"
#line 12 "c:\\program files\\microsoft visual studio\\vc98\\include\\cwchar"
 


#line 16 "c:\\program files\\microsoft visual studio\\vc98\\include\\cwchar"
#line 17 "c:\\program files\\microsoft visual studio\\vc98\\include\\cwchar"





#line 12 "c:\\program files\\microsoft visual studio\\vc98\\include\\iosfwd"



#pragma pack(push,8)
#line 17 "c:\\program files\\microsoft visual studio\\vc98\\include\\iosfwd"
namespace std {
                
typedef long streamoff;
const streamoff _BADOFF = -1;
typedef int streamsize;
extern  const fpos_t _Fpz;
                
template<class _St>
        class fpos {
        typedef fpos<_St> _Myt;
public:






        fpos(streamoff _O = 0)
                : _Off(_O), _Fpos(_Fpz), _State(_Stz) {}
#line 37 "c:\\program files\\microsoft visual studio\\vc98\\include\\iosfwd"
        fpos(_St _S, fpos_t _F)
                : _Off(0), _Fpos(_F), _State(_S) {}
        _St state() const
                {return (_State); }
        void state(_St _S)
                {_State = _S; }
        fpos_t get_fpos_t() const
                {return (_Fpos); }
        operator streamoff() const
                {return (_Off + ((long)(_Fpos))); }
        streamoff operator-(const _Myt& _R) const
                {return ((streamoff)*this - (streamoff)_R); }
        _Myt& operator+=(streamoff _O)
                {_Off += _O;
                return (*this); }
        _Myt& operator-=(streamoff _O)
                {_Off -= _O;
                return (*this); }
        _Myt operator+(streamoff _O) const
                {_Myt _Tmp = *this;
                return (_Tmp += _O); }
        _Myt operator-(streamoff _O) const
                {_Myt _Tmp = *this;
                return (_Tmp -= _O); }
        bool operator==(const _Myt& _R) const
                {return ((streamoff)*this == (streamoff)_R); }
        bool operator!=(const _Myt& _R) const
                {return (!(*this == _R)); }
private:
        static _St _Stz;
        streamoff _Off;
        fpos_t _Fpos;
        _St _State;
        };
template<class _St>
        _St fpos<_St>::_Stz;
typedef fpos<mbstate_t> streampos;
typedef streampos wstreampos;
                
template<class _E>
        struct char_traits {
        typedef _E char_type;
        typedef _E int_type;
        typedef streampos pos_type;
        typedef streamoff off_type;
        typedef mbstate_t state_type;
        static void __cdecl assign(_E& _X, const _E& _Y)
                {_X = _Y; }
        static bool __cdecl eq(const _E& _X, const _E& _Y)
                {return (_X == _Y); }
        static bool __cdecl lt(const _E& _X, const _E& _Y)
                {return (_X < _Y); }
        static int __cdecl compare(const _E *_U, const _E *_V, size_t _N)
                {for (size_t _I = 0; _I < _N; ++_I, ++_U, ++_V)
                        if (!eq(*_U, *_V))
                                return (lt(*_U, *_V) ? -1 : +1);
                return (0); }
        static size_t __cdecl length(const _E *_U)
                {size_t _N;
                for (_N = 0; !eq(*_U, _E(0)); ++_U)
                        ++_N;
                return (_N); }
        static _E * __cdecl copy(_E *_U, const _E *_V, size_t _N)
                {_E *_S = _U;
                for (; 0 < _N; --_N, ++_U, ++_V)
                        assign(*_U, *_V);
                return (_S); }
        static const _E * __cdecl find(const _E *_U, size_t _N,
                const _E& _C)
                {for (; 0 < _N; --_N, ++_U)
                        if (eq(*_U, _C))
                                return (_U);
                return (0); }
        static _E * __cdecl move(_E *_U, const _E *_V, size_t _N)
                {_E *_Ans = _U;
                if (_V < _U && _U < _V + _N)
                        for (_U += _N, _V += _N; 0 < _N; --_N)
                                assign(*--_U, *--_V);
                else
                        for (; 0 < _N; --_N, ++_U, ++_V)
                                assign(*_U, *_V);
                return (_Ans); }
        static _E * __cdecl assign(_E *_U, size_t _N, const _E& _C)
                {_E *_Ans = _U;
                for (; 0 < _N; --_N, ++_U)
                        assign(*_U, _C);
                return (_Ans); }
        static _E __cdecl to_char_type(const int_type& _C)
                {return ((_E)_C); }
        static int_type __cdecl to_int_type(const _E& _C)
                {return ((int_type)_C); }
        static bool __cdecl eq_int_type(const int_type& _X,
                const int_type& _Y)
                {return (_X == _Y); }
        static int_type __cdecl eof()
                {return ((-1)); }
        static int_type __cdecl not_eof(const int_type& _C)
                {return (_C != eof() ? _C : !eof()); }
        };
                
template<> struct  char_traits<wchar_t> {
        typedef wchar_t _E;
        typedef _E char_type;   
        typedef wint_t int_type;
        typedef streampos pos_type;
        typedef streamoff off_type;
        typedef mbstate_t state_type;
        static void __cdecl assign(_E& _X, const _E& _Y)
                {_X = _Y; }
        static bool __cdecl eq(const _E& _X, const _E& _Y)
                {return (_X == _Y); }
        static bool __cdecl lt(const _E& _X, const _E& _Y)
                {return (_X < _Y); }
        static int __cdecl compare(const _E *_U, const _E *_V, size_t _N)
                {return (wmemcmp(_U, _V, _N)); }
        static size_t __cdecl length(const _E *_U)
                {return (wcslen(_U)); }
        static _E *__cdecl copy(_E *_U, const _E *_V, size_t _N)
                {return (wmemcpy(_U, _V, _N)); }
        static const _E * __cdecl find(const _E *_U, size_t _N,
                const _E& _C)
                {return ((const _E *)wmemchr(_U, _C, _N)); }
        static _E * __cdecl move(_E *_U, const _E *_V, size_t _N)
                {return (wmemmove(_U, _V, _N)); }
        static _E * __cdecl assign(_E *_U, size_t _N, const _E& _C)
                {return (wmemset(_U, _C, _N)); }
        static _E __cdecl to_char_type(const int_type& _C)
                {return ((_E)_C); }
        static int_type __cdecl to_int_type(const _E& _C)
                {return ((int_type)_C); }
        static bool __cdecl eq_int_type(const int_type& _X,
                const int_type& _Y)
                {return (_X == _Y); }
        static int_type __cdecl eof()
                {return ((wint_t)(0xFFFF)); }
        static int_type __cdecl not_eof(const int_type& _C)
                {return (_C != eof() ? _C : !eof()); }
        };
                
template<> struct  char_traits<char> {
        typedef char _E;
        typedef _E char_type;
        typedef int int_type;
        typedef streampos pos_type;
        typedef streamoff off_type;
        typedef mbstate_t state_type;
        static void __cdecl assign(_E& _X, const _E& _Y)
                {_X = _Y; }
        static bool __cdecl eq(const _E& _X, const _E& _Y)
                {return (_X == _Y); }
        static bool __cdecl lt(const _E& _X, const _E& _Y)
                {return (_X < _Y); }
        static int __cdecl compare(const _E *_U, const _E *_V, size_t _N)
                {return (memcmp(_U, _V, _N)); }
        static size_t __cdecl length(const _E *_U)
                {return (strlen(_U)); }
        static _E * __cdecl copy(_E *_U, const _E *_V, size_t _N)
                {return ((_E *)memcpy(_U, _V, _N)); }
        static const _E * __cdecl find(const _E *_U, size_t _N,
                const _E& _C)
                {return ((const _E *)memchr(_U, _C, _N)); }
        static _E * __cdecl move(_E *_U, const _E *_V, size_t _N)
                {return ((_E *)memmove(_U, _V, _N)); }
        static _E * __cdecl assign(_E *_U, size_t _N, const _E& _C)
                {return ((_E *)memset(_U, _C, _N)); }
        static _E __cdecl to_char_type(const int_type& _C)
                {return ((_E)_C); }
        static int_type __cdecl to_int_type(const _E& _C)
                {return ((int_type)((unsigned char)_C)); }
        static bool __cdecl eq_int_type(const int_type& _X,
                const int_type& _Y)
                {return (_X == _Y); }
        static int_type __cdecl eof()
                {return ((-1)); }
        static int_type __cdecl not_eof(const int_type& _C)
                {return (_C != eof() ? _C : !eof()); }
        };
                
template<class T>
        class allocator;
class ios_base;
template<class _E, class _Tr = char_traits<_E> >
        class basic_ios;
template<class _E, class _Tr = char_traits<_E> >
        class istreambuf_iterator;
template<class _E, class _Tr = char_traits<_E> >
        class ostreambuf_iterator;
template<class _E, class _Tr = char_traits<_E> >
        class basic_streambuf;
template<class _E, class _Tr = char_traits<_E> >
        class basic_istream;
template<class _E, class _Tr = char_traits<_E> >
        class basic_ostream;
template<class _E, class _Tr = char_traits<_E> >
        class basic_iostream;
template<class _E, class _Tr = char_traits<_E>,
        class _A = allocator<_E> >
        class basic_stringbuf;
template<class _E, class _Tr = char_traits<_E>,
        class _A = allocator<_E> >
        class basic_istringstream;
template<class _E, class _Tr = char_traits<_E>,
        class _A = allocator<_E> >
        class basic_ostringstream;
template<class _E, class _Tr = char_traits<_E>,
        class _A = allocator<_E> >
        class basic_stringstream;
template<class _E, class _Tr = char_traits<_E> >
        class basic_filebuf;
template<class _E, class _Tr = char_traits<_E> >
        class basic_ifstream;
template<class _E, class _Tr = char_traits<_E> >
        class basic_ofstream;
template<class _E, class _Tr = char_traits<_E> >
        class basic_fstream;

                
typedef basic_ios<char, char_traits<char> > ios;
typedef basic_streambuf<char, char_traits<char> > streambuf;
typedef basic_istream<char, char_traits<char> > istream;
typedef basic_ostream<char, char_traits<char> > ostream;
typedef basic_iostream<char, char_traits<char> > iostream;
typedef basic_stringbuf<char, char_traits<char>,
        allocator<char> > stringbuf;
typedef basic_istringstream<char, char_traits<char>,
        allocator<char> > istringstream;
typedef basic_ostringstream<char, char_traits<char>,
        allocator<char> > ostringstream;
typedef basic_stringstream<char, char_traits<char>,
        allocator<char> > stringstream;
typedef basic_filebuf<char, char_traits<char> > filebuf;
typedef basic_ifstream<char, char_traits<char> > ifstream;
typedef basic_ofstream<char, char_traits<char> > ofstream;
typedef basic_fstream<char, char_traits<char> > fstream;
                
typedef basic_ios<wchar_t, char_traits<wchar_t> > wios;
typedef basic_streambuf<wchar_t, char_traits<wchar_t> >
        wstreambuf;
typedef basic_istream<wchar_t, char_traits<wchar_t> > wistream;
typedef basic_ostream<wchar_t, char_traits<wchar_t> > wostream;
typedef basic_iostream<wchar_t, char_traits<wchar_t> > wiostream;
typedef basic_stringbuf<wchar_t, char_traits<wchar_t>,
        allocator<wchar_t> > wstringbuf;
typedef basic_istringstream<wchar_t, char_traits<wchar_t>,
        allocator<wchar_t> > wistringstream;
typedef basic_ostringstream<wchar_t, char_traits<wchar_t>,
        allocator<wchar_t> > wostringstream;
typedef basic_stringstream<wchar_t, char_traits<wchar_t>,
        allocator<wchar_t> > wstringstream;
typedef basic_filebuf<wchar_t, char_traits<wchar_t> > wfilebuf;
typedef basic_ifstream<wchar_t, char_traits<wchar_t> > wifstream;
typedef basic_ofstream<wchar_t, char_traits<wchar_t> > wofstream;
typedef basic_fstream<wchar_t, char_traits<wchar_t> > wfstream;




















};

#pragma pack(pop)
#line 314 "c:\\program files\\microsoft visual studio\\vc98\\include\\iosfwd"

#line 316 "c:\\program files\\microsoft visual studio\\vc98\\include\\iosfwd"





#line 10 "c:\\program files\\microsoft visual studio\\vc98\\include\\utility"


#pragma pack(push,8)
#line 14 "c:\\program files\\microsoft visual studio\\vc98\\include\\utility"
namespace std {
		
template<class _T1, class _T2> struct pair {
	typedef _T1 first_type;
	typedef _T2 second_type;
	pair()
		: first(_T1()), second(_T2()) {}
	pair(const _T1& _V1, const _T2& _V2)
		: first(_V1), second(_V2) {}
	template<class U, class V> pair(const pair<U, V> &p)
		: first(p.first), second(p.second) {}
	_T1 first;
	_T2 second;
	};
template<class _T1, class _T2> inline
	bool __cdecl operator==(const pair<_T1, _T2>& _X,
		const pair<_T1, _T2>& _Y)
	{return (_X.first == _Y.first && _X.second == _Y.second); }
template<class _T1, class _T2> inline
	bool __cdecl operator!=(const pair<_T1, _T2>& _X,
		const pair<_T1, _T2>& _Y)
	{return (!(_X == _Y)); }
template<class _T1, class _T2> inline
	bool __cdecl operator<(const pair<_T1, _T2>& _X,
		const pair<_T1, _T2>& _Y)
	{return (_X.first < _Y.first ||
		!(_Y.first < _X.first) && _X.second < _Y.second); }
template<class _T1, class _T2> inline
	bool __cdecl operator>(const pair<_T1, _T2>& _X,
		const pair<_T1, _T2>& _Y)
	{return (_Y < _X); }
template<class _T1, class _T2> inline
	bool __cdecl operator<=(const pair<_T1, _T2>& _X,
		const pair<_T1, _T2>& _Y)
	{return (!(_Y < _X)); }
template<class _T1, class _T2> inline
	bool __cdecl operator>=(const pair<_T1, _T2>& _X,
		const pair<_T1, _T2>& _Y)
	{return (!(_X < _Y)); }
template<class _T1, class _T2> inline
	pair<_T1, _T2> __cdecl make_pair(const _T1& _X, const _T2& _Y)
	{return (pair<_T1, _T2>(_X, _Y)); }
		
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag
	: public input_iterator_tag {};
struct bidirectional_iterator_tag
	: public forward_iterator_tag {};
struct random_access_iterator_tag
	: public bidirectional_iterator_tag  {};
		
template<class _C, class _Ty, class _D = ptrdiff_t>
	struct iterator {
	typedef _C iterator_category;
	typedef _Ty value_type;
	typedef _D distance_type;
	};
template<class _Ty, class _D>
	struct _Bidit : public iterator<bidirectional_iterator_tag,
		_Ty, _D> {};
template<class _Ty, class _D>
	struct _Ranit : public iterator<random_access_iterator_tag,
		_Ty, _D> {};
		
template<class _It>
	struct iterator_traits {
	typedef _It::iterator_category iterator_category;
	typedef _It::value_type value_type;
	typedef _It::distance_type distance_type;
	};
		
template<class _C, class _Ty, class _D> inline
	_C __cdecl _Iter_cat(const iterator<_C, _Ty, _D>&)
	{_C _IterCatTag;
	 _C* _pIterCatTag;
	_pIterCatTag = &_IterCatTag;	
	return (_IterCatTag); }
template<class _Ty> inline
	random_access_iterator_tag __cdecl _Iter_cat(const _Ty *)
	{random_access_iterator_tag _RandIterTag;
	 random_access_iterator_tag* _pRandIterTag;
	_pRandIterTag = &_RandIterTag;	
	return (_RandIterTag); }
		
template<class _II> inline
	ptrdiff_t __cdecl distance(_II _F, _II _L)
	{ptrdiff_t _N = 0;
	_Distance(_F, _L, _N, _Iter_cat(_F));
	return (_N); }
template<class _II, class _D> inline
	void __cdecl _Distance(_II _F, _II _L, _D& _N)
	{_Distance(_F, _L, _N, _Iter_cat(_F)); }
template<class _II, class _D> inline
	void __cdecl _Distance(_II _F, _II _L, _D& _N, input_iterator_tag)
	{for (; _F != _L; ++_F)
		++_N; }
template<class _II, class _D> inline
	void __cdecl _Distance(_II _F, _II _L, _D& _N, forward_iterator_tag)
	{for (; _F != _L; ++_F)
		++_N; }
template<class _II, class _D> inline
	void __cdecl _Distance(_II _F, _II _L, _D& _N,
		bidirectional_iterator_tag)
	{for (; _F != _L; ++_F)
		++_N; }
template<class _RI, class _D> inline
	void __cdecl _Distance(_RI _F, _RI _L, _D& _N,
		random_access_iterator_tag)
	{_N += _L - _F; }
		
template<class _RI,
	class _Ty,
	class _Rt = _Ty&,
	class _Pt = _Ty *,
	class _D = ptrdiff_t>
	class reverse_iterator : public _Ranit<_Ty, _D> {
public:
	typedef reverse_iterator<_RI, _Ty, _Rt, _Pt, _D> _Myt;
	typedef _RI iter_type;
	typedef _Rt reference_type;
	typedef _Pt pointer_type;
	reverse_iterator()
		{}
	explicit reverse_iterator(_RI _X)
		: current(_X) {}
	_RI base() const
		{return (current); }
	_Rt operator*() const
		{return (*(current - 1)); }
	_Pt operator->() const
		{return (&**this); }
	_Myt& operator++()
		{--current;
		return (*this); }
	_Myt operator++(int)
		{_Myt _Tmp = *this;
		--current;
		return (_Tmp); }
	_Myt& operator--()
		{++current;
		return (*this); }
	_Myt operator--(int)
		{_Myt _Tmp = *this;
		++current;
		return (_Tmp); }
	_Myt& operator+=(_D _N)
		{current -= _N;
		return (*this); }
	_Myt operator+(_D _N) const
		{return (_Myt(current - _N)); }
	_Myt& operator-=(_D _N)
		{current += _N;
		return (*this); }
	_Myt operator-(_D _N) const
		{return (_Myt(current + _N)); }
	_Rt operator[](_D _N) const
		{return (*(*this + _N)); }
protected:
	_RI current;
	};
template<class _RI, class _Ty, class _Rt, class _Pt,
	class _D> inline
	bool __cdecl operator==(
		const reverse_iterator<_RI, _Ty, _Rt, _Pt, _D>& _X,
		const reverse_iterator<_RI, _Ty, _Rt, _Pt, _D>& _Y)
	{return (_X.base() == _Y.base()); }
template<class _RI, class _Ty, class _Rt, class _Pt,
	class _D> inline
	bool __cdecl operator!=(
		const reverse_iterator<_RI, _Ty, _Rt, _Pt, _D>& _X,
		const reverse_iterator<_RI, _Ty, _Rt, _Pt, _D>& _Y)
	{return (!(_X == _Y)); }
template<class _RI, class _Ty, class _Rt, class _Pt,
	class _D> inline
	bool __cdecl operator<(
		const reverse_iterator<_RI, _Ty, _Rt, _Pt, _D>& _X,
		const reverse_iterator<_RI, _Ty, _Rt, _Pt, _D>& _Y)
	{return (_Y.base() < _X.base()); }
template<class _RI, class _Ty, class _Rt, class _Pt,
	class _D> inline
	bool __cdecl operator>(
		const reverse_iterator<_RI, _Ty, _Rt, _Pt, _D>& _X,
		const reverse_iterator<_RI, _Ty, _Rt, _Pt, _D>& _Y)
	{return (_Y < _X); }
template<class _RI, class _Ty, class _Rt, class _Pt,
	class _D> inline
	bool __cdecl operator<=(
		const reverse_iterator<_RI, _Ty, _Rt, _Pt, _D>& _X,
		const reverse_iterator<_RI, _Ty, _Rt, _Pt, _D>& _Y)
	{return (!(_Y < _X)); }
template<class _RI, class _Ty, class _Rt, class _Pt,
	class _D> inline
	bool __cdecl operator>=(
		const reverse_iterator<_RI, _Ty, _Rt, _Pt, _D>& _X,
		const reverse_iterator<_RI, _Ty, _Rt, _Pt, _D>& _Y)
	{return (!(_X < _Y)); }
template<class _RI, class _Ty, class _Rt, class _Pt,
	class _D> inline
	_D __cdecl operator-(
		const reverse_iterator<_RI, _Ty, _Rt, _Pt, _D>& _X,
		const reverse_iterator<_RI, _Ty, _Rt, _Pt, _D>& _Y)
	{return (_Y.base() - _X.base()); }
template<class _RI, class _Ty, class _Rt, class _Pt,
	class _D> inline
	reverse_iterator<_RI, _Ty, _Rt, _Pt, _D> __cdecl operator+(_D _N,
		const reverse_iterator<_RI, _Ty, _Rt, _Pt, _D>& _Y)
	{return (reverse_iterator<_RI, _Ty, _Rt, _Pt, _D>(
		_Y.base() - _N)); }
		
template<class _E, class _Tr = char_traits<_E> >
	class istreambuf_iterator
		: public iterator<input_iterator_tag, _E, _Tr::off_type> {
public:
	typedef istreambuf_iterator<_E, _Tr> _Myt;
	typedef _E char_type;
	typedef _Tr traits_type;
	typedef _Tr::int_type int_type;
	typedef basic_streambuf<_E, _Tr> streambuf_type;
	typedef basic_istream<_E, _Tr> istream_type;
	istreambuf_iterator(streambuf_type *_Sb = 0) throw ()
		: _Sbuf(_Sb), _Got(_Sb == 0) {}
	istreambuf_iterator(istream_type& _I) throw ()
		: _Sbuf(_I.rdbuf()), _Got(_I.rdbuf() == 0) {}
	const _E& operator*() const
		{if (!_Got)
			((_Myt *)this)->_Peek();
		return (_Val); }
	const _E *operator->() const
		{return (&**this); }
	_Myt& operator++()
		{_Inc();
		return (*this); }
	_Myt operator++(int)
		{if (!_Got)
			_Peek();
		_Myt _Tmp = *this;
		_Inc();
		return (_Tmp); }
	bool equal(const _Myt& _X) const
		{if (!_Got)
			((_Myt *)this)->_Peek();
		if (!_X._Got)
			((_Myt *)&_X)->_Peek();
		return (_Sbuf == 0 && _X._Sbuf == 0
			|| _Sbuf != 0 && _X._Sbuf != 0); }
private:
	void _Inc()
		{if (_Sbuf == 0
			|| _Tr::eq_int_type(_Tr::eof(), _Sbuf->sbumpc()))
			_Sbuf = 0, _Got = true;
		else
			_Got = false; }
	_E _Peek()
		{int_type _C;
		if (_Sbuf == 0
			|| _Tr::eq_int_type(_Tr::eof(), _C = _Sbuf->sgetc()))
			_Sbuf = 0;
		else
			_Val = _Tr::to_char_type(_C);
		_Got = true;
		return (_Val); }
	streambuf_type *_Sbuf;
	bool _Got;
	_E _Val;
	};
template<class _E, class _Tr> inline
	bool __cdecl operator==(const istreambuf_iterator<_E, _Tr>& _X,
		const istreambuf_iterator<_E, _Tr>& _Y)
	{return (_X.equal(_Y)); }
template<class _E, class _Tr> inline
	bool __cdecl operator!=(const istreambuf_iterator<_E, _Tr>& _X,
		const istreambuf_iterator<_E, _Tr>& _Y)
	{return (!(_X == _Y)); }
		
template<class _E, class _Tr = char_traits<_E> >
	class ostreambuf_iterator
		: public iterator<output_iterator_tag, void, void> {
	typedef ostreambuf_iterator<_E, _Tr> _Myt;
public:
	typedef _E char_type;
	typedef _Tr traits_type;
	typedef basic_streambuf<_E, _Tr> streambuf_type;
	typedef basic_ostream<_E, _Tr> ostream_type;
	ostreambuf_iterator(streambuf_type *_Sb) throw ()
		: _Failed(false), _Sbuf(_Sb) {}
	ostreambuf_iterator(ostream_type& _O) throw ()
		: _Failed(false), _Sbuf(_O.rdbuf()) {}
	_Myt& operator=(_E _X)
		{if (_Sbuf == 0
			|| _Tr::eq_int_type(_Tr::eof(), _Sbuf->sputc(_X)))
			_Failed = true;
		return (*this); }
	_Myt& operator*()
		{return (*this); }
	_Myt& operator++()
		{return (*this); }
	_Myt& operator++(int)
		{return (*this); }
	bool failed() const throw ()
		{return (_Failed); }
private:
	bool _Failed;
	streambuf_type *_Sbuf;
	};
		
	namespace rel_ops {
template<class _Ty> inline
	bool __cdecl operator!=(const _Ty& _X, const _Ty& _Y)
	{return (!(_X == _Y)); }
template<class _Ty> inline
	bool __cdecl operator>(const _Ty& _X, const _Ty& _Y)
	{return (_Y < _X); }
template<class _Ty> inline
	bool __cdecl operator<=(const _Ty& _X, const _Ty& _Y)
	{return (!(_Y < _X)); }
template<class _Ty> inline
	bool __cdecl operator>=(const _Ty& _X, const _Ty& _Y)
	{return (!(_X < _Y)); }
	};
};

#pragma pack(pop)
#line 338 "c:\\program files\\microsoft visual studio\\vc98\\include\\utility"

#line 340 "c:\\program files\\microsoft visual studio\\vc98\\include\\utility"






















#line 16 "c:\\program files\\microsoft visual studio\\vc98\\include\\xmemory"

 
 
 
#line 21 "c:\\program files\\microsoft visual studio\\vc98\\include\\xmemory"
 
 
namespace std {
		
template<class _Ty> inline
	_Ty  *_Allocate(ptrdiff_t _N, _Ty  *)
	{if (_N < 0)
		_N = 0;
	return ((_Ty  *)operator new("c:\\program files\\microsoft visual studio\\vc98\\include\\xmemory", 29)(
		(size_t)_N * sizeof (_Ty))); }
		
template<class _T1, class _T2> inline
	void _Construct(_T1  *_P, const _T2& _V)
	{new("c:\\program files\\microsoft visual studio\\vc98\\include\\xmemory", 34) ((void  *)_P) _T1(_V); }
		
template<class _Ty> inline
	void _Destroy(_Ty  *_P)
	{(_P)->~_Ty(); }
inline void _Destroy(char  *_P)
	{}
inline void _Destroy(wchar_t  *_P)
	{}
		
template<class _Ty>
	class allocator {
public:
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef _Ty  *pointer;
	typedef const _Ty  *const_pointer;
	typedef _Ty & reference;
	typedef const _Ty & const_reference;
	typedef _Ty value_type;
	pointer address(reference _X) const
		{return (&_X); }
	const_pointer address(const_reference _X) const
		{return (&_X); }
	pointer allocate(size_type _N, const void *)
		{return (_Allocate((difference_type)_N, (pointer)0)); }
	char  *_Charalloc(size_type _N)
		{return (_Allocate((difference_type)_N,
			(char  *)0)); }
	void deallocate(void  *_P, size_type)
		{operator delete(_P); }
	void construct(pointer _P, const _Ty& _V)
		{_Construct(_P, _V); }
	void destroy(pointer _P)
		{_Destroy(_P); }
	size_t max_size() const
		{size_t _N = (size_t)(-1) / sizeof (_Ty);
		return (0 < _N ? _N : 1); }
	};
template<class _Ty, class _U> inline
	bool operator==(const allocator<_Ty>&, const allocator<_U>&)
	{return (true); }
template<class _Ty, class _U> inline
	bool operator!=(const allocator<_Ty>&, const allocator<_U>&)
	{return (false); }
		
template<> class  allocator<void> {
public:
	typedef void _Ty;
	typedef _Ty  *pointer;
	typedef const _Ty  *const_pointer;
	typedef _Ty value_type;
	};
};

#pragma pack(pop)
#line 91 "c:\\program files\\microsoft visual studio\\vc98\\include\\xmemory"

#line 93 "c:\\program files\\microsoft visual studio\\vc98\\include\\xmemory"






















#line 10 "c:\\program files\\microsoft visual studio\\vc98\\include\\xstring"


#pragma pack(push,8)
#line 14 "c:\\program files\\microsoft visual studio\\vc98\\include\\xstring"
 #line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\xutility"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\xutility"






#pragma pack(push,8)
#line 14 "c:\\program files\\microsoft visual studio\\vc98\\include\\xutility"
namespace std {
		
template<class _II, class _OI> inline
	_OI copy(_II _F, _II _L, _OI _X)
	{for (; _F != _L; ++_X, ++_F)
		*_X = *_F;
	return (_X); }
		
template<class _BI1, class _BI2> inline
	_BI2 copy_backward(_BI1 _F, _BI1 _L, _BI2 _X)
	{while (_F != _L)
		*--_X = *--_L;
	return (_X); }
		
template<class _II1, class _II2> inline
	bool equal(_II1 _F, _II1 _L, _II2 _X)
	{return (mismatch(_F, _L, _X).first == _L); }
		
template<class _II1, class _II2, class _Pr> inline
	bool equal(_II1 _F, _II1 _L, _II2 _X, _Pr _P)
	{return (mismatch(_F, _L, _X, _P).first == _L); }
		
template<class _FI, class _Ty> inline
	void fill(_FI _F, _FI _L, const _Ty& _X)
	{for (; _F != _L; ++_F)
		*_F = _X; }
		
template<class _OI, class _Sz, class _Ty> inline
	void fill_n(_OI _F, _Sz _N, const _Ty& _X)
	{for (; 0 < _N; --_N, ++_F)
		*_F = _X; }
		
template<class _II1, class _II2> inline
	bool lexicographical_compare(_II1 _F1, _II1 _L1,
		_II2 _F2, _II2 _L2)
	{for (; _F1 != _L1 && _F2 != _L2; ++_F1, ++_F2)
		if (*_F1 < *_F2)
			return (true);
		else if (*_F2 < *_F1)
			return (false);
	return (_F1 == _L1 && _F2 != _L2); }
		
template<class _II1, class _II2, class _Pr> inline
	bool lexicographical_compare(_II1 _F1, _II1 _L1,
		_II2 _F2, _II2 _L2, _Pr _P)
	{for (; _F1 != _L1 && _F2 != _L2; ++_F1, ++_F2)
		if (_P(*_F1, *_F2))
			return (true);
		else if (_P(*_F2, *_F1))
			return (false);
	return (_F1 == _L1 && _F2 != _L2); }
		




template<class _Ty> inline
	const _Ty& _cpp_max(const _Ty& _X, const _Ty& _Y)
	{return (_X < _Y ? _Y : _X); }
		
template<class _Ty, class _Pr> inline
	const _Ty& _cpp_max(const _Ty& _X, const _Ty& _Y, _Pr _P)
	{return (_P(_X, _Y) ? _Y : _X); }
		
template<class _Ty> inline
	const _Ty& _cpp_min(const _Ty& _X, const _Ty& _Y)
	{return (_Y < _X ? _Y : _X); }
		
template<class _Ty, class _Pr> inline
	const _Ty& _cpp_min(const _Ty& _X, const _Ty& _Y, _Pr _P)
	{return (_P(_Y, _X) ? _Y : _X); }
		
template<class _II1, class _II2> inline
	pair<_II1, _II2> mismatch(_II1 _F, _II1 _L, _II2 _X)
	{for (; _F != _L && *_F == *_X; ++_F, ++_X)
		;
	return (pair<_II1, _II2>(_F, _X)); }
		
template<class _II1, class _II2, class _Pr> inline
	pair<_II1, _II2> mismatch(_II1 _F, _II1 _L, _II2 _X, _Pr _P)
	{for (; _F != _L && _P(*_F, *_X); ++_F, ++_X)
		;
	return (pair<_II1, _II2>(_F, _X)); }
		
template<class _Ty> inline
	void swap(_Ty& _X, _Ty& _Y)
	{_Ty _Tmp = _X;
	_X = _Y, _Y = _Tmp; }
};

#pragma pack(pop)
#line 106 "c:\\program files\\microsoft visual studio\\vc98\\include\\xutility"

#line 108 "c:\\program files\\microsoft visual studio\\vc98\\include\\xutility"






















#line 15 "c:\\program files\\microsoft visual studio\\vc98\\include\\xstring"
namespace std {
 void __cdecl _Xlen();
 void __cdecl _Xran();
		
template<class _E,
	class _Tr = char_traits<_E>,
	class _A = allocator<_E> >
	class basic_string {
public:
	typedef basic_string<_E, _Tr, _A> _Myt;
	typedef _A::size_type size_type;
	typedef _A::difference_type difference_type;
	typedef _A::pointer pointer;
	typedef _A::const_pointer const_pointer;
	typedef _A::reference reference;
	typedef _A::const_reference const_reference;
	typedef _A::value_type value_type;
	typedef _A::pointer iterator;
	typedef _A::const_pointer const_iterator;
	typedef reverse_iterator<const_iterator, value_type,
		const_reference, const_pointer, difference_type>
			const_reverse_iterator;
	typedef reverse_iterator<iterator, value_type,
		reference, pointer, difference_type>
			reverse_iterator;
	explicit basic_string(const _A& _Al = _A())
		: allocator(_Al) {_Tidy(); }
	basic_string(const _Myt& _X)
		: allocator(_X.allocator)
		{_Tidy(), assign(_X, 0, npos); }
	basic_string(const _Myt& _X, size_type _P, size_type _M,
		const _A& _Al = _A())
		: allocator(_Al) {_Tidy(), assign(_X, _P, _M); }
	basic_string(const _E *_S, size_type _N,
		const _A& _Al = _A())
		: allocator(_Al) {_Tidy(), assign(_S, _N); }
	basic_string(const _E *_S, const _A& _Al = _A())
		: allocator(_Al) {_Tidy(), assign(_S); }
	basic_string(size_type _N, _E _C, const _A& _Al = _A())
		: allocator(_Al) {_Tidy(), assign(_N, _C); }
	typedef const_iterator _It;
	basic_string(_It _F, _It _L, const _A& _Al = _A())
		: allocator(_Al) {_Tidy(); assign(_F, _L); }
	~basic_string()
		{_Tidy(true); }
	typedef _Tr traits_type;
	typedef _A allocator_type;
	enum _Mref {_FROZEN = 255};
	static const size_type npos;
	_Myt& operator=(const _Myt& _X)
		{return (assign(_X)); }
	_Myt& operator=(const _E *_S)
		{return (assign(_S)); }
	_Myt& operator=(_E _C)
		{return (assign(1, _C)); }
	_Myt& operator+=(const _Myt& _X)
		{return (append(_X)); }
	_Myt& operator+=(const _E *_S)
		{return (append(_S)); }
	_Myt& operator+=(_E _C)
		{return (append(1, _C)); }
	_Myt& append(const _Myt& _X)
		{return (append(_X, 0, npos)); }
	_Myt& append(const _Myt& _X, size_type _P, size_type _M)
		{if (_X.size() < _P)
			_Xran();
		size_type _N = _X.size() - _P;
		if (_N < _M)
			_M = _N;
		if (npos - _Len <= _M)
			_Xlen();
		if (0 < _M && _Grow(_N = _Len + _M))
			{_Tr::copy(_Ptr + _Len, &_X.c_str()[_P], _M);
			_Eos(_N); }
		return (*this); }
	_Myt& append(const _E *_S, size_type _M)
		{if (npos - _Len <= _M)
			_Xlen();
		size_type _N;
		if (0 < _M && _Grow(_N = _Len + _M))
			{_Tr::copy(_Ptr + _Len, _S, _M);
			_Eos(_N); }
		return (*this); }
	_Myt& append(const _E *_S)
		{return (append(_S, _Tr::length(_S))); }
	_Myt& append(size_type _M, _E _C)
		{if (npos - _Len <= _M)
			_Xlen();
		size_type _N;
		if (0 < _M && _Grow(_N = _Len + _M))
			{_Tr::assign(_Ptr + _Len, _M, _C);
			_Eos(_N); }
		return (*this); }
	_Myt& append(_It _F, _It _L)
		{return (replace(end(), end(), _F, _L)); }
	_Myt& assign(const _Myt& _X)
		{return (assign(_X, 0, npos)); }
	_Myt& assign(const _Myt& _X, size_type _P, size_type _M)
		{if (_X.size() < _P)
			_Xran();
		size_type _N = _X.size() - _P;
		if (_M < _N)
			_N = _M;
		if (this == &_X)
			erase((size_type)(_P + _N)), erase(0, _P);
		else if (0 < _N && _N == _X.size()
			&& _Refcnt(_X.c_str()) < _FROZEN - 1
			&& allocator == _X.allocator)
			{_Tidy(true);
			_Ptr = (_E *)_X.c_str();
			_Len = _X.size();
			_Res = _X.capacity();
			++_Refcnt(_Ptr); }
		else if (_Grow(_N, true))
			{_Tr::copy(_Ptr, &_X.c_str()[_P], _N);
			_Eos(_N); }
		return (*this); }
	_Myt& assign(const _E *_S, size_type _N)
		{if (_Grow(_N, true))
			{_Tr::copy(_Ptr, _S, _N);
			_Eos(_N); }
		return (*this); }
	_Myt& assign(const _E *_S)
		{return (assign(_S, _Tr::length(_S))); }
	_Myt& assign(size_type _N, _E _C)
		{if (_N == npos)
			_Xlen();
		if (_Grow(_N, true))
			{_Tr::assign(_Ptr, _N, _C);
			_Eos(_N); }
		return (*this); }
	_Myt& assign(_It _F, _It _L)
		{return (replace(begin(), end(), _F, _L)); }
	_Myt& insert(size_type _P0, const _Myt& _X)
		{return (insert(_P0, _X, 0, npos)); }
	_Myt& insert(size_type _P0, const _Myt& _X, size_type _P,
		size_type _M)
		{if (_Len < _P0 || _X.size() < _P)
			_Xran();
		size_type _N = _X.size() - _P;
		if (_N < _M)
			_M = _N;
		if (npos - _Len <= _M)
			_Xlen();
		if (0 < _M && _Grow(_N = _Len + _M))
			{_Tr::move(_Ptr + _P0 + _M, _Ptr + _P0, _Len - _P0);
			_Tr::copy(_Ptr + _P0, &_X.c_str()[_P], _M);
			_Eos(_N); }
		return (*this); }
	_Myt& insert(size_type _P0, const _E *_S, size_type _M)
		{if (_Len < _P0)
			_Xran();
		if (npos - _Len <= _M)
			_Xlen();
		size_type _N;
		if (0 < _M && _Grow(_N = _Len + _M))
			{_Tr::move(_Ptr + _P0 + _M, _Ptr + _P0, _Len - _P0);
			_Tr::copy(_Ptr + _P0, _S, _M);
			_Eos(_N); }
		return (*this); }
	_Myt& insert(size_type _P0, const _E *_S)
		{return (insert(_P0, _S, _Tr::length(_S))); }
	_Myt& insert(size_type _P0, size_type _M, _E _C)
		{if (_Len < _P0)
			_Xran();
		if (npos - _Len <= _M)
			_Xlen();
		size_type _N;
		if (0 < _M && _Grow(_N = _Len + _M))
			{_Tr::move(_Ptr + _P0 + _M, _Ptr + _P0, _Len - _P0);
			_Tr::assign(_Ptr + _P0, _M, _C);
			_Eos(_N); }
		return (*this); }
	iterator insert(iterator _P, _E _C)
		{size_type _P0 = _Pdif(_P, begin());
		insert(_P0, 1, _C);
		return (begin() + _P0); }
	void insert(iterator _P, size_type _M, _E _C)
		{size_type _P0 = _Pdif(_P, begin());
		insert(_P0, _M, _C); }
	void insert(iterator _P, _It _F, _It _L)
		{replace(_P, _P, _F, _L); }
	_Myt& erase(size_type _P0 = 0, size_type _M = npos)
		{if (_Len < _P0)
			_Xran();
		_Split();
		if (_Len - _P0 < _M)
			_M = _Len - _P0;
		if (0 < _M)
			{_Tr::move(_Ptr + _P0, _Ptr + _P0 + _M,
				_Len - _P0 - _M);
			size_type _N = _Len - _M;
			if (_Grow(_N))
				_Eos(_N); }
		return (*this); }
	iterator erase(iterator _P)
		{size_t _M = _Pdif(_P, begin());
		erase(_M, 1);
		return (_Psum(_Ptr, _M)); }
	iterator erase(iterator _F, iterator _L)
		{size_t _M = _Pdif(_F, begin());
		erase(_M, _Pdif(_L, _F));
		return (_Psum(_Ptr, _M)); }
	_Myt& replace(size_type _P0, size_type _N0, const _Myt& _X)
		{return (replace(_P0, _N0, _X, 0, npos)); }
	_Myt& replace(size_type _P0, size_type _N0, const _Myt& _X,
		size_type _P, size_type _M)
		{if (_Len < _P0 || _X.size() < _P)
			_Xran();
		if (_Len - _P0 < _N0)
			_N0 = _Len - _P0;
		size_type _N = _X.size() - _P;
		if (_N < _M)
			_M = _N;
		if (npos - _M <= _Len - _N0)
			_Xlen();
		_Split();
		size_type _Nm = _Len - _N0 - _P0;
		if (_M < _N0)
			_Tr::move(_Ptr + _P0 + _M, _Ptr + _P0 + _N0, _Nm);
		if ((0 < _M || 0 < _N0) && _Grow(_N = _Len + _M - _N0))
			{if (_N0 < _M)
				_Tr::move(_Ptr + _P0 + _M, _Ptr + _P0 + _N0, _Nm);
			_Tr::copy(_Ptr + _P0, &_X.c_str()[_P], _M);
			_Eos(_N); }
		return (*this); }
	_Myt& replace(size_type _P0, size_type _N0, const _E *_S,
		size_type _M)
		{if (_Len < _P0)
			_Xran();
		if (_Len - _P0 < _N0)
			_N0 = _Len - _P0;
		if (npos - _M <= _Len - _N0)
			_Xlen();
		_Split();
		size_type _Nm = _Len - _N0 - _P0;
		if (_M < _N0)
			_Tr::move(_Ptr + _P0 + _M, _Ptr + _P0 + _N0, _Nm);
		size_type _N;
		if ((0 < _M || 0 < _N0) && _Grow(_N = _Len + _M - _N0))
			{if (_N0 < _M)
				_Tr::move(_Ptr + _P0 + _M, _Ptr + _P0 + _N0, _Nm);
			_Tr::copy(_Ptr + _P0, _S, _M);
			_Eos(_N); }
		return (*this); }
	_Myt& replace(size_type _P0, size_type _N0, const _E *_S)
		{return (replace(_P0, _N0, _S, _Tr::length(_S))); }
	_Myt& replace(size_type _P0, size_type _N0,
		size_type _M, _E _C)
		{if (_Len < _P0)
			_Xran();
		if (_Len - _P0 < _N0)
			_N0 = _Len - _P0;
		if (npos - _M <= _Len - _N0)
			_Xlen();
		_Split();
		size_type _Nm = _Len - _N0 - _P0;
		if (_M < _N0)
			_Tr::move(_Ptr + _P0 + _M, _Ptr + _P0 + _N0, _Nm);
		size_type _N;
		if ((0 < _M || 0 < _N0) && _Grow(_N = _Len + _M - _N0))
			{if (_N0 < _M)
				_Tr::move(_Ptr + _P0 + _M, _Ptr + _P0 + _N0,
					_Nm);
			_Tr::assign(_Ptr + _P0, _M, _C);
			_Eos(_N); }
		return (*this); }
	_Myt& replace(iterator _F, iterator _L, const _Myt& _X)
		{return (replace(
			_Pdif(_F, begin()), _Pdif(_L, _F), _X)); }
	_Myt& replace(iterator _F, iterator _L, const _E *_S,
		size_type _M)
		{return (replace(
			_Pdif(_F, begin()), _Pdif(_L, _F), _S, _M)); }
	_Myt& replace(iterator _F, iterator _L, const _E *_S)
		{return (replace(
			_Pdif(_F, begin()), _Pdif(_L, _F), _S)); }
	_Myt& replace(iterator _F, iterator _L,	size_type _M, _E _C)
		{return (replace(
			_Pdif(_F, begin()), _Pdif(_L, _F), _M, _C)); }
	_Myt& replace(iterator _F1, iterator _L1,
		_It _F2, _It _L2)
		{size_type _P0 = _Pdif(_F1, begin());
		size_type _M = 0;
		_Distance(_F2, _L2, _M);
		replace(_P0, _Pdif(_L1, _F1), _M, _E(0));
		for (_F1 = begin() + _P0; 0 < _M; ++_F1, ++_F2, --_M)
			*_F1 = *_F2;
		return (*this); }
	iterator begin()
		{_Freeze();
		return (_Ptr); }
	const_iterator begin() const
		{return (_Ptr); }
	iterator end()
		{_Freeze();
		return ((iterator)_Psum(_Ptr, _Len)); }
	const_iterator end() const
		{return ((const_iterator)_Psum(_Ptr, _Len)); }
	reverse_iterator rbegin()
		{return (reverse_iterator(end())); }
	const_reverse_iterator rbegin() const
		{return (const_reverse_iterator(end())); }
	reverse_iterator rend()
		{return (reverse_iterator(begin())); }
	const_reverse_iterator rend() const
		{return (const_reverse_iterator(begin())); }
	reference at(size_type _P0)
		{if (_Len <= _P0)
			_Xran();
		_Freeze();
		return (_Ptr[_P0]); }
	const_reference at(size_type _P0) const
		{if (_Len <= _P0)
			_Xran();
		return (_Ptr[_P0]); }
	reference operator[](size_type _P0)
		{if (_Len < _P0 || _Ptr == 0)
			return ((reference)*_Nullstr());
		_Freeze();
		return (_Ptr[_P0]); }
	const_reference operator[](size_type _P0) const
		{if (_Ptr == 0)
			return (*_Nullstr());
		else
			return (_Ptr[_P0]); }
	const _E *c_str() const
		{return (_Ptr == 0 ? _Nullstr() : _Ptr); }
	const _E *data() const
		{return (c_str()); }
	size_type length() const
		{return (_Len); }
	size_type size() const
		{return (_Len); }
	size_type max_size() const
		{size_type _N = allocator.max_size();
		return (_N <= 2 ? 1 : _N - 2); }
	void resize(size_type _N, _E _C)
		{_N <= _Len ? erase(_N) : append(_N - _Len, _C); }
	void resize(size_type _N)
		{_N <= _Len ? erase(_N) : append(_N - _Len, _E(0)); }
	size_type capacity() const
		{return (_Res); }
	void reserve(size_type _N = 0)
		{if (_Res < _N)
			_Grow(_N); }
	bool empty() const
		{return (_Len == 0); }
	size_type copy(_E *_S, size_type _N, size_type _P0 = 0) const
		{if (_Len < _P0)
			_Xran();
		if (_Len - _P0 < _N)
			_N = _Len - _P0;
		if (0 < _N)
			_Tr::copy(_S, _Ptr + _P0, _N);
		return (_N); }
	void swap(_Myt& _X)
		{if (allocator == _X.allocator)
			{std::swap(_Ptr, _X._Ptr);
			std::swap(_Len, _X._Len);
			std::swap(_Res, _X._Res); }
		else
			{_Myt _Ts = *this; *this = _X, _X = _Ts; }}
	friend void swap(_Myt& _X, _Myt& _Y)
		{_X.swap(_Y); }
	size_type find(const _Myt& _X, size_type _P = 0) const
		{return (find(_X.c_str(), _P, _X.size())); }
	size_type find(const _E *_S, size_type _P,
		size_type _N) const
		{if (_N == 0 && _P <= _Len)
			return (_P);
		size_type _Nm;
		if (_P < _Len && _N <= (_Nm = _Len - _P))
			{const _E *_U, *_V;
			for (_Nm -= _N - 1, _V = _Ptr + _P;
				(_U = _Tr::find(_V, _Nm, *_S)) != 0;
				_Nm -= _U - _V + 1, _V = _U + 1)
				if (_Tr::compare(_U, _S, _N) == 0)
					return (_U - _Ptr); }
		return (npos); }
	size_type find(const _E *_S, size_type _P = 0) const
		{return (find(_S, _P, _Tr::length(_S))); }
	size_type find(_E _C, size_type _P = 0) const
		{return (find((const _E *)&_C, _P, 1)); }
	size_type rfind(const _Myt& _X, size_type _P = npos) const
		{return (rfind(_X.c_str(), _P, _X.size())); }
	size_type rfind(const _E *_S, size_type _P,
		size_type _N) const
		{if (_N == 0)
			return (_P < _Len ? _P : _Len);
		if (_N <= _Len)
			for (const _E *_U = _Ptr +
				+ (_P < _Len - _N ? _P : _Len - _N); ; --_U)
				if (_Tr::eq(*_U, *_S)
					&& _Tr::compare(_U, _S, _N) == 0)
					return (_U - _Ptr);
				else if (_U == _Ptr)
					break;
		return (npos); }
	size_type rfind(const _E *_S, size_type _P = npos) const
		{return (rfind(_S, _P, _Tr::length(_S))); }
	size_type rfind(_E _C, size_type _P = npos) const
		{return (rfind((const _E *)&_C, _P, 1)); }
	size_type find_first_of(const _Myt& _X,
		size_type _P = 0) const
		{return (find_first_of(_X.c_str(), _P, _X.size())); }
	size_type find_first_of(const _E *_S, size_type _P,
		size_type _N) const
		{if (0 < _N && _P < _Len)
			{const _E *const _V = _Ptr + _Len;
			for (const _E *_U = _Ptr + _P; _U < _V; ++_U)
				if (_Tr::find(_S, _N, *_U) != 0)
					return (_U - _Ptr); }
		return (npos); }
	size_type find_first_of(const _E *_S, size_type _P = 0) const
		{return (find_first_of(_S, _P, _Tr::length(_S))); }
	size_type find_first_of(_E _C, size_type _P = 0) const
		{return (find((const _E *)&_C, _P, 1)); }
	size_type find_last_of(const _Myt& _X,
		size_type _P = npos) const
		{return (find_last_of(_X.c_str(), _P, _X.size())); }
	size_type find_last_of(const _E *_S, size_type _P,
		size_type _N) const
		{if (0 < _N && 0 < _Len)
			for (const _E *_U = _Ptr
				+ (_P < _Len ? _P : _Len - 1); ; --_U)
				if (_Tr::find(_S, _N, *_U) != 0)
					return (_U - _Ptr);
				else if (_U == _Ptr)
					break;
		return (npos); }
	size_type find_last_of(const _E *_S,
		size_type _P = npos) const
		{return (find_last_of(_S, _P, _Tr::length(_S))); }
	size_type find_last_of(_E _C, size_type _P = npos) const
		{return (rfind((const _E *)&_C, _P, 1)); }
	size_type find_first_not_of(const _Myt& _X,
		size_type _P = 0) const
		{return (find_first_not_of(_X.c_str(), _P,
			_X.size())); }
	size_type find_first_not_of(const _E *_S, size_type _P,
		size_type _N) const
		{if (_P < _Len)
			{const _E *const _V = _Ptr + _Len;
			for (const _E *_U = _Ptr + _P; _U < _V; ++_U)
				if (_Tr::find(_S, _N, *_U) == 0)
					return (_U - _Ptr); }
		return (npos); }
	size_type find_first_not_of(const _E *_S,
		size_type _P = 0) const
		{return (find_first_not_of(_S, _P, _Tr::length(_S))); }
	size_type find_first_not_of(_E _C, size_type _P = 0) const
		{return (find_first_not_of((const _E *)&_C, _P, 1)); }
	size_type find_last_not_of(const _Myt& _X,
		size_type _P = npos) const
		{return (find_last_not_of(_X.c_str(), _P, _X.size())); }
	size_type find_last_not_of(const _E *_S, size_type _P,
		 size_type _N) const
		{if (0 < _Len)
			for (const _E *_U = _Ptr
				+ (_P < _Len ? _P : _Len - 1); ; --_U)
				if (_Tr::find(_S, _N, *_U) == 0)
					return (_U - _Ptr);
				else if (_U == _Ptr)
					break;
		return (npos); }
	size_type find_last_not_of(const _E *_S,
		size_type _P = npos) const
		{return (find_last_not_of(_S, _P, _Tr::length(_S))); }
	size_type find_last_not_of(_E _C, size_type _P = npos) const
		{return (find_last_not_of((const _E *)&_C, _P, 1)); }
	_Myt substr(size_type _P = 0, size_type _M = npos) const
		{return (_Myt(*this, _P, _M)); }
	int compare(const _Myt& _X) const
		{return (compare(0, _Len, _X.c_str(), _X.size())); }
	int compare(size_type _P0, size_type _N0,
		const _Myt& _X) const
		{return (compare(_P0, _N0, _X, 0, npos)); }
	int compare(size_type _P0, size_type _N0, const _Myt& _X,
		size_type _P, size_type _M) const
		{if (_X.size() < _P)
			_Xran();
		if (_X._Len - _P < _M)
			_M = _X._Len - _P;
		return (compare(_P0, _N0, _X.c_str() + _P, _M)); }
	int compare(const _E *_S) const
		{return (compare(0, _Len, _S, _Tr::length(_S))); }
	int compare(size_type _P0, size_type _N0, const _E *_S) const
		{return (compare(_P0, _N0, _S, _Tr::length(_S))); }
	int compare(size_type _P0, size_type _N0, const _E *_S,
		size_type _M) const
		{if (_Len < _P0)
			_Xran();
		if (_Len - _P0 < _N0)
			_N0 = _Len - _P0;
		size_type _Ans = _Tr::compare(_Psum(_Ptr, _P0), _S,
			_N0 < _M ? _N0 : _M);
		return (_Ans != 0 ? _Ans : _N0 < _M ? -1
			: _N0 == _M ? 0 : +1); }
	_A get_allocator() const
		{return (allocator); }
protected:
	_A allocator;
private:
	enum {_MIN_SIZE = sizeof (_E) <= 32 ? 31 : 7};
	void _Copy(size_type _N)
		{size_type _Ns = _N | _MIN_SIZE;
		if (max_size() < _Ns)
			_Ns = _N;
		_E *_S;
		try {
			_S = allocator.allocate(_Ns + 2, (void *)0);
		} catch (...) {
			_Ns = _N;
			_S = allocator.allocate(_Ns + 2, (void *)0);
		}
		if (0 < _Len)
			_Tr::copy(_S + 1, _Ptr,_Len>_Ns?_Ns:_Len);
		size_type _Olen = _Len;
		_Tidy(true);
		_Ptr = _S + 1;
		_Refcnt(_Ptr) = 0;
		_Res = _Ns;
		_Eos(_Olen>_Ns?_Ns:_Olen); }
	void _Eos(size_type _N)
		{_Tr::assign(_Ptr[_Len = _N], _E(0)); }
	void _Freeze()
		{if (_Ptr != 0
			&& _Refcnt(_Ptr) != 0 && _Refcnt(_Ptr) != _FROZEN)
			_Grow(_Len);
		if (_Ptr != 0)
			_Refcnt(_Ptr) = _FROZEN; }
	bool _Grow(size_type _N, bool _Trim = false)
		{if (max_size() < _N)
			_Xlen();
		if (_Ptr != 0
			&& _Refcnt(_Ptr) != 0 && _Refcnt(_Ptr) != _FROZEN)
			if (_N == 0)
				{--_Refcnt(_Ptr), _Tidy();
				return (false); }
			else
				{_Copy(_N);
				return (true); }
		if (_N == 0)
			{if (_Trim)
				_Tidy(true);
			else if (_Ptr != 0)
				_Eos(0);
			return (false); }
		else
			{if (_Trim && (_MIN_SIZE < _Res || _Res < _N))
				{_Tidy(true);
				_Copy(_N); }
			else if (!_Trim && _Res < _N)
				_Copy(_N);
			return (true); }}
	static const _E * __cdecl _Nullstr()
		{static const _E _C = _E(0);
		return (&_C); }
	static size_type _Pdif(const_pointer _P2, const_pointer _P1)
		{return (_P2 == 0 ? 0 : _P2 - _P1); }
	static const_pointer _Psum(const_pointer _P, size_type _N)
		{return (_P == 0 ? 0 : _P + _N); }
	static pointer _Psum(pointer _P, size_type _N)
		{return (_P == 0 ? 0 : _P + _N); }
	unsigned char& _Refcnt(const _E *_U)
		{return (((unsigned char *)_U)[-1]); }
	void _Split()
		{if (_Ptr != 0 && _Refcnt(_Ptr) != 0 && _Refcnt(_Ptr) != _FROZEN)
			{_E *_Temp = _Ptr;
			_Tidy(true);
			assign(_Temp); }}
	void _Tidy(bool _Built = false)
		{if (!_Built || _Ptr == 0)
			;
		else if (_Refcnt(_Ptr) == 0 || _Refcnt(_Ptr) == _FROZEN)
			allocator.deallocate(_Ptr - 1, _Res + 2);
		else
			--_Refcnt(_Ptr);
		_Ptr = 0, _Len = 0, _Res = 0; }
	_E *_Ptr;
	size_type _Len, _Res;
	};
template<class _E, class _Tr, class _A>
	const basic_string<_E, _Tr, _A>::size_type
		basic_string<_E, _Tr, _A>::npos = -1;










typedef basic_string<char, char_traits<char>, allocator<char> >
	string;

typedef basic_string<wchar_t, char_traits<wchar_t>,
	allocator<wchar_t> > wstring;

};

#pragma pack(pop)
#line 621 "c:\\program files\\microsoft visual studio\\vc98\\include\\xstring"

#line 623 "c:\\program files\\microsoft visual studio\\vc98\\include\\xstring"





#line 11 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdexcept"


#pragma pack(push,8)
#line 15 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdexcept"
namespace std {
		
class  logic_error : public exception {
public:
	explicit logic_error(const string& _S)
		: exception(""), _Str(_S) {}
	virtual ~logic_error()
		{}
	virtual const char *what() const
		{return (_Str.c_str()); }
protected:
	virtual void _Doraise() const
		{throw (*this); }
private:
	string _Str;
	};
		
class  domain_error : public logic_error {
public:
	explicit domain_error(const string& _S)
		: logic_error(_S) {}
	virtual ~domain_error()
		{}
protected:
	virtual void _Doraise() const
		{throw (*this); }
	};
		
class invalid_argument : public logic_error {
public:
	explicit invalid_argument(const string& _S)
		: logic_error(_S) {}
	virtual ~invalid_argument()
		{}
protected:
	virtual void _Doraise() const
		{throw (*this); }
	};
		
class  length_error : public logic_error {
public:
	explicit length_error(const string& _S)
		: logic_error(_S) {}
	virtual ~length_error()
		{}
protected:
	virtual void _Doraise() const
		{throw (*this); }
	};
		
class  out_of_range : public logic_error {
public:
	explicit out_of_range(const string& _S)
		: logic_error(_S) {}
	virtual ~out_of_range()
		{}
protected:
	virtual void _Doraise() const
		{throw (*this); }
	};
		
class  runtime_error : public exception {
public:
	explicit runtime_error(const string& _S)
		: exception(""), _Str(_S) {}
	virtual ~runtime_error()
		{}
	virtual const char *what() const
		{return (_Str.c_str()); }
protected:
	virtual void _Doraise() const
		{throw (*this); }
private:
	string _Str;
	};
		
class  overflow_error : public runtime_error {
public:
	explicit overflow_error(const string& _S)
		: runtime_error(_S) {}
	virtual ~overflow_error()
		{}
protected:
	virtual void _Doraise() const
		{throw (*this); }
	};
		
class  underflow_error : public runtime_error {
public:
	explicit underflow_error(const string& _S)
		: runtime_error(_S) {}
	virtual ~underflow_error()
		{}
protected:
	virtual void _Doraise() const
		{throw (*this); }
	};
		
class  range_error : public runtime_error {
public:
	explicit range_error(const string& _S)
		: runtime_error(_S) {}
	virtual ~range_error()
		{}
protected:
	virtual void _Doraise() const
		{throw (*this); }
	};
};

#pragma pack(pop)
#line 127 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdexcept"

#line 129 "c:\\program files\\microsoft visual studio\\vc98\\include\\stdexcept"





#line 12 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocale"
#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\typeinfo"
















#pragma once
#line 19 "c:\\program files\\microsoft visual studio\\vc98\\include\\typeinfo"








 

#line 30 "c:\\program files\\microsoft visual studio\\vc98\\include\\typeinfo"





















#pragma pack(push,8)
#line 53 "c:\\program files\\microsoft visual studio\\vc98\\include\\typeinfo"

class type_info {
public:
     virtual ~type_info();
     int operator==(const type_info& rhs) const;
     int operator!=(const type_info& rhs) const;
     int before(const type_info& rhs) const;
     const char* name() const;
     const char* raw_name() const;
private:
    void *_m_data;
    char _m_d_name[1];
    type_info(const type_info& rhs);
    type_info& operator=(const type_info& rhs);
};



 

 namespace std {
		
class  bad_cast : public exception {
public:
	bad_cast(const char *_S = "bad cast") throw ()
		: exception(_S) {}
	virtual ~bad_cast() throw ()
		{}
protected:
	virtual void _Doraise() const
		{throw (*this); }
	};
		
class  bad_typeid : public exception {
public:
	bad_typeid(const char *_S = "bad typeid") throw ()
		: exception(_S) {}
	virtual ~bad_typeid() throw ()
		{}
protected:
	virtual void _Doraise() const
		{throw (*this); }
	};

class  __non_rtti_object : public bad_typeid {
public:
    __non_rtti_object(const char * what_arg) : bad_typeid(what_arg) {}
};
using ::type_info;
 };
using std::__non_rtti_object;









#pragma pack(pop)
#line 115 "c:\\program files\\microsoft visual studio\\vc98\\include\\typeinfo"

#line 117 "c:\\program files\\microsoft visual studio\\vc98\\include\\typeinfo"






#line 13 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocale"
#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocinfo"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocinfo"



#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocinfo.h"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocinfo.h"



#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\ctype.h"














#pragma once
#line 17 "c:\\program files\\microsoft visual studio\\vc98\\include\\ctype.h"






#line 24 "c:\\program files\\microsoft visual studio\\vc98\\include\\ctype.h"



extern "C" {
#line 29 "c:\\program files\\microsoft visual studio\\vc98\\include\\ctype.h"


















#line 48 "c:\\program files\\microsoft visual studio\\vc98\\include\\ctype.h"


























#line 75 "c:\\program files\\microsoft visual studio\\vc98\\include\\ctype.h"



 extern unsigned short _ctype[];
 extern unsigned short *_pctype;

 extern wctype_t *_pwctype;
#line 83 "c:\\program files\\microsoft visual studio\\vc98\\include\\ctype.h"
#line 84 "c:\\program files\\microsoft visual studio\\vc98\\include\\ctype.h"








                                













 int __cdecl _isctype(int, int);
 int __cdecl isalpha(int);
 int __cdecl isupper(int);
 int __cdecl islower(int);
 int __cdecl isdigit(int);
 int __cdecl isxdigit(int);
 int __cdecl isspace(int);
 int __cdecl ispunct(int);
 int __cdecl isalnum(int);
 int __cdecl isprint(int);
 int __cdecl isgraph(int);
 int __cdecl iscntrl(int);
 int __cdecl toupper(int);
 int __cdecl tolower(int);
 int __cdecl _tolower(int);
 int __cdecl _toupper(int);
 int __cdecl __isascii(int);
 int __cdecl __toascii(int);
 int __cdecl __iscsymf(int);
 int __cdecl __iscsym(int);

#line 128 "c:\\program files\\microsoft visual studio\\vc98\\include\\ctype.h"


































#line 163 "c:\\program files\\microsoft visual studio\\vc98\\include\\ctype.h"
























































































#line 252 "c:\\program files\\microsoft visual studio\\vc98\\include\\ctype.h"

#line 254 "c:\\program files\\microsoft visual studio\\vc98\\include\\ctype.h"

















































#line 304 "c:\\program files\\microsoft visual studio\\vc98\\include\\ctype.h"
















#line 321 "c:\\program files\\microsoft visual studio\\vc98\\include\\ctype.h"

#line 323 "c:\\program files\\microsoft visual studio\\vc98\\include\\ctype.h"


}
#line 327 "c:\\program files\\microsoft visual studio\\vc98\\include\\ctype.h"


#line 330 "c:\\program files\\microsoft visual studio\\vc98\\include\\ctype.h"
#line 10 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocinfo.h"
#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\locale.h"














#pragma once
#line 17 "c:\\program files\\microsoft visual studio\\vc98\\include\\locale.h"






#line 24 "c:\\program files\\microsoft visual studio\\vc98\\include\\locale.h"







#pragma pack(push,8)
#line 33 "c:\\program files\\microsoft visual studio\\vc98\\include\\locale.h"


extern "C" {
#line 37 "c:\\program files\\microsoft visual studio\\vc98\\include\\locale.h"


















#line 56 "c:\\program files\\microsoft visual studio\\vc98\\include\\locale.h"

















#line 74 "c:\\program files\\microsoft visual studio\\vc98\\include\\locale.h"



























struct lconv {
        char *decimal_point;
        char *thousands_sep;
        char *grouping;
        char *int_curr_symbol;
        char *currency_symbol;
        char *mon_decimal_point;
        char *mon_thousands_sep;
        char *mon_grouping;
        char *positive_sign;
        char *negative_sign;
        char int_frac_digits;
        char frac_digits;
        char p_cs_precedes;
        char p_sep_by_space;
        char n_cs_precedes;
        char n_sep_by_space;
        char p_sign_posn;
        char n_sign_posn;
        };

#line 123 "c:\\program files\\microsoft visual studio\\vc98\\include\\locale.h"












 char * __cdecl setlocale(int, const char *);
 struct lconv * __cdecl localeconv(void);










#line 148 "c:\\program files\\microsoft visual studio\\vc98\\include\\locale.h"


}
#line 152 "c:\\program files\\microsoft visual studio\\vc98\\include\\locale.h"


#pragma pack(pop)
#line 156 "c:\\program files\\microsoft visual studio\\vc98\\include\\locale.h"

#line 158 "c:\\program files\\microsoft visual studio\\vc98\\include\\locale.h"
#line 11 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocinfo.h"






		











		



















typedef struct _Collvec {
	unsigned long _Hand;	
	unsigned int _Page;		
	} _Collvec;

typedef struct _Ctypevec {
	unsigned long _Hand;	
	unsigned int _Page;		
	const short *_Table;
	int _Delfl;
	} _Ctypevec;

typedef struct _Cvtvec {
	unsigned long _Hand;	
	unsigned int _Page;		
	} _Cvtvec;

		
extern "C" {
 _Collvec __cdecl _Getcoll();
 _Ctypevec __cdecl _Getctype();
 _Cvtvec __cdecl _Getcvt();
char *__cdecl _Getdays();
char *__cdecl _Getmonths();
void *__cdecl _Gettnames();
 int __cdecl _Mbrtowc(wchar_t *, const char *, size_t,
	mbstate_t *, const _Cvtvec *);
extern float __cdecl _Stof(const char *, char **, long);
extern double __cdecl _Stod(const char *, char **, long);
extern long double __cdecl _Stold(const char *, char **, long);
 int __cdecl _Strcoll(const char *, const char *,
	const char *, const char *, const _Collvec *);
size_t __cdecl _Strftime(char *, size_t, const char *,
	const struct tm *, void *);
 size_t __cdecl _Strxfrm(char *, char *,
	const char *, const char *, const _Collvec *);
 int __cdecl _Tolower(int, const _Ctypevec *);
 int __cdecl _Toupper(int, const _Ctypevec *);
 int __cdecl _Wcrtomb(char *, wchar_t, mbstate_t *,
	const _Cvtvec *);
 int __cdecl _Wcscoll(const wchar_t *, const wchar_t *,
	const wchar_t *, const wchar_t *, const _Collvec *);
 size_t __cdecl _Wcsxfrm(wchar_t *, wchar_t *,
	const wchar_t *, const wchar_t *, const _Collvec *);
}
#line 95 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocinfo.h"





#line 10 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocinfo"




#pragma pack(push,8)
#line 16 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocinfo"
namespace std {

		
class  _Timevec {
public:
	_Timevec(void *_P = 0)
		: _Ptr(_P) {}
	_Timevec(const _Timevec& _Rhs)
		{*this = _Rhs; }
	~_Timevec()
		{free(_Ptr); }
	_Timevec& operator=(const _Timevec& _Rhs)
		{_Ptr = _Rhs._Ptr;
		((_Timevec *)&_Rhs)->_Ptr = 0;
		return (*this); }
	void *_Getptr() const
		{return (_Ptr); }
private:
	void *_Ptr;
	};
		
class  _Locinfo {
public:
	typedef ::_Collvec _Collvec;
	typedef ::_Ctypevec _Ctypevec;
	typedef ::_Cvtvec _Cvtvec;
	typedef std::_Timevec _Timevec;
	_Locinfo(const char * = "C");
	_Locinfo(int, const char *);
	~_Locinfo();
	_Locinfo& _Addcats(int, const char *);
	string _Getname() const
		{return (_Nname); }
	_Collvec _Getcoll() const
		{return (::_Getcoll()); }
	_Ctypevec _Getctype() const
		{return (::_Getctype()); }
	_Cvtvec _Getcvt() const
		{return (::_Getcvt()); }
	const lconv *_Getlconv() const
		{return (localeconv()); }
	_Timevec _Gettnames() const
		{return (_Timevec(::_Gettnames())); }
	const char *_Getdays() const
		{char *_S = ::_Getdays();
		if (_S != 0)
			{((_Locinfo *)this)->_Days = _S, free(_S); }
		return (_Days.size() != 0 ? _Days.c_str()
				: ":Sun:Sunday:Mon:Monday:Tue:Tuesday"
				":Wed:Wednesday:Thu:Thursday:Fri:Friday"
				":Sat:Saturday"); }
	const char *_Getmonths() const
		{char *_S = ::_Getmonths();
		if (_S != 0)
			{((_Locinfo *)this)->_Months = _S, free(_S); }
		return (_Months.size() != 0 ? _Months.c_str()
				: ":Jan:January:Feb:February:Mar:March"
				":Apr:April:May:May:Jun:June"
				":Jul:July:Aug:August:Sep:September"
				":Oct:October:Nov:November:Dec:December"); }
	const char *_Getfalse() const
		{return ("false"); }
	const char *_Gettrue() const
		{return ("true"); }
	const char *_Getno() const
		{return ("no"); }
	const char *_Getyes() const
		{return ("yes"); }
private:
	string _Days, _Months, _Oname, _Nname;
	};
		
template<class _E> inline
	int __cdecl _Strcoll(const _E *_F1, const _E *_L1,
		const _E *_F2, const _E *_L2, const _Locinfo::_Collvec *)
	{for (; _F1 != _L1 && _F2 != _L2; ++_F1, ++_F2)
		if (*_F1 < *_F2)
			return (-1);
		else if (*_F2 < *_F1)
			return (+1);
	return (_F2 != _L2 ? -1 : _F1 != _L1 ? +1 : 0); }
template<class _E> inline
	size_t __cdecl _Strxfrm(_E *_F1, _E *_L1,
		const _E *_F2, const _E *_L2, const _Locinfo::_Collvec *)
	{size_t _N = _L2 - _F2;
	if (_N <= _L1 - _F1)
		memcpy(_F1, _F2, _N * sizeof (_E));
	return (_N); }
};

#pragma pack(pop)
#line 108 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocinfo"

#line 110 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocinfo"





#line 14 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocale"


#pragma pack(push,8)
#line 18 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocale"
namespace std {
                
class  locale {
public:
        enum _Category {collate = ((1 << (1)) >> 1), ctype = ((1 << (2)) >> 1),
                monetary = ((1 << (3)) >> 1), numeric = ((1 << (4)) >> 1),
                time = ((1 << (5)) >> 1), messages = ((1 << (6)) >> 1),
                all = (((1 << (7)) >> 1) - 1), none = 0};
        typedef int category;
                        
        class  id {
        public:
                operator size_t()
                        {_Lockit _Lk;
                        if (_Id == 0)
                                _Id = ++_Id_cnt;
                        return (_Id); }
        private:
                size_t _Id;
                static int _Id_cnt;
                };
        class _Locimp;
                        
        class  facet {
                friend class locale;
                friend class _Locimp;
        public:
                static size_t __cdecl _Getcat()
                        {return ((size_t)(-1)); }
                void _Incref()
                        {_Lockit _Lk;
                        if (_Refs < (size_t)(-1))
                                ++_Refs; }
                facet *_Decref()
                        {_Lockit _Lk;
                        if (0 < _Refs && _Refs < (size_t)(-1))
                                --_Refs;
                        return (_Refs == 0 ? this : 0); }
        public:
                virtual ~facet()
                        {}
        protected:
                explicit facet(size_t _R = 0)
                        : _Refs(_R) {}
        private:
                facet(const facet&);    
                const facet& operator=(const facet&);   
                size_t _Refs;
                };
                        
        class _Locimp : public facet {
        public:
                ~_Locimp();
        private:
                friend class locale;
                _Locimp(bool _Xp = false);
                _Locimp(const _Locimp&);
                void _Addfac(facet *, size_t);
                static _Locimp *__cdecl _Makeloc(const _Locinfo&,
                        category, _Locimp *, const locale *);
                static void __cdecl _Makewloc(const _Locinfo&,
                        category, _Locimp *, const locale *);
                static void __cdecl _Makexloc(const _Locinfo&,
                        category, _Locimp *, const locale *);
                facet **_Fv;
                size_t _Nfv;
                category _Cat;
                bool _Xpar;
                string _Name;
                static  _Locimp *_Clocptr, *_Global;
                };
        locale& _Addfac(facet *, size_t, size_t);
        bool operator()(const string&, const string&) const;
        locale() throw ()
                : _Ptr(_Init())
                {_Lockit _lk;
                _Locimp::_Global->_Incref(); }
        locale(_Uninitialized)
                {}
        locale(const locale& _X) throw ()
                : _Ptr(_X._Ptr)
                {_Ptr->_Incref(); }
        locale(const locale&, const locale&, category);
        explicit locale(const char *, category = all);
        locale(const locale&, const char *, category);
        ~locale() throw ()
                {if (_Ptr != 0)
                        delete _Ptr->_Decref(); }
        locale& operator=(const locale& _X) throw ()
                {if (_Ptr != _X._Ptr)
                        {delete _Ptr->_Decref();
                        _Ptr = _X._Ptr;
                        _Ptr->_Incref(); }
                return (*this); }
        string name() const
                {return (_Ptr->_Name); }
        const facet *_Getfacet(size_t _Id, bool _Xp = false) const;
        bool _Iscloc() const;
        bool operator==(const locale& _X) const;
        bool operator!=(const locale& _X) const
                {return (!(*this == _X)); }
        static const locale& __cdecl classic();
        static locale __cdecl global(const locale&);
        static locale __cdecl empty();
private:
        locale(_Locimp *_P)
                : _Ptr(_P) {}
        static _Locimp *__cdecl _Init();
        static void __cdecl _Tidy();
        _Locimp *_Ptr;
        };
;
                
template<class _F>
        class _Tidyfac {
public:
        static _F *__cdecl _Save(_F *_Fac)
                {_Lockit _Lk;
                _Facsav = _Fac;
                _Facsav->_Incref();
                atexit(_Tidy);
                return (_Fac); }
        static void __cdecl _Tidy()
                {_Lockit _Lk;
                delete _Facsav->_Decref();
                _Facsav = 0; }
private:
        static _F *_Facsav;
        };
template<class _F>
        _F *_Tidyfac<_F>::_Facsav = 0;
 
 
 
template<class _F> inline
        locale _Addfac(locale _X, _F *_Fac)
                {_Lockit _Lk;
                return (_X._Addfac(_Fac, _F::id, _F::_Getcat())); }
template<class _F> inline
        const _F& __cdecl use_facet(const locale& _L, const _F *,
                bool _Cfacet)
        {static const locale::facet *_Psave = 0;
        _Lockit _Lk;
        size_t _Id = _F::id;
        const locale::facet *_Pf = _L._Getfacet(_Id, true);
        if (_Pf != 0)
                ;
        else if (!_Cfacet || !_L._Iscloc())
                throw bad_cast("missing locale facet");
        else if (_Psave == 0)
                _Pf = _Psave = _Tidyfac<_F>::_Save(new("c:\\program files\\microsoft visual studio\\vc98\\include\\xlocale", 168) _F);
        else
                _Pf = _Psave;
        return (*(const _F *)_Pf); }
                

template<class _E> inline
        int _Narrow(_E _C)      
        {return ((unsigned char)(char)_C); }
inline int _Narrow(wchar_t _C)
        {return (wctob(_C)); }
                

template<class _E> inline
        _E _Widen(char _Ch, _E *)       
        {return (_Ch); }
inline wchar_t _Widen(char _Ch, wchar_t *)
        {return (btowc(_Ch)); }
                
template<class _E, class _II> inline
        int __cdecl _Getloctxt(_II& _F, _II& _L, size_t _N,
                const _E *_S)
        {for (size_t _I = 0; _S[_I] != (_E)0; ++_I)
                if (_S[_I] == _S[0])
                        ++_N;
        string _Str(_N, '\0');
        int _Ans = -2;
        for (size_t _J = 1; ; ++_J, ++_F, _Ans = -1)
                {bool  _Pfx;
                size_t _I, _K;
                for (_I = 0, _K = 0, _Pfx = false; _K < _N; ++_K)
                        {for (; _S[_I] != (_E)0 && _S[_I] != _S[0]; ++_I)
                                ;
                        if (_Str[_K] != '\0')
                                _I += _Str[_K];
                        else if (_S[_I += _J] == _S[0] || _S[_I] == (_E)0)
                                {_Str[_K] = _J < 127 ? _J : 127;
                                _Ans = _K; }
                        else if (_F == _L || _S[_I] != *_F)
                                _Str[_K] = _J < 127 ? _J : 127;
                        else
                                _Pfx = true; }
                if (!_Pfx || _F == _L)
                        break; }
        return (_Ans); }
                

template<class _E> inline
        _E *__cdecl _Maklocstr(const char *_S, _E *)
        {size_t _L = strlen(_S) + 1;
        _E *_X = new("c:\\program files\\microsoft visual studio\\vc98\\include\\xlocale", 218) _E[_L];
        for (_E *_P = _X; 0 < _L; --_L, ++_P, ++_S)
                *_P = _Widen(*_S, (_E *)0);
        return (_X); }
                
class  codecvt_base : public locale::facet {
public:
        enum _Result {ok, partial, error, noconv};
        typedef int result;
        codecvt_base(size_t _R = 0)
                : locale::facet(_R) {}
        bool always_noconv() const throw ()
                {return (do_always_noconv()); }
        int max_length() const throw ()
                {return (do_max_length()); }
        int encoding() const throw ()
                {return (do_encoding()); }
protected:
        virtual bool do_always_noconv() const throw ()
                {return (true); }
        virtual int do_max_length() const throw ()
                {return (1); }
        virtual int do_encoding() const throw ()
                {return (1); }
        };
;
                
template<class _E, class _To, class _St>
        class codecvt : public codecvt_base {
public:
        typedef _E from_type;
        typedef _To to_type;
        typedef _St state_type;
        result in(_St& _State,
                const _To *_F1, const _To *_L1, const _To *& _Mid1,
                _E *_F2, _E *_L2, _E *& _Mid2) const
                {return (do_in(_State,
                        _F1, _L1, _Mid1, _F2, _L2, _Mid2)); }
        result out(_St& _State,
                const _E *_F1, const _E *_L1, const _E *& _Mid1,
                _To *_F2, _To *_L2, _To *& _Mid2) const
                {return (do_out(_State,
                        _F1, _L1, _Mid1, _F2, _L2, _Mid2)); }
        int length(_St& _State, const _E *_F1,
                const _E *_L1, size_t _N2) const throw ()
                {return (do_length(_State, _F1, _L1, _N2)); }
        static locale::id id;
        explicit codecvt(size_t _R = 0)
                : codecvt_base(_R) {_Init(_Locinfo()); }
        codecvt(const _Locinfo& _Lobj, size_t _R = 0)
                : codecvt_base(_R) {_Init(_Lobj); }
        static size_t __cdecl _Getcat()
                {return (2); }
public:
        virtual ~codecvt()
                {};
protected:
        void _Init(const _Locinfo& _Lobj)
                {_Cvt = _Lobj._Getcvt(); }
        virtual result do_in(_St& _State,
                const _To *_F1, const _To *, const _To *& _Mid1,
                _E *_F2, _E *, _E *& _Mid2) const
                {_Mid1 = _F1, _Mid2 = _F2;
                return (noconv); }
        virtual result do_out(_St& _State,
                const _E *_F1, const _E *, const _E *& _Mid1,
                _To *_F2, _To *, _To *& _Mid2) const
                {_Mid1 = _F1, _Mid2 = _F2;
                return (noconv); }
        virtual int do_length(_St& _State, const _E *_F1,
                const _E *_L1, size_t _N2) const throw ()
                {return (_N2 < _L1 - _F1 ? _N2 : _L1 - _F1); }
private:
        _Locinfo::_Cvtvec _Cvt;
        };
template<class _E, class _To, class _St>
        locale::id codecvt<_E, _To, _St>::id;
                
class  codecvt<wchar_t, char, mbstate_t> : public codecvt_base {
public:
        typedef wchar_t _E;
        typedef char _To;
        typedef mbstate_t _St;
        typedef _E from_type;
        typedef _To to_type;
        typedef _St state_type;
        result in(_St& _State,
                const _To *_F1, const _To *_L1, const _To *& _Mid1,
                _E *_F2, _E *_L2, _E *& _Mid2) const
                {return (do_in(_State,
                        _F1, _L1, _Mid1, _F2, _L2, _Mid2)); }
        result out(_St& _State,
                const _E *_F1, const _E *_L1, const _E *& _Mid1,
                _To *_F2, _To *_L2, _To *& _Mid2) const
                {return (do_out(_State,
                        _F1, _L1, _Mid1, _F2, _L2, _Mid2)); }
        int length(_St& _State, const _E *_F1,
                const _E *_L1, size_t _N2) const throw ()
                {return (do_length(_State, _F1, _L1, _N2)); }
        static locale::id id;
        explicit codecvt(size_t _R = 0)
                : codecvt_base(_R) {_Init(_Locinfo()); }
        codecvt(const _Locinfo& _Lobj, size_t _R = 0)
                : codecvt_base(_R) {_Init(_Lobj); }
        static size_t __cdecl _Getcat()
                {return (2); }
public:
        virtual ~codecvt()
                {};
protected:
        void _Init(const _Locinfo& _Lobj)
                {_Cvt = _Lobj._Getcvt(); }
        virtual result do_in(_St& _State,
                const _To *_F1, const _To *_L1, const _To *& _Mid1,
                _E *_F2, _E *_L2, _E *& _Mid2) const
                {_Mid1 = _F1, _Mid2 = _F2;
                result _Ans = _Mid1 == _L1 ? ok : partial;
                int _N;
                while (_Mid1 != _L1 && _Mid2 != _L2)
                        switch (_N =
                                _Mbrtowc(_Mid2, _Mid1, _L1 - _Mid1,
                                        &_State, &_Cvt))
                        {case -2:
                                _Mid1 = _L1;
                                return (_Ans);
                        case -1:
                                return (error);
                        case 0:
                                _N = strlen(_Mid1) + 1;
                        default:        
                                _Mid1 += _N, ++_Mid2, _Ans = ok; }
                return (_Ans); }
        virtual result do_out(_St& _State,
                const _E *_F1, const _E *_L1, const _E *& _Mid1,
                _To *_F2, _To *_L2, _To *& _Mid2) const
                {_Mid1 = _F1, _Mid2 = _F2;
                result _Ans = _Mid1 == _L1 ? ok : partial;
                int _N;
                while (_Mid1 != _L1 && _Mid2 != _L2)
                        if (__mb_cur_max <= _L2 - _Mid2)
                                if ((_N =
                                        _Wcrtomb(_Mid2, *_Mid1, &_State,
                                                &_Cvt)) <= 0)
                                        return (error);
                                else
                                        ++_Mid1, _Mid2 += _N, _Ans = ok;
                        else
                                {_To _Buf[2];
                                _St _Stsave = _State;
                                if ((_N =
                                        _Wcrtomb(_Buf, *_Mid1, &_State,
                                                &_Cvt)) <= 0)
                                        return (error);
                                else if (_L2 - _Mid2 < _N)
                                        {_State = _Stsave;
                                        return (_Ans); }
                                else
                                        {memcpy(_Mid2, _Buf, _N);
                                        ++_Mid1, _Mid2 += _N, _Ans = ok; }}
                return (_Ans); }
        virtual int do_length(_St& _State, const _E *_F1,
                const _E *_L1, size_t _N2) const throw ()
                {const _E *_Mid1;
                _To _Buf[2];
                int _N;
                for (_Mid1 = _F1; _Mid1 != _L1 && 0 < _N2;
                        ++_Mid1, _N2 -= _N)
                        if ((_N =
                                _Wcrtomb(_Buf, *_Mid1, &_State, &_Cvt)) <= 0
                                        || _N2 < _N)
                                break;
                return (_Mid1 - _F1); }
        virtual bool do_always_noconv() const throw ()
                {return (false); }
        virtual int do_max_length() const throw ()
                {return (2); }
        virtual int do_encoding() const throw ()
                {return (0); }
private:
        _Locinfo::_Cvtvec _Cvt;
        };
                
template<class _E, class _To, class _St>
        class codecvt_byname : public codecvt<_E, _To, _St> {
public:
        explicit codecvt_byname(const char *_S, size_t _R = 0)
                : codecvt<_E, _To, _St>(_Locinfo(_S), _R) {}
public:
        virtual ~codecvt_byname()
                {}
        };
                
struct  ctype_base : public locale::facet {
        enum _Mask {alnum = 0x4|0x2|0x1|0x100, alpha = 0x2|0x1|0x100,
                cntrl = 0x20, digit = 0x4, graph = 0x4|0x2|0x10|0x1|0x100,
                lower = 0x2, print = 0x4|0x2|0x10|0x40|0x1|0x100|0x80,
                punct = 0x10, space = 0x8|0x40|0x000, upper = 0x1,
                xdigit = 0x80};

        typedef short mask;     
        ctype_base(size_t _R = 0)
                : locale::facet(_R) {}
        };
                
template<class _E>
        class ctype : public ctype_base {
public:
        typedef _E char_type;
        bool is(mask _M, _E _C) const
                {return (do_is(_M, _C)); }
        const _E *is(const _E *_F, const _E *_L, mask *_V) const
                {return (do_is(_F, _L, _V)); }
        const _E *scan_is(mask _M, const _E *_F,
                const _E *_L) const
                {return (do_scan_is(_M, _F, _L)); }
        const _E *scan_not(mask _M, const _E *_F,
                const _E *_L) const
                {return (do_scan_not(_M, _F, _L)); }
        _E tolower(_E _C) const
                {return (do_tolower(_C)); }
        const _E *tolower(_E *_F, const _E *_L) const
                {return (do_tolower(_F, _L)); }
        _E toupper(_E _C) const
                {return (do_toupper(_C)); }
        const _E *toupper(_E *_F, const _E *_L) const
                {return (do_toupper(_F, _L)); }
        _E widen(char _X) const
                {return (do_widen(_X)); }
        const char *widen(const char *_F, const char *_L,
                _E *_V) const
                {return (do_widen(_F, _L, _V)); }
        char narrow(_E _C, char _D = '\0') const
                {return (do_narrow(_C, _D)); }
        const _E *narrow(const _E *_F, const _E *_L, char _D,
                char *_V) const
                {return (do_narrow(_F, _L, _D, _V)); }
        static locale::id id;
        explicit ctype(size_t _R = 0)
                : ctype_base(_R) {_Init(_Locinfo()); }
        ctype(const _Locinfo& _Lobj, size_t _R = 0)
                : ctype_base(_R) {_Init(_Lobj); }
        static size_t __cdecl _Getcat()
                {return (2); }
public:
        virtual ~ctype()
                {if (_Ctype._Delfl)
                        free((void *)_Ctype._Table); }
protected:
        void _Init(const _Locinfo& _Lobj)
                {_Ctype = _Lobj._Getctype(); }
        virtual bool do_is(mask _M, _E _C) const
                {return ((_Ctype._Table[narrow(_C)] & _M) != 0); }
        virtual const _E *do_is(const _E *_F, const _E *_L,
                mask *_V) const
                {for (; _F != _L; ++_F, ++_V)
                        *_V = _Ctype._Table[narrow(*_F)];
                return (_F); }
        virtual const _E *do_scan_is(mask _M, const _E *_F,
                const _E *_L) const
                {for (; _F != _L && !is(_M, *_F); ++_F)
                        ;
                return (_F); }
        virtual const _E *do_scan_not(mask _M, const _E *_F,
                const _E *_L) const
                {for (; _F != _L && is(_M, *_F); ++_F)
                        ;
                return (_F); }
        virtual _E do_tolower(_E _C) const
                {return ((_E)widen((char)_Tolower(narrow(_C), &_Ctype))); }
        virtual const _E *do_tolower(_E *_F, const _E *_L) const
                {for (; _F != _L; ++_F)
                        *_F = (_E)_Tolower(*_F, &_Ctype);
                return ((const _E *)_F); }
        virtual _E do_toupper(_E _C) const
                {return ((_E)widen((char)_Toupper(narrow(_C), &_Ctype))); }
        virtual const _E *do_toupper(_E *_F, const _E *_L) const
                {for (; _F != _L; ++_F)
                        *_F = (_E)_Toupper(*_F, &_Ctype);
                return ((const _E *)_F); }
        virtual _E do_widen(char _X) const
                {return (_Widen(_X, (_E *)0)); }
        virtual const char *do_widen(const char *_F, const char *_L,
                _E *_V) const
                {for (; _F != _L; ++_F, ++_V)
                        *_V = _Widen(*_F, (_E *)0);
                return (_F); }
        virtual char do_narrow(_E _C, char) const
                {return ((char)_Narrow((_E)(_C))); }
        virtual const _E *do_narrow(const _E *_F, const _E *_L,
                char, char *_V) const
                {for (; _F != _L; ++_F, ++_V)
                        *_V = (char)_Narrow((_E)(*_F));
                return (_F); }
private:
        _Locinfo::_Ctypevec _Ctype;
        };

template<class _E>
        locale::id ctype<_E>::id;

                
class  ctype<char> : public ctype_base {
public:
        typedef char _E;
        typedef _E char_type;
        bool is(mask _M, _E _C) const
                {return ((_Ctype._Table[(unsigned char)_C] & _M) != 0); }
        const _E *is(const _E *_F, const _E *_L, mask *_V) const
                {for (; _F != _L; ++_F, ++_V)
                        *_V = _Ctype._Table[(unsigned char)*_F];
                return (_F); }
        const _E *scan_is(mask _M, const _E *_F,
                const _E *_L) const
                {for (; _F != _L && !is(_M, *_F); ++_F)
                        ;
                return (_F); }
        const _E *scan_not(mask _M, const _E *_F,
                const _E *_L) const
                {for (; _F != _L && is(_M, *_F); ++_F)
                        ;
                return (_F); }
        _E tolower(_E _C) const
                {return (do_tolower(_C)); }
        const _E *tolower(_E *_F, const _E *_L) const
                {return (do_tolower(_F, _L)); }
        _E toupper(_E _C) const
                {return (do_toupper(_C)); }
        const _E *toupper(_E *_F, const _E *_L) const
                {return (do_toupper(_F, _L)); }
        _E widen(char _X) const
                {return (_X); }
        const _E *widen(const char *_F, const char *_L, _E *_V) const
                {memcpy(_V, _F, _L - _F);
                return (_L); }
        _E narrow(_E _C, char _D = '\0') const
                {return (_C); }
        const _E *narrow(const _E *_F, const _E *_L, char _D,
                char *_V) const
                {memcpy(_V, _F, _L - _F);
                return (_L); }
        static locale::id id;
        explicit ctype(const mask *_Tab = 0, bool _Df = false,
                size_t _R = 0)
                : ctype_base(_R)
                {_Lockit Lk;
                _Init(_Locinfo());
                if (_Ctype._Delfl)
                        free((void *)_Ctype._Table), _Ctype._Delfl = false;
                if (_Tab == 0)
                        _Ctype._Table = _Cltab;
                else
                        _Ctype._Table = _Tab, _Ctype._Delfl = _Df; }
        ctype(const _Locinfo& _Lobj, size_t _R = 0)
                : ctype_base(_R) {_Init(_Lobj); }
        static size_t __cdecl _Getcat()
                {return (2); }
        static const size_t table_size;
public:
        virtual ~ctype()
                {if (_Ctype._Delfl)
                        free((void *)_Ctype._Table); }
protected:
        static void __cdecl _Term(void)
                {free((void *)_Cltab); }
        void _Init(const _Locinfo& _Lobj)
                {_Lockit Lk;
                _Ctype = _Lobj._Getctype();
                if (_Cltab == 0)
                        {_Cltab = _Ctype._Table;
                        atexit(_Term);
                        _Ctype._Delfl = false; }}
        virtual _E do_tolower(_E _C) const
                {return (_E)(_Tolower((unsigned char)_C, &_Ctype)); }
        virtual const _E *do_tolower(_E *_F, const _E *_L) const
                {for (; _F != _L; ++_F)
                        *_F = (_E)_Tolower(*_F, &_Ctype);
                return ((const _E *)_F); }
        virtual _E do_toupper(_E _C) const
                {return ((_E)_Toupper((unsigned char)_C, &_Ctype)); }
        virtual const _E *do_toupper(_E *_F, const _E *_L) const
                {for (; _F != _L; ++_F)
                        *_F = (_E)_Toupper(*_F, &_Ctype);
                return ((const _E *)_F); }
        const mask *table() const throw ()
                {return (_Ctype._Table); }
        static const mask * __cdecl classic_table() throw ()
                {_Lockit Lk;
                if (_Cltab == 0)
                        locale::classic();      
                return (_Cltab); }
private:
        _Locinfo::_Ctypevec _Ctype;
        static const mask *_Cltab;
        };


                
template<class _E>
        class ctype_byname : public ctype<_E> {
public:
        explicit ctype_byname(const char *_S, size_t _R = 0)
                : ctype<_E>(_Locinfo(_S), _R) {}
public:
        virtual ~ctype_byname()
                {}
        };








};

#pragma pack(pop)
#line 636 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocale"

#line 638 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocale"





#line 10 "c:\\program files\\microsoft visual studio\\vc98\\include\\xiosbase"


#pragma pack(push,8)
#line 14 "c:\\program files\\microsoft visual studio\\vc98\\include\\xiosbase"
namespace std {
                
class  ios_base {
public:
                        
        class failure : public runtime_error {
        public:
                explicit failure(const string &_S)
                        : runtime_error(_S) {}
                virtual ~failure()
                        {}
        protected:
                virtual void _Doraise() const
                        {throw (*this); }
        };
        enum _Fmtflags {skipws = 0x0001, unitbuf = 0x0002,
                uppercase = 0x0004, showbase = 0x0008,
                showpoint = 0x0010, showpos = 0x0020,
                left = 0x0040, right = 0x0080, internal = 0x0100,
                dec = 0x0200, oct = 0x0400, hex = 0x0800,
                scientific = 0x1000, fixed = 0x2000, boolalpha = 0x4000,
                adjustfield = 0x01c0, basefield = 0x0e00,
                floatfield = 0x3000, _Fmtmask = 0x7fff, _Fmtzero = 0};
        enum _Iostate {goodbit = 0x0, eofbit = 0x1,
                failbit = 0x2, badbit = 0x4, _Statmask = 0x7};
        enum _Openmode {in = 0x01, out = 0x02, ate = 0x04,
                app = 0x08, trunc = 0x10, binary = 0x20};
        enum seekdir {beg = 0, cur = 1, end = 2};
        enum event {erase_event, imbue_event, copyfmt_event};
        typedef void (__cdecl *event_callback)(event, ios_base&, int);
        typedef int fmtflags;
        typedef int iostate;
        typedef int openmode;
        typedef short io_state, open_mode, seek_dir;
                        
        class  Init {
        public:
                Init();
                ~Init();
        private:
                static int _Init_cnt;
                };
        ios_base& operator=(const ios_base& _R)
                {if (this != &_R)
                        {_State = _R._State;
                        copyfmt(_R); }
                return (*this); }
        operator void *() const
                {return (fail() ? 0 : (void *)this); }
        bool operator!() const
                {return (fail()); }
        void clear(iostate = goodbit, bool = false);
        void clear(io_state _St)
                {clear((iostate)_St); }
        iostate rdstate() const
                {return (_State); }
        void setstate(iostate _St, bool _Ex = false)
                {if (_St != goodbit)
                        clear((iostate)((int)rdstate() | (int)_St), _Ex); }
        void setstate(io_state _St)
                {setstate((iostate)_St); }
        bool good() const
                {return (rdstate() == goodbit); }
        bool eof() const
                {return ((int)rdstate() & (int)eofbit); }
        bool fail() const
                {return (((int)rdstate() & ((int)badbit | (int)failbit)) != 0); }
        bool bad() const
                {return (((int)rdstate() & (int)badbit) != 0); }
        iostate exceptions() const
                {return (_Except); }
        void exceptions(iostate _Ne)
                {_Except = _Ne & _Statmask;
                clear(_State); }
        void exceptions(io_state _St)
                {exceptions((iostate)_St); }
        fmtflags flags() const
                {return (_Fmtfl); }
        fmtflags flags(fmtflags _Nf)
                {fmtflags _Of = _Fmtfl;
                _Fmtfl = _Nf & _Fmtmask;
                return (_Of); }
        fmtflags setf(fmtflags _Nf)
                {ios_base::fmtflags _Of = _Fmtfl;
                _Fmtfl |= _Nf & _Fmtmask;
                return (_Of); }
        fmtflags setf(fmtflags _Nf, fmtflags _M)
                {ios_base::fmtflags _Of = _Fmtfl;
                _Fmtfl = (_Fmtfl & ~_M) | (_Nf & _M & _Fmtmask);
                return (_Of); }
        void unsetf(fmtflags _M)
                {_Fmtfl &= ~_M; }
        streamsize precision() const
                {return (_Prec); }
        streamsize precision(int _Np)
                {streamsize _Op = _Prec;
                _Prec = _Np;
                return (_Op); }
        streamsize width() const
                {return (_Wide); }
        streamsize width(streamsize _Nw)
                {streamsize _Ow = _Wide;
                _Wide = _Nw;
                return (_Ow); }
        locale getloc() const
                {return (_Loc); }
        locale imbue(const locale&);
        static int __cdecl xalloc()
                {_Lockit _Lk;
                return (_Index++); }
        long& iword(int _Idx)
                {return (_Findarr(_Idx)._Lo); }
        void *& pword(int _Idx)
                {return (_Findarr(_Idx)._Vp); }
        void register_callback(event_callback, int);
        ios_base& copyfmt(const ios_base&);
        virtual ~ios_base();
        static bool __cdecl sync_with_stdio(bool _Sfl = true)
                {_Lockit _Lk;
                const bool _Osfl = _Sync;
                _Sync = _Sfl;
                return (_Osfl); }
protected:
        ios_base()
                : _Loc(_Noinit), _Stdstr(0) {}
        void _Addstd();
        void _Init();
private:
                        
        struct _Iosarray {
        public:
                _Iosarray(int _Idx, _Iosarray *_Link)
                        : _Next(_Link), _Index(_Idx), _Lo(0), _Vp(0) {}
                _Iosarray *_Next;
                int _Index;
                long _Lo;
                void *_Vp;
                };
                        
        struct _Fnarray {
                _Fnarray(int _Idx, event_callback _P, _Fnarray *_Link)
                        : _Next(_Link), _Index(_Idx), _Pfn(_P) {}
                _Fnarray *_Next;
                int _Index;
                event_callback _Pfn;
                };
        void _Callfns(event);
        _Iosarray& _Findarr(int);
        void _Tidy();
        iostate _State, _Except;
        fmtflags _Fmtfl;
        int _Prec, _Wide;
        _Iosarray *_Arr;
        _Fnarray *_Calls;
        locale _Loc;
        size_t _Stdstr;
        static int _Index;
        static bool _Sync;
        };



};

#pragma pack(pop)
#line 180 "c:\\program files\\microsoft visual studio\\vc98\\include\\xiosbase"

#line 182 "c:\\program files\\microsoft visual studio\\vc98\\include\\xiosbase"





#line 14 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocnum"


#pragma pack(push,8)
#line 18 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocnum"
namespace std {
		
template<class _E>
	class numpunct : public locale::facet {
public:
	typedef basic_string<_E, char_traits<_E>, allocator<_E> >
		string_type;
	typedef _E char_type;
	static locale::id id;
	_E decimal_point() const
		{return (do_decimal_point()); }
	_E thousands_sep() const
		{return (do_thousands_sep()); }
	string grouping() const
		{return (do_grouping()); }
	string_type falsename() const
		{return (do_falsename()); }
	string_type truename() const
		{return (do_truename()); }
	explicit numpunct(size_t _R = 0)
		: locale::facet(_R) {_Init(_Locinfo()); }
	numpunct(const _Locinfo& _Lobj, size_t _R = 0)
		: locale::facet(_R) {_Init(_Lobj); }
	static size_t __cdecl _Getcat()
		{return (4); }
public:
	virtual ~numpunct()
		{delete[] _Gr;
		delete[] _Nf;
		delete[] _Nt; }
protected:
	void _Init(const _Locinfo& _Lobj)
		{const lconv *_P = _Lobj._Getlconv();
		_Dp = _Widen(_P->decimal_point[0], (_E *)0);
		_Ks = _Widen(_P->thousands_sep[0], (_E *)0);
		_Gr = _Maklocstr(_P->grouping, (char *)0);
		_Nf = _Maklocstr(_Lobj._Getfalse(), (_E *)0);
		_Nt = _Maklocstr(_Lobj._Gettrue(), (_E *)0); }
	virtual _E do_decimal_point() const
		{return (_Dp); }
	virtual _E do_thousands_sep() const
		{return (_Ks); }
	virtual string do_grouping() const
		{return (string(_Gr)); }
	virtual string_type do_falsename() const
		{return (string_type(_Nf)); }
	virtual string_type do_truename() const
		{return (string_type(_Nt)); }
private:
	char *_Gr;
	_E _Dp, _Ks, *_Nf, *_Nt;
	};
typedef numpunct<char> _Npc;
typedef numpunct<wchar_t> _Npwc;
		
template<class _E>
	class numpunct_byname : public numpunct<_E> {
public:
	explicit numpunct_byname(const char *_S, size_t _R = 0)
		: numpunct<_E>(_Locinfo(_S), _R) {}
public:
	virtual ~numpunct_byname()
		{}
	};
template<class _E>
	locale::id numpunct<_E>::id;
 

template<class _E> inline
	bool (isdigit)(_E _C, const locale& _L)
	{return (use_facet(_L, (ctype<_E> *)0, true).is(ctype_base::digit, _C)); }

		
template<class _E,
	class _II = istreambuf_iterator<_E, char_traits<_E> > >
	class num_get : public locale::facet {
public:
	typedef numpunct<_E> _Mypunct;
	typedef basic_string<_E, char_traits<_E>, allocator<_E> >
		_Mystr;
	static size_t __cdecl _Getcat()
		{return (4); }
	static locale::id id;
public:
	virtual ~num_get()
		{}
protected:
	void _Init(const _Locinfo& _Lobj)
		{}
public:
	explicit num_get(size_t _R = 0)
		: locale::facet(_R) {_Init(_Locinfo()); }
	num_get(const _Locinfo& _Lobj, size_t _R = 0)
		: locale::facet(_R) {_Init(_Lobj); }
	typedef _E char_type;
	typedef _II iter_type;
	_II get(_II _F, _II _L, ios_base& _X, ios_base::iostate& _St,
		_Bool& _V) const
		{return (do_get(_F, _L, _X, _St, _V)); }
	_II get(_II _F, _II _L, ios_base& _X, ios_base::iostate& _St,
		unsigned short& _V) const
		{return (do_get(_F, _L, _X, _St, _V)); }
	_II get(_II _F, _II _L, ios_base& _X, ios_base::iostate& _St,
		unsigned int& _V) const
		{return (do_get(_F, _L, _X, _St, _V)); }
	_II get(_II _F, _II _L, ios_base& _X, ios_base::iostate& _St,
		long& _V) const
		{return (do_get(_F, _L, _X, _St, _V)); }
	_II get(_II _F, _II _L, ios_base& _X, ios_base::iostate& _St,
		unsigned long& _V) const
		{return (do_get(_F, _L, _X, _St, _V)); }
	_II get(_II _F, _II _L, ios_base& _X, ios_base::iostate& _St,
		float& _V) const
		{return (do_get(_F, _L, _X, _St, _V)); }
	_II get(_II _F, _II _L, ios_base& _X, ios_base::iostate& _St,
		double& _V) const
		{return (do_get(_F, _L, _X, _St, _V)); }
	_II get(_II _F, _II _L, ios_base& _X, ios_base::iostate& _St,
		long double& _V) const
		{return (do_get(_F, _L, _X, _St, _V)); }
	_II get(_II _F, _II _L, ios_base& _X, ios_base::iostate& _St,
		void *& _V) const
		{return (do_get(_F, _L, _X, _St, _V)); }
protected:
	virtual _II do_get(_II _F, _II _L, ios_base& _X,
		ios_base::iostate& _St, _Bool& _V) const
		{int _Ans = -1;
		if (_X.flags() & ios_base::boolalpha)
			{const _Mypunct& _Fac = use_facet(_X.getloc(), (_Mypunct *)0, true);
			_Mystr _Str(1, (_E)0);
			_Str += _Fac.falsename();
			_Str += (_E)0;
			_Str += _Fac.truename();
			_Ans = _Getloctxt(_F, _L, (size_t)2, _Str.c_str()); }
		else
			{char _Ac[32], *_Ep;
			errno = 0;
			const unsigned long _Ulo = strtoul(_Ac, &_Ep,
				_Getifld(_Ac, _F, _L, _X.flags(), _X.getloc()));
			if (_Ep != _Ac && errno == 0 && _Ulo <= 1)
				_Ans = _Ulo; }
		if (_F == _L)
			_St |= ios_base::eofbit;
		if (_Ans < 0)
			_St |= ios_base::failbit;
		else
			_V = _Ans != 0;
		return (_F); }
	virtual _II do_get(_II _F, _II _L, ios_base& _X,
		ios_base::iostate& _St, unsigned short& _V) const
		{char _Ac[32], *_Ep;
		errno = 0;
		int _Base =
			_Getifld(_Ac, _F, _L, _X.flags(), _X.getloc());
		char *_S = _Ac[0] == '-' ? _Ac + 1 : _Ac;
		const unsigned long _Ans = strtoul(_S, &_Ep, _Base);
		if (_F == _L)
			_St |= ios_base::eofbit;
		if (_Ep == _S || errno != 0 || 0xffff < _Ans)
			_St |= ios_base::failbit;
		else
			_V = (unsigned short)(_Ac[0] == '-' ? -_Ans : _Ans);
		return (_F); }
	virtual _II do_get(_II _F, _II _L, ios_base& _X,
		ios_base::iostate& _St, unsigned int& _V) const
		{char _Ac[32], *_Ep;
		errno = 0;
		int _Base =
			_Getifld(_Ac, _F, _L, _X.flags(), _X.getloc());
		char *_S = _Ac[0] == '-' ? _Ac + 1 : _Ac;
		const unsigned long _Ans = strtoul(_S, &_Ep, _Base);
		if (_F == _L)
			_St |= ios_base::eofbit;
		if (_Ep == _S || errno != 0 || 0xffffffff < _Ans)
			_St |= ios_base::failbit;
		else
			_V = _Ac[0] == '-' ? -_Ans : _Ans;
		return (_F); }
	virtual _II do_get(_II _F, _II _L, ios_base& _X,
		ios_base::iostate& _St, long& _V) const
		{char _Ac[32], *_Ep;
		errno = 0;
		const long _Ans = strtol(_Ac, &_Ep,
			_Getifld(_Ac, _F, _L, _X.flags(), _X.getloc()));
		if (_F == _L)
			_St |= ios_base::eofbit;
		if (_Ep == _Ac || errno != 0)
			_St |= ios_base::failbit;
		else
			_V = _Ans;
		return (_F); }
	virtual _II do_get(_II _F, _II _L, ios_base& _X,
		ios_base::iostate& _St, unsigned long& _V) const
		{char _Ac[32], *_Ep;
		errno = 0;
		const unsigned long _Ans = strtoul(_Ac, &_Ep,
			_Getifld(_Ac, _F, _L, _X.flags(), _X.getloc()));
		if (_F == _L)
			_St |= ios_base::eofbit;
		if (_Ep == _Ac || errno != 0)
			_St |= ios_base::failbit;
		else
			_V = _Ans;
		return (_F); }
	virtual _II do_get(_II _F, _II _L, ios_base& _X,
		ios_base::iostate& _St, float& _V) const
		{char _Ac[8 + 36 + 32], *_Ep;
		errno = 0;
		const float _Ans = _Stof(_Ac, &_Ep,
			_Getffld(_Ac, _F, _L, _X.getloc()));
		if (_F == _L)
			_St |= ios_base::eofbit;
		if (_Ep == _Ac || errno != 0)
			_St |= ios_base::failbit;
		else
			_V = _Ans;
		return (_F); }
	virtual _II do_get(_II _F, _II _L, ios_base& _X,
		ios_base::iostate& _St, double& _V) const
		{char _Ac[8 + 36 + 32], *_Ep;
		errno = 0;
		const double _Ans = _Stod(_Ac, &_Ep,
			_Getffld(_Ac, _F, _L, _X.getloc()));
		if (_F == _L)
			_St |= ios_base::eofbit;
		if (_Ep == _Ac || errno != 0)
			_St |= ios_base::failbit;
		else
			_V = _Ans;
		return (_F); }
	virtual _II do_get(_II _F, _II _L, ios_base& _X,
		ios_base::iostate& _St, long double& _V) const
		{char _Ac[8 + 36 + 32], *_Ep;
		errno = 0;
		const long double _Ans = _Stold(_Ac, &_Ep,
			_Getffld(_Ac, _F, _L, _X.getloc()));
		if (_F == _L)
			_St |= ios_base::eofbit;
		if (_Ep == _Ac || errno != 0)
			_St |= ios_base::failbit;
		else
			_V = _Ans;
		return (_F); }
	virtual _II do_get(_II _F, _II _L, ios_base& _X,
		ios_base::iostate& _St, void *& _V) const
		{union _Pvlo {
			void *_Pv;
			unsigned long _Lo[1 +
				(sizeof (void *) - 1) / sizeof (unsigned long)];
			} _U;
		const int _NL = sizeof (_U._Lo) / sizeof (unsigned long);
		for (int _I = 0; ; ++_F)
			{char _Ac[32], *_Ep;
			errno = 0;
			_U._Lo[_I] = strtoul(_Ac, &_Ep,
				_Getifld(_Ac, _F, _L,
					ios_base::hex, _X.getloc()));
			if (_F == _L)
				_St |= ios_base::eofbit;
			if (_Ep == _Ac || errno != 0)
				{_St |= ios_base::failbit;
				break; }
			if (_NL <= ++_I)
				break;
			if (_F == _L || *_F != _Widen(':', (_E *)0))
				{_St |= ios_base::failbit;
				break; }}
		if (!(_St & ios_base::failbit))
			_V = _U._Pv;
		return (_F); }
private:
	static int __cdecl _Getifld(char *_Ac, _II& _F, _II& _L,
		ios_base::fmtflags _Bfl, const locale& _Loc)
		{const _E _E0 = _Widen('0', (_E *)0);
		const _Mypunct& _Fac = use_facet(_Loc, (_Mypunct *)0, true);
		const string _Gr = _Fac.grouping();
		const _E _Ks = _Fac.thousands_sep();
		char *_P = _Ac;
		if (_F == _L)
			;
		else if (*_F == _Widen('+', (_E *)0))
			*_P++ = '+', ++_F;
		else if (*_F == _Widen('-', (_E *)0))
			*_P++ = '-', ++_F;
		_Bfl &= ios_base::basefield;
		int _Base = _Bfl == ios_base::oct ? 8
			: _Bfl == ios_base::hex ? 16
			: _Bfl == ios_base::_Fmtzero ? 0 : 10;
		bool _Sd = false, _Snz = false;
		if (_F != _L && *_F == _E0)
			{_Sd = true, ++_F;
			if (_F != _L && (*_F == _Widen('x', (_E *)0)
					|| *_F == _Widen('X', (_E *)0))
				&& (_Base == 0 || _Base == 16))
				_Base = 16, _Sd = false, ++_F;
			else if (_Base == 0)
				_Base = 8; }
		int _Dlen = _Base == 0 || _Base == 10 ? 10
			: _Base == 8 ? 8 : 16 + 6;
		string _Grin(1, _Sd ? '\1' : '\0');
		size_t _I = 0;
		for (char *const _Pe = &_Ac[32 - 1];
			_F != _L; ++_F)
			if (memchr("0123456789abcdefABCDEF",
				*_P = (char)_Narrow((_E)(*_F)), _Dlen) != 0)
				{if ((_Snz || *_P != '0') && _P < _Pe)
					++_P, _Snz = true;
				_Sd = true;
				if (_Grin[_I] != 127)
					++_Grin[_I]; }
			else if (_Grin[_I] == '\0' || _Ks == (_E)0
				|| *_F != _Ks)
				break;
			else
				_Grin.append(1, '\0'), ++_I;
		if (_I == 0)
			;
		else if ('\0' < _Grin[_I])
			++_I;
		else
			_Sd = false;
		for (const char *_Pg = _Gr.c_str(); _Sd && 0 < _I; --_I)
			if (*_Pg == 127)
				break;
			else if (0 < --_I && *_Pg != _Grin[_I]
				|| 0 == _I && *_Pg < _Grin[_I])
				_Sd = false;
			else if ('\0' < _Pg[1])
				++_Pg;
		if (_Sd && !_Snz)
			*_P++ = '0';
		else if (!_Sd)
			_P = _Ac;
		*_P = '\0';
		return (_Base);
		}
	static int __cdecl _Getffld(char *_Ac, _II& _F, _II &_L,
		const locale& _Loc)
		{const _E _E0 = _Widen('0', (_E *)0);
		const _Mypunct& _Fac = use_facet(_Loc, (_Mypunct *)0, true);
		char *_P = _Ac;
		if (_F == _L)
			;
		else if (*_F == _Widen('+', (_E *)0))
			*_P++ = '+', ++_F;
		else if (*_F == _Widen('-', (_E *)0))
			*_P++ = '-', ++_F;
		bool _Sd = false;
		for (; _F != _L && *_F == _E0; _Sd = true, ++_F)
			;
		if (_Sd)
			*_P++ = '0';
		int _Ns = 0;
		int _Pten = 0;
		for (; _F != _L && isdigit(*_P = (char)_Narrow((_E)(*_F)), _Loc);
			_Sd = true, ++_F)
			if (_Ns < 36)
				++_P, ++_Ns;
			else
				++_Pten;
		if (_F != _L && *_F == _Fac.decimal_point())
			*_P++ = localeconv()->decimal_point[0], ++_F;
		if (_Ns == 0)
			{for (; _F != _L && *_F == _E0; _Sd = true, ++_F)
				--_Pten;
			if (_Pten < 0)
				*_P++ = '0', ++_Pten; }
		for (; _F != _L && isdigit(*_P = (char)_Narrow((_E)(*_F)), _Loc);
			_Sd = true, ++_F)
			if (_Ns < 36)
				++_P, ++_Ns;
		if (_Sd && _F != 
_L
&& (*_F == _Widen('e', (_E *)0) || *_F == _Widen('E', (_E *)0)))
			{*_P++ = 'e', ++_F;
			_Sd = false, _Ns = 0;
			if (_F == _L)
				;
			else if (*_F == _Widen('+', (_E *)0))
				*_P++ = '+', ++_F;
			else if (*_F == _Widen('-', (_E *)0))
				*_P++ = '-', ++_F;
			for (; _F != _L && *_F == _E0; _Sd = true, ++_F)
				;
			if (_Sd)
				*_P++ = '0';
			for (; _F != _L && isdigit(*_P = (char)_Narrow((_E)(*_F)), _Loc);
				_Sd = true, ++_F)
				if (_Ns < 8)
					++_P, ++_Ns; }
		if (!_Sd)
			_P = _Ac;
		*_P = '\0';
		return (_Pten);
		};
	};
template<class _E, class _II>
	locale::id num_get<_E, _II>::id;
		
template<class _E,
	class _OI = ostreambuf_iterator<_E, char_traits<_E> > >
	class num_put : public locale::facet {
public:
	typedef numpunct<_E> _Mypunct;
	typedef basic_string<_E, char_traits<_E>, allocator<_E> >
		_Mystr;
	static size_t __cdecl _Getcat()
		{return (4); }
	static locale::id id;
public:
	virtual ~num_put()
		{}
protected:
	void _Init(const _Locinfo& _Lobj)
		{}
public:
	explicit num_put(size_t _R = 0)
		: locale::facet(_R) {_Init(_Locinfo()); }
	num_put(const _Locinfo& _Lobj, size_t _R = 0)
		: locale::facet(_R) {_Init(_Lobj); }
	typedef _E char_type;
	typedef _OI iter_type;
	_OI put(_OI _F, ios_base& _X, _E _Fill,
		_Bool _V) const
		{return (do_put(_F, _X, _Fill, _V)); }
	_OI put(_OI _F, ios_base& _X, _E _Fill,
		long _V) const
		{return (do_put(_F, _X, _Fill, _V)); }
	_OI put(_OI _F, ios_base& _X, _E _Fill,
		unsigned long _V) const
		{return (do_put(_F, _X, _Fill, _V)); }
	_OI put(_OI _F, ios_base& _X, _E _Fill,
		double _V) const
		{return (do_put(_F, _X, _Fill, _V)); }
	_OI put(_OI _F, ios_base& _X, _E _Fill,
		long double _V) const
		{return (do_put(_F, _X, _Fill, _V)); }
	_OI put(_OI _F, ios_base& _X, _E _Fill,
		const void *_V) const
		{return (do_put(_F, _X, _Fill, _V)); }
protected:
	virtual _OI do_put(_OI _F, ios_base& _X, _E _Fill,
		_Bool _V) const
		{const _Mypunct& _Fac = use_facet(_X.getloc(), (_Mypunct *)0, true);
		_Mystr _Str;
		if (!(_X.flags() & ios_base::boolalpha))
			_Str.append(1, _Widen(_V ? '1' : '0', (_E *)0));
		else if (_V)
			_Str = _Fac.truename();
		else
			_Str = _Fac.falsename();
		size_t _M = _X.width() <= 0 || _X.width() <= _Str.size()
			? 0 : _X.width() - _Str.size();
		ios_base::fmtflags _Afl =
			_X.flags() & ios_base::adjustfield;
		if (_Afl != ios_base::left)
			_F = _Rep(_F, _Fill, _M), _M = 0;
		_F = _Put(_F, _Str.c_str(), _Str.size());
		_X.width(0);
		return (_Rep(_F, _Fill, _M)); }
	virtual _OI do_put(_OI _F, ios_base& _X, _E _Fill,
		long _V) const
		{char _Buf[2 * 32], _Fmt[6];
		return (_Iput(_F, _X, _Fill, _Buf,
			sprintf(_Buf, _Ifmt(_Fmt, 'd', _X.flags()), _V))); }
	virtual _OI do_put(_OI _F, ios_base& _X, _E _Fill,
		unsigned long _V) const
		{char _Buf[2 * 32], _Fmt[6];
		return (_Iput(_F, _X, _Fill, _Buf,
			sprintf(_Buf, _Ifmt(_Fmt, 'u', _X.flags()), _V))); }
	virtual _OI do_put(_OI _F, ios_base& _X, _E _Fill,
		double _V) const
		{char _Buf[8 + 36 + 32], _Fmt[8];
		streamsize _Prec = _X.precision() <= 0
			&& !(_X.flags() & ios_base::fixed) ? 6
			: _X.precision();
		int _Mpr = 36 < _Prec ? 36 : _Prec;
		return (_Fput(_F, _X, _Fill, _Buf, _Prec - _Mpr,
			sprintf(_Buf, _Ffmt(_Fmt, 0, _X.flags()),
				_Mpr, _V))); }
	virtual _OI do_put(_OI _F, ios_base& _X, _E _Fill,
		long double _V) const
		{char _Buf[8 + 36 + 32], _Fmt[8];
		streamsize _Prec = _X.precision() <= 0
			&& !(_X.flags() & ios_base::fixed) ? 6
			: _X.precision();
		int _Mpr = 36 < _Prec ? 36 : _Prec;
		return (_Fput(_F, _X, _Fill, _Buf, _Prec - _Mpr,
			sprintf(_Buf, _Ffmt(_Fmt, 'L', _X.flags()),
				_Mpr, _V))); }
	virtual _OI do_put(_OI _F, ios_base& _X, _E _Fill,
		const void *_V) const
		{
		const int _NL = 1
			+ (sizeof (void *) - 1) / sizeof (unsigned long);
		char _Buf[(_NL + 1) * (32 + 1)];
		int _N = sprintf(_Buf, "%p", _V);
		size_t _M = _X.width() <= 0 || _X.width() <= _N
			? 0 : _X.width() - _N;
		ios_base::fmtflags _Afl =
			_X.flags() & ios_base::adjustfield;
		if (_Afl != ios_base::left)
			_F = _Rep(_F, _Fill, _M), _M = 0;
		_F = _Putc(_F, _Buf, _N);
		_X.width(0);
		return (_Rep(_F, _Fill, _M)); }
	static char *_Ffmt(char *_Fmt, char _Spec,
		ios_base::fmtflags _Fl)
		{char *_S = _Fmt;
		*_S++ = '%';
		if (_Fl & ios_base::showpos)
			*_S++ = '+';
		if (_Fl & ios_base::showpoint)
			*_S++ = '#';
		*_S++ = '.';
		*_S++ = '*';
		if (_Spec != 0)
			*_S++ = _Spec;	
		ios_base::fmtflags _Ffl = _Fl & ios_base::floatfield;
		*_S++ = _Ffl == ios_base::fixed ? 'f'
			: _Ffl == ios_base::scientific ? 'e' : 'g';
		*_S = '\0';
		return (_Fmt); }
	static _OI __cdecl _Fput(_OI _F, ios_base& _X, _E _Fill,
		const char *_S, size_t _Nz, size_t _N)
		{size_t _M = _X.width() <= 0 || _X.width() <= _N  + _Nz
			? 0 : _X.width() - _N - _Nz;
		ios_base::fmtflags _Afl =
			_X.flags() & ios_base::adjustfield;
		if (_Afl != ios_base::left && _Afl != ios_base::internal)
			_F = _Rep(_F, _Fill, _M), _M = 0;
		else if (_Afl == ios_base::internal)
			{if (0 < _N && (*_S == '+' || *_S == '-'))
				_F = _Putc(_F, _S, 1), ++_S, --_N;
			_F = _Rep(_F, _Fill, _M), _M = 0; }
		const char *_P = (const char *)memchr(_S,
			localeconv()->decimal_point[0], _N);
		if (_P != 0)
			{const _Mypunct& _Fac = use_facet(_X.getloc(), (_Mypunct *)0, true);
			size_t _Nf = _P - _S + 1;
			_F = _Putc(_F, _S, _Nf - 1);
			_F = _Rep(_F, _Fac.decimal_point(), 1);
			_S += _Nf, _N -= _Nf; }
		if ((_P = (const char *)memchr(_S, 'e', _N)) != 0)
			{size_t _Nm = _P - _S + 1;
			_F = _Putc(_F, _S, _Nm - 1);
			_F = _Rep(_F, _Widen('0', (_E *)0), _Nz), _Nz = 0;
			_F = _Putc(_F, _X.flags() & ios_base::uppercase
				? "E" : "e", 1);
			_S += _Nm, _N -= _Nm; }
		_F = _Putc(_F, _S, _N);
		_F = _Rep(_F, _Widen('0', (_E *)0), _Nz);
		_X.width(0);
		return (_Rep(_F, _Fill, _M)); }
	static char *__cdecl _Ifmt(char *_Fmt, char _Spec,
		ios_base::fmtflags _Fl)
		{char *_S = _Fmt;
		*_S++ = '%';
		if (_Fl & ios_base::showpos)
			*_S++ = '+';
		if (_Fl & ios_base::showbase)
			*_S++ = '#';
		*_S++ = 'l';
		ios_base::fmtflags _Bfl = _Fl & ios_base::basefield;
		*_S++ = _Bfl == ios_base::oct ? 'o'
			: _Bfl != ios_base::hex ? _Spec	
			: _Fl & ios_base::uppercase ? 'X' : 'x';
		*_S = '\0';
		return (_Fmt); }
	static _OI __cdecl _Iput(_OI _F, ios_base& _X, _E _Fill,
		char *_S, size_t _N)
		{const size_t _Np = *_S == '+' || *_S == '-' ? 1
			: *_S == '0' && (_S[1] == 'x' || _S[1] == 'X') ? 2
			: 0;
		const _Mypunct& _Fac = use_facet(_X.getloc(), (_Mypunct *)0, true);
		const string _Gr = _Fac.grouping();
		const _E _Ks = _Fac.thousands_sep();
		bool _Grp = '\0' < *_Gr.c_str();
		if (_Grp)
			{const char *_Pg = _Gr.c_str();
			size_t _I = _N;
			for (_Grp = false; *_Pg != 127 && '\0' < *_Pg
				&& *_Pg < _I - _Np; _Grp = true)
				{_I -= *_Pg;
				memmove(&_S[_I + 1], &_S[_I], _N + 1 - _I);
				_S[_I] = ',', ++_N;
				if ('\0' < _Pg[1])
					++_Pg; }}
		size_t _M = _X.width() <= 0 || _X.width() <= _N
			? 0 : _X.width() - _N;
		ios_base::fmtflags _Afl =
			_X.flags() & ios_base::adjustfield;
		if (_Afl != ios_base::left && _Afl != ios_base::internal)
			_F = _Rep(_F, _Fill, _M), _M = 0;
		else if (_Afl == ios_base::internal)
			{_F = _Putc(_F, _S, _Np), _S += _Np, _N -= _Np;
			_F = _Rep(_F, _Fill, _M), _M = 0; }
		if (!_Grp)
			_F = _Putc(_F, _S, _N);
		else
			for (; ; ++_S, --_N)
				{size_t _Nd = strcspn(_S, ",");
				_F = _Putc(_F, _S, _Nd);
				_S += _Nd, _N -= _Nd;
				if (_N == 0)
					break;
				if (_Ks != (_E)0)
					_F = _Rep(_F, _Ks, 1); }
		_X.width(0);
		return (_Rep(_F, _Fill, _M)); }
	static _OI _Put(_OI _F, const _E *_S, size_t _N)
		{for (; 0 < _N; --_N, ++_F, ++_S)
			*_F = *_S;
		return (_F); }
	static _OI _Putc(_OI _F, const char *_S, size_t _N)
		{for (; 0 < _N; --_N, ++_F, ++_S)
			*_F = _Widen(*_S, (_E *)0);
		return (_F); }
	static _OI _Rep(_OI _F, _E _C, size_t _N)
		{for (; 0 < _N; --_N, ++_F)
			*_F = _C;
		return (_F); }
	};
template<class _E, class _OI>
	locale::id num_put<_E, _OI>::id;


















};

#pragma pack(pop)
#line 664 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocnum"

#line 666 "c:\\program files\\microsoft visual studio\\vc98\\include\\xlocnum"





#line 10 "c:\\program files\\microsoft visual studio\\vc98\\include\\streambuf"


#pragma pack(push,8)
#line 14 "c:\\program files\\microsoft visual studio\\vc98\\include\\streambuf"
namespace std {
		
template<class _E, class _Tr = char_traits<_E> >
	class basic_streambuf {
protected:
	basic_streambuf()
		: _Loc() {_Init(); }
	basic_streambuf(_Uninitialized)
		: _Loc(_Noinit) {}
public:
	typedef basic_streambuf<_E, _Tr> _Myt;
	typedef _E char_type;
	typedef _Tr traits_type;
	virtual ~basic_streambuf()
		{}
	typedef _Tr::int_type int_type;
	typedef _Tr::pos_type pos_type;
	typedef _Tr::off_type off_type;
	pos_type pubseekoff(off_type _O, ios_base::seekdir _W,
		ios_base::openmode _M = ios_base::in | ios_base::out)
		{return (seekoff(_O, _W, _M)); }
	pos_type pubseekoff(off_type _O, ios_base::seek_dir _W,
		ios_base::open_mode _M)
		{return (pubseekoff(_O, (ios_base::seekdir)_W,
			(ios_base::openmode)_M)); }
	pos_type pubseekpos(pos_type _P,
		ios_base::openmode _M = ios_base::in | ios_base::out)
		{return (seekpos(_P, _M)); }
	pos_type pubseekpos(pos_type _P, ios_base::open_mode _M)
		{return (seekpos(_P, (ios_base::openmode)_M)); }
	_Myt *pubsetbuf(_E *_S, streamsize _N)
		{return (setbuf(_S, _N)); }
	locale pubimbue(const locale &_Ln)
		{locale _Lo = _Loc;
		imbue(_Ln);
		_Loc = _Ln;
		return (_Lo); }
	locale getloc()
		{return (_Loc); }
	streamsize in_avail()
		{return (gptr() != 0 && gptr() < egptr()
			? egptr() - gptr() : showmanyc()); }
	int pubsync()
		{return (sync()); }
	int_type sbumpc()
		{return (gptr() != 0 && gptr() < egptr()
			? _Tr::to_int_type(*_Gninc()) : uflow()); }
	int_type sgetc()
		{return (gptr() != 0 && gptr() < egptr()
			? _Tr::to_int_type(*gptr()) : underflow()); }
	streamsize sgetn(_E *_S, streamsize _N)
		{return (xsgetn(_S, _N)); }
	int_type snextc()
		{return (_Tr::eq_int_type(_Tr::eof(), sbumpc())
			? _Tr::eof() : sgetc()); }
	int_type sputbackc(_E _C)
		{return (gptr() != 0 && eback() < gptr()
			&& _Tr::eq(_C, gptr()[-1])
			? _Tr::to_int_type(*_Gndec())
			: pbackfail(_Tr::to_int_type(_C))); }
	void stossc()
		{if (gptr() != 0 && gptr() < egptr())
			_Gninc();
		else
			uflow(); }
	int_type sungetc()
		{return (gptr() != 0 && eback() < gptr()
			? _Tr::to_int_type(*_Gndec()) : pbackfail()); }
	int_type sputc(_E _C)
		{return (pptr() != 0 && pptr() < epptr()
			? _Tr::to_int_type(*_Pninc() = _C)
			: overflow(_Tr::to_int_type(_C))); }
	streamsize sputn(const _E *_S, streamsize _N)
		{return (xsputn(_S, _N)); }
protected:
	_E *eback() const
		{return (*_IGbeg); }
	_E *gptr() const
		{return (*_IGnext); }
	_E *pbase() const
		{return (*_IPbeg); }
	_E *pptr() const
		{return (*_IPnext); }
	_E *egptr() const
		{return (*_IGnext + *_IGcnt); }
	void gbump(int _N)
		{*_IGcnt -= _N;
		*_IGnext += _N; }
	void setg(_E *_B, _E *_N, _E *_L)
		{*_IGbeg = _B, *_IGnext = _N, *_IGcnt = _L - _N; }
	_E *epptr() const
		{return (*_IPnext + *_IPcnt); }
	_E *_Gndec()
		{++*_IGcnt;
		return (--*_IGnext); }
	_E *_Gninc()
		{--*_IGcnt;
		return ((*_IGnext)++); }
	void pbump(int _N)
		{*_IPcnt -= _N;
		*_IPnext += _N; }
	void setp(_E *_B, _E *_L)
		{*_IPbeg = _B, *_IPnext = _B, *_IPcnt = _L - _B; }
	void setp(_E *_B, _E *_N, _E *_L)
		{*_IPbeg = _B, *_IPnext = _N, *_IPcnt = _L - _N; }
	_E *_Pninc()
		{--*_IPcnt;
		return ((*_IPnext)++); }
	void _Init()
		{_IGbeg = &_Gbeg, _IPbeg = &_Pbeg;
		_IGnext = &_Gnext, _IPnext = &_Pnext;
		_IGcnt = &_Gcnt, _IPcnt = &_Pcnt;
		setp(0, 0), setg(0, 0, 0); }
	void _Init(_E **_Gb, _E **_Gn, int *_Gc,
		_E **_Pb, _E **_Pn, int *_Pc)
		{_IGbeg = _Gb, _IPbeg = _Pb;
		_IGnext = _Gn, _IPnext = _Pn;
		_IGcnt = _Gc, _IPcnt = _Pc; }
	virtual int_type overflow(int_type = _Tr::eof())
		{return (_Tr::eof()); }
	virtual int_type pbackfail(int_type = _Tr::eof())
		{return (_Tr::eof()); }
	virtual int showmanyc()
		{return (0); }
	virtual int_type underflow()
		{return (_Tr::eof()); }
	virtual int_type uflow()
		{return (_Tr::eq_int_type(_Tr::eof(), underflow())
			? _Tr::eof() : _Tr::to_int_type(*_Gninc())); }
	virtual streamsize xsgetn(_E * _S, streamsize _N)
		{int_type _C;
		streamsize _M, _Ns;
		for (_Ns = 0; 0 < _N; )
			if (gptr() != 0 && 0 < (_M = egptr() - gptr()))
				{if (_N < _M)
					_M = _N;
				_Tr::copy(_S, gptr(), _M);
				_S += _M, _Ns += _M, _N -= _M, gbump(_M); }
			else if (_Tr::eq_int_type(_Tr::eof(), _C = uflow()))
				break;
			else
				*_S++ = _Tr::to_char_type(_C), ++_Ns, --_N;
		return (_Ns); }
	virtual streamsize xsputn(const _E *_S, streamsize _N)
		{streamsize _M, _Ns;
		for (_Ns = 0; 0 < _N; )
			if (pptr() != 0 && 0 < (_M = epptr() - pptr()))
				{if (_N < _M)
					_M = _N;
				_Tr::copy(pptr(), _S, _M);
				_S += _M, _Ns += _M, _N -= _M, pbump(_M); }
			else if (_Tr::eq_int_type(_Tr::eof(),
				overflow(_Tr::to_int_type(*_S))))
				break;
			else
				++_S, ++_Ns, --_N;
		return (_Ns); }
	virtual pos_type seekoff(off_type, ios_base::seekdir,
		ios_base::openmode = ios_base::in | ios_base::out)
		{return (streampos(_BADOFF)); }
	virtual pos_type seekpos(pos_type,
		ios_base::openmode = ios_base::in | ios_base::out)
		{return (streampos(_BADOFF)); }
	virtual _Myt *setbuf(_E *, streamsize)
		{return (this); }
	virtual int sync()
		{return (0); }
	virtual void imbue(const locale& _Loc)
		{}
private:
	_E *_Gbeg, *_Pbeg;
	_E **_IGbeg, **_IPbeg;
	_E *_Gnext, *_Pnext;
	_E **_IGnext, **_IPnext;
	int _Gcnt, _Pcnt;
	int *_IGcnt, *_IPcnt;
	locale _Loc;
	};








};

#pragma pack(pop)
#line 204 "c:\\program files\\microsoft visual studio\\vc98\\include\\streambuf"

#line 206 "c:\\program files\\microsoft visual studio\\vc98\\include\\streambuf"





#line 10 "c:\\program files\\microsoft visual studio\\vc98\\include\\ios"


#pragma pack(push,8)
#line 14 "c:\\program files\\microsoft visual studio\\vc98\\include\\ios"
namespace std {
		
template<class _E, class _Tr = char_traits<_E> >
	class basic_ios : public ios_base {
public:
	typedef basic_ios<_E, _Tr> _Myt;
	typedef basic_ostream<_E, _Tr> _Myos;
	typedef basic_streambuf<_E, _Tr> _Mysb;
	typedef ctype<_E> _Ctype;
	explicit basic_ios(_Mysb *_S)
		{init(_S); }
	basic_ios(const _Myt& _R)
		{init(0), *this = _R; }
	virtual ~basic_ios()
		{}
	typedef _E char_type;
	typedef _Tr traits_type;
	typedef _Tr::int_type int_type;
	typedef _Tr::pos_type pos_type;
	typedef _Tr::off_type off_type;
	void clear(iostate _St = goodbit, bool _Ex = false)
		{ios_base::clear(_Sb == 0 ? (int)_St | (int)badbit
			: (int)_St, _Ex); }
	void clear(io_state _St)
		{clear((iostate)_St); }
	void setstate(iostate _St, bool _Ex = false)
		{if (_St != goodbit)
			clear((iostate)((int)rdstate() | (int)_St), _Ex); }
	void setstate(io_state _St)
		{setstate((iostate)_St); }
	_Myt& copyfmt(const _Myt& _R)
		{_Tiestr = _R.tie();
		_Fillch = _R.fill();
		ios_base::copyfmt(_R);
		return (*this); }
	_Myos *tie() const
		{return (_Tiestr); }
	_Myos *tie(_Myos *_N)
		{_Myos *_O = _Tiestr;
		_Tiestr = _N;
		return (_O); }
	_Mysb *rdbuf() const
		{return (_Sb); }
	_Mysb *rdbuf(_Mysb *_N)
		{_Mysb *_O = _Sb;
		_Sb = _N;
		clear();
		return (_O); }
	locale imbue(const locale& _Ln)
		{if (rdbuf() != 0)
			rdbuf()->pubimbue(_Ln);
		return (ios_base::imbue(_Ln)); }
	_E fill() const
		{return (_Fillch); }
	_E fill(_E _Nf)
		{_E _Of = _Fillch;
		_Fillch = _Nf;
		return (_Of); }
	char narrow(_E _C, char _D = '\0') const
		{const _Ctype& _Fac = use_facet(getloc(), (_Ctype *)0, true);
		return (_Fac.narrow(_C, _D)); }
	_E widen(char _C) const
		{const _Ctype& _Fac = use_facet(getloc(), (_Ctype *)0, true);
		return (_Fac.widen(_C)); }
protected:
	void init(_Mysb *_S = 0,
		bool _Isstd = false)
		{_Sb = _S;
		_Tiestr = 0;
		_Fillch = _Widen(' ', (_E *)0);
		_Init();
		if (_Sb == 0)
			setstate(badbit);
		if (_Isstd)
			_Addstd(); }
	basic_ios()
		{}
private:
	_Mysb *_Sb;
	_Myos *_Tiestr;
	_E _Fillch;
	};








		
inline ios_base& __cdecl boolalpha(ios_base& _I)
	{_I.setf(ios_base::boolalpha);
	return (_I); }
inline ios_base& __cdecl dec(ios_base& _I)
	{_I.setf(ios_base::dec, ios_base::basefield);
	return (_I); }
inline ios_base& __cdecl fixed(ios_base& _I)
	{_I.setf(ios_base::fixed, ios_base::floatfield);
	return (_I); }
inline ios_base& __cdecl hex(ios_base& _I)
	{_I.setf(ios_base::hex, ios_base::basefield);
	return (_I); }
inline ios_base& __cdecl internal(ios_base& _I)
	{_I.setf(ios_base::internal, ios_base::adjustfield);
	return (_I); }
inline ios_base& __cdecl left(ios_base& _I)
	{_I.setf(ios_base::left, ios_base::adjustfield);
	return (_I); }
inline ios_base& __cdecl noboolalpha(ios_base& _I)
	{_I.unsetf(ios_base::boolalpha);
	return (_I); }
inline ios_base& __cdecl noshowbase(ios_base& _I)
	{_I.unsetf(ios_base::showbase);
	return (_I); }
inline ios_base& __cdecl noshowpoint(ios_base& _I)
	{_I.unsetf(ios_base::showpoint);
	return (_I); }
inline ios_base& __cdecl noshowpos(ios_base& _I)
	{_I.unsetf(ios_base::showpos);
	return (_I); }
inline ios_base& __cdecl noskipws(ios_base& _I)
	{_I.unsetf(ios_base::skipws);
	return (_I); }
inline ios_base& __cdecl nounitbuf(ios_base& _I)
	{_I.unsetf(ios_base::unitbuf);
	return (_I); }
inline ios_base& __cdecl nouppercase(ios_base& _I)
	{_I.unsetf(ios_base::uppercase);
	return (_I); }
inline ios_base& __cdecl oct(ios_base& _I)
	{_I.setf(ios_base::oct, ios_base::basefield);
	return (_I); }
inline ios_base& __cdecl right(ios_base& _I)
	{_I.setf(ios_base::right, ios_base::adjustfield);
	return (_I); }
inline ios_base& __cdecl scientific(ios_base& _I)
	{_I.setf(ios_base::scientific, ios_base::floatfield);
	return (_I); }
inline ios_base& __cdecl showbase(ios_base& _I)
	{_I.setf(ios_base::showbase);
	return (_I); }
inline ios_base& __cdecl showpoint(ios_base& _I)
	{_I.setf(ios_base::showpoint);
	return (_I); }
inline ios_base& __cdecl showpos(ios_base& _I)
	{_I.setf(ios_base::showpos);
	return (_I); }
inline ios_base& __cdecl skipws(ios_base& _I)
	{_I.setf(ios_base::skipws);
	return (_I); }
inline ios_base& __cdecl unitbuf(ios_base& _I)
	{_I.setf(ios_base::unitbuf);
	return (_I); }
inline ios_base& __cdecl uppercase(ios_base& _I)
	{_I.setf(ios_base::uppercase);
	return (_I); }
};

#pragma pack(pop)
#line 175 "c:\\program files\\microsoft visual studio\\vc98\\include\\ios"

#line 177 "c:\\program files\\microsoft visual studio\\vc98\\include\\ios"





#line 10 "c:\\program files\\microsoft visual studio\\vc98\\include\\ostream"


#pragma pack(push,8)
#line 14 "c:\\program files\\microsoft visual studio\\vc98\\include\\ostream"
		
 
 

 

namespace std {
		
template<class _E, class _Tr = char_traits<_E> >
	class basic_ostream : virtual public basic_ios<_E, _Tr> {
public:
	typedef basic_ostream<_E, _Tr> _Myt;
	typedef basic_ios<_E, _Tr> _Myios;
	typedef basic_streambuf<_E, _Tr> _Mysb;
	typedef ostreambuf_iterator<_E, _Tr> _Iter;
	typedef num_put<_E, _Iter> _Nput;
	explicit basic_ostream(basic_streambuf<_E, _Tr> *_S,
		bool _Isstd = false, bool _Doinit = true)
		{if (_Doinit)
		    init(_S, _Isstd); }
	basic_ostream(_Uninitialized)
		{_Addstd(); }
	virtual ~basic_ostream()
		{}
	class sentry {
	public:
		explicit sentry(_Myt& _Os)
			: _Ok(_Os.opfx()), _Ostr(_Os) {}
		~sentry()
			{if (!uncaught_exception())
				_Ostr.osfx(); }
		operator bool() const
			{return (_Ok); }
	private:
		bool _Ok;
		_Myt& _Ostr;
		};
	bool opfx()
		{if (good() && tie() != 0)
			tie()->flush();
		return (good()); }
	void osfx()
		{if (flags() & unitbuf)
			flush(); }
	_Myt& operator<<(_Myt& (__cdecl *_F)(_Myt&))
		{return ((*_F)(*this)); }
	_Myt& operator<<(_Myios& (__cdecl *_F)(_Myios&))
		{(*_F)(*(_Myios *)this);
		return (*this); }
	_Myt& operator<<(ios_base& (__cdecl *_F)(ios_base&))
		{(*_F)(*(ios_base *)this);
		return (*this); }
	_Myt& operator<<(_Bool _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nput& _Fac = use_facet(getloc(), (_Nput *)0, true);
			try {
			if (_Fac.put(_Iter(rdbuf()), *this,
				fill(), _X).failed())
				_St |= badbit;
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator<<(short _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nput& _Fac = use_facet(getloc(), (_Nput *)0, true);
			fmtflags _Bfl = flags() & basefield;
			long _Y = (_Bfl == oct || _Bfl == hex)
				? (long)(unsigned short)_X : (long)_X;
			try {
			if (_Fac.put(_Iter(rdbuf()), *this,
				fill(), _Y).failed())
				_St |= badbit;
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator<<(unsigned short _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nput& _Fac = use_facet(getloc(), (_Nput *)0, true);
			try {
			if (_Fac.put(_Iter(rdbuf()), *this,
				fill(), (unsigned long)_X).failed())
				_St |= badbit;
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator<<(int _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nput& _Fac = use_facet(getloc(), (_Nput *)0, true);
			fmtflags _Bfl = flags() & basefield;
			long _Y = (_Bfl == oct || _Bfl == hex)
				? (long)(unsigned int)_X : (long)_X;
			try {
			if (_Fac.put(_Iter(rdbuf()), *this,
				fill(), _Y).failed())
				_St |= badbit;
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator<<(unsigned int _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nput& _Fac = use_facet(getloc(), (_Nput *)0, true);
			try {
			if (_Fac.put(_Iter(rdbuf()), *this,
				fill(), (unsigned long)_X).failed())
				_St |= badbit;
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator<<(long _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nput& _Fac = use_facet(getloc(), (_Nput *)0, true);
			try {
			if (_Fac.put(_Iter(rdbuf()), *this,
				fill(), _X).failed())
				_St |= badbit;
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator<<(unsigned long _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nput& _Fac = use_facet(getloc(), (_Nput *)0, true);
			try {
			if (_Fac.put(_Iter(rdbuf()), *this,
				fill(), _X).failed())
				_St |= badbit;
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator<<(float _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nput& _Fac = use_facet(getloc(), (_Nput *)0, true);
			try {
			if (_Fac.put(_Iter(rdbuf()), *this,
				fill(), (double)_X).failed())
				_St |= badbit;
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator<<(double _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nput& _Fac = use_facet(getloc(), (_Nput *)0, true);
			try {
			if (_Fac.put(_Iter(rdbuf()), *this,
				fill(), _X).failed())
				_St |= badbit;
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator<<(long double _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nput& _Fac = use_facet(getloc(), (_Nput *)0, true);
			try {
			if (_Fac.put(_Iter(rdbuf()), *this,
				fill(), _X).failed())
				_St |= badbit;
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator<<(const void *_X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nput& _Fac = use_facet(getloc(), (_Nput *)0, true);
			try {
			if (_Fac.put(_Iter(rdbuf()), *this,
				fill(), _X).failed())
				_St |= badbit;
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator<<(_Mysb *_Pb)
		{iostate _St = goodbit;
		bool _Copied = false;
		const sentry _Ok(*this);
		if (_Ok && _Pb != 0)
			for (int_type _C = _Tr::eof(); ; _Copied = true)
				{try {
				_C = _Tr::eq_int_type(_Tr::eof(), _C)
					? _Pb->sgetc() : _Pb->snextc();
				} catch (...) {
					setstate(failbit);
					throw;
				}
				if (_Tr::eq_int_type(_Tr::eof(),_C))
					break;
				try {
					if (_Tr::eq_int_type(_Tr::eof(),
						rdbuf()->sputc(_Tr::to_char_type(_C))))
						{_St |= badbit;
						break; }
				} catch (...) { setstate(ios_base::badbit, true); } }
		width(0);
		setstate(!_Copied ? _St | failbit : _St);
		return (*this); }
	_Myt& put(_E _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (!_Ok)
			_St |= badbit;
		else
			{try {
			 if (_Tr::eq_int_type(_Tr::eof(),
				rdbuf()->sputc(_X)))
				_St |= badbit;
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& write(const _E *_S, streamsize _N)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (!_Ok)
			_St |= badbit;
		else
			{try {
			if (rdbuf()->sputn(_S, _N) != _N)
				_St |= badbit;
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& flush()
		{iostate _St = goodbit;
		if (!fail() && rdbuf()->pubsync() == -1)
			_St |= badbit;
		setstate(_St);
		return (*this); }
	_Myt& seekp(pos_type _P)
		{if (!fail())
			rdbuf()->pubseekpos(_P, out);
		return (*this); }
	_Myt& seekp(off_type _O, ios_base::seekdir _W)
		{if (!fail())
			rdbuf()->pubseekoff(_O, _W, out);
		return (*this); }
	pos_type tellp()
		{if (!fail())
			return (rdbuf()->pubseekoff(0, cur, out));
		else
			return (streampos(_BADOFF)); }
	};










		
template<class _E, class _Tr> inline
	basic_ostream<_E, _Tr>& __cdecl operator<<(
		basic_ostream<_E, _Tr>& _O, const _E *_X)
	{typedef basic_ostream<_E, _Tr> _Myos;
	ios_base::iostate _St = ios_base::goodbit;
	size_t _N = _Tr::length(_X);
	size_t _M = _O.width() <= 0 || _O.width() <= _N
		? 0 : _O.width() - _N;
	const _Myos::sentry _Ok(_O);
	if (!_Ok)
		_St |= ios_base::badbit;
	else
		{try {
		if ((_O.flags() & ios_base::adjustfield)
			!= ios_base::left)
			for (; 0 < _M; --_M)
				if (_Tr::eq_int_type(_Tr::eof(),
					_O.rdbuf()->sputc(_O.fill())))
					{_St |= ios_base::badbit;
					break; }
		if (_St == ios_base::goodbit
			&& _O.rdbuf()->sputn(_X, _N) != _N)
			_St |= ios_base::badbit;
		if (_St == ios_base::goodbit)
			for (; 0 < _M; --_M)
				if (_Tr::eq_int_type(_Tr::eof(),
					_O.rdbuf()->sputc(_O.fill())))
					{_St |= ios_base::badbit;
					break; }
		_O.width(0);
		} catch (...) { (_O).setstate(ios_base::badbit, true); } }
	_O.setstate(_St);
	return (_O); }
template<class _E, class _Tr> inline
	basic_ostream<_E, _Tr>& __cdecl operator<<(
		basic_ostream<_E, _Tr>& _O, _E _C)
	{typedef basic_ostream<_E, _Tr> _Myos;
	ios_base::iostate _St = ios_base::goodbit;
	const _Myos::sentry _Ok(_O);
	if (_Ok)
		{size_t _M = _O.width() <= 1 ? 0 : _O.width() - 1;
		try {
		if ((_O.flags() & ios_base::adjustfield)
			!= ios_base::left)
			for (; _St == ios_base::goodbit && 0 < _M; --_M)
				if (_Tr::eq_int_type(_Tr::eof(),
					_O.rdbuf()->sputc(_O.fill())))
					_St |= ios_base::badbit;
		if (_St == ios_base::goodbit
			&& _Tr::eq_int_type(_Tr::eof(),
				_O.rdbuf()->sputc(_C)))
			_St |= ios_base::badbit;
		for (; _St == ios_base::goodbit && 0 < _M; --_M)
			if (_Tr::eq_int_type(_Tr::eof(),
				_O.rdbuf()->sputc(_O.fill())))
				_St |= ios_base::badbit;
		} catch (...) { (_O).setstate(ios_base::badbit, true); } }
	_O.width(0);
	_O.setstate(_St);
	return (_O); }
template<class _E, class _Tr> inline
	basic_ostream<_E, _Tr>& __cdecl operator<<(
		basic_ostream<_E, _Tr>& _O, const signed char *_X)
	{return (_O << (const char *)_X); }
template<class _E, class _Tr> inline
	basic_ostream<_E, _Tr>& __cdecl operator<<(
		basic_ostream<_E, _Tr>& _O, const signed char _C)
	{return (_O << (char)_C); }
template<class _E, class _Tr> inline
	basic_ostream<_E, _Tr>& __cdecl operator<<(
		basic_ostream<_E, _Tr>& _O, const unsigned char *_X)
	{return (_O << (const char *)_X); }
template<class _E, class _Tr> inline
	basic_ostream<_E, _Tr>& __cdecl operator<<(
		basic_ostream<_E, _Tr>& _O, const unsigned char _C)
	{return (_O << (char)_C); }
template<class _E, class _Tr> inline
	basic_ostream<_E, _Tr>& __cdecl operator<<(
		basic_ostream<_E, _Tr>& _O, const signed short *_X)
	{return (_O << (const wchar_t *)_X); }
		
template<class _E, class _Tr> inline
	basic_ostream<_E, _Tr>&
		__cdecl endl(basic_ostream<_E, _Tr>& _O)
	{_O.put(_O.widen('\n'));
	_O.flush();
	return (_O); }
 inline basic_ostream<char, char_traits<char> >&
	__cdecl endl(basic_ostream<char, char_traits<char> >& _O)
	{_O.put('\n');
	_O.flush();
	return (_O); }
 inline basic_ostream<wchar_t, char_traits<wchar_t> >&
	__cdecl endl(basic_ostream<wchar_t,
		char_traits<wchar_t> >& _O)
	{_O.put('\n');
	_O.flush();
	return (_O); }
template<class _E, class _Tr> inline
	basic_ostream<_E, _Tr>&
		__cdecl ends(basic_ostream<_E, _Tr>& _O)
	{_O.put(_E('\0'));
	return (_O); }
 inline basic_ostream<char, char_traits<char> >&
	__cdecl ends(basic_ostream<char, char_traits<char> >& _O)
	{_O.put('\0');
	return (_O); }
 inline basic_ostream<wchar_t, char_traits<wchar_t> >&
	__cdecl ends(basic_ostream<wchar_t,
		char_traits<wchar_t> >& _O)
	{_O.put('\0');
	return (_O); }
template<class _E, class _Tr> inline
	basic_ostream<_E, _Tr>&
		__cdecl flush(basic_ostream<_E, _Tr>& _O)
	{_O.flush();
	return (_O); }
 inline basic_ostream<char, char_traits<char> >&
	__cdecl flush(basic_ostream<char, char_traits<char> >& _O)
	{_O.flush();
	return (_O); }
 inline basic_ostream<wchar_t, char_traits<wchar_t> >&
	__cdecl flush(basic_ostream<wchar_t,
		char_traits<wchar_t> >& _O)
	{_O.flush();
	return (_O); }


























};

#pragma pack(pop)
#line 440 "c:\\program files\\microsoft visual studio\\vc98\\include\\ostream"

#line 442 "c:\\program files\\microsoft visual studio\\vc98\\include\\ostream"





#line 10 "c:\\program files\\microsoft visual studio\\vc98\\include\\istream"


#pragma pack(push,8)
#line 14 "c:\\program files\\microsoft visual studio\\vc98\\include\\istream"
namespace std {
		
template<class _E, class _Tr = char_traits<_E> >
	class basic_istream : virtual public basic_ios<_E, _Tr> {
public:
	typedef basic_istream<_E, _Tr> _Myt;
	typedef basic_ios<_E, _Tr> _Myios;
	typedef basic_streambuf<_E, _Tr> _Mysb;
	typedef istreambuf_iterator<_E, _Tr> _Iter;
	typedef ctype<_E> _Ctype;
	typedef num_get<_E, _Iter> _Nget;
	explicit basic_istream(_Mysb *_S, bool _Isstd = false)
		: _Chcount(0) {init(_S, _Isstd); }
	basic_istream(_Uninitialized)
		{_Addstd(); }
	virtual ~basic_istream()
		{}
	class sentry {
	public:
		explicit sentry(_Myt& _Is, bool _Noskip = false)
			: _Ok(_Is.ipfx(_Noskip)) {}
		operator bool() const
			{return (_Ok); }
	private:
		bool _Ok;
		};
	bool ipfx(bool _Noskip = false)
		{if (good())
			{if (tie() != 0)
				tie()->flush();
			if (!_Noskip && flags() & skipws)
				{const _Ctype& _Fac = use_facet(getloc(), (_Ctype *)0, true);
				try {
				int_type _C = rdbuf()->sgetc();
				while (!_Tr::eq_int_type(_Tr::eof(), _C)
					&& _Fac.is(_Ctype::space,
						_Tr::to_char_type(_C)))
					_C = rdbuf()->snextc();
				} catch (...) { setstate(ios_base::badbit, true); } }
			if (good())
				return (true); }
		setstate(failbit);
		return (false); }
	void isfx()
		{}
	_Myt& operator>>(_Myt& (__cdecl *_F)(_Myt&))
		{return ((*_F)(*this)); }
	_Myt& operator>>(_Myios& (__cdecl *_F)(_Myios&))
		{(*_F)(*(_Myios *)this);
		return (*this); }
	_Myt& operator>>(ios_base& (__cdecl *_F)(ios_base&))
		{(*_F)(*(ios_base *)this);
		return (*this); }
	_Myt& operator>>(_Bool& _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nget& _Fac = use_facet(getloc(), (_Nget *)0, true);
			try {
			_Fac.get(_Iter(rdbuf()), _Iter(0), *this, _St, _X);
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator>>(short& _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{long _Y;
			const _Nget& _Fac = use_facet(getloc(), (_Nget *)0, true);
			try {
			_Fac.get(_Iter(rdbuf()), _Iter(0), *this, _St, _Y);
			} catch (...) { setstate(ios_base::badbit, true); }
			if (_St & failbit || _Y < (-32768) || 32767 < _Y)
				_St |= failbit;
			else
				_X = (short)_Y; }
		setstate(_St);
		return (*this); }
	_Myt& operator>>(unsigned short& _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nget& _Fac = use_facet(getloc(), (_Nget *)0, true);
			try {
			_Fac.get(_Iter(rdbuf()), _Iter(0), *this, _St, _X);
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator>>(int& _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{long _Y;
			const _Nget& _Fac = use_facet(getloc(), (_Nget *)0, true);
			try {
			_Fac.get(_Iter(rdbuf()), _Iter(0), *this, _St, _Y);
			} catch (...) { setstate(ios_base::badbit, true); }
			if (_St & failbit || _Y < (-2147483647 - 1) || 2147483647 < _Y)
				_St |= failbit;
			else
				_X = _Y; }
		setstate(_St);
		return (*this); }
	_Myt& operator>>(unsigned int& _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nget& _Fac = use_facet(getloc(), (_Nget *)0, true);
			try {
			_Fac.get(_Iter(rdbuf()), _Iter(0), *this, _St, _X);
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator>>(long& _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nget& _Fac = use_facet(getloc(), (_Nget *)0, true);
			try {
			_Fac.get(_Iter(rdbuf()), _Iter(0), *this, _St, _X);
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator>>(unsigned long& _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nget& _Fac = use_facet(getloc(), (_Nget *)0, true);
			try {
			_Fac.get(_Iter(rdbuf()), _Iter(0), *this, _St, _X);
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator>>(float& _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nget& _Fac = use_facet(getloc(), (_Nget *)0, true);
			try {
			_Fac.get(_Iter(rdbuf()), _Iter(0), *this, _St, _X);
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator>>(double& _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nget& _Fac = use_facet(getloc(), (_Nget *)0, true);
			try {
			_Fac.get(_Iter(rdbuf()), _Iter(0), *this, _St, _X);
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator>>(long double& _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nget& _Fac = use_facet(getloc(), (_Nget *)0, true);
			try {
			_Fac.get(_Iter(rdbuf()), _Iter(0), *this, _St, _X);
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator>>(void *& _X)
		{iostate _St = goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{const _Nget& _Fac = use_facet(getloc(), (_Nget *)0, true);
			try {
			_Fac.get(_Iter(rdbuf()), _Iter(0), *this, _St, _X);
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& operator>>(_Mysb *_Pb)
		{iostate _St = goodbit;
		bool _Copied = false;
		const sentry _Ok(*this);
		if (_Ok && _Pb != 0)
			{try {
			int_type _C = rdbuf()->sgetc();
			for (; ; _C = rdbuf()->snextc())
				if (_Tr::eq_int_type(_Tr::eof(), _C))
					{_St |= eofbit;
					break; }
				else
					{try {
						if (_Tr::eq_int_type(_Tr::eof(),
							_Pb->sputc(_Tr::to_char_type(_C))))
							break;
					} catch (...) {
						break;
					}
					_Copied = true; }
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(!_Copied ? _St | failbit : _St);
		return (*this); }
	int_type get()
		{int_type _C;
		iostate _St = goodbit;
		_Chcount = 0;
		const sentry _Ok(*this, true);
		if (!_Ok)
			_C = _Tr::eof();
		else
			{try {
			_C = rdbuf()->sbumpc();
			if (_Tr::eq_int_type(_Tr::eof(), _C))
				_St |= eofbit | failbit;
			else
				++_Chcount;
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (_C); }
	_Myt& get(_E *_S, streamsize _N)
		{return (get(_S, _N, widen('\n'))); }
	_Myt& get(_E *_S, streamsize _N, _E _D)
		{iostate _St = goodbit;
		_Chcount = 0;
		const sentry _Ok(*this, true);
		if (_Ok && 0 < _N)
			{try {
			int_type _C = rdbuf()->sgetc();
			for (; 0 < --_N; _C = rdbuf()->snextc())
				if (_Tr::eq_int_type(_Tr::eof(), _C))
					{_St |= eofbit;
					break; }
				else if (_Tr::to_char_type(_C) == _D)
					break;
				else
					*_S++ = _Tr::to_char_type(_C), ++_Chcount;
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_Chcount == 0 ? _St | failbit : _St);
		*_S = _E(0);
		return (*this); }
	_Myt& get(_E& _X)
		{int_type _C = get();
		if (!_Tr::eq_int_type(_Tr::eof(), _C))
			_X = _Tr::to_char_type(_C);
		return (*this); }
	_Myt& get(_Mysb& _Sb)
		{return (get(_Sb, widen('\n'))); }
	_Myt& get(_Mysb& _Sb, _E _D)
		{iostate _St = goodbit;
		_Chcount = 0;
		const sentry _Ok(*this, true);
		if (_Ok)
			{try {
			int_type _C = rdbuf()->sgetc();
			for (; ; _C = rdbuf()->snextc())
				if (_Tr::eq_int_type(_Tr::eof(), _C))
					{_St |= eofbit;
					break; }
				else
					{try {
						_E _Ch = _Tr::to_char_type(_C);
						if (_Ch == _D
							|| _Tr::eq_int_type(_Tr::eof(),
								_Sb.sputc(_Ch)))
							break;
					} catch (...) {
						break;
					}
					++_Chcount; }
			} catch (...) { setstate(ios_base::badbit, true); } }
		if (_Chcount == 0)
			_St |= failbit;
		setstate(_St);
		return (*this); }
	_Myt& getline(_E *_S, streamsize _N)
		{return (getline(_S, _N, widen('\n'))); }
	_Myt& getline(_E *_S, streamsize _N, _E _D)
		{iostate _St = goodbit;
		_Chcount = 0;
		const sentry _Ok(*this, true);
		if (_Ok && 0 < _N)
			{int_type _Di = _Tr::to_int_type(_D);
			try {
			int_type _C = rdbuf()->sgetc();
			for (; ; _C = rdbuf()->snextc())
				if (_Tr::eq_int_type(_Tr::eof(), _C))
					{_St |= eofbit;
					break; }
				else if (_C == _Di)
					{++_Chcount;
					rdbuf()->stossc();
					break; }
				else if (--_N <= 0)
					{_St |= failbit;
					break; }
				else
					{++_Chcount;
					*_S++ = _Tr::to_char_type(_C); }
			} catch (...) { setstate(ios_base::badbit, true); } }
		*_S = _E(0);
		setstate(_Chcount == 0 ? _St | failbit : _St);
		return (*this); }
	_Myt& ignore(streamsize _N = 1, int_type _Di = _Tr::eof())
		{iostate _St = goodbit;
		_Chcount = 0;
		const sentry _Ok(*this, true);
		if (_Ok && 0 < _N)
			{try {
			for (; ; )
				{int_type _C;
				if (_N != 2147483647 && --_N < 0)
					break;
				else if (_Tr::eq_int_type(_Tr::eof(),
					_C = rdbuf()->sbumpc()))
					{_St |= eofbit;
					break; }
				else
					{++_Chcount;
					if (_C == _Di)
						break; }}
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& read(_E *_S, streamsize _N)
		{iostate _St = goodbit;
		_Chcount = 0;
		const sentry _Ok(*this, true);
		if (_Ok)
			{try {
			const streamsize _M = rdbuf()->sgetn(_S, _N);
			_Chcount += _M;
			if (_M != _N)
				_St |= eofbit | failbit;
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	streamsize readsome(_E *_S, streamsize _N)
		{iostate _St = goodbit;
		_Chcount = 0;
		int _M;
		if (rdbuf() == 0)
			_St |= failbit;
		else if ((_M = rdbuf()->in_avail()) < 0)
			_St |= eofbit;
		else if (0 < _M)
			read(_S, _M < _N ? _M : _N);
		setstate(_St);
		return (gcount()); }
	int_type peek()
		{iostate _St = goodbit;
		_Chcount = 0;
		int_type _C;
		const sentry _Ok(*this, true);
		if (!_Ok)
			_C = _Tr::eof();
		else
			{try {
			if (_Tr::eq_int_type(_Tr::eof(),
				_C = rdbuf()->sgetc()))
				_St |= eofbit;
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (_C); }
	_Myt& putback(_E _X)
		{iostate _St = goodbit;
		_Chcount = 0;
		const sentry _Ok(*this, true);
		if (_Ok)
			{try {
			if (_Tr::eq_int_type(_Tr::eof(),
				rdbuf()->sputbackc(_X)))
				_St |= badbit;
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	_Myt& unget()
		{iostate _St = goodbit;
		_Chcount = 0;
		const sentry _Ok(*this, true);
		if (_Ok)
			{try {
			if (_Tr::eq_int_type(_Tr::eof(),
				rdbuf()->sungetc()))
				_St |= badbit;
			} catch (...) { setstate(ios_base::badbit, true); } }
		setstate(_St);
		return (*this); }
	streamsize gcount() const
		{return (_Chcount); }
	int sync()
		{iostate _St = goodbit;
		int _Ans;
		if (rdbuf() == 0)
			_Ans = -1;
		else if (rdbuf()->pubsync() == -1)
			_St |= badbit, _Ans = -1;
		else
			_Ans = 0;
		setstate(_St);
		return (_Ans); }
	_Myt& seekg(pos_type _P)
		{if (!fail())
			rdbuf()->pubseekpos(_P, in);
		return (*this); }
	_Myt& seekg(off_type _O, ios_base::seekdir _W)
		{if (!fail())
			rdbuf()->pubseekoff(_O, _W, in);
		return (*this); }
	pos_type tellg()
		{if (!fail())
			return (rdbuf()->pubseekoff(0, cur, in));
		else
			return (streampos(_BADOFF)); }
private:
	streamsize _Chcount;
	};








		
template<class _E, class _Tr = char_traits<_E> >
	class basic_iostream : public basic_istream<_E, _Tr>,
		public basic_ostream<_E, _Tr> {
public:
	explicit basic_iostream(basic_streambuf<_E, _Tr> *_S)
		: basic_istream<_E, _Tr>(_S), basic_ostream<_E, _Tr>(_S, false, false)
		{}
	virtual ~basic_iostream()
		{}
	};










		
template<class _E, class _Tr> inline
	basic_istream<_E, _Tr>& __cdecl operator>>(
		basic_istream<_E, _Tr>& _I, _E *_X)
	{typedef basic_istream<_E, _Tr> _Myis;
	typedef ctype<_E> _Ctype;
	ios_base::iostate _St = ios_base::goodbit;
	_E *_S = _X;
	const _Myis::sentry _Ok(_I);
	if (_Ok)
		{const _Ctype& _Fac = use_facet(_I.getloc(), (_Ctype *)0, true);
		try {
		int _N = 0 < _I.width() ? _I.width() : 2147483647;
		_Myis::int_type _C = _I.rdbuf()->sgetc();
		for (; 0 < --_N; _C = _I.rdbuf()->snextc())
			if (_Tr::eq_int_type(_Tr::eof(), _C))
				{_St |= ios_base::eofbit;
				break; }
			else if (_Fac.is(_Ctype::space,
				_Tr::to_char_type(_C)))
				break;
			else
				*_S++ = _Tr::to_char_type(_C);
		} catch (...) { (_I).setstate(ios_base::badbit, true); } }
	*_S = _E(0);
	_I.width(0);
	_I.setstate(_S == _X ? _St | ios_base::failbit : _St);
	return (_I); }
template<class _E, class _Tr> inline
	basic_istream<_E, _Tr>& __cdecl operator>>(
		basic_istream<_E, _Tr>& _I, _E& _X)
	{typedef basic_istream<_E, _Tr> _Myis;
	_Myis::int_type _C;
	ios_base::iostate _St = ios_base::goodbit;
	const _Myis::sentry _Ok(_I);
	if (_Ok)
		{try {
		_C = _I.rdbuf()->sbumpc();
		if (_Tr::eq_int_type(_Tr::eof(), _C))
			_St |= ios_base::eofbit | ios_base::failbit;
		else
			_X = _Tr::to_char_type(_C);
		} catch (...) { (_I).setstate(ios_base::badbit, true); } }
	_I.setstate(_St);
	return (_I); }
template<class _E, class _Tr> inline
	basic_istream<_E, _Tr>& __cdecl operator>>(
		basic_istream<_E, _Tr>& _I, signed char *_X)
	{return (_I >> (char *)_X); }
template<class _E, class _Tr> inline
	basic_istream<_E, _Tr>& __cdecl operator>>(
		basic_istream<_E, _Tr>& _I, signed char& _C)
	{return (_I >> (char&)_C); }
template<class _E, class _Tr> inline
	basic_istream<_E, _Tr>& __cdecl operator>>(
		basic_istream<_E, _Tr>& _I, unsigned char *_X)
	{return (_I >> (char *)_X); }
template<class _E, class _Tr> inline
	basic_istream<_E, _Tr>& __cdecl operator>>(
		basic_istream<_E, _Tr>& _I, unsigned char& _C)
	{return (_I >> (char&)_C); }
template<class _E, class _Tr> inline
	basic_istream<_E, _Tr>& __cdecl operator>>(
		basic_istream<_E, _Tr>& _I, signed short * _X)
	{return (_I >> (wchar_t *)_X); }
		
template<class _E, class _Tr> inline
	basic_istream<_E, _Tr>& __cdecl ws(basic_istream<_E, _Tr>& _I)
	{typedef basic_istream<_E, _Tr> _Myis;
	typedef ctype<_E> _Ctype;
	ios_base::iostate _St = ios_base::goodbit;
	const _Myis::sentry _Ok(_I, true);
	if (_Ok)
		{const _Ctype& _Fac = use_facet(_I.getloc(), (_Ctype *)0, true);
		try {
		for (_Tr::int_type _C = _I.rdbuf()->sgetc(); ;
			_C = _I.rdbuf()->snextc())
			if (_Tr::eq_int_type(_Tr::eof(), _C))
				{_St |= ios_base::eofbit;
				break; }
			else if (!_Fac.is(_Ctype::space,
				_Tr::to_char_type(_C)))
				break;
		} catch (...) { (_I).setstate(ios_base::badbit, true); } }
	_I.setstate(_St);
	return (_I); }
 inline basic_istream<char, char_traits<char> >&
	__cdecl ws(basic_istream<char, char_traits<char> >& _I)
	{typedef char _E;
	typedef char_traits<_E> _Tr;
	ios_base::iostate _St = ios_base::goodbit;
	const basic_istream<_E, _Tr>::sentry _Ok(_I, true);
	if (_Ok)
		{const ctype<_E>& _Fac = use_facet(_I.getloc(), (ctype<_E> *)0, true);
		try {
		for (_Tr::int_type _C = _I.rdbuf()->sgetc(); ;
			_C = _I.rdbuf()->snextc())
			if (_Tr::eq_int_type(_Tr::eof(), _C))
				{_St |= ios_base::eofbit;
				break; }
			else if (!_Fac.is(ctype<_E>::space,
				_Tr::to_char_type(_C)))
				break;
		} catch (...) { (_I).setstate(ios_base::badbit, true); } }
	_I.setstate(_St);
	return (_I); }
 inline basic_istream<wchar_t, char_traits<wchar_t> >&
	__cdecl ws(basic_istream<wchar_t, char_traits<wchar_t> >& _I)
	{typedef wchar_t _E;
	typedef char_traits<_E> _Tr;
	ios_base::iostate _St = ios_base::goodbit;
	const basic_istream<_E, _Tr>::sentry _Ok(_I, true);
	if (_Ok)
		{const ctype<_E>& _Fac = use_facet(_I.getloc(), (ctype<_E> *)0, true);
		try {
		for (_Tr::int_type _C = _I.rdbuf()->sgetc(); ;
			_C = _I.rdbuf()->snextc())
			if (_Tr::eq_int_type(_Tr::eof(), _C))
				{_St |= ios_base::eofbit;
				break; }
			else if (_Fac.is(ctype<_E>::space,
				_Tr::to_char_type(_C)))
				break;
		} catch (...) { (_I).setstate(ios_base::badbit, true); } }
	_I.setstate(_St);
	return (_I); }




























};

#pragma pack(pop)
#line 611 "c:\\program files\\microsoft visual studio\\vc98\\include\\istream"

#line 613 "c:\\program files\\microsoft visual studio\\vc98\\include\\istream"





#line 10 "c:\\program files\\microsoft visual studio\\vc98\\include\\string"


#pragma pack(push,8)
#line 14 "c:\\program files\\microsoft visual studio\\vc98\\include\\string"
namespace std {
        
template<class _E, class _Tr, class _A> inline
    basic_string<_E, _Tr, _A> __cdecl operator+(
        const basic_string<_E, _Tr, _A>& _L,
        const basic_string<_E, _Tr, _A>& _R)
    {return (basic_string<_E, _Tr, _A>(_L) += _R); }
template<class _E, class _Tr, class _A> inline
    basic_string<_E, _Tr, _A> __cdecl operator+(const _E *_L,
        const basic_string<_E, _Tr, _A>& _R)
    {return (basic_string<_E, _Tr, _A>(_L) += _R); }
template<class _E, class _Tr, class _A> inline
    basic_string<_E, _Tr, _A> __cdecl operator+(
        const _E _L, const basic_string<_E, _Tr, _A>& _R)
    {return (basic_string<_E, _Tr, _A>(1, _L) += _R); }
template<class _E, class _Tr, class _A> inline
    basic_string<_E, _Tr, _A> __cdecl operator+(
        const basic_string<_E, _Tr, _A>& _L,
        const _E *_R)
    {return (basic_string<_E, _Tr, _A>(_L) += _R); }
template<class _E, class _Tr, class _A> inline
    basic_string<_E, _Tr, _A> __cdecl operator+(
        const basic_string<_E, _Tr, _A>& _L, const _E _R)
    {return (basic_string<_E, _Tr, _A>(_L) += _R); }
template<class _E, class _Tr, class _A> inline
    bool __cdecl operator==(const basic_string<_E, _Tr, _A>& _L,
        const basic_string<_E, _Tr, _A>& _R)
    {return (_L.compare(_R) == 0); }
template<class _E, class _Tr, class _A> inline
    bool __cdecl operator==(const _E * _L,
        const basic_string<_E, _Tr, _A>& _R)
    {return (_R.compare(_L) == 0); }
template<class _E, class _Tr, class _A> inline
    bool __cdecl operator==(const basic_string<_E, _Tr, _A>& _L,
        const _E *_R)
    {return (_L.compare(_R) == 0); }
template<class _E, class _Tr, class _A> inline
    bool __cdecl operator!=(const basic_string<_E, _Tr, _A>& _L,
        const basic_string<_E, _Tr, _A>& _R)
    {return (!(_L == _R)); }
template<class _E, class _Tr, class _A> inline
    bool __cdecl operator!=(const _E *_L,
        const basic_string<_E, _Tr, _A>& _R)
    {return (!(_L == _R)); }
template<class _E, class _Tr, class _A> inline
    bool __cdecl operator!=(const basic_string<_E, _Tr, _A>& _L,
        const _E *_R)
    {return (!(_L == _R)); }
template<class _E, class _Tr, class _A> inline
    bool __cdecl operator<(const basic_string<_E, _Tr, _A>& _L,
        const basic_string<_E, _Tr, _A>& _R)
    {return (_L.compare(_R) < 0); }
template<class _E, class _Tr, class _A> inline
    bool __cdecl operator<(const _E * _L,
        const basic_string<_E, _Tr, _A>& _R)
    {return (_R.compare(_L) > 0); }
template<class _E, class _Tr, class _A> inline
    bool __cdecl operator<(const basic_string<_E, _Tr, _A>& _L,
        const _E *_R)
    {return (_L.compare(_R) < 0); }
template<class _E, class _Tr, class _A> inline
    bool __cdecl operator>(const basic_string<_E, _Tr, _A>& _L,
        const basic_string<_E, _Tr, _A>& _R)
    {return (_R < _L); }
template<class _E, class _Tr, class _A> inline
    bool __cdecl operator>(const _E * _L,
        const basic_string<_E, _Tr, _A>& _R)
    {return (_R < _L); }
template<class _E, class _Tr, class _A> inline
    bool __cdecl operator>(const basic_string<_E, _Tr, _A>& _L,
        const _E *_R)
    {return (_R < _L); }
template<class _E, class _Tr, class _A> inline
    bool __cdecl operator<=(const basic_string<_E, _Tr, _A>& _L,
        const basic_string<_E, _Tr, _A>& _R)
    {return (!(_R < _L)); }
template<class _E, class _Tr, class _A> inline
    bool __cdecl operator<=(const _E * _L,
        const basic_string<_E, _Tr, _A>& _R)
    {return (!(_R < _L)); }
template<class _E, class _Tr, class _A> inline
    bool __cdecl operator<=(const basic_string<_E, _Tr, _A>& _L,
        const _E *_R)
    {return (!(_R < _L)); }
template<class _E, class _Tr, class _A> inline
    bool __cdecl operator>=(const basic_string<_E, _Tr, _A>& _L,
        const basic_string<_E, _Tr, _A>& _R)
    {return (!(_L < _R)); }
template<class _E, class _Tr, class _A> inline
    bool __cdecl operator>=(const _E * _L,
        const basic_string<_E, _Tr, _A>& _R)
    {return (!(_L < _R)); }
template<class _E, class _Tr, class _A> inline
    bool __cdecl operator>=(const basic_string<_E, _Tr, _A>& _L,
        const _E *_R)
    {return (!(_L < _R)); }
        
template<class _E, class _Tr, class _A> inline
    basic_istream<_E, _Tr>& __cdecl operator>>(
        basic_istream<_E, _Tr>& _I,
        basic_string<_E, _Tr, _A>& _X)
    {typedef ctype<_E> _Ctype;
    typedef basic_istream<_E, _Tr> _Myis;
    ios_base::iostate _St = ios_base::goodbit;
    bool _Chg = false;
    _X.erase();
    const _Myis::sentry _Ok(_I);
    if (_Ok)
        {const _Ctype& _Fac = use_facet(_I.getloc(), (_Ctype *)0, true);
        try {
        _A::size_type _N = 0 < _I.width()
            && _I.width() < _X.max_size()
                ? _I.width() : _X.max_size();
        _Tr::int_type _C = _I.rdbuf()->sgetc();
        for (; 0 < --_N; _C = _I.rdbuf()->snextc())
            if(_Tr::eq_int_type(_Tr::eof(), _C))
                {_St |= ios_base::eofbit;
                break; }
            else if (_Fac.is(_Ctype::space,
                _Tr::to_char_type(_C)))
                break;
            else
                {_X.append(1, _Tr::to_char_type(_C));
                _Chg = true; }
        } catch (...) { (_I).setstate(ios_base::badbit, true); }; }
    _I.width(0);
    if (!_Chg)
        _St |= ios_base::failbit;
    _I.setstate(_St);
    return (_I); }
template<class _E, class _Tr, class _A> inline
    basic_istream<_E, _Tr>& __cdecl getline(basic_istream<_E, _Tr>& _I,
        basic_string<_E, _Tr, _A>& _X)
    {return (getline(_I, _X, _I.widen('\n'))); }
template<class _E, class _Tr, class _A> inline
    basic_istream<_E, _Tr>& __cdecl getline(basic_istream<_E, _Tr>& _I,
        basic_string<_E, _Tr, _A>& _X, const _E _D)
    {typedef basic_istream<_E, _Tr> _Myis;
    ios_base::iostate _St = ios_base::goodbit;
    bool _Chg = false;
    _X.erase();
    const _Myis::sentry _Ok(_I, true);
    if (_Ok)
        {try {
        _Tr::int_type _C = _I.rdbuf()->sgetc();
        for (; ; _C = _I.rdbuf()->snextc())
            if (_Tr::eq_int_type(_Tr::eof(), _C))
                {_St |= ios_base::eofbit;
                break; }
            else if (_Tr::eq((_E)_C, _D))
                {_Chg = true;
                _I.rdbuf()->snextc();
                break; }
            else if (_X.max_size() <= _X.size())
                {_St |= ios_base::failbit;
                break; }
            else
                _X += _Tr::to_char_type(_C), _Chg = true;
        } catch (...) { (_I).setstate(ios_base::badbit, true); }; }
    if (!_Chg)
        _St |= ios_base::failbit;
    _I.setstate(_St);
    return (_I); }
template<class _E, class _Tr, class _A> inline
    basic_ostream<_E, _Tr>& __cdecl operator<<(
        basic_ostream<_E, _Tr>& _O,
        const basic_string<_E, _Tr, _A>& _X)
    {
    _O << _X.c_str();
    return (_O); }






























































































































































};

#pragma pack(pop)
#line 346 "c:\\program files\\microsoft visual studio\\vc98\\include\\string"

#line 348 "c:\\program files\\microsoft visual studio\\vc98\\include\\string"





#line 8 "d:\\hassan\\devs\\solarsystem\\trunk\\engine\\xml\\xml.h"
#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\vector"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\vector"




#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\memory"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\memory"






#pragma pack(push,8)
#line 14 "c:\\program files\\microsoft visual studio\\vc98\\include\\memory"
		
template<class _Ty>
	inline void *operator new("c:\\program files\\microsoft visual studio\\vc98\\include\\memory", 16)(size_t _N, std::allocator<_Ty>& _Al)
	{return (_Al._Charalloc(_N)); }
namespace std {
		
template<class _Ty> inline
	pair<_Ty  *, ptrdiff_t>
		get_temporary_buffer(ptrdiff_t _N, _Ty  *)
	{_Ty  *_P;
	for (_P = 0; 0 < _N; _N /= 2)
		if ((_P = (_Ty  *)operator new("c:\\program files\\microsoft visual studio\\vc98\\include\\memory", 25)(
			(size_t)_N * sizeof (_Ty), nothrow)) != 0)
			break;
	return (pair<_Ty  *, ptrdiff_t>(_P, _N)); }
		
template<class _Ty> inline
	void return_temporary_buffer(_Ty *_P)
	{operator delete(_P); }
		
template<class _II, class _FI> inline
	_FI uninitialized_copy(_II _F, _II _L, _FI _X)
	{for (; _F != _L; ++_X, ++_F)
		_Construct(&*_X, *_F);
	return (_X); }
		
template<class _FI, class _Ty> inline
	void uninitialized_fill(_FI _F, _FI _L, const _Ty& _X)
	{for (; _F != _L; ++_F)
		_Construct(&*_F, _X); }
		
template<class _FI, class _S, class _Ty> inline
	void uninitialized_fill_n(_FI _F, _S _N, const _Ty& _X)
	{for (; 0 < _N; --_N, ++_F)
		_Construct(&*_F, _X); }
		
template<class _OI, class _Ty>
	class raw_storage_iterator
		: public iterator<output_iterator_tag, void, void> {
public:
	typedef _OI iterator_type;
	typedef _Ty element_type;
	explicit raw_storage_iterator(_OI _X)
		: _Next(_X) {}
	raw_storage_iterator<_OI, _Ty>& operator*()
		{return (*this); }
	raw_storage_iterator<_OI, _Ty>& operator=(const _Ty& _X)
		{_Construct(&*_Next, _X);
		return (*this); }
	raw_storage_iterator<_OI, _Ty>& operator++()
		{++_Next;
		return (*this); }
	raw_storage_iterator<_OI, _Ty> operator++(int)
		{raw_storage_iterator<_OI, _Ty> _Ans = *this;
		++_Next;
		return (_Ans); }
private:
	_OI _Next;
	};
		
template<class _Ty>
	class _Temp_iterator
		: public iterator<output_iterator_tag, void, void> {
public:
	typedef _Ty  *_Pty;
	_Temp_iterator(ptrdiff_t _N = 0)
		{pair<_Pty, ptrdiff_t> _Pair =
			get_temporary_buffer(_N, (_Pty)0);
		_Buf._Begin = _Pair.first;
		_Buf._Cur = _Pair.first;
		_Buf._Hiwater = _Pair.first;
		_Buf._Len = _Pair.second;
		_Pb = &_Buf; }
	_Temp_iterator(const _Temp_iterator<_Ty>& _X)
		{_Buf._Begin = 0;
		_Buf._Cur = 0;
		_Buf._Hiwater = 0;
		_Buf._Len = 0;
		*this = _X; }
	~_Temp_iterator()
		{if (_Buf._Begin != 0)
			{for (_Pty _F = _Buf._Begin;
				_F != _Buf._Hiwater; ++_F)
				_Destroy(&*_F);
			return_temporary_buffer(_Buf._Begin); }}
	_Temp_iterator<_Ty>& operator=(const _Temp_iterator<_Ty>& _X)
		{_Pb = _X._Pb;
		return (*this); }
	_Temp_iterator<_Ty>& operator=(const _Ty& _V)
		{if (_Pb->_Cur < _Pb->_Hiwater)
			*_Pb->_Cur++ = _V;
		else
			{_Construct(&*_Pb->_Cur, _V);
			_Pb->_Hiwater = ++_Pb->_Cur; }
		return (*this); }
	_Temp_iterator<_Ty>& operator*()
		{return (*this); }
	_Temp_iterator<_Ty>& operator++()
		{return (*this); }
	_Temp_iterator<_Ty>& operator++(int)
		{return (*this); }
	_Temp_iterator<_Ty>& _Init()
		{_Pb->_Cur = _Pb->_Begin;
		return (*this); }
	_Pty _First() const
		{return (_Pb->_Begin); }
	_Pty _Last() const
		{return (_Pb->_Cur); }
	ptrdiff_t _Maxlen() const
		{return (_Pb->_Len); }
private:
	struct _Bufpar {
		_Pty _Begin;
		_Pty _Cur;
		_Pty _Hiwater;
		ptrdiff_t _Len;
		} _Buf, *_Pb;
	};
		
template<class _Ty>
	class auto_ptr {
public:
	typedef _Ty element_type;
	explicit auto_ptr(_Ty *_P = 0) throw ()
		: _Owns(_P != 0), _Ptr(_P) {}
	auto_ptr(const auto_ptr<_Ty>& _Y) throw ()
		: _Owns(_Y._Owns), _Ptr(_Y.release()) {}
	auto_ptr<_Ty>& operator=(const auto_ptr<_Ty>& _Y) throw ()
		{if (this != &_Y)
			{if (_Ptr != _Y.get())
				{if (_Owns)
					delete _Ptr;
				_Owns = _Y._Owns; }
			else if (_Y._Owns)
				_Owns = true;
			_Ptr = _Y.release(); }
		return (*this); }
	~auto_ptr()
		{if (_Owns)
			delete _Ptr; }
	_Ty& operator*() const throw ()
		{return (*get()); }
	_Ty *operator->() const throw ()
		{return (get()); }
	_Ty *get() const throw ()
		{return (_Ptr); }
	_Ty *release() const throw ()
		{((auto_ptr<_Ty> *)this)->_Owns = false;
		return (_Ptr); }
private:
	bool _Owns;
	_Ty *_Ptr;
	};
};

#pragma pack(pop)
#line 171 "c:\\program files\\microsoft visual studio\\vc98\\include\\memory"

#line 173 "c:\\program files\\microsoft visual studio\\vc98\\include\\memory"






















#line 11 "c:\\program files\\microsoft visual studio\\vc98\\include\\vector"




#pragma pack(push,8)
#line 17 "c:\\program files\\microsoft visual studio\\vc98\\include\\vector"
namespace std {
		
template<class _Ty, class _A = allocator<_Ty> >
	class vector {
public:
	typedef vector<_Ty, _A> _Myt;
	typedef _A allocator_type;
	typedef _A::size_type size_type;
	typedef _A::difference_type difference_type;
	typedef _A::pointer _Tptr;
	typedef _A::const_pointer _Ctptr;
	typedef _A::reference reference;
	typedef _A::const_reference const_reference;
	typedef _A::value_type value_type;
	typedef _Tptr iterator;
	typedef _Ctptr const_iterator;
	typedef reverse_iterator<const_iterator, value_type,
		const_reference, _Ctptr, difference_type>
			const_reverse_iterator;
	typedef reverse_iterator<iterator, value_type,
		reference, _Tptr, difference_type>
			reverse_iterator;
	explicit vector(const _A& _Al = _A())
		: allocator(_Al), _First(0), _Last(0), _End(0) {}
	explicit vector(size_type _N, const _Ty& _V = _Ty(),
		const _A& _Al = _A())
		: allocator(_Al)
		{_First = allocator.allocate(_N, (void *)0);
		_Ufill(_First, _N, _V);
		_Last = _First + _N;
		_End = _Last; }
	vector(const _Myt& _X)
		: allocator(_X.allocator)
		{_First = allocator.allocate(_X.size(), (void *)0);
		_Last = _Ucopy(_X.begin(), _X.end(), _First);
		_End = _Last; }
	typedef const_iterator _It;
	vector(_It _F, _It _L, const _A& _Al = _A())
		: allocator(_Al), _First(0), _Last(0), _End(0)
		{insert(begin(), _F, _L); }
	~vector()
		{_Destroy(_First, _Last);
		allocator.deallocate(_First, _End - _First);
		_First = 0, _Last = 0, _End = 0; }
	_Myt& operator=(const _Myt& _X)
		{if (this == &_X)
			;
		else if (_X.size() <= size())
			{iterator _S = copy(_X.begin(), _X.end(), _First);
			_Destroy(_S, _Last);
			_Last = _First + _X.size(); }
		else if (_X.size() <= capacity())
			{const_iterator _S = _X.begin() + size();
			copy(_X.begin(), _S, _First);
			_Ucopy(_S, _X.end(), _Last);
			_Last = _First + _X.size(); }
		else
			{_Destroy(_First, _Last);
			allocator.deallocate(_First, _End - _First);
			_First = allocator.allocate(_X.size(), (void *)0);
			_Last = _Ucopy(_X.begin(), _X.end(),
				_First);
			_End = _Last; }
		return (*this); }
	void reserve(size_type _N)
		{if (capacity() < _N)
			{iterator _S = allocator.allocate(_N, (void *)0);
			_Ucopy(_First, _Last, _S);
			_Destroy(_First, _Last);
			allocator.deallocate(_First, _End - _First);
			_End = _S + _N;
			_Last = _S + size();
			_First = _S; }}
	size_type capacity() const
		{return (_First == 0 ? 0 : _End - _First); }
	iterator begin()
		{return (_First); }
	const_iterator begin() const
		{return ((const_iterator)_First); }
	iterator end()
		{return (_Last); }
	const_iterator end() const
		{return ((const_iterator)_Last); }
	reverse_iterator rbegin()
		{return (reverse_iterator(end())); }
	const_reverse_iterator rbegin() const
		{return (const_reverse_iterator(end())); }
	reverse_iterator rend()
		{return (reverse_iterator(begin())); }
	const_reverse_iterator rend() const
		{return (const_reverse_iterator(begin())); }
	void resize(size_type _N, const _Ty& _X = _Ty())
		{if (size() < _N)
			insert(end(), _N - size(), _X);
		else if (_N < size())
			erase(begin() + _N, end()); }
	size_type size() const
		{return (_First == 0 ? 0 : _Last - _First); }
	size_type max_size() const
		{return (allocator.max_size()); }
	bool empty() const
		{return (size() == 0); }
	_A get_allocator() const
		{return (allocator); }
	const_reference at(size_type _P) const
		{if (size() <= _P)
			_Xran();
		return (*(begin() + _P)); }
	reference at(size_type _P)
		{if (size() <= _P)
			_Xran();
		return (*(begin() + _P)); }
	const_reference operator[](size_type _P) const
		{return (*(begin() + _P)); }
	reference operator[](size_type _P)
		{return (*(begin() + _P)); }
	reference front()
		{return (*begin()); }
	const_reference front() const
		{return (*begin()); }
	reference back()
		{return (*(end() - 1)); }
	const_reference back() const
		{return (*(end() - 1)); }
	void push_back(const _Ty& _X)
		{insert(end(), _X); }
	void pop_back()
		{erase(end() - 1); }
	void assign(_It _F, _It _L)
		{erase(begin(), end());
		insert(begin(), _F, _L); }
	void assign(size_type _N, const _Ty& _X = _Ty())
		{erase(begin(), end());
		insert(begin(), _N, _X); }
	iterator insert(iterator _P, const _Ty& _X = _Ty())
		{size_type _O = _P - begin();
		insert(_P, 1, _X);
		return (begin() + _O); }
	void insert(iterator _P, size_type _M, const _Ty& _X)
		{if (_End - _Last < _M)
			{size_type _N = size() + (_M < size() ? size() : _M);
			iterator _S = allocator.allocate(_N, (void *)0);
			iterator _Q = _Ucopy(_First, _P, _S);
			_Ufill(_Q, _M, _X);
			_Ucopy(_P, _Last, _Q + _M);
			_Destroy(_First, _Last);
			allocator.deallocate(_First, _End - _First);
			_End = _S + _N;
			_Last = _S + size() + _M;
			_First = _S; }
		else if (_Last - _P < _M)
			{_Ucopy(_P, _Last, _P + _M);
			_Ufill(_Last, _M - (_Last - _P), _X);
			fill(_P, _Last, _X);
			_Last += _M; }
		else if (0 < _M)
			{_Ucopy(_Last - _M, _Last, _Last);
			copy_backward(_P, _Last - _M, _Last);
			fill(_P, _P + _M, _X);
			_Last += _M; }}
	void insert(iterator _P, _It _F, _It _L)
		{size_type _M = 0;
		_Distance(_F, _L, _M);
		if (_End - _Last < _M)
			{size_type _N = size() + (_M < size() ? size() : _M);
			iterator _S = allocator.allocate(_N, (void *)0);
			iterator _Q = _Ucopy(_First, _P, _S);
			_Q = _Ucopy(_F, _L, _Q);
			_Ucopy(_P, _Last, _Q);
			_Destroy(_First, _Last);
			allocator.deallocate(_First, _End - _First);
			_End = _S + _N;
			_Last = _S + size() + _M;
			_First = _S; }
		else if (_Last - _P < _M)
			{_Ucopy(_P, _Last, _P + _M);
			_Ucopy(_F + (_Last - _P), _L, _Last);
			copy(_F, _F + (_Last - _P), _P);
			_Last += _M; }
		else if (0 < _M)
			{_Ucopy(_Last - _M, _Last, _Last);
			copy_backward(_P, _Last - _M, _Last);
			copy(_F, _L, _P);
			_Last += _M; }}
	iterator erase(iterator _P)
		{copy(_P + 1, end(), _P);
		_Destroy(_Last - 1, _Last);
		--_Last;
		return (_P); }
	iterator erase(iterator _F, iterator _L)
		{iterator _S = copy(_L, end(), _F);
		_Destroy(_S, end());
		_Last = _S;
		return (_F); }
	void clear()
		{erase(begin(), end()); }
	bool _Eq(const _Myt& _X) const
		{return (size() == _X.size()
			&& equal(begin(), end(), _X.begin())); }
	bool _Lt(const _Myt& _X) const
		{return (lexicographical_compare(begin(), end(),
			_X.begin(), _X.end())); }
	void swap(_Myt& _X)
		{if (allocator == _X.allocator)
			{std::swap(_First, _X._First);
			std::swap(_Last, _X._Last);
			std::swap(_End, _X._End); }
		else
			{_Myt _Ts = *this; *this = _X, _X = _Ts; }}
	friend void swap(_Myt& _X, _Myt& _Y)
		{_X.swap(_Y); }
protected:
	void _Destroy(iterator _F, iterator _L)
		{for (; _F != _L; ++_F)
			allocator.destroy(_F); }
	iterator _Ucopy(const_iterator _F, const_iterator _L,
		iterator _P)
		{for (; _F != _L; ++_P, ++_F)
			allocator.construct(_P, *_F);
		return (_P); }
	void _Ufill(iterator _F, size_type _N, const _Ty &_X)
		{for (; 0 < _N; --_N, ++_F)
			allocator.construct(_F, _X); }
	void _Xran() const
		{throw out_of_range("invalid vector<T> subscript"); }
	_A allocator;
	iterator _First, _Last, _End;
	};
		
typedef unsigned int _Vbase;
const int _VBITS = 8 * sizeof (_Vbase);
typedef allocator<_Vbase> _Bool_allocator;
class vector<_Bool, _Bool_allocator> {
public:
	typedef _Bool_allocator _A;
	typedef _Bool _Ty;
	typedef vector<_Ty, _A> _Myt;
	typedef vector<_Vbase, _A> _Vbtype;
	typedef _A allocator_type;
	typedef _A::size_type size_type;
	typedef _A::difference_type difference_type;

		
	class reference {
	public:
		reference()
			: _Mask(0), _Ptr(0) {}
		reference(size_t _O, _Vbase *_P)
			: _Mask((_Vbase)1 << _O), _Ptr(_P) {}
		reference& operator=(const reference& _X)
			{return (*this = bool(_X)); }
		reference& operator=(bool _V)
			{if (_V)
				*_Ptr |= _Mask;
			else
				*_Ptr &= ~_Mask;
			return (*this); }
		void flip()
			{*_Ptr ^= _Mask; }
		bool operator~() const
			{return (!bool(*this)); }
		operator bool() const
			{return ((*_Ptr & _Mask) != 0); }
	protected:
		_Vbase _Mask, *_Ptr;
		};

	typedef const reference const_reference;
	typedef bool value_type;
		
	class iterator;
	class const_iterator : public _Ranit<_Bool, difference_type> {
	public:
		const_iterator()
			: _Off(0), _Ptr(0) {}
		const_iterator(size_t _O, const _Vbase *_P)
			: _Off(_O), _Ptr((_Vbase*)_P) {}
		const_iterator(const iterator& _X)
			: _Off(_X._Off), _Ptr(_X._Ptr) {}
		const_reference operator*() const
			{return (const_reference(_Off, _Ptr)); }
		const_iterator& operator++()
			{_Inc();
			return (*this); }
		const_iterator operator++(int)
			{const_iterator _Tmp = *this;
			_Inc();
			return (_Tmp); }
		const_iterator& operator--()
			{_Dec();
			return (*this); }
		const_iterator operator--(int)
			{const_iterator _Tmp = *this;
			_Dec();
			return (_Tmp); }
		const_iterator& operator+=(difference_type _N)
			{_Off += _N;
			_Ptr += _Off / _VBITS;
			_Off %= _VBITS;
			return (*this); }
		const_iterator& operator-=(difference_type _N)
			{return (*this += -_N); }
		const_iterator operator+(difference_type _N) const
			{const_iterator _Tmp = *this;
			return (_Tmp += _N); }
		const_iterator operator-(difference_type _N) const
			{const_iterator _Tmp = *this;
			return (_Tmp -= _N); }
		difference_type operator-(const const_iterator _X) const
			{return (_VBITS * (_Ptr - _X._Ptr)
				+ (difference_type)_Off
				- (difference_type)_X._Off); }
		const_reference operator[](difference_type _N) const
			{return (*(*this + _N)); }
		bool operator==(const const_iterator& _X) const
			{return (_Ptr == _X._Ptr && _Off == _X._Off); }
		bool operator!=(const const_iterator& _X) const
			{return (!(*this == _X)); }
		bool operator<(const const_iterator& _X) const
			{return (_Ptr < _X._Ptr
				|| _Ptr == _X._Ptr && _Off < _X._Off); }
		bool operator>(const const_iterator& _X) const
			{return (_X < *this); }
		bool operator<=(const const_iterator& _X) const
			{return (!(_X < *this)); }
		bool operator>=(const const_iterator& _X) const
			{return (!(*this < _X)); }
	protected:
		void _Dec()
			{if (_Off != 0)
				--_Off;
			else
				_Off = _VBITS - 1, --_Ptr; }
		void _Inc()
			{if (_Off < _VBITS - 1)
				++_Off;
			else
				_Off = 0, ++_Ptr; }
		size_t _Off;
		_Vbase *_Ptr;
		};
		
	class iterator : public const_iterator {
	public:
		iterator()
			: const_iterator() {}
		iterator(size_t _O, _Vbase *_P)
			: const_iterator(_O, _P) {}
		reference operator*() const
			{return (reference(_Off, _Ptr)); }
		iterator& operator++()
			{_Inc();
			return (*this); }
		iterator operator++(int)
			{iterator _Tmp = *this;
			_Inc();
			return (_Tmp); }
		iterator& operator--()
			{_Dec();
			return (*this); }
		iterator operator--(int)
			{iterator _Tmp = *this;
			_Dec();
			return (_Tmp); }
		iterator& operator+=(difference_type _N)
			{_Off += _N;
			_Ptr += _Off / _VBITS;
			_Off %= _VBITS;
			return (*this); }
		iterator& operator-=(difference_type _N)
			{return (*this += -_N); }
		iterator operator+(difference_type _N) const
			{iterator _Tmp = *this;
			return (_Tmp += _N); }
		iterator operator-(difference_type _N) const
			{iterator _Tmp = *this;
			return (_Tmp -= _N); }
		difference_type operator-(const iterator _X) const
			{return (_VBITS * (_Ptr - _X._Ptr)
				+ (difference_type)_Off
				- (difference_type)_X._Off); }
		reference operator[](difference_type _N) const
			{return (*(*this + _N)); }
		bool operator==(const iterator& _X) const
			{return (_Ptr == _X._Ptr && _Off == _X._Off); }
		bool operator!=(const iterator& _X) const
			{return (!(*this == _X)); }
		bool operator<(const iterator& _X) const
			{return (_Ptr < _X._Ptr
				|| _Ptr == _X._Ptr && _Off < _X._Off); }
		bool operator>(const iterator& _X) const
			{return (_X < *this); }
		bool operator<=(const iterator& _X) const
			{return (!(_X < *this)); }
		bool operator>=(const iterator& _X) const
			{return (!(*this < _X)); }
		};
	typedef reverse_iterator<const_iterator, value_type,
		const_reference, const_reference *, difference_type>
			const_reverse_iterator;
	typedef reverse_iterator<iterator, value_type,
		reference, reference *, difference_type>
			reverse_iterator;
	explicit vector(const _A& _Al = _A())
		: _Size(0), _Vec(_Al) {}
	explicit vector(size_type _N, const bool _V = false,
		const _A& _Al = _A())
		: _Vec(_Nw(_N), _V ? -1 : 0, _Al) {_Trim(_N); }
	typedef const_iterator _It;
	vector(_It _F, _It _L, const _A& _Al = _A())
		: _Size(0), _Vec(_Al)
		{insert(begin(), _F, _L); }
	~vector()
		{_Size = 0; }
	void reserve(size_type _N)
		{_Vec.reserve(_Nw(_N)); }
	size_type capacity() const
		{return (_Vec.capacity() * _VBITS); }
	iterator begin()
		{return (iterator(0, _Vec.begin())); }
	const_iterator begin() const
		{return (const_iterator(0, _Vec.begin())); }
	iterator end()
		{iterator _Tmp = begin();
		if (0 < _Size)
			_Tmp += _Size;
		return (_Tmp); }
	const_iterator end() const
		{const_iterator _Tmp = begin();
		if (0 < _Size)
			_Tmp += _Size;
		return (_Tmp); }
	reverse_iterator rbegin()
		{return (reverse_iterator(end())); }
	const_reverse_iterator rbegin() const
		{return (const_reverse_iterator(end())); }
	reverse_iterator rend()
		{return (reverse_iterator(begin())); }
	const_reverse_iterator rend() const
		{return (const_reverse_iterator(begin())); }
	void resize(size_type _N, bool _X = false)
		{if (size() < _N)
			insert(end(), _N - size(), _X);
		else if (_N < size())
			erase(begin() + _N, end()); }
	size_type size() const
		{return (_Size); }
	size_type max_size() const
		{return (_Vec.max_size() * _VBITS); }
	bool empty() const
		{return (size() == 0); }
	_A get_allocator() const
		{return (_Vec.get_allocator()); }
	const_reference at(size_type _P) const
		{if (size() <= _P)
			_Xran();
		return (*(begin() + _P)); }
	reference at(size_type _P)
		{if (size() <= _P)
			_Xran();
		return (*(begin() + _P)); }
	const_reference operator[](size_type _P) const
		{return (*(begin() + _P)); }
	reference operator[](size_type _P)
		{return (*(begin() + _P)); }
	reference front()
		{return (*begin()); }
	const_reference front() const
		{return (*begin()); }
	reference back()
		{return (*(end() - 1)); }
	const_reference back() const
		{return (*(end() - 1)); }
	void push_back(const bool _X)
		{insert(end(), _X); }
	void pop_back()
		{erase(end() - 1); }
	void assign(_It _F, _It _L)
		{erase(begin(), end());
		insert(begin(), _F, _L); }
	void assign(size_type _N, const bool _X = false)
		{erase(begin(), end());
		insert(begin(), _N, _X); }
	iterator insert(iterator _P, const bool _X = false)
		{size_type _O = _P - begin();
		insert(_P, 1, _X);
		return (begin() + _O); }
	void insert(iterator _P, size_type _M, const bool _X)
		{if (0 < _M)
			{if (capacity() - size() < _M)
				{size_type _O = _P - begin();
				_Vec.resize(_Nw(size() + _M), 0);
				_P = begin() + _O; }
			copy_backward(_P, end(), end() + _M);
			fill(_P, _P + _M, _X);
			_Size += _M; }}
	void insert(iterator _P, _It _F, _It _L)
		{size_type _M = 0;
		_Distance(_F, _L, _M);
		if (0 < _M)
			{if (capacity() - size() < _M)
				{size_type _O = _P - begin();
				_Vec.resize(_Nw(size() + _M), 0);
				_P = begin() + _O; }
			copy_backward(_P, end(), end() + _M);
			copy(_F, _L, _P);
			_Size += _M; }}
	iterator erase(iterator _P)
		{copy(_P + 1, end(), _P);
		_Trim(_Size - 1);
		return (_P); }
	iterator erase(iterator _F, iterator _L)
		{iterator _S = copy(_L, end(), _F);
		_Trim(_S - begin());
		return (_F); }
	void clear()
		{erase(begin(), end()); }
	void flip()
		{for (_Vbtype::iterator _S = _Vec.begin();
			_S != _Vec.end(); ++_S)
			*_S = ~*_S;
		_Trim(_Size); }
	bool _Eq(const _Myt& _X) const
		{return (_Size == _X._Size && _Vec._Eq(_X._Vec)); }
	bool _Lt(const _Myt& _X) const
		{return (_Size < _X._Size
			|| _Size == _X._Size && _Vec._Lt(_X._Vec)); }
	void swap(_Myt& _X)
		{std::swap(_Size, _X._Size);
		_Vec.swap(_X._Vec); }
	friend void swap(_Myt& _X, _Myt& _Y)
		{_X.swap(_Y); }
	static void swap(reference _X, reference _Y)
		{bool _V = _X;
		_X = _Y;
		_Y = _V; }
protected:
	static size_type _Nw(size_type _N)
		{return ((_N + _VBITS - 1) / _VBITS); }
	void _Trim(size_type _N)
		{size_type _M = _Nw(_N);
		if (_M < _Vec.size())
			_Vec.erase(_Vec.begin() + _M, _Vec.end());
		_Size = _N;
		_N %= _VBITS;
		if (0 < _N)
			_Vec[_M - 1] &= ((_Vbase)1 << _N) - 1; }
	void _Xran() const
		{throw out_of_range("invalid vector<bool> subscript"); }
	size_type _Size;
	_Vbtype _Vec;
	};
typedef vector<_Bool, _Bool_allocator> _Bvector;
		
template<class _Ty, class _A> inline
	bool operator==(const vector<_Ty, _A>& _X,
		const vector<_Ty, _A>& _Y)
	{return (_X._Eq(_Y)); }
template<class _Ty, class _A> inline
	bool operator!=(const vector<_Ty, _A>& _X,
		const vector<_Ty, _A>& _Y)
	{return (!(_X == _Y)); }
template<class _Ty, class _A> inline
	bool operator<(const vector<_Ty, _A>& _X,
		const vector<_Ty, _A>& _Y)
	{return (_X._Lt(_Y)); }
template<class _Ty, class _A> inline
	bool operator>(const vector<_Ty, _A>& _X,
		const vector<_Ty, _A>& _Y)
	{return (_Y < _X); }
template<class _Ty, class _A> inline
	bool operator<=(const vector<_Ty, _A>& _X,
		const vector<_Ty, _A>& _Y)
	{return (!(_Y < _X)); }
template<class _Ty, class _A> inline
	bool operator>=(const vector<_Ty, _A>& _X,
		const vector<_Ty, _A>& _Y)
	{return (!(_X < _Y)); }
};

#pragma pack(pop)
#line 599 "c:\\program files\\microsoft visual studio\\vc98\\include\\vector"

#line 601 "c:\\program files\\microsoft visual studio\\vc98\\include\\vector"






















#line 9 "d:\\hassan\\devs\\solarsystem\\trunk\\engine\\xml\\xml.h"
#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\set"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\set"



#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\functional"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\functional"






#pragma pack(push,8)
#line 14 "c:\\program files\\microsoft visual studio\\vc98\\include\\functional"
namespace std {
		
template<class _A, class _R>
	struct unary_function {
	typedef _A argument_type;
	typedef _R result_type;
	};
		
template<class _A1, class _A2, class _R>
	struct binary_function {
	typedef _A1 first_argument_type;
	typedef _A2 second_argument_type;
	typedef _R result_type;
	};
		
template<class _Ty>
	struct plus : binary_function<_Ty, _Ty, _Ty> {
	_Ty operator()(const _Ty& _X, const _Ty& _Y) const
		{return (_X + _Y); }
	};
		
template<class _Ty>
	struct minus : binary_function<_Ty, _Ty, _Ty> {
	_Ty operator()(const _Ty& _X, const _Ty& _Y) const
		{return (_X - _Y); }
	};
		
template<class _Ty>
	struct multiplies : binary_function<_Ty, _Ty, _Ty> {
	_Ty operator()(const _Ty& _X, const _Ty& _Y) const
		{return (_X * _Y); }
	};
		
template<class _Ty>
	struct divides : binary_function<_Ty, _Ty, _Ty> {
	_Ty operator()(const _Ty& _X, const _Ty& _Y) const
		{return (_X / _Y); }
	};
		
template<class _Ty>
	struct modulus : binary_function<_Ty, _Ty, _Ty> {
	_Ty operator()(const _Ty& _X, const _Ty& _Y) const
		{return (_X % _Y); }
	};
		
template<class _Ty>
	struct negate : unary_function<_Ty, _Ty> {
	_Ty operator()(const _Ty& _X) const
		{return (-_X); }
	};
		
template<class _Ty>
	struct equal_to : binary_function<_Ty, _Ty, bool> {
	bool operator()(const _Ty& _X, const _Ty& _Y) const
		{return (_X == _Y); }
	};
		
template<class _Ty>
	struct not_equal_to : binary_function<_Ty, _Ty, bool> {
	bool operator()(const _Ty& _X, const _Ty& _Y) const
		{return (_X != _Y); }
	};
		
template<class _Ty>
	struct greater : binary_function<_Ty, _Ty, bool> {
	bool operator()(const _Ty& _X, const _Ty& _Y) const
		{return (_X > _Y); }
	};
		
template<class _Ty>
	struct less : binary_function<_Ty, _Ty, bool> {
	bool operator()(const _Ty& _X, const _Ty& _Y) const
		{return (_X < _Y); }
	};
		
template<class _Ty>
	struct greater_equal : binary_function<_Ty, _Ty, bool> {
	bool operator()(const _Ty& _X, const _Ty& _Y) const
		{return (_X >= _Y); }
	};
		
template<class _Ty>
	struct less_equal : binary_function<_Ty, _Ty, bool> {
	bool operator()(const _Ty& _X, const _Ty& _Y) const
		{return (_X <= _Y); }
	};
		
template<class _Ty>
	struct logical_and : binary_function<_Ty, _Ty, bool> {
	bool operator()(const _Ty& _X, const _Ty& _Y) const
		{return (_X && _Y); }
	};
		
template<class _Ty>
	struct logical_or : binary_function<_Ty, _Ty, bool> {
	bool operator()(const _Ty& _X, const _Ty& _Y) const
		{return (_X || _Y); }
	};
		
template<class _Ty>
	struct logical_not : unary_function<_Ty, bool> {
	bool operator()(const _Ty& _X) const
		{return (!_X); }
	};
		
template<class _Ufn>
	class unary_negate
	: public unary_function<_Ufn::argument_type, bool> {
public:
	explicit unary_negate(const _Ufn& _X)
		: _Fn(_X) {}
	bool operator()(const _Ufn::argument_type& _X) const
		{return (!_Fn(_X)); }
protected:
	_Ufn _Fn;
	};
		
template<class _Ufn> inline
	unary_negate<_Ufn> not1(const _Ufn& _X)
		{return (unary_negate<_Ufn>(_X)); }
		
template<class _Bfn>
	class binary_negate
	: public binary_function<_Bfn::first_argument_type,
		_Bfn::second_argument_type, bool> {
public:
	explicit binary_negate(const _Bfn& _X)
		: _Fn(_X) {}
	bool operator()(const _Bfn::first_argument_type& _X,
		const _Bfn::second_argument_type& _Y) const
		{return (!_Fn(_X, _Y)); }
protected:
	_Bfn _Fn;
	};
		
template<class _Bfn> inline
	binary_negate<_Bfn> not2(const _Bfn& _X)
		{return (binary_negate<_Bfn>(_X)); }
		
template<class _Bfn>
	class binder1st
	: public unary_function<_Bfn::second_argument_type,
		_Bfn::result_type> {
public:
	binder1st(const _Bfn& _X,
		const _Bfn::first_argument_type& _Y)
		: op(_X), value(_Y) {}
	result_type operator()(const argument_type& _X) const
		{return (op(value, _X)); }
protected:
	_Bfn op;
	_Bfn::first_argument_type value;
	};
		
template<class _Bfn, class _Ty> inline
	binder1st<_Bfn> bind1st(const _Bfn& _X, const _Ty& _Y)
		{return (binder1st<_Bfn>(_X,
			_Bfn::first_argument_type(_Y))); }
		
template<class _Bfn>
	class binder2nd
	: public unary_function<_Bfn::first_argument_type,
		_Bfn::result_type> {
public:
	binder2nd(const _Bfn& _X,
		const _Bfn::second_argument_type& _Y)
		: op(_X), value(_Y) {}
	result_type operator()(const argument_type& _X) const
		{return (op(_X, value)); }
protected:
	_Bfn op;
	_Bfn::second_argument_type value;
	};
		
template<class _Bfn, class _Ty> inline
	binder2nd<_Bfn> bind2nd(const _Bfn& _X, const _Ty& _Y)
		{return (binder2nd<_Bfn>(_X,
			_Bfn::second_argument_type(_Y))); }
		
template<class _A, class _R>
	class pointer_to_unary_function
		: public unary_function<_A, _R> {
public:
	explicit pointer_to_unary_function(_R (__cdecl *_X)(_A))
		: _Fn(_X) {}
	_R operator()(_A _X) const
		{return (_Fn(_X)); }
protected:
	_R (__cdecl *_Fn)(_A);
	};
		
template<class _A1, class _A2, class _R>
	class pointer_to_binary_function
		: public binary_function<_A1, _A2, _R> {
public:
	explicit pointer_to_binary_function(
		_R (__cdecl *_X)(_A1, _A2))
		: _Fn(_X) {}
	_R operator()(_A1 _X, _A2 _Y) const
		{return (_Fn(_X, _Y)); }
protected:
	_R (__cdecl *_Fn)(_A1, _A2);
	};
		
template<class _A, class _R> inline
	pointer_to_unary_function<_A, _R>
		ptr_fun(_R (__cdecl *_X)(_A))
		{return (pointer_to_unary_function<_A, _R>(_X)); }
template<class _A1, class _A2, class _R> inline
	pointer_to_binary_function<_A1, _A2, _R>
		ptr_fun(_R (__cdecl *_X)(_A1, _A2))
		{return (pointer_to_binary_function<_A1, _A2, _R>(_X)); }
		
template<class _R, class _Ty>
	class mem_fun_t : public unary_function<_Ty *, _R> {
public:
	explicit mem_fun_t(_R (_Ty::*_Pm)())
		: _Ptr(_Pm) {}
	_R operator()(_Ty *_P) const
		{return ((_P->*_Ptr)()); }
private:
	_R (_Ty::*_Ptr)();
	};
		
template<class _R, class _Ty> inline
	mem_fun_t<_R, _Ty> mem_fun(_R (_Ty::*_Pm)())
	{return (mem_fun_t<_R, _Ty>(_Pm)); }
		
template<class _R, class _Ty, class _A>
	class mem_fun1_t : public binary_function<_Ty *, _A, _R> {
public:
	explicit mem_fun1_t(_R (_Ty::*_Pm)(_A))
		: _Ptr(_Pm) {}
	_R operator()(_Ty *_P, _A _Arg) const
		{return ((_P->*_Ptr)(_Arg)); }
private:
	_R (_Ty::*_Ptr)(_A);
	};
		
template<class _R, class _Ty, class _A> inline
	mem_fun1_t<_R, _Ty, _A> mem_fun1(_R (_Ty::*_Pm)(_A))
	{return (mem_fun1_t<_R, _Ty, _A>(_Pm)); }
		
template<class _R, class _Ty>
	class mem_fun_ref_t : public unary_function<_Ty, _R> {
public:
	explicit mem_fun_ref_t(_R (_Ty::*_Pm)())
		: _Ptr(_Pm) {}
	_R operator()(_Ty& _X) const
		{return ((_X.*_Ptr)()); }
private:
	_R (_Ty::*_Ptr)();
	};
		
template<class _R, class _Ty> inline
	mem_fun_ref_t<_R, _Ty> mem_fun_ref(_R (_Ty::*_Pm)())
	{return (mem_fun_ref_t<_R, _Ty>(_Pm)); }
		
template<class _R, class _Ty, class _A>
	class mem_fun1_ref_t : public binary_function<_Ty *, _A, _R> {
public:
	explicit mem_fun1_ref_t(_R (_Ty::*_Pm)(_A))
		: _Ptr(_Pm) {}
	_R operator()(_Ty& _X, _A _Arg) const
		{return ((_X.*_Ptr)(_Arg)); }
private:
	_R (_Ty::*_Ptr)(_A);
	};
		
template<class _R, class _Ty, class _A> inline
	mem_fun1_ref_t<_R, _Ty, _A> mem_fun1_ref(_R (_Ty::*_Pm)(_A))
	{return (mem_fun1_ref_t<_R, _Ty, _A>(_Pm)); }
};

#pragma pack(pop)
#line 290 "c:\\program files\\microsoft visual studio\\vc98\\include\\functional"

#line 292 "c:\\program files\\microsoft visual studio\\vc98\\include\\functional"






















#line 10 "c:\\program files\\microsoft visual studio\\vc98\\include\\set"
#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\xtree"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\xtree"




#line 1 "c:\\program files\\microsoft visual studio\\vc98\\include\\iterator"



#pragma once
#line 6 "c:\\program files\\microsoft visual studio\\vc98\\include\\iterator"






#pragma pack(push,8)
#line 14 "c:\\program files\\microsoft visual studio\\vc98\\include\\iterator"
namespace std {
		
template<class _BI,
	class _Ty,
	class _Rt = _Ty&,
	class _Pt = _Ty *,
	class _D = ptrdiff_t>
	class reverse_bidirectional_iterator
		: public _Bidit<_Ty, _D> {
public:
	typedef reverse_bidirectional_iterator<_BI,
		_Ty, _Rt, _Pt, _D> _Myt;
	typedef _BI iter_type;
	typedef _Rt reference_type;
	typedef _Pt pointer_type;
	reverse_bidirectional_iterator()
		{}
	explicit reverse_bidirectional_iterator(_BI _X)
		: current(_X) {}
	_BI base() const
		{return (current); }
	_Rt operator*() const
		{_BI _Tmp = current;
		return (*--_Tmp); }
	_Pt operator->() const
		{return (&**this); }
	_Myt& operator++()
		{--current;
		return (*this); }
	_Myt operator++(int)
		{_Myt _Tmp = *this;
		--current;
		return (_Tmp); }
	_Myt& operator--()
		{++current;
		return (*this); }
	_Myt operator--(int)
		{_Myt _Tmp = *this;
		++current;
		return (_Tmp); }
protected:
	_BI current;
	};
template<class _BI, class _Ty, class _Rt, class _Pt,
	class _D> inline
	bool operator==(const reverse_bidirectional_iterator<_BI,
			_Ty, _Rt, _Pt, _D>& _X,
		const reverse_bidirectional_iterator<_BI,
			_Ty, _Rt, _Pt, _D>& _Y)
	{return (_X.base() == _Y.base()); }
template<class _BI, class _Ty, class _Rt, class _Pt,
	class _D> inline
	bool operator!=(const reverse_bidirectional_iterator<_BI,
			_Ty, _Rt, _Pt, _D>& _X,
		const reverse_bidirectional_iterator<_BI,
			_Ty, _Rt, _Pt, _D>& _Y)
	{return (!(_X == _Y)); }
		
template<class _C>
	class back_insert_iterator
		: public iterator<output_iterator_tag, void, void> {
public:
	typedef _C container_type;
	typedef _C::value_type value_type;
	explicit back_insert_iterator(_C& _X)
		: container(_X) {}
	back_insert_iterator<_C>& operator=(
		const value_type& _V)
		{container.push_back(_V);
		return (*this); }
	back_insert_iterator<_C>& operator*()
		{return (*this); }
	back_insert_iterator<_C>& operator++()
		{return (*this); }
	back_insert_iterator<_C> operator++(int)
		{return (*this); }
protected:
	_C& container;
	};
template<class _C> inline
	back_insert_iterator<_C> back_inserter(_C& _X)
	{return (back_insert_iterator<_C>(_X)); }
		
template<class _C>
	class front_insert_iterator
		: public iterator<output_iterator_tag, void, void> {
public:
	typedef _C container_type;
	typedef _C::value_type value_type;
	explicit front_insert_iterator(_C& _X)
		: container(_X) {}
	front_insert_iterator<_C>& operator=(
		const value_type& _V)
		{container.push_front(_V);
		return (*this); }
	front_insert_iterator<_C>& operator*()
		{return (*this); }
	front_insert_iterator<_C>& operator++()
		{return (*this); }
	front_insert_iterator<_C> operator++(int)
		{return (*this); }
protected:
	_C& container;
	};
template<class _C> inline
	front_insert_iterator<_C> front_inserter(_C& _X)
	{return (front_insert_iterator<_C>(_X)); }
		
template<class _C>
	class insert_iterator
		: public iterator<output_iterator_tag, void, void> {
public:
	typedef _C container_type;
	typedef _C::value_type value_type;
	insert_iterator(_C& _X, _C::iterator _I)
		: container(_X), iter(_I) {}
	insert_iterator<_C>& operator=(
		const value_type& _V)
		{iter = container.insert(iter, _V);
		++iter;
		return (*this); }
	insert_iterator<_C>& operator*()
		{return (*this); }
	insert_iterator<_C>& operator++()
		{return (*this); }
	insert_iterator<_C>& operator++(int)
		{return (*this); }
protected:
	_C& container;
	_C::iterator iter;
	};
template<class _C, class _XI> inline
	insert_iterator<_C> inserter(_C& _X, _XI _I)
	{return (insert_iterator<_C>(_X, _C::iterator(_I))); }
		
template<class _U, class _E = char,
	class _Tr = char_traits<_E> >
	class istream_iterator
		: public iterator<input_iterator_tag, _U, ptrdiff_t> {
public:
	typedef _E char_type;
	typedef _Tr traits_type;
	typedef basic_istream<_E, _Tr> istream_type;
	istream_iterator()
		: _Istr(0) {}
	istream_iterator(istream_type& _I)
		: _Istr(&_I) {_Getval(); }
	const _U& operator*() const
		{return (_Val); }
	const _U *operator->() const
		{return (&**this); }
	istream_iterator<_U, _E, _Tr>& operator++()
		{_Getval();
		return (*this); }
	istream_iterator<_U, _E, _Tr> operator++(int)
		{istream_iterator<_U, _E, _Tr> _Tmp = *this;
		_Getval();
		return (_Tmp); }
	bool _Equal(const istream_iterator<_U, _E, _Tr>& _X) const
		{return (_Istr == _X._Istr); }
protected:
	void _Getval()
		{if (_Istr != 0 && !(*_Istr >> _Val))
			_Istr = 0; }
	istream_type *_Istr;
	_U _Val;
	};
template<class _U, class _E, class _Tr> inline
	bool operator==(const istream_iterator<_U, _E, _Tr>& _X,
		const istream_iterator<_U, _E, _Tr>& _Y)
	{return (_X._Equal(_Y)); }
template<class _U, class _E, class _Tr> inline
	bool operator!=(const istream_iterator<_U, _E, _Tr>& _X,
		const istream_iterator<_U, _E, _Tr>& _Y)
	{return (!(_X == _Y)); }
		
template<class _U, class _E = char,
	class _Tr = char_traits<_E> >
	class ostream_iterator
		: public iterator<output_iterator_tag, void, void> {
public:
	typedef _U value_type;
	typedef _E char_type;
	typedef _Tr traits_type;
	typedef basic_ostream<_E, _Tr> ostream_type;
	ostream_iterator(ostream_type& _O,
		const _E *_D = 0)
		: _Ostr(&_O), _Delim(_D) {}
	ostream_iterator<_U, _E, _Tr>& operator=(const _U& _X)
		{*_Ostr << _X;
		if (_Delim != 0)
			*_Ostr << _Delim;
		return (*this); }
	ostream_iterator<_U, _E, _Tr>& operator*()
		{return (*this); }
	ostream_iterator<_U, _E, _Tr>& operator++()
		{return (*this); }
	ostream_iterator<_U, _E, _Tr> operator++(int)
		{return (*this); }
protected:
	const _E *_Delim;
	ostream_type *_Ostr;
	};
		
template<class _C, class _Ty, class _D> inline
	_Ty *_Val_type(const iterator<_C, _Ty, _D>&)
	{return ((_Ty *)0); }
template<class _Ty> inline
	_Ty *_Val_type(const _Ty *)
	{return ((_Ty *)0); }
		
template<class _II, class _D> inline
	void advance(_II& _I, _D _N)
	{_Advance(_I, _N, _Iter_cat(_I)); }
template<class _II, class _D> inline
	void _Advance(_II& _I, _D _N, input_iterator_tag)
	{for (; 0 < _N; --_N)
		++_I; }
template<class _FI, class _D> inline
	void _Advance(_FI& _I, _D _N, forward_iterator_tag)
	{for (; 0 < _N; --_N)
		++_I; }
template<class _BI, class _D> inline
	void _Advance(_BI& _I, _D _N, bidirectional_iterator_tag)
	{for (; 0 < _N; --_N)
		++_I;
	for (; _N < 0; ++_N)
		--_I; }
template<class _RI, class _D> inline
	void _Advance(_RI& _I, _D _N, random_access_iterator_tag)
	{_I += _N; }
		
template<class _C, class _Ty, class _D> inline
	_D *_Dist_type(const iterator<_C, _Ty, _D>&)
	{return ((_D *)0); }
template<class _Ty> inline
	ptrdiff_t *_Dist_type(const _Ty *)
	{return ((ptrdiff_t *)0); }
};

#pragma pack(pop)
#line 256 "c:\\program files\\microsoft visual studio\\vc98\\include\\iterator"

#line 258 "c:\\program files\\microsoft visual studio\\vc98\\include\\iterator"






















#line 11 "c:\\program files\\microsoft visual studio\\vc98\\include\\xtree"




#pragma pack(push,8)
#line 17 "c:\\program files\\microsoft visual studio\\vc98\\include\\xtree"
namespace std {
                
template<class _K, class _Ty, class _Kfn, class _Pr, class _A>
        class _Tree {
protected:
        enum _Redbl {_Red, _Black};
        struct _Node;
        friend struct _Node;
        typedef _Node  * _Nodeptr;
        struct _Node {
                _Nodeptr _Left, _Parent, _Right;
                _Ty _Value;
                _Redbl _Color;
                };
        typedef _Nodeptr  & _Nodepref;
        typedef const _K  & _Keyref;
        typedef _Redbl  & _Rbref;
        typedef _Ty  & _Vref;
        static _Rbref _Color(_Nodeptr _P)
                {return ((_Rbref)(*_P)._Color); }
        static _Keyref _Key(_Nodeptr _P)
                {return (_Kfn()(_Value(_P))); }
        static _Nodepref _Left(_Nodeptr _P)
                {return ((_Nodepref)(*_P)._Left); }
        static _Nodepref _Parent(_Nodeptr _P)
                {return ((_Nodepref)(*_P)._Parent); }
        static _Nodepref _Right(_Nodeptr _P)
                {return ((_Nodepref)(*_P)._Right); }
        static _Vref _Value(_Nodeptr _P)
                {return ((_Vref)(*_P)._Value); }
public:
        typedef _Tree<_K, _Ty, _Kfn, _Pr, _A> _Myt;
        typedef _K key_type;
        typedef _Ty value_type;
        typedef _A::size_type size_type;
        typedef _A::difference_type difference_type;
        typedef _Ty  * _Tptr;
        typedef const _Ty  * _Ctptr;
        typedef _Ty  & reference;
        typedef const _Ty  & const_reference;
                
        class iterator;
        class const_iterator;
        friend class const_iterator;
        class const_iterator : public _Bidit<_Ty, difference_type> {
        public:
                const_iterator()
                        {}
                const_iterator(_Nodeptr _P)
                        : _Ptr(_P) {}
                const_iterator(const iterator& _X)
                        : _Ptr(_X._Ptr) {}
                const_reference operator*() const
                        {return (_Value(_Ptr)); }
                _Ctptr operator->() const
                        {return (&**this); }
                const_iterator& operator++()
                        {_Inc();
                        return (*this); }
                const_iterator operator++(int)
                        {const_iterator _Tmp = *this;
                        ++*this;
                        return (_Tmp); }
                const_iterator& operator--()
                        {_Dec();
                        return (*this); }
                const_iterator operator--(int)
                        {const_iterator _Tmp = *this;
                        --*this;
                        return (_Tmp); }
                bool operator==(const const_iterator& _X) const
                        {return (_Ptr == _X._Ptr); }
                bool operator!=(const const_iterator& _X) const
                        {return (!(*this == _X)); }
                void _Dec()
                        {if (_Color(_Ptr) == _Red
                                && _Parent(_Parent(_Ptr)) == _Ptr)
                                _Ptr = _Right(_Ptr);
                        else if (_Left(_Ptr) != _Nil)
                                _Ptr = _Max(_Left(_Ptr));
                        else
                                {_Nodeptr _P;
                                while (_Ptr == _Left(_P = _Parent(_Ptr)))
                                        _Ptr = _P;
                                _Ptr = _P; }}
                void _Inc()
                        {if (_Right(_Ptr) != _Nil)
                                _Ptr = _Min(_Right(_Ptr));
                        else
                                {_Nodeptr _P;
                                while (_Ptr == _Right(_P = _Parent(_Ptr)))
                                        _Ptr = _P;
                                if (_Right(_Ptr) != _P)
                                        _Ptr = _P; }}
                _Nodeptr _Mynode() const
                        {return (_Ptr); }
        protected:
                _Nodeptr _Ptr;
                };
                
        friend class iterator;
        class iterator : public const_iterator {
        public:
                iterator()
                        {}
                iterator(_Nodeptr _P)
                        : const_iterator(_P) {}
                reference operator*() const
                        {return (_Value(_Ptr)); }
                _Tptr operator->() const
                        {return (&**this); }
                iterator& operator++()
                        {_Inc();
                        return (*this); }
                iterator operator++(int)
                        {iterator _Tmp = *this;
                        ++*this;
                        return (_Tmp); }
                iterator& operator--()
                        {_Dec();
                        return (*this); }
                iterator operator--(int)
                        {iterator _Tmp = *this;
                        --*this;
                        return (_Tmp); }
                bool operator==(const iterator& _X) const
                        {return (_Ptr == _X._Ptr); }
                bool operator!=(const iterator& _X) const
                        {return (!(*this == _X)); }
                };
        typedef reverse_bidirectional_iterator<iterator,
                value_type, reference, _Tptr, difference_type>
                        reverse_iterator;
        typedef reverse_bidirectional_iterator<const_iterator,
                value_type, const_reference, _Ctptr, difference_type>
                        const_reverse_iterator;
        typedef pair<iterator, bool> _Pairib;
        typedef pair<iterator, iterator> _Pairii;
        typedef pair<const_iterator, const_iterator> _Paircc;
        explicit _Tree(const _Pr& _Parg, bool _Marg = true,
                const _A& _Al = _A())
                : allocator(_Al),
                key_compare(_Parg), _Multi(_Marg)
                {_Init(); }
        _Tree(const _Ty *_F, const _Ty *_L,
                const _Pr& _Parg, bool _Marg = true,
                const _A& _Al = _A())
                : allocator(_Al),
                key_compare(_Parg), _Multi(_Marg)
                {_Init();
                insert(_F, _L); }
        _Tree(const _Myt& _X)
                : allocator(_X.allocator),
                key_compare(_X.key_compare), _Multi(_X._Multi)
                {_Init();
                _Copy(_X); }
        ~_Tree()
                {erase(begin(), end());
                _Freenode(_Head);
                _Head = 0, _Size = 0;
                _Nodeptr _Tmp = 0;
                        {_Lockit _Lk;
                        if (--_Nilrefs == 0)
                                {_Tmp = _Nil;
                                _Nil = 0; }}
                if (_Tmp != 0)
                        _Freenode(_Tmp); }
        _Myt& operator=(const _Myt& _X)
                {if (this != &_X)
                        {erase(begin(), end());
                        key_compare = _X.key_compare;
                        _Copy(_X); }
                return (*this); }
        iterator begin()
                {return (iterator(_Lmost())); }
        const_iterator begin() const
                {return (const_iterator(_Lmost())); }
        iterator end()
                {return (iterator(_Head)); }
        const_iterator end() const
                {return (const_iterator(_Head)); }
        reverse_iterator rbegin()
                {return (reverse_iterator(end())); }
        const_reverse_iterator rbegin() const
                {return (const_reverse_iterator(end())); }
        reverse_iterator rend()
                {return (reverse_iterator(begin())); }
        const_reverse_iterator rend() const
                {return (const_reverse_iterator(begin())); }
        size_type size() const
                {return (_Size); }
        size_type max_size() const
                {return (allocator.max_size()); }
        bool empty() const
                {return (size() == 0); }
        _A get_allocator() const
                {return (allocator); }
        _Pr key_comp() const
                {return (key_compare); }
        _Pairib insert(const value_type& _V)
                {_Nodeptr _X = _Root();
                _Nodeptr _Y = _Head;
                bool _Ans = true;
                        while (_X != _Nil)
                                {_Y = _X;
                                _Ans = key_compare(_Kfn()(_V), _Key(_X));
                                _X = _Ans ? _Left(_X) : _Right(_X); }
                if (_Multi)
                        return (_Pairib(_Insert(_X, _Y, _V), true));
                iterator _P = iterator(_Y);
                if (!_Ans)
                        ;
                else if (_P == begin())
                        return (_Pairib(_Insert(_X, _Y, _V), true));
                else
                        --_P;
                if (key_compare(_Key(_P._Mynode()), _Kfn()(_V)))
                        return (_Pairib(_Insert(_X, _Y, _V), true));
                return (_Pairib(_P, false)); }
        iterator insert(iterator _P, const value_type& _V)
                {if (size() == 0)
                        ;
                else if (_P == begin())
                        {if (key_compare(_Kfn()(_V), _Key(_P._Mynode())))
                                return (_Insert(_Head, _P._Mynode(), _V)); }
                else if (_P == end())
                        {if (key_compare(_Key(_Rmost()), _Kfn()(_V)))
                                return (_Insert(_Nil, _Rmost(), _V)); }
                else
                        {iterator _Pb = _P;
                        if (key_compare(_Key((--_Pb)._Mynode()), _Kfn()(_V))
                                && key_compare(_Kfn()(_V), _Key(_P._Mynode())))
                                {if (_Right(_Pb._Mynode()) == _Nil)
                                        return (_Insert(_Nil, _Pb._Mynode(), _V));
                                else
                                        return (_Insert(_Head, _P._Mynode(), _V)); }}
                return (insert(_V).first); }
        void insert(iterator _F, iterator _L)
                {for (; _F != _L; ++_F)
                        insert(*_F); }
        void insert(const value_type *_F, const value_type *_L)
                {for (; _F != _L; ++_F)
                        insert(*_F); }
        iterator erase(iterator _P)
                {_Nodeptr _X;
                _Nodeptr _Y = (_P++)._Mynode();
                _Nodeptr _Z = _Y;
                if (_Left(_Y) == _Nil)
                        _X = _Right(_Y);
                else if (_Right(_Y) == _Nil)
                        _X = _Left(_Y);
                else
                        _Y = _Min(_Right(_Y)), _X = _Right(_Y);
                if (_Y != _Z)
                        {_Parent(_Left(_Z)) = _Y;
                        _Left(_Y) = _Left(_Z);
                        if (_Y == _Right(_Z))
                                _Parent(_X) = _Y;
                        else
                                {_Parent(_X) = _Parent(_Y);
                                _Left(_Parent(_Y)) = _X;
                                _Right(_Y) = _Right(_Z);
                                _Parent(_Right(_Z)) = _Y; }
                        if (_Root() == _Z)
                                _Root() = _Y;
                        else if (_Left(_Parent(_Z)) == _Z)
                                _Left(_Parent(_Z)) = _Y;
                        else
                                _Right(_Parent(_Z)) = _Y;
                        _Parent(_Y) = _Parent(_Z);
                        std::swap(_Color(_Y), _Color(_Z));
                        _Y = _Z; }
                else
                        {_Parent(_X) = _Parent(_Y);
                        if (_Root() == _Z)
                                _Root() = _X;
                        else if (_Left(_Parent(_Z)) == _Z)
                                _Left(_Parent(_Z)) = _X;
                        else
                                _Right(_Parent(_Z)) = _X;
                        if (_Lmost() != _Z)
                                ;
                        else if (_Right(_Z) == _Nil)
                                _Lmost() = _Parent(_Z);
                        else
                                _Lmost() = _Min(_X);
                        if (_Rmost() != _Z)
                                ;
                        else if (_Left(_Z) == _Nil)
                                _Rmost() = _Parent(_Z);
                        else
                                _Rmost() = _Max(_X); }
                if (_Color(_Y) == _Black)
                        {while (_X != _Root() && _Color(_X) == _Black)
                                if (_X == _Left(_Parent(_X)))
                                        {_Nodeptr _W = _Right(_Parent(_X));
                                        if (_Color(_W) == _Red)
                                                {_Color(_W) = _Black;
                                                _Color(_Parent(_X)) = _Red;
                                                _Lrotate(_Parent(_X));
                                                _W = _Right(_Parent(_X)); }
                                        if (_Color(_Left(_W)) == _Black
                                                && _Color(_Right(_W)) == _Black)
                                                {_Color(_W) = _Red;
                                                _X = _Parent(_X); }
                                        else
                                                {if (_Color(_Right(_W)) == _Black)
                                                        {_Color(_Left(_W)) = _Black;
                                                        _Color(_W) = _Red;
                                                        _Rrotate(_W);
                                                        _W = _Right(_Parent(_X)); }
                                                _Color(_W) = _Color(_Parent(_X));
                                                _Color(_Parent(_X)) = _Black;
                                                _Color(_Right(_W)) = _Black;
                                                _Lrotate(_Parent(_X));
                                                break; }}
                                else
                                        {_Nodeptr _W = _Left(_Parent(_X));
                                        if (_Color(_W) == _Red)
                                                {_Color(_W) = _Black;
                                                _Color(_Parent(_X)) = _Red;
                                                _Rrotate(_Parent(_X));
                                                _W = _Left(_Parent(_X)); }
                                        if (_Color(_Right(_W)) == _Black
                                                && _Color(_Left(_W)) == _Black)
                                                {_Color(_W) = _Red;
                                                _X = _Parent(_X); }
                                        else
                                                {if (_Color(_Left(_W)) == _Black)
                                                        {_Color(_Right(_W)) = _Black;
                                                        _Color(_W) = _Red;
                                                        _Lrotate(_W);
                                                        _W = _Left(_Parent(_X)); }
                                                _Color(_W) = _Color(_Parent(_X));
                                                _Color(_Parent(_X)) = _Black;
                                                _Color(_Left(_W)) = _Black;
                                                _Rrotate(_Parent(_X));
                                                break; }}
                        _Color(_X) = _Black; }
                _Destval(&_Value(_Y));
                _Freenode(_Y);
                --_Size;
                return (_P); }
        iterator erase(iterator _F, iterator _L)
                {if (size() == 0 || _F != begin() || _L != end())
                        {while (_F != _L)
                                erase(_F++);
                        return (_F); }
                else
                        {_Erase(_Root());
                        _Root() = _Nil, _Size = 0;
                        _Lmost() = _Head, _Rmost() = _Head;
                        return (begin()); }}
        size_type erase(const _K& _X)
                {_Pairii _P = equal_range(_X);
                size_type _N = 0;
                _Distance(_P.first, _P.second, _N);
                erase(_P.first, _P.second);
                return (_N); }
        void erase(const _K *_F, const _K *_L)
                {for (; _F != _L; ++_F)
                        erase(*_F); }
        void clear()
                {erase(begin(), end()); }
        iterator find(const _K& _Kv)
                {iterator _P = lower_bound(_Kv);
                return (_P == end()
                        || key_compare(_Kv, _Key(_P._Mynode()))
                                ? end() : _P); }
        const_iterator find(const _K& _Kv) const
                {const_iterator _P = lower_bound(_Kv);
                return (_P == end()
                        || key_compare(_Kv, _Key(_P._Mynode()))
                                ? end() : _P); }
        size_type count(const _K& _Kv) const
                {_Paircc _Ans = equal_range(_Kv);
                size_type _N = 0;
                _Distance(_Ans.first, _Ans.second, _N);
                return (_N); }
        iterator lower_bound(const _K& _Kv)
                {return (iterator(_Lbound(_Kv))); }
        const_iterator lower_bound(const _K& _Kv) const
                {return (const_iterator(_Lbound(_Kv))); }
        iterator upper_bound(const _K& _Kv)
                {return (iterator(_Ubound(_Kv))); }
        const_iterator upper_bound(const _K& _Kv) const
                {return (iterator(_Ubound(_Kv))); }
        _Pairii equal_range(const _K& _Kv)
                {return (_Pairii(lower_bound(_Kv), upper_bound(_Kv))); }
        _Paircc equal_range(const _K& _Kv) const
                {return (_Paircc(lower_bound(_Kv), upper_bound(_Kv))); }
        void swap(_Myt& _X)
                {std::swap(key_compare, _X.key_compare);
                if (allocator == _X.allocator)
                        {std::swap(_Head, _X._Head);
                        std::swap(_Multi, _X._Multi);
                        std::swap(_Size, _X._Size); }
                else
                        {_Myt _Ts = *this; *this = _X, _X = _Ts; }}
        friend void swap(_Myt& _X, _Myt& _Y)
                {_X.swap(_Y); }
protected:
        static _Nodeptr _Nil;
        static size_t _Nilrefs;
        void _Copy(const _Myt& _X)
                {_Root() = _Copy(_X._Root(), _Head);
                _Size = _X.size();
                if (_Root() != _Nil)
                        {_Lmost() = _Min(_Root());
                        _Rmost() = _Max(_Root()); }
                else
                        _Lmost() = _Head, _Rmost() = _Head; }
        _Nodeptr _Copy(_Nodeptr _X, _Nodeptr _P)
                {_Nodeptr _R = _X;
                for (; _X != _Nil; _X = _Left(_X))
                        {_Nodeptr _Y = _Buynode(_P, _Color(_X));
                        if (_R == _X)
                                _R = _Y;
                        _Right(_Y) = _Copy(_Right(_X), _Y);
                        _Consval(&_Value(_Y), _Value(_X));
                        _Left(_P) = _Y;
                        _P = _Y; }
                _Left(_P) = _Nil;
                return (_R); }
        void _Erase(_Nodeptr _X)
                {for (_Nodeptr _Y = _X; _Y != _Nil; _X = _Y)
                        {_Erase(_Right(_Y));
                        _Y = _Left(_Y);
                        _Destval(&_Value(_X));
                        _Freenode(_X); }}
        void _Init()
                {_Nodeptr _Tmp = _Buynode(0, _Black);
                {_Lockit _Lk;
                if (_Nil == 0)
                                {_Nil = _Tmp;
                                _Tmp = 0;
                        _Left(_Nil) = 0, _Right(_Nil) = 0; }
                        ++_Nilrefs; }
                if (_Tmp != 0)
                        _Freenode(_Tmp);
                _Head = _Buynode(_Nil, _Red), _Size = 0;
                _Lmost() = _Head, _Rmost() = _Head; }
        iterator _Insert(_Nodeptr _X, _Nodeptr _Y, const _Ty& _V)
                {_Nodeptr _Z = _Buynode(_Y, _Red);
                _Left(_Z) = _Nil, _Right(_Z) = _Nil;
                _Consval(&_Value(_Z), _V);
                ++_Size;
                if (_Y == _Head || _X != _Nil
                        || key_compare(_Kfn()(_V), _Key(_Y)))
                        {_Left(_Y) = _Z;
                        if (_Y == _Head)
                                {_Root() = _Z;
                                _Rmost() = _Z; }
                        else if (_Y == _Lmost())
                                _Lmost() = _Z; }
                else
                        {_Right(_Y) = _Z;
                        if (_Y == _Rmost())
                                _Rmost() = _Z; }
                for (_X = _Z; _X != _Root()
                        && _Color(_Parent(_X)) == _Red; )
                        if (_Parent(_X) == _Left(_Parent(_Parent(_X))))
                                {_Y = _Right(_Parent(_Parent(_X)));
                                if (_Color(_Y) == _Red)
                                        {_Color(_Parent(_X)) = _Black;
                                        _Color(_Y) = _Black;
                                        _Color(_Parent(_Parent(_X))) = _Red;
                                        _X = _Parent(_Parent(_X)); }
                                else
                                        {if (_X == _Right(_Parent(_X)))
                                                {_X = _Parent(_X);
                                                _Lrotate(_X); }
                                        _Color(_Parent(_X)) = _Black;
                                        _Color(_Parent(_Parent(_X))) = _Red;
                                        _Rrotate(_Parent(_Parent(_X))); }}
                        else
                                {_Y = _Left(_Parent(_Parent(_X)));
                                if (_Color(_Y) == _Red)
                                        {_Color(_Parent(_X)) = _Black;
                                        _Color(_Y) = _Black;
                                        _Color(_Parent(_Parent(_X))) = _Red;
                                        _X = _Parent(_Parent(_X)); }
                                else
                                        {if (_X == _Left(_Parent(_X)))
                                                {_X = _Parent(_X);
                                                _Rrotate(_X); }
                                        _Color(_Parent(_X)) = _Black;
                                        _Color(_Parent(_Parent(_X))) = _Red;
                                        _Lrotate(_Parent(_Parent(_X))); }}
                _Color(_Root()) = _Black;
                return (iterator(_Z)); }
        _Nodeptr _Lbound(const _K& _Kv) const
                {_Nodeptr _X = _Root();
                _Nodeptr _Y = _Head;
                while (_X != _Nil)
                        if (key_compare(_Key(_X), _Kv))
                                _X = _Right(_X);
                        else
                                _Y = _X, _X = _Left(_X);
                return (_Y); }
        _Nodeptr& _Lmost()
                {return (_Left(_Head)); }
        _Nodeptr& _Lmost() const
                {return (_Left(_Head)); }
        void _Lrotate(_Nodeptr _X)
                {_Nodeptr _Y = _Right(_X);
                _Right(_X) = _Left(_Y);
                if (_Left(_Y) != _Nil)
                        _Parent(_Left(_Y)) = _X;
                _Parent(_Y) = _Parent(_X);
                if (_X == _Root())
                        _Root() = _Y;
                else if (_X == _Left(_Parent(_X)))
                        _Left(_Parent(_X)) = _Y;
                else
                        _Right(_Parent(_X)) = _Y;
                _Left(_Y) = _X;
                _Parent(_X) = _Y; }
        static _Nodeptr _Max(_Nodeptr _P)
                {while (_Right(_P) != _Nil)
                        _P = _Right(_P);
                return (_P); }
        static _Nodeptr _Min(_Nodeptr _P)
                {while (_Left(_P) != _Nil)
                        _P = _Left(_P);
                return (_P); }
        _Nodeptr& _Rmost()
                {return (_Right(_Head)); }
        _Nodeptr& _Rmost() const
                {return (_Right(_Head)); }
        _Nodeptr& _Root()
                {return (_Parent(_Head)); }
        _Nodeptr& _Root() const
                {return (_Parent(_Head)); }
        void _Rrotate(_Nodeptr _X)
                {_Nodeptr _Y = _Left(_X);
                _Left(_X) = _Right(_Y);
                if (_Right(_Y) != _Nil)
                        _Parent(_Right(_Y)) = _X;
                _Parent(_Y) = _Parent(_X);
                if (_X == _Root())
                        _Root() = _Y;
                else if (_X == _Right(_Parent(_X)))
                        _Right(_Parent(_X)) = _Y;
                else
                        _Left(_Parent(_X)) = _Y;
                _Right(_Y) = _X;
                _Parent(_X) = _Y; }
        _Nodeptr _Ubound(const _K& _Kv) const
                {_Nodeptr _X = _Root();
                _Nodeptr _Y = _Head;
                while (_X != _Nil)
                        if (key_compare(_Kv, _Key(_X)))
                                _Y = _X, _X = _Left(_X);
                        else
                                _X = _Right(_X);
                return (_Y); }
        _Nodeptr _Buynode(_Nodeptr _Parg, _Redbl _Carg)
                {_Nodeptr _S = (_Nodeptr)allocator._Charalloc(
                        1 * sizeof (_Node));
                _Parent(_S) = _Parg;
                _Color(_S) = _Carg;
                return (_S); }
        void _Consval(_Tptr _P, const _Ty& _V)
                {_Construct(&*_P, _V); }
        void _Destval(_Tptr _P)
                {_Destroy(&*_P); }
        void _Freenode(_Nodeptr _S)
                {allocator.deallocate(_S, 1); }
        _A allocator;
        _Pr key_compare;
        _Nodeptr _Head;
        bool _Multi;
        size_type _Size;
        };
template<class _K, class _Ty, class _Kfn, class _Pr, class _A>
        _Tree<_K, _Ty, _Kfn, _Pr, _A>::_Nodeptr
                _Tree<_K, _Ty, _Kfn, _Pr, _A>::_Nil = 0;
template<class _K, class _Ty, class _Kfn, class _Pr, class _A>
        size_t _Tree<_K, _Ty, _Kfn, _Pr, _A>::_Nilrefs = 0;
                
template<class _K, class _Ty, class _Kfn,
        class _Pr, class _A> inline
        bool operator==(const _Tree<_K, _Ty, _Kfn, _Pr, _A>& _X,
                const _Tree<_K, _Ty, _Kfn, _Pr, _A>& _Y)
        {return (_X.size() == _Y.size()
                && equal(_X.begin(), _X.end(), _Y.begin())); }
template<class _K, class _Ty, class _Kfn,
        class _Pr, class _A> inline
        bool operator!=(const _Tree<_K, _Ty, _Kfn, _Pr, _A>& _X,
                const _Tree<_K, _Ty, _Kfn, _Pr, _A>& _Y)
        {return (!(_X == _Y)); }
template<class _K, class _Ty, class _Kfn,
        class _Pr, class _A> inline
        bool operator<(const _Tree<_K, _Ty, _Kfn, _Pr, _A>& _X,
                const _Tree<_K, _Ty, _Kfn, _Pr, _A>& _Y)
        {return (lexicographical_compare(_X.begin(), _X.end(),
                _Y.begin(), _Y.end())); }
template<class _K, class _Ty, class _Kfn,
        class _Pr, class _A> inline
        bool operator>(const _Tree<_K, _Ty, _Kfn, _Pr, _A>& _X,
                const _Tree<_K, _Ty, _Kfn, _Pr, _A>& _Y)
        {return (_Y < _X); }
template<class _K, class _Ty, class _Kfn,
        class _Pr, class _A> inline
        bool operator<=(const _Tree<_K, _Ty, _Kfn, _Pr, _A>& _X,
                const _Tree<_K, _Ty, _Kfn, _Pr, _A>& _Y)
        {return (!(_Y < _X)); }
template<class _K, class _Ty, class _Kfn,
        class _Pr, class _A> inline
        bool operator>=(const _Tree<_K, _Ty, _Kfn, _Pr, _A>& _X,
                const _Tree<_K, _Ty, _Kfn, _Pr, _A>& _Y)
        {return (!(_X < _Y)); }
};

#pragma pack(pop)
#line 634 "c:\\program files\\microsoft visual studio\\vc98\\include\\xtree"

#line 636 "c:\\program files\\microsoft visual studio\\vc98\\include\\xtree"






















#line 11 "c:\\program files\\microsoft visual studio\\vc98\\include\\set"


#pragma pack(push,8)
#line 15 "c:\\program files\\microsoft visual studio\\vc98\\include\\set"

namespace std {
		
template<class _K, class _Pr = less<_K>,
	class _A = allocator<_K> >
	class set {
public:
	typedef set<_K, _Pr, _A> _Myt;
	typedef _K value_type;
	struct _Kfn : public unary_function<value_type, _K> {
		const _K& operator()(const value_type& _X) const
		{return (_X); }
		};
	typedef _Pr value_compare;
	typedef _K key_type;
	typedef _Pr key_compare;
	typedef _A allocator_type;
	typedef _Tree<_K, value_type, _Kfn, _Pr, _A> _Imp;
	typedef _Imp::size_type size_type;
	typedef _Imp::difference_type difference_type;
	typedef _Imp::reference reference;
	typedef _Imp::const_reference const_reference;
	typedef _Imp::iterator iterator;
	typedef _Imp::const_iterator const_iterator;
	typedef _Imp::reverse_iterator reverse_iterator;
	typedef _Imp::const_reverse_iterator const_reverse_iterator;
	typedef pair<iterator, bool> _Pairib;
	typedef pair<iterator, iterator> _Pairii;
	typedef pair<const_iterator, const_iterator> _Paircc;
	explicit set(const _Pr& _Pred = _Pr(), const _A& _Al = _A())
		: _Tr(_Pred, false, _Al) {}
	typedef const value_type *_It;
	set(_It _F, _It _L, const _Pr& _Pred = _Pr(),
		const _A& _Al = _A())
		: _Tr(_Pred, false, _Al)
		{for (; _F != _L; ++_F)
			_Tr.insert(*_F); }
	_Myt& operator=(const _Myt& _X)
		{_Tr = _X._Tr;
		return (*this); }
	iterator begin()
		{return (_Tr.begin()); }
	const_iterator begin() const
		{return (_Tr.begin()); }
	iterator end()
		{return (_Tr.end()); }
	const_iterator end() const
		{return (_Tr.end()); }
	reverse_iterator rbegin()
		{return (_Tr.rbegin()); }
	const_reverse_iterator rbegin() const
		{return (_Tr.rbegin()); }
	reverse_iterator rend()
		{return (_Tr.rend()); }
	const_reverse_iterator rend() const
		{return (_Tr.rend()); }
	size_type size() const
		{return (_Tr.size()); }
	size_type max_size() const
		{return (_Tr.max_size()); }
	bool empty() const
		{return (_Tr.empty()); }
	_A get_allocator() const
		{return (_Tr.get_allocator()); }
	_Pairib insert(const value_type& _X)
		{_Imp::_Pairib _Ans = _Tr.insert(_X);
		return (_Pairib(_Ans.first, _Ans.second)); }
	iterator insert(iterator _P, const value_type& _X)
		{return (_Tr.insert((_Imp::iterator&)_P, _X)); }
	void insert(_It _F, _It _L)
		{for (; _F != _L; ++_F)
			_Tr.insert(*_F); }
	iterator erase(iterator _P)
		{return (_Tr.erase((_Imp::iterator&)_P)); }
	iterator erase(iterator _F, iterator _L)
		{return (_Tr.erase((_Imp::iterator&)_F,
			(_Imp::iterator&)_L)); }
	size_type erase(const _K& _Kv)
		{return (_Tr.erase(_Kv)); }
	void clear()
		{_Tr.clear(); }
	void swap(_Myt& _X)
		{std::swap(_Tr, _X._Tr); }
	friend void swap(_Myt& _X, _Myt& _Y)
		{_X.swap(_Y); }
	key_compare key_comp() const
		{return (_Tr.key_comp()); }
	value_compare value_comp() const
		{return (_Tr.key_comp()); }
	const_iterator find(const _K& _Kv) const
		{return (_Tr.find(_Kv)); }
	iterator find(const _K& _Kv)
		{return (_Tr.find(_Kv)); }
	size_type count(const _K& _Kv) const
		{return (_Tr.count(_Kv)); }
	iterator lower_bound(const _K& _Kv)
		{return (_Tr.lower_bound(_Kv)); }
	const_iterator lower_bound(const _K& _Kv) const
		{return (_Tr.lower_bound(_Kv)); }
	iterator upper_bound(const _K& _Kv)
		{return (_Tr.upper_bound(_Kv)); }
	const_iterator upper_bound(const _K& _Kv) const
		{return (_Tr.upper_bound(_Kv)); }
	_Pairii equal_range(const _K& _Kv)
		{return (_Tr.equal_range(_Kv)); }
	_Paircc equal_range(const _K& _Kv) const
		{return (_Tr.equal_range(_Kv)); }
protected:
	_Imp _Tr;
	};
		
template<class _K, class _Pr, class _A> inline
	bool operator==(const set<_K, _Pr, _A>& _X,
		const set<_K, _Pr, _A>& _Y)
	{return (_X.size() == _Y.size()
		&& equal(_X.begin(), _X.end(), _Y.begin())); }
template<class _K, class _Pr, class _A> inline
	bool operator!=(const set<_K, _Pr, _A>& _X,
		const set<_K, _Pr, _A>& _Y)
	{return (!(_X == _Y)); }
template<class _K, class _Pr, class _A> inline
	bool operator<(const set<_K, _Pr, _A>& _X,
		const set<_K, _Pr, _A>& _Y)
	{return (lexicographical_compare(_X.begin(), _X.end(),
		_Y.begin(), _Y.end())); }
template<class _K, class _Pr, class _A> inline
	bool operator>(const set<_K, _Pr, _A>& _X,
		const set<_K, _Pr, _A>& _Y)
	{return (_Y < _X); }
template<class _K, class _Pr, class _A> inline
	bool operator<=(const set<_K, _Pr, _A>& _X,
		const set<_K, _Pr, _A>& _Y)
	{return (!(_Y < _X)); }
template<class _K, class _Pr, class _A> inline
	bool operator>=(const set<_K, _Pr, _A>& _X,
		const set<_K, _Pr, _A>& _Y)
	{return (!(_X < _Y)); }
		
template<class _K, class _Pr = less<_K>,
	class _A = allocator<_K> >
	class multiset {
public:
	typedef multiset<_K, _Pr, _A> _Myt;
	typedef _K value_type;
	struct _Kfn : public unary_function<value_type, _K> {
		const _K& operator()(const value_type& _X) const
		{return (_X); }
		};
	typedef _Pr value_compare;
	typedef _K key_type;
	typedef _Pr key_compare;
	typedef _A allocator_type;
	typedef _Tree<_K, value_type, _Kfn, _Pr, _A> _Imp;
	typedef _Imp::size_type size_type;
	typedef _Imp::difference_type difference_type;
	typedef _Imp::reference reference;
	typedef _Imp::const_reference const_reference;
	typedef _Imp::iterator iterator;
	typedef _Imp::const_iterator const_iterator;
	typedef _Imp::reverse_iterator reverse_iterator;
	typedef _Imp::const_reverse_iterator const_reverse_iterator;
	typedef pair<iterator, iterator> _Pairii;
	typedef pair<const_iterator, const_iterator> _Paircc;
	explicit multiset(const _Pr& _Pred = _Pr(),
		const _A& _Al = _A())
		: _Tr(_Pred, true, _Al) {}
	typedef const value_type *_It;
	multiset(_It _F, _It _L, const _Pr& _Pred = _Pr(),
			const _A& _Al = _A())
		: _Tr(_Pred, true, _Al)
		{for (; _F != _L; ++_F)
			_Tr.insert(*_F); }
	_Myt& operator=(const _Myt& _X)
		{_Tr = _X._Tr;
		return (*this); }
	iterator begin()
		{return (_Tr.begin()); }
	const_iterator begin() const
		{return (_Tr.begin()); }
	iterator end()
		{return (_Tr.end()); }
	const_iterator end() const
		{return (_Tr.end()); }
	reverse_iterator rbegin()
		{return (_Tr.rbegin()); }
	const_reverse_iterator rbegin() const
		{return (_Tr.rbegin()); }
	reverse_iterator rend()
		{return (_Tr.rend()); }
	const_reverse_iterator rend() const
		{return (_Tr.rend()); }
	size_type size() const
		{return (_Tr.size()); }
	size_type max_size() const
		{return (_Tr.max_size()); }
	bool empty() const
		{return (_Tr.empty()); }
	_A get_allocator() const
		{return (_Tr.get_allocator()); }
	iterator insert(const value_type& _X)
		{return (_Tr.insert(_X).first); }
	iterator insert(iterator _P, const value_type& _X)
		{return (_Tr.insert((_Imp::iterator&)_P, _X)); }
	void insert(_It _F, _It _L)
		{for (; _F != _L; ++_F)
			_Tr.insert(*_F); }
	iterator erase(iterator _P)
		{return (_Tr.erase((_Imp::iterator&)_P)); }
	iterator erase(iterator _F, iterator _L)
		{return (_Tr.erase((_Imp::iterator&)_F,
			(_Imp::iterator&)_L)); }
	size_type erase(const _K& _Kv)
		{return (_Tr.erase(_Kv)); }
	void clear()
		{_Tr.clear(); }
	void swap(_Myt& _X)
		{std::swap(_Tr, _X._Tr); }
	friend void swap(_Myt& _X, _Myt& _Y)
		{_X.swap(_Y); }
	key_compare key_comp() const
		{return (_Tr.key_comp()); }
	value_compare value_comp() const
		{return (_Tr.key_comp()); }
	iterator find(const _K& _Kv)
		{return (_Tr.find(_Kv)); }
	const_iterator find(const _K& _Kv) const
		{return (_Tr.find(_Kv)); }
	size_type count(const _K& _Kv) const
		{return (_Tr.count(_Kv)); }
	iterator lower_bound(const _K& _Kv)
		{return (_Tr.lower_bound(_Kv)); }
	const_iterator lower_bound(const _K& _Kv) const
		{return (_Tr.lower_bound(_Kv)); }
	iterator upper_bound(const _K& _Kv)
		{return (_Tr.upper_bound(_Kv)); }
	const_iterator upper_bound(const _K& _Kv) const
		{return (_Tr.upper_bound(_Kv)); }
	_Pairii equal_range(const _K& _Kv)
		{return (_Tr.equal_range(_Kv)); }
	_Paircc equal_range(const _K& _Kv) const
		{return (_Tr.equal_range(_Kv)); }
protected:
	_Imp _Tr;
	};
		
template<class _K, class _Pr, class _A> inline
	bool operator==(const multiset<_K, _Pr, _A>& _X,
		const multiset<_K, _Pr, _A>& _Y)
	{return (_X.size() == _Y.size()
		&& equal(_X.begin(), _X.end(), _Y.begin())); }
template<class _K, class _Pr, class _A> inline
	bool operator!=(const multiset<_K, _Pr, _A>& _X,
		const multiset<_K, _Pr, _A>& _Y)
	{return (!(_X == _Y)); }
template<class _K, class _Pr, class _A> inline
	bool operator<(const multiset<_K, _Pr, _A>& _X,
		const multiset<_K, _Pr, _A>& _Y)
	{return (lexicographical_compare(_X.begin(), _X.end(),
		_Y.begin(), _Y.end())); }
template<class _K, class _Pr, class _A> inline
	bool operator>(const multiset<_K, _Pr, _A>& _X,
		const multiset<_K, _Pr, _A>& _Y)
	{return (_Y < _X); }
template<class _K, class _Pr, class _A> inline
	bool operator<=(const multiset<_K, _Pr, _A>& _X,
		const multiset<_K, _Pr, _A>& _Y)
	{return (!(_Y < _X)); }
template<class _K, class _Pr, class _A> inline
	bool operator>=(const multiset<_K, _Pr, _A>& _X,
		const multiset<_K, _Pr, _A>& _Y)
	{return (!(_X < _Y)); }
};

#pragma pack(pop)
#line 290 "c:\\program files\\microsoft visual studio\\vc98\\include\\set"

#line 292 "c:\\program files\\microsoft visual studio\\vc98\\include\\set"






















#line 10 "d:\\hassan\\devs\\solarsystem\\trunk\\engine\\xml\\xml.h"


typedef std::string String;

































class XmlAttribute {
public:
	String key;
	String value;
	
	XmlAttribute() {}
	XmlAttribute( const XmlAttribute &attr ) { *this = attr; }
	XmlAttribute& operator=( const XmlAttribute &attr ) {
		key = attr.key;
		value = attr.value;
		return *this;
	}
	bool operator<( const XmlAttribute &attr ) const {
		return _stricmp( key.c_str(),attr.key.c_str() ) < 0;
	}
	bool operator==( const XmlAttribute &attr ) const {
		return _stricmp( key.c_str(),attr.key.c_str() ) == 0;
	}
	bool operator!=( const XmlAttribute &attr ) const {
		return !(*this == attr);
	}
};


class XmlNode;


typedef std::set<XmlAttribute>	XmlAttributes;






class XmlNodeRef {
private:
  XmlNode* p;
public:
  XmlNodeRef() : p(0) {}
	XmlNodeRef( int Null ) : p(0) {}
  XmlNodeRef( XmlNode* p_ );
  XmlNodeRef( const XmlNodeRef &p_ );
	explicit XmlNodeRef( const String &tag );
  ~XmlNodeRef();
	
  operator XmlNode*() const { return p; }
  operator const XmlNode*() const { return p; }
  XmlNode& operator*() const { return *p; }
  XmlNode* operator->(void) const { return p; }
  
  XmlNodeRef&  operator=( XmlNode* newp );
	XmlNodeRef&  operator=( const XmlNodeRef &newp );
	
  operator bool() const { return p != 0; };
	bool operator !() const { return p == 0; };
	
 	
  bool  operator == ( const XmlNode* p2 ) const { return p == p2; };
  bool  operator != ( const XmlNode* p2 ) const { return p != p2; };
  bool  operator <  ( const XmlNode* p2 ) const { return p < p2; };
  bool  operator >  ( const XmlNode* p2 ) const { return p > p2; };
	
	friend bool operator == ( const XmlNodeRef &p1,int null );
  friend bool operator != ( const XmlNodeRef &p1,int null );
	friend bool operator == ( int null,const XmlNodeRef &p1 );
  friend bool operator != ( int null,const XmlNodeRef &p1 );
};




class XmlParser
{
public:
	
	XmlNodeRef parse( const String& fileName );
	
	
	XmlNodeRef parse( const std::vector<char> &buffer );

	String getErrorString() const { return m_errorString; }
private:
	String m_errorString;
};








class XmlNode {
public:
	
	~XmlNode();

	
	const String& getTag() const { return m_tag; };

	
	bool isTag( const String &tag ) const;

	
	const XmlAttributes&	getAttributes() const { return m_attributes; };
	
	String getAttribute( const String &key ) const;
	
	bool haveAttribute( const String &key ) const;

	
	void setAttribute( const String &key,const String &value );
	
	
	void addChild( const XmlNodeRef &node );

	
	int	getChildCount() const { return m_childs.size(); };
	
	
	XmlNodeRef getChild( unsigned int i ) const;

	
	XmlNodeRef findChild( const String &tag ) const;

	
	XmlNodeRef	getParent() const { return m_parent; }

	
	const String& getContent() const { return m_content; };

	
	int getLine() const { return m_line; };
	
	void setLine( int line ) { m_line = line; };

	
	String getXML() const;

	
	void getValue( String &value ) const;
	void getValue( int &value ) const;
	void getValue( float &value ) const;
	void getValue( bool &value ) const { int v; getValue(v); value = (v != 0); }

	
	void setValue( const String &value );
	void setValue( int value );
	void setValue( float value );

	
	bool getSubNodeValue( const String &tag,String &value ) const;
	bool getSubNodeValue( const String &tag,int &value ) const;
	bool getSubNodeValue( const String &tag,float &value ) const;

	
	void setSubNodeValue( const String &tag,const String &value );
	void setSubNodeValue( const String &tag,int value );
	void setSubNodeValue( const String &tag,float value );

private:
	
	XmlNode( const String &tag ) {
		m_tag = tag;
		m_parent = 0;
		m_refCount = 0;
	}

	
	void addRef() { m_refCount++; };
	
	void release() { if (--m_refCount <= 0) delete this; };

	
	int m_refCount;

	
	int m_line;
	
	String m_tag;

	
	String m_content;
	
	XmlNode *m_parent;
	
	
	typedef std::vector<XmlNodeRef>	XmlNodes;
	XmlNodes m_childs;
	
	XmlAttributes m_attributes;

	
	friend class XmlNodeRef;
};




inline XmlNodeRef::XmlNodeRef( const String &tag )
{
	p = new("d:\\hassan\\devs\\solarsystem\\trunk\\engine\\xml\\xml.h", 247) XmlNode( tag );
	p->addRef();
}

inline XmlNodeRef::XmlNodeRef( XmlNode* p_ ) : p(p_)
{
	if (p) p->addRef();
}

inline XmlNodeRef::XmlNodeRef( const XmlNodeRef &p_ ) : p(p_.p)
{
	if (p) p->addRef();
}

inline XmlNodeRef::~XmlNodeRef()
{
	if (p) p->release();
}

inline XmlNodeRef&  XmlNodeRef::operator=( XmlNode* newp )
{
	if (newp) newp->addRef();
	if (p) p->release();
	p = newp;
	return *this;
}

inline XmlNodeRef&  XmlNodeRef::operator=( const XmlNodeRef &newp )
{
	if (newp.p) newp.p->addRef();
	if (p) p->release();
	p = newp.p;
	return *this;
}

inline bool operator == ( const XmlNodeRef &p1,int null )	{
	return p1.p == 0;
}

inline bool operator != ( const XmlNodeRef &p1,int null )	{
	return p1.p != 0;
}

inline bool operator == ( int null,const XmlNodeRef &p1 )	{
	return p1.p == 0;
}

inline bool operator != ( int null,const XmlNodeRef &p1 )	{
	return p1.p != 0;
}

#line 299 "d:\\hassan\\devs\\solarsystem\\trunk\\engine\\xml\\xml.h"
#line 14 "d:\\hassan\\devs\\solarsystem\\trunk\\engine\\xml\\xml.cpp"