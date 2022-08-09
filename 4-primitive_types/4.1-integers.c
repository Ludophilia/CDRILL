// INTEGERS TYPES (p8, GNU C Reference Manual)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf
// https://www.tutorialspoint.com/cprogramming/c_data_types.htm# 

#include <stdio.h>
#include <limits.h>

/* The integer data types range in size from at least 8 bits to at least 
32 bits { int (32bits), unsigned char (8bits), signed char (8bits), 
short (16bits), unsigned short (16bits)}. The C99 standard extends this range 
to include integer sizes of at least 64 bits { long (64bits), 
unsigned long (64bits)}. You should use INTEGER TYPES for storing WHOLE 
NUMBER values and the CHAR data TYPE for storing CHARACTERS). */

/* Note - The range of an unsigned bit field of N bits is from 0 to 2N−1, 
and the range of a signed bit field of N bits is from −2N/2 to (2N/2)−1 */

void	char_integers8(void)
{
    char	a_char = -126; /* By convention, you should use the char data type 
	specifically for storing ASCII characters (such as ‘m’), including escape 
	sequences (such as ‘\n’). */
    signed char    signed_char = -33;
    unsigned char	 unsigned_char = 255;

    printf("CHAR - EX: %i, MIN: %i, MAX: %i\n", a_char, 
	CHAR_MIN, CHAR_MAX, CHAR_BIT); /* Depending on your system, the char data 
	type is defined as having the same range as either the signed char or the
	unsigned char data type (they are three distinct types, however). */
    printf("SIGNED CHAR - EX: %i, MIN: %i, MAX: %i\n", signed_char, 
	SCHAR_MIN, SCHAR_MAX); /* The 8-bit signed char data type can hold integer 
	values in the range of −128 to 127. */
    printf("UNSIGNED CHAR - EX: %i, MIN: %i, MAX: %i\n\n", unsigned_char,
	0, UCHAR_MAX); /* The 8-bit unsigned char data type can hold integer values
	 in the range of 0 to 255. */
}

void	short_integers16(void)
{
    short int	 short_int = -31000;
    unsigned short int	  ushort_int = 26086;
    short	 short_int2 = -31001;
    unsigned short	  ushort_int2 = 26087;

    printf("SHORT INT - EX: %i, MIN: %i, MAX: %i\n", short_int, 
	SHRT_MIN, SHRT_MAX); /* The 16-bit short int data type can hold integer 
	values in the range of −32,768 to 32,767. You may also refer to this data 
	type as short, signed short int, or signed short. */
    printf("UNSIGNED SHORT INT - EX: %i, MIN: %i, MAX: %i\n\n", ushort_int,
	0, USHRT_MAX); /* The 16-bit unsigned short int data type can hold integer 
	values in the range of 0 to 65,535. You may also refer to this data type as 
	unsigned short. */
}

void	integers32(void)
{
    int    an_integer = -2080988000;
    unsigned int	uinteger = 4000000000;

    printf("BASE INT - EX: %i, MIN: %i, MAX: %i\n", an_integer, 
	INT_MIN, INT_MAX); /* The 32-bit int data type can hold integer values in 
	the range of −2,147,483,648 to 2,147,483,647. You may also refer to this 
	data type as signed int or signed. */
    printf("UNSIGNED INT - EX: %u, MIN: %u, MAX: %u\n\n", uinteger,
	0, UINT_MAX); /* The 32-bit int data type can hold integer values in the
	range of −2,147,483,648 to 2,147,483,647. You may also refer to this data 
	type as signed int or signed. */
}

void	long_integers3264(void)
{
    long int	a_long_int1 = -2080988000000;
    long	a_long_int2 = -2080988001000;
    unsigned long	 a_ulong_int = 4000000000000;

    printf("LONG INT - EX: %li, MIN: %li, MAX: %li\n", a_long_int1, 
	LONG_MIN, LONG_MAX); /* The 32-bit long int data type can hold integer 
	values in the range of at least −2,147,483,648 to 2,147,483,647. 
	// Depending on your system, this data type might be 64-bit, in which case 
	its range is identical to that of the long long int data type.) You may 
	also refer to this data type as long, signed long int, or signed long. */
    printf("UNSIGNED INT - EX: %lu, MIN: %i, MAX: %lu\n\n", a_ulong_int, 
	0, ULONG_MAX); /* The 32-bit unsigned long int data type can hold integer
	values in the range of at least 0 to 4,294,967,295. // Depending on your 
	system, this data type might be 64-bit, in which case its range is identical
	to that of the unsigned long long int data type. You may also refer to this
	data type as unsigned long. */
}

void	long_long_integers64(void) {
    long long int	 a_long_long_int1 = -2080988000000; 
    long long	 a_long_long_int2 = -2080988001000; 
    unsigned long long	  a_ulong_long_int = 40000000000000;

    printf("LONG LONG INT - EX: %lli, MIN: %lli, MAX: %lli\n", a_long_long_int1,
	LLONG_MIN, LLONG_MAX); /* The 64-bit long long int data type can hold 
	integer values in the range of −9,223,372,036,854,775,808 to 
	9,223,372,036,854,775,807. You may also refer to this data type as 
	long long, signed long long int or signed long long. // 
	This type is not part of C89, but is both part of C99 and a GNU C 
	extension. */
    printf("UNSIGNED LONG LONG INT - EX: %llu, MIN: %i, MAX: %llu\n", 
	a_ulong_long_int, 0, ULLONG_MAX); /* The 64-bit unsigned long long int data
	type can hold integer values in the range of at least 0 to 
	18,446,744,073,709,551,615. You may also refer to this data type as unsigned
	long long. // This type is not part of C89, but is both part of C99 and a 
	GNU C extension. */
}

int	   main(void)
{
    char_integers8();
    short_integers16();
    integers32();
    long_integers3264();
    long_long_integers64();
	return (0);
}