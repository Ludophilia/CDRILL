// COMARISONS OPERATORS (p32)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

/* You use the comparison operators to determine how two operands relate to 
each other: are they equal to each other, is one larger than the other, is one
smaller than the other, and so on.
When you use any of the comparison operators, the result is either 1 or 0, 
meaning true or false, respectively.
Comparing floating-point values for exact equality or inequality can produce
unexpected results. Section 2.1.2 [Real Number Types], page 9 for more 
information.
You can compare function pointers for equality or inequality; the comparison 
tests if two function pointers point to the same function or not. */

void    equal_to_operator(void)
{
	/* The equal-to operator == tests its two operands for equality. The result
	is 1 if the operands are equal, and 0 if the operands are not equal. */
	int    x;
	int    y;

	printf("Equality test: choose two integers x and y:\n");
	scanf("%i %i", &x, &y);

	if (x == y)
	{
		printf("\n%i is equal to %i\n\n", x, y);
	} else
	{
		printf("\n%i is not equal to %i\n\n", x, y);
	}
}

void    not_equal_to_operator(void)
{
	/* The not-equal-to operator != tests its two operands for inequality. 
	The result is 1 if the operands are not equal, and 0 if the operands are 
	equal. */
	int    x;
	int    y;

	printf("Inequality test: choose two integers x and y:\n");
	scanf("%i %i", &x, &y);

	if (x != y)
	{
		printf("\n%i is not equal to %i\n\n", x, y);
	} else
	{
		printf("\n%i is equal to %i\n\n", x, y);
	}
}

void    less_than_operators(void)
{
	/* Beyond equality and inequality, there are operators you can use to test 
	if one value is less than, greater than, less-than-or-equal-to, or 
	greater-than-or-equal-to another value.
	As the operators seen before, they return 1 if the operands satisfies the 
	test, 0 otherwise. */
	int    x;
	int    y;

	printf("Inferiority test: choose two integers x and y:\n");
	scanf("%i %i", &x, &y);

	if (x < y)
	{
		printf("%i is less than %i\n", x, y);
	} 
	if (x <= y)
	{
		printf("%i is less than or equal to %i\n\n", x, y);
	} else 
	{
		printf("%i is greater than %i\n\n", x, y);
	}
}

void    greater_than_operators(void)
{
	/* Beyond equality and inequality, there are operators you can use to test 
	if one value is less than, greater than, less-than-or-equal-to, or 
	greater-than-or-equal-to another value.
	As the operators seen before, they return 1 if the operands satisfies the 
	test, 0 otherwise. */
	int    x;
	int    y;

	printf("Superiority test: choose two integers x and y:\n");
	scanf("%i %i", &x, &y);

	if (x > y)
	{
		printf("%i is greater than %i\n", x, y);
	} 
	if (x >= y)
	{
		printf("%i is greater than or equal to %i\n\n", x, y);
	} else 
	{
		printf("%i is less than %i\n\n", x, y);
	}
}

int    main(void)
{
	equal_to_operator();
	not_equal_to_operator();
	less_than_operators();
	greater_than_operators();
}