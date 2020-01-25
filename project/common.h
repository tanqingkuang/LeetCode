#include "stdio.h"
#include "string.h"
#include "math.h"
#include "time.h"
#include "malloc.h"
#include "windows.h"
#include <conio.h>

#ifndef _COMMON_H_
#define _COMMON_H_

#define uint8  unsigned char
#define int8   signed char
#define uint16 unsigned short
#define int16  signed short
#define uint32 unsigned int
#define int32  signed int
#define ulong  unsigned long
#define uint64 unsigned long long
#define int64  signed long

#ifndef bool
#define bool uint32
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(_X_) (sizeof((_X_)) / sizeof((_X_)[0]))
#endif

#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

void set_console_color(unsigned short color_index);

#endif
