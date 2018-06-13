#ifndef __MYTYPES_H_
#define __MYTYPES_H_

typedef unsigned char   uchar;
typedef unsigned int    uint;

typedef unsigned char           tU8;
typedef unsigned short          tU16;
typedef unsigned int            tU32;

typedef signed char             tS8;
typedef short                   tS16;
typedef int                     tS32;

#ifndef NULL
#define NULL             0
#endif

#ifndef TRUE
#define TRUE        0
#endif
#ifndef true
#define true        0
#endif
#ifndef FALSE
#define FALSE       -1
#endif
#ifndef false
#define false       -1
#endif


#define DEBUG

#ifdef	DEBUG
#include <stdio.h>
#define	PRINTF(format, args...)		fprintf(stdout, format, ##args)
#else
#define	PRINTF(format, args...)	
#endif


#endif 