// INTEGERS CONSTANTS (LITTERALS) (p3, GNU C Reference Manual)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

void	decimal_values(void)
{
    int    i;
    int    decimal_values[] = { 459, 23901, 8, 12 }; /* In all other cases, the 
	sequence of digits is assumed to be decimal (base 10). Decimal values may 
	use the digits from 0 to 9. */

    for (i = 0; i < 4; i ++)
	{
        printf("decimal_value %d: %i\n", i, decimal_values[i]); /* %i also does 
		the same, convert an integer to a decimal. */
    }
}

void	octal_values(void)
{
    int    i;
    int    octal_values[] = { 057, 012, 03, 0241 }; /* If the first digit is 0 
	(zero), and the next character is not ‘x’ or ‘X’, then the constant is 
	considered to be octal (base 8). */

    for (i = 0; i < 4; i ++)
	{
        printf("octal_value %d: %o\n", i, octal_values[i]); /* %o displays the 
		number is octalValue AS a octal number. Changing to %d or %x converts 
		that number to decimal to !*/
    }
}

void	hexadecimal_values(void)
{
    char	i;
    int    hex_values[] = { 0x2f, 0x88, 0xAB43 }; /*  - If the sequence of 
	digits is preceded by 0x or 0X, then the constant is considered to be
	hexadecimal. */ 

    for (i = 0; i < 3; i ++)
	{
        printf("hex_value %d: %x\n", i, hex_values[i]); /* %x displays the 
		number is hex_value AS a hex number. Changing to %d or %x converts that 
		number to decimal or hex! */
    }
}

void	long_or_unsigned_values(void) // Not a very compelling example tbh
{ 
    int    i;
    int    list_of_integers[] = { 11L, 45UL, 10u, 0x2fL, 011U }; /* 11L 10u 
	0x2fL 011U 45UL - You can force an integer constant to be of a long and/or 
	unsigned integer type by appending a sequence of one or more letters to 
	the end of the constant */
    
	for (i = 0; i < 5; i ++)
	{
        printf("long_integers %d: %d\n", i, list_of_integers[i]);
    }
}

int    main(void) 
{
    decimal_values();
    octal_values();
    hexadecimal_values();
    long_or_unsigned_values();
	return (0);
}