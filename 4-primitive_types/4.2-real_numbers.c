// REAL NUMBER TYPES (p9, GNU C Reference Manual)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf
// https://www.tutorialspoint.com/cprogramming/c_data_types.htm#

#include <stdio.h>
#include <float.h>

/* There are three data types that represent fractional numbers. While the 
sizes and ranges of these types are consistent across most computer systems in
use today, historically the sizes of these types varied from system to 
system. */

/* As such, the minimum and maximum values are stored in macro definitions in 
the library header file float.h. In this section, we include the names of the
macro definitions in place of their possible values; check your system’s 
float.h for specific numbers. */

/* NOTE - All floating point data types are signed; trying to use 
unsigned float, for example, will cause a compile-time error. */

void	float32(void)
{
    float	 a_flot_num = 3.74;
    
    printf("FLOAT - EX: %.2f, MIN: %e, MAX: %e\n\n", a_flot_num,
	FLT_MIN, FLT_MAX); /* The float data type is the smallest of the three
	floating point types, if they differ in size at all. Its minimum value is
	stored in the FLT_MIN, and should be no greater than 1e-37. Its maximum
	value is stored in FLT_MAX, and should be no less than 1e37. */
}

void	double64(void)
{
    double	  a_double_num = 15e99;

    printf("DOUBLE - EX: %.1e, MIN: %e, MAX: %e\n\n", a_double_num,
	DBL_MIN, DBL_MAX); /* The double data type is at least as large as the 
	float type, and it may be larger. Its minimum value is stored in DBL_MIN,
	and its maximum value is stored in DBL_MAX. */
}

void	long_double80(void)
{
    long double a_long_double_num = 64e128;

    printf("LONG DOUBLE - EX: %.1Le, MIN: %Le, MAX: %Le\n\n", a_long_double_num,
	LDBL_MIN, LDBL_MAX); /* The long double data type is at least as large as 
	the float type, and it may be larger. Its minimum value is stored in
	LDBL_MIN, and its maximum value is stored in LDBL_MAX. */
}

void	on_comparisons(void)
{
    float ftpt = 42.2e99;
    float fptt1 = 4.22e100;

    printf("Are 42.2e99 and 4.22e100 equal? %i\n", (ftpt == fptt1)); /* The 
	real number types provided in C are of finite precision, and accordingly,
	not all real numbers can be represented exactly. // Most computer systems
	that GCC compiles for use a binary representation for real numbers, which
	is unable to precisely represent numbers such as, for example, 4.2. (It
	works for macOS however) // For this reason, we recommend that you consider
	not comparing real numbers for exact equality with the == operator, but 
	rather check that real numbers are within an acceptable tolerance. */
}

int	   main(void)
{
    float32();
    double64();
    long_double80();
    on_comparisons();
    return (0);
}