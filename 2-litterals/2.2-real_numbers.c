// REAL NUMBERS CONSTANTS (LITTERALS)(p4, GNU C Reference Manual)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

void	real_number_constants(void) 
{
    int    i;
    float    real_numbers[] = { 4., .7, 0.4, 4.7 }; /* - A real number constant 
	is a value that represents a fractional (floating point) number. It consists
	of a sequence of digits which represents the integer (or “whole”) part of 
	the number, and a sequence of digits which represents the fractional part. 
	Either the integer part or the fractional part may be omitted, but
	not both. */

    for (i = 0; i < 4; i ++)
	{
        printf("real_number #%d: %.2f\n", i, real_numbers[i]); /* %f converts a 
		floating point number to the decimal notation in the style of d.d. 
		Precision is of 6 digits by default (O.OOOOO1), can be changed by adding
		an integer p representing the precision between % and f (%.pf, example 
		: %.4f for 4 digits after the point) */
    }
}

void	exponent_number_constants(void) 
{
    int    i;
    float	 exponents[] = { 5e2, 5e-2, 1e3, 3e-3 }; /* 5e2 (or5*100), 
	5e-2 (or 5*(1/100)) - Real number constants can also be followed by e or E, 
	and an integer exponent. The exponent can be either positive or negative. */

    for (i = 0; i < 4; i ++) 
	{
        printf("Exponent #%i: %.0e\n", i, exponents[i]); /* %e converts floating
		-point number to the decimal exponent notation. As for %f, the precision
		is of 6 digits after the point by default. Precision can be changed by 
		appending .p between % and e, p being a positive int or zero. */
    }
}

void	real_numbers_forced_conversions(void) 
{
    float	 forcedConversions[] = { 2.7f, 3.L }; /* You can append a letter to 
	the end of a real number constant to cause it to be of a particular type. If
	you append the letter F (or f) to a real number constant, then its type is 
	float. If you append the letter L (or l), then its type is long double. */

    printf("This is a float: %.1f\n", forcedConversions[0]);
    printf("This is a long double: %g\n", forcedConversions[1]); /* %g converts 
	floating-point number to decimal or decimal exponent notation depending on 
	the value and the precision. */
}

int    main(void)
{
    real_number_constants();
    exponent_number_constants();
    real_numbers_forced_conversions();
    return (0);
}
