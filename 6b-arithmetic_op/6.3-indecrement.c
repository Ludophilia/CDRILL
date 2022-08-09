// Incrementing and Decrementing (p29)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

void    increment_example(void)
{
	/* The increment operator ++ adds 1 to its operand. The operand must be a 
	either a variable of one of the primitive data types, a pointer, or an 
	enumeration variable. You can apply the increment operator either before 
	or after the operand. 
	A prefix increment adds 1 BEFORE the operand is evaluated. A postfix 
	increment adds 1 AFTER the operand is evaluated. With character types for
	example, changing the position of the operator would make no difference. 
	However, there are cases like integer types where it does (sometimes) make a 
	difference.
	*/
	char    w = '1';
	char    y = 'B';
	int    x = 5;
	int    *p = &x;
	float    z = 5.2;

	printf("++w = %c\n", ++w); // '2'
	printf("w++ = %c\n", w++); // '2'
	printf("++y = %c\n", ++y); // 'C'
	printf("y++ = %c\n", y++); // 'C'
	printf("++x = %i\n", ++x); // 6 (sometimes)
	printf("x++ = %i\n", x++); // 6 or 5 (sometimes)
	printf("++z = %.1f\n", ++z); // 6.2
	printf("z++ = %.1f\n", z++); // 6.2
	printf("++p = %p\n", ++p); // 0x309ba154c or &x + sizeof    (int)
	printf("p++ = %p\n\n", p++); // 0x309ba154c
}

void    decrement_example(void)
{
	/* The increment operator -- substracts 1 to its operand. The operand must
	be a either a variable of one of the primitive data types, a pointer, or an 
	enumeration variable. You can apply the decrement operator either before 
	or after the operand. 
	A prefix decrements substracts 1 BEFORE the operand is evaluated. A postfix 
	increment substracts 1 AFTER the operand is evaluated. With character types
	for example, changing the position of the operator would make no difference. 
	However, there are cases like integer types where it does (sometimes) make a 
	difference.
	*/
	char    w = '1';
	char    y = 'B';
	int    x = 5;
	int    *p = &x;
	float    z = 5.2;

	printf("--w = %c\n", --w); // '0'
	printf("w-- = %c\n", w--); // '0'
	printf("--y = %c\n", --y); // 'A'
	printf("y-- = %c\n", y--); // 'A'
	printf("--x = %i\n", --x); // 4 (sometimes)
	printf("x-- = %i\n", x--); // 4 or 5 (sometimes)
	printf("--z = %.1f\n", --z); // 4.2
	printf("z-- = %.1f\n", z--); // 4.2
	printf("--p = %p\n", --p); // 0x309ba154c or &x + sizeof    (int)
	printf("p-- = %p\n\n", p--); // 0x309ba154c
}

int    main(void)
{
	increment_example();
	decrement_example();
}