// BITWISE OPERATOR (p33)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

/* C provides operators for performing bitwise conjunction, inclusive disjun-
-ction, exclusive disjunction, and negation (complement).
In C, you can only use these operators with operands of an integer (or 
character (??? - no!)) type, and for maximum portability, you should ONLY USE 
the bitwise NEGATION operator with UNSIGNED INTEGER TYPES. */

void    conjuction(void)
{
	/* Biwise conjunction examines each bit in its two operands, and when two 
	corresponding bits are both 1, the resulting bit is 1. All other resulting 
	bits are 0. */
	printf("1100 & 1011 = 0x%x = 1000\n", 0b1100 & 0b1011); 
}

void    incluse_disjunction(void)
{
	/* Bitwise inclusive disjunction examines each bit in its two operands, 
	and when two corresponding bits are both 0, the resulting bit is 0. 
	All other resulting bits are 1. */
	printf("1100 | 1011 = 0x%x = 1111\n", 0b1100 | 0b1011); 
}

void    exclusive_disjuction(void)
{
	/* Bitwise exclusive disjunction examines each bit in its two operands, and
	when two corresponding bits are different, the resulting bit is 1. All other
	resulting bits are 0. */
	printf("1100 ^ 1011 = 0x%x = 0111\n", 0b1100 ^ 0b1011);
}

void    complement(void)
{
	/* Bitwise negation reverses each bit in its operand */
	printf("~0xffffffff = 0x%x = 00000000\n", ~0xffffffff); /* On 32 bits at 
	least cannot typecast to char, wtf */
}

int    main(void)
{
	conjuction();
	incluse_disjunction();
	exclusive_disjuction();
	negation();
}