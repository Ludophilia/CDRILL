// SIZEOF OPERATOR (p35)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

void    sizeof_example(void)
{
	/* You can use the sizeof operator to obtain the size (in bytes) of the 
	data type of its operand. 
	The operand may be an actual type specifier (such as int or float), as 
	well as any valid expression.
	When the operand is a type name, it must be enclosed in parentheses.
	The result of the sizeof operator is of a type called size_t, which is 
	defined in the header file <stddef.h>. size_t is an unsigned integer type,
	perhaps identical to unsigned int or unsigned long int; it varies from 
	system to system. 
	The size_t type is often a convenient type for a loop index, since it is 
	guaranteed to be able to hold the number of elements in any array; 
	this is not the case with int, for example. */
	size_t    a;
	size_t    b;
	size_t    c;
	size_t    d;
	size_t    e;
	
	a = sizeof(int);
	b = sizeof(float);
	c = sizeof a;
	d = sizeof 5;
	e = sizeof 5.143;
	printf("sizes: a(int) = %zuB, b(float) = %zuB, c(ulong) = %zuB, "
	"d(int) = %zuB, e(double) = %zuB\n",  a, b, c, d, e);
}

void    sizeof_and_arrays(void)
{
	/* The sizeof operator can be used to automatically compute the number of 
	elements in an array.
	There are two cases where this technique does not work. The first is where 
	the array element has zero size (GCC supports zero-sized structures as a 
	GNU extension). The second is where the array is in fact a function 
	parameter. */
	int    values[4] = { 1, 2, 48, 681 };
	size_t    i;

	for (i = 0 ; i < (sizeof values / sizeof values [0]) ; i++)
	{
		printf("%i\n", values[i]);
	}
}

int    main(void)
{
	sizeof_example();
	sizeof_and_arrays();
}