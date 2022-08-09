// TYPECASTING (p36)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

void    typecasting_ex(void)
{
	/* You can use a type cast to explicitly cause an expression to be of a 
	specified data type. A type cast consists of a type specifier enclosed in
	parentheses, followed by an expression. 
	To ensure proper casting, you should also enclose the expression that 
	follows the type specifier in parentheses.
	In the next example, since 7 and 3 are both integers, integer division is 
	performed, and even though x is a floating-point variable, it receives 
	the value 2. Explicitly casting the result of the division to float does 
	no good, because the computed value of y/z is already 2.
	To fix this problem, you need to convert one of the operands to a 
	floating-point type before the division takes place. */
	float    x;

	x = (float)(7 / 3); // x = 2.0 because 7 / 3 takes precedence.
	printf("x = %.2f\n", x);
	x = (float)7 / 3; // x = 2.33, 7 has been converted before division.
	printf("x = %.2f\n", x);
}

void    typecasting_limitations(void)
{
	/* Type casting only works with scalar types (that is, integer, 
	floating-point or pointer types). Therefore, the next example is not 
	allowed. */
	struct    s_structure {};
	struct s_structure    struct_var;
	unsigned char    array_of_bytes[8];

	/* struct_var = (struct s_structure)array_of_bytes; */ /* cast to type
	struct s_structure is not allowed */
}

int    main(void)
{
	typecasting_ex();
}