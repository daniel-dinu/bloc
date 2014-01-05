/* config.h
	Configuration file for the MSP430 crypto library
	
	(Heavily) copied and adapted from the ESTREAM project :
	http://www.ecrypt.eu.org/stream/
		
	Big thanks to them for this!
	
*/

#ifndef CRYPTOLIB_CONFIG
#define CRYPTOLIB_CONFIG

/* ------------------------------------------------------------------------- */

/* Guess the endianness of the target architecture. */

/* 
 * The LITTLE endian machines:
 */
#if defined(__ultrix)           /* Older MIPS */
#define CRYPTOLIB_LITTLE_ENDIAN
#elif defined(__alpha)          /* Alpha */
#define CRYPTOLIB_LITTLE_ENDIAN
#elif defined(i386)             /* x86 (gcc) */
#define CRYPTOLIB_LITTLE_ENDIAN
#elif defined(__i386)           /* x86 (gcc) */
#define CRYPTOLIB_LITTLE_ENDIAN
#elif defined(__x86_64)         /* x86_64 (gcc) */
#define CRYPTOLIB_LITTLE_ENDIAN
#elif defined(_M_IX86)          /* x86 (MSC, Borland) */
#define CRYPTOLIB_LITTLE_ENDIAN
#elif defined(_MSC_VER)         /* x86 (surely MSC) */
#define CRYPTOLIB_LITTLE_ENDIAN
#elif defined(__INTEL_COMPILER) /* x86 (surely Intel compiler icl.exe) */
#define CRYPTOLIB_LITTLE_ENDIAN
#elif defined(MSP430)			/* TI MSP430 processor (gcc) */
#define CRYPTOLIB_LITTLE_ENDIAN
#elif defined(__MSP430)			/* TI MSP430 processor */
#define CRYPTOLIB_LITTLE_ENDIAN


/* 
 * The BIG endian machines: 
 */
#elif defined(__sparc)          /* Newer Sparc's */
#define CRYPTOLIB_BIG_ENDIAN
#elif defined(__powerpc__)      /* PowerPC */
#define CRYPTOLIB_BIG_ENDIAN
#elif defined(__ppc__)          /* PowerPC */
#define CRYPTOLIB_BIG_ENDIAN
#elif defined(__hppa)           /* HP-PA */
#define CRYPTOLIB_BIG_ENDIAN
#elif defined(__arm__)			/* arm (gcc) */
#define CRYPTOLIB_BIG_ENDIAN

/* 
 * Finally machines with UNKNOWN endianness:
 */
#elif defined (_AIX)            /* RS6000 */
#define CRYPTOLIB_UNKNOWN
#elif defined(__aux)            /* 68K */
#define CRYPTOLIB_UNKNOWN
#elif defined(__dgux)           /* 88K (but P6 in latest boxes) */
#define CRYPTOLIB_UNKNOWN
#elif defined(__sgi)            /* Newer MIPS */
#define CRYPTOLIB_UNKNOWN
#else	                        /* Any other processor */
#define CRYPTOLIB_UNKNOWN
#endif

/* ------------------------------------------------------------------------- */

/*
 * Find minimal-width types to store 8-bit, 16-bit, 32-bit, and 64-bit
 * integers.
 *
 * Note: to enable 64-bit types on 32-bit compilers, it might be
 * necessary to switch from ISO C90 mode to ISO C99 mode (e.g., gcc
 * -std=c99), or to allow compiler-specific extensions.
 */

#include <limits.h>

/* --- check char --- */

#if (UCHAR_MAX / 0xFU > 0xFU)
#ifndef I8T
#define I8T char
#define U8C(v) (v##U)

#if (UCHAR_MAX == 0xFFU)
#define CRYPTOLIB_I8T_IS_BYTE
#endif

#endif

#if (UCHAR_MAX / 0xFFU > 0xFFU)
#ifndef I16T
#define I16T char
#define U16C(v) (v##U)
#endif

#if (UCHAR_MAX / 0xFFFFU > 0xFFFFU)
#ifndef I32T
#define I32T char
#define U32C(v) (v##U)
#endif

#if (UCHAR_MAX / 0xFFFFFFFFU > 0xFFFFFFFFU)
#ifndef I64T
#define I64T char
#define U64C(v) (v##U)
#define CRYPTOLIB_NATIVE64
#endif

#endif
#endif
#endif
#endif

