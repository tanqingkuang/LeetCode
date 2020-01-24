
#define uint8  unsigned char
#define int8   signed char
#define uint16 unsigned short
#define int16  signed short
#define uint32 unsigned int
#define int32  signed int
#define ulong  unsigned long
#define uint64 unsigned long long
#define int64  signed long

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(_X_) (sizeof((_X_)) / sizeof((_X_)[0]))
#endif

#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

