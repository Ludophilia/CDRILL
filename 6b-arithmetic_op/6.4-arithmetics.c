// ARITHMETIC OPERATORS (p30)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>
#include <complex.h>

/* C provides operators for standard arithmetic operations: addition,
subtraction, multiplication, and division, along with modular division and
negation. 
Note that you can add and subtract TO memory pointers, BUT you CANNOT multiply 
or divide them. */

void    addition(void)
{
	int    *p1;

	printf("5 + 3 = %i\n", 5 + 3);
	printf("10.23 + 37.332 = %.3f\n", 10.23 + 37.332);
	printf("p1 + 0x1 = %p\n\n", p1 + 0x1);
}

void    substraction(void)
{
	/* If the operand you use with the negative operator is of an unsigned data
	type, then the result cannot be negative, but rather is the maximum value of
	the unsigned data type, minus the value of the operand. */
	int    *p1;
	unsigned short    z = 0;

	printf("5 - 3 = %i\n", 5 - 3);
	printf("10.23 - 37.332 = %.3f\n", 10.23 - 37.332);
	printf("p1 - 0x1 = %p\n", p1 - 0x1);
	printf("z = z - 1 = %i\n\n", z = z - 1);
}

void    multiplication(void)
{
	printf("5 * 3 = %i\n", 5 * 3);
	printf("10.23 * 37.332 = %.3f\n\n", 10.23 * 37.332);
}

void    division(void)
{
	/* Integer division of positive values truncates towards zero, so 5/3 is 1
	instead of ~1,667.
	However, if either operand is negative, the direction of rounding is 
	implementation-defined. Section A.5 [Signed Integer Division], page 75 
	for information about overflow in signed integer division. */
	printf("5 / 3 = %i\n", 5 / 3);
	printf("5 / 3 = %.2f\n", 5.0 / 3);
	printf("10.23 / 37.332 = %.3f\n\n", 10.23 / 37.332);
}

void    modular_division(void)
{
	/* You use the modulus operator % to obtain the remainder produced by 
	dividing its two integer operands. You put the operands on either side 
	of the operator, and it does matter which operand goes on which side: 3 % 5 
	and 5 % 3 do not have the same result.  */
	printf("5 %% 3 = %i\n\n", 5 % 3);
}

void    negation(void)
{
	int    x = 5;
	float    y = 3.14159;
	unsigned short    z = 1;
	printf("-x = %i\n", -x);
	printf("-y = %.5f\n", -y);
	printf("-z = %i\n\n", -z);
}

void    complex_conjugation(void)
{
	/* As a GNU extension, you can use the complex conjugation operator ~ to
	perform complex conjugation on its operand — that is, it reverses the sign
	of its imaginary component. The operand must be an expression of a complex
	number type. */
	float complex    z = 5 + 17 * I;
	
	printf("z = %.2f + %.2fi\n", creal(z), cimag(z));
	printf("~z = %.2f + %.2fi\n\n", creal(~z), cimag(~z));
}

int    main(void)
{
	addition();
	substraction();
	multiplication();
	division();
	modular_division();
	negation();
	complex_conjugation();
}