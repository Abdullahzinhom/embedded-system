

#ifndef Platform_Type.h
#define Platform_Type.h

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define CPU_TYPE                CPU_TYPE_32
#define CPU_BIT_ORDER           LSB_FSRT
#define CPU_BYTE_ORDER          LOW_BYTE_FISRT



#ifndef TRUE
#define TRUE 1
#endif // TRUE

#ifndef FALSE
#define FALSE 0
#endif // FALSE

typedef unsigned char                   boolean;
typedef char                            char_t;
typedef float                           float32;
typedef double                          double64;


typedef unsigned char                   unit8;
typedef signed char                     snit8;
typedef unsigned short                  unit16;
typedef signed short                    snit16;
typedef unsigned int                    unit32;
typedef signed int                      snit32;
typedef unsigned long long              unit64;
typedef signed long long                snit64;


typedef volatile unsigned char          vunit8_t;
typedef volatile signed char            vsnit8_t;

typedef volatile unsigned short         vunit16_t;
typedef volatile signed short           vsnit16_t;

typedef volatile unsigned int           vunit32_t;
typedef volatile signed int             vsnit32_t;

typedef volatile unsigned long long     vunit64_t;
typedef volatile  signed long long      vsnit64_t;






#endif // PLATEFROM_TYPE

