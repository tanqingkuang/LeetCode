#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
#define int64  signed long long

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

#define memset_s(src, len, dest, cnt) memset(src, dest, cnt)
#define memcpy_s(src, len, dest, cnt) memcpy(src, dest, cnt)
#define memcmp_s(src, len, dest, cnt) memcmp(src, dest, cnt)

void display_result(bool rst, char *func);

#define TEST_EQ(a, b) display_result(a==b, __FUNCTION__)
#define TEST_NE(a, b) display_result(a!=b, __FUNCTION__)

#endif
