// ARRAY SUBSCRIPTS (p37)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

void    on_subscripts(void)
{
	/* You can access array elements by specifying the name of the array, and 
	the array subscript (or index, or element number) enclosed in brackets. 
	The array subscript expression A[i] is defined as being identical to the
	expression (*((A)+(i))).
	This means that many uses of an array name are equivalent to a pointer 
	expression. It also means that you cannot subscript an array having the
	register storage class. */
	int    arr1[3] = { [0 ... 1] = 1, [2] = 3 };
	
	printf("arr1[2] = %i\n", arr1[2]);
	printf("*(arr1 + 2) = %i\n", *(arr1 + 2));
}

int    main(void)
{
	on_subscripts();
	return (0);
}

