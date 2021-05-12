/* 
 *
 * CS:APP Data Lab 
 * 
 * <Jerry Perez // Username: jperez2>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) 
{
  return (~x & ~y);
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) 
{
  int allbits;
  int oddbits = (0xAA << 8) | 0xAA;
  oddbits = oddbits | (oddbits << 16);
  allbits = oddbits | x;
  allbits = ~allbits;
  return !allbits;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) 
{

 int j = 0xFF;
 int shiftN = n << 3; 
 int shiftM = m << 3;
 int nbyte = (j << shiftN)& x;
 int mbyte = (j << shiftM)& x;
 int combine = (j << shiftN) | (j << shiftM);
 nbyte = (nbyte >> shiftN)& j;
 mbyte = (mbyte >> shiftM)& j;
 nbyte = nbyte << shiftM;
 mbyte = mbyte << shiftN;
 combine = ~combine & x;   
 return combine | nbyte | mbyte;

}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) 
{

 int sign = 1 << 31;
 int lower = ~0x30;
 int upper = ~(sign | 0x39);
 lower = sign & (lower + 1 + x) >> 31;
 upper = sign & (upper + x) >> 31; 
 return !(upper | lower);

}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) 
{
  return (x >> n) ^ (((x & (1 << 31)) >> n) << 1);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) 
{

 int movebit, contain1, other;
 int isit0 = !x;
 int isitneg1 = ! (x + 1);
 int notzero = !!x<<31>>31;
 x = (x>>31) ^ x;
 contain1 = !!(x & ((1 << 31) >> 15));
 movebit = contain1 << 4;
 x = x >> movebit;
 other = movebit;
 contain1 = !! (x & ((0xFF) << 8));
 movebit = contain1 << 3;
 x = x >> movebit;
 other = other + movebit;
 contain1 = !!(x & 0xF0);
 movebit = contain1 << 2;
 x = x >> movebit;
 other = other + movebit;
 contain1 = !!(x & 0xC);
 movebit = contain1 << 1;
 x = x >> movebit;
 other = other + movebit;
 contain1 = !!(x & 0x2);
 other = other + contain1;
 return isit0 | isitneg1 | (notzero & (!isitneg1 << 31 >> 31) & (other + 2));

}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) 
{
 return ((x >> 31) | (!!x));
}
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) 
{
  return !(x ^ y);
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) 
{

  int var1 = x << (32 + (~n + 1));
  int var2 = ~(1 << 31);
  var2 = var2 >> (n+((~1)+1));
  x = x >> n;
  x = x & var2;
  return x | var1;

}
/* 
 * rempwr2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int rempwr2(int x, int n) 
{
 int thismask = x >> 31;
 int thispower = (1 << n) + ~0;
 int answer = x & thispower;
 return (x & thispower) + (((~((!!answer) << n)) + 1) & thismask);
}
/*
 * leftBitCount - returns count of number of consective 1's in
 *     left-hand (most significant) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
int leftBitCount(int x) 
{
 int j = x; 
 int shift;
 int store;
 int all = !(~x);
 store = !(~(j>>16)) << 4;
 j <<= store;
 shift = !(~(j >> 24)) << 3;
 j <<= shift;
 store |= shift;
 shift = !(~(j>>28)) << 2;
 j <<= shift;
 store |= shift;
 shift = !(~(j >> 30)) << 1;
 j <<= shift;
 store |= shift;
 store ^= 1 &((j>>31));
 return store + all;
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) 
{
 int sum1, sum2, mask, maximum;
 sum1 = x+y;
 mask = ((sum1^x) & (sum1^y))>>31; 
 sum2 = sum1 & ~mask;		   
 maximum = mask & ((1<<31) + (sum1>>31)); 
 return sum2 | maximum;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) 
{
 if (((uf<<1) >>24) == 0xFF)
{
  if ((uf << 9))
   return uf;
}
  return uf ^ 0x80000000;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) 
{
 int exponent = uf & 0x7F800000;
 int sign = uf & 0x80000000;
 int fraction = uf & 0x007FFFFF; 
 if (exponent == 0x7F800000) 
  return uf; 
   if ((!exponent) || (exponent == 0x00800000)) 
{
    fraction = fraction | exponent;
    fraction = (uf & 0x00FFFFFF) >> 1;
    fraction += ((uf & 3) >> 1) & (uf & 1);
    return sign | fraction;
}
 return sign | ((exponent - 1) & 0x7F800000) | fraction;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) 
{
 unsigned sign = x >> 31 & 0x1;
 unsigned exp = 158;
 unsigned frac = -x; 
 unsigned j, forfirst, forrest, other;
 if (!x) 
{
 return 0;
}
  if (!sign) 
  {
   frac = -frac;
  }
   if (x == (1 << 31))
  {
    return 0xCF << 24;
  }
 while (!(frac & (1 << 31))) 
{ 
 frac = frac << 1;
 exp = exp - 1;
}
 j = (frac >> 8) & 0x1;
 forfirst = (frac >> 7) & 0x1;
 forrest = frac & 0x7f;
 exp = exp << 23;
 frac = (frac << 1) >> 9;
 other = exp | frac;
 if ((j && forfirst) || (forrest && forfirst)) 
{
 other = other + 1;
}
 return other | (sign << 31);
}
