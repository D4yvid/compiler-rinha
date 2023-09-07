#ifndef TYPES_H
#define TYPES_H

typedef char i8;
typedef short i16;
typedef int i32;
typedef long i64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;

typedef float f32;
typedef double f64;

#define UNUSED(...) (void) __VA_ARGS__;
#define MAX(a, b) ((a) > (b)) ? (a) : (b)
#define MIN(a, b) ((a) < (b)) ? (a) : (b)

#endif /** TYPES_H */