/* --- check short --- */

#if (USHRT_MAX / 0xFU > 0xFU)
#ifndef I8T
#define I8T short
#define U8C(v) (v##U)

#if (USHRT_MAX == 0xFFU)
#define CRYPTOLIB_I8T_IS_BYTE
#endif

#endif

#if (USHRT_MAX / 0xFFU > 0xFFU)
#ifndef I16T
#define I16T short
#define U16C(v) (v##U)
#endif

#if (USHRT_MAX / 0xFFFFU > 0xFFFFU)
#ifndef I32T
#define I32T short
#define U32C(v) (v##U)
#endif

#if (USHRT_MAX / 0xFFFFFFFFU > 0xFFFFFFFFU)
#ifndef I64T
#define I64T short
#define U64C(v) (v##U)
#define CRYPTOLIB_NATIVE64
#endif

#endif
#endif
#endif
#endif

/* --- check int --- */

#if (UINT_MAX / 0xFU > 0xFU)
#ifndef I8T
#define I8T int
#define U8C(v) (v##U)

#if (ULONG_MAX == 0xFFU)
#define CRYPTOLIB_I8T_IS_BYTE
#endif

#endif

#if (UINT_MAX / 0xFFU > 0xFFU)
#ifndef I16T
#define I16T int
#define U16C(v) (v##U)
#endif

#if (UINT_MAX / 0xFFFFU > 0xFFFFU)
#ifndef I32T
#define I32T int
#define U32C(v) (v##U)
#endif

#if (UINT_MAX / 0xFFFFFFFFU > 0xFFFFFFFFU)
#ifndef I64T
#define I64T int
#define U64C(v) (v##U)
#define CRYPTOLIB_NATIVE64
#endif

#endif
#endif
#endif
#endif

/* --- check long --- */

#if (ULONG_MAX / 0xFUL > 0xFUL)
#ifndef I8T
#define I8T long
#define U8C(v) (v##UL)

#if (ULONG_MAX == 0xFFUL)
#define CRYPTOLIB_I8T_IS_BYTE
#endif

#endif

#if (ULONG_MAX / 0xFFUL > 0xFFUL)
#ifndef I16T
#define I16T long
#define U16C(v) (v##UL)
#endif

#if (ULONG_MAX / 0xFFFFUL > 0xFFFFUL)
#ifndef I32T
#define I32T long
#define U32C(v) (v##UL)
#endif

#if (ULONG_MAX / 0xFFFFFFFFUL > 0xFFFFFFFFUL)
#ifndef I64T
#define I64T long
#define U64C(v) (v##UL)
#define CRYPTOLIB_NATIVE64
#endif

#endif
#endif
#endif
#endif

/* --- check long long --- */

#ifdef ULLONG_MAX

#if (ULLONG_MAX / 0xFULL > 0xFULL)
#ifndef I8T
#define I8T long long
#define U8C(v) (v##ULL)

#if (ULLONG_MAX == 0xFFULL)
#define CRYPTOLIB_I8T_IS_BYTE
#endif

#endif

#if (ULLONG_MAX / 0xFFULL > 0xFFULL)
#ifndef I16T
#define I16T long long
#define U16C(v) (v##ULL)
#endif

#if (ULLONG_MAX / 0xFFFFULL > 0xFFFFULL)
#ifndef I32T
#define I32T long long
#define U32C(v) (v##ULL)
#endif

#if (ULLONG_MAX / 0xFFFFFFFFULL > 0xFFFFFFFFULL)
#ifndef I64T
#define I64T long long
#define U64C(v) (v##ULL)
#endif

#endif
#endif
#endif
#endif

#endif

/* --- check __int64 --- */

#if !defined(__STDC__) && defined(_UI64_MAX)

#ifndef I64T
#define I64T __int64
#define U64C(v) (v##ui64)
#endif

#endif

/* ------------------------------------------------------------------------- */

/* find the largest type on this platform (used for alignment) */

#if defined(__SSE__) || (defined(_MSC_VER) && (_MSC_VER >= 1300))

#include <xmmintrin.h>
#define MAXT __m128

#elif defined(__MMX__)

#include <mmintrin.h>
#define MAXT __m64

#elif defined(__ALTIVEC__)

#define MAXT __vector int

#else

#define MAXT long

#endif

/* ------------------------------------------------------------------------- */

#endif
