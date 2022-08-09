// Expressions (p28)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>
#include <math.h>

void    assignment_operators(void)
{
	/* Assignment operators store values in variables. C provides several
	variations of assignment operators.
	The standard assignment operator = simply stores the value of its right 
	operand in the variable specified by its left operand. As with all 
	assignment operators, the left operand cannot be a literal or constant 
	value. 
	Unlike the other assignment operators that will be described in the next
	sections, you can use the plain assignment operator to store values of a
	structure type. */
	int    x = 10;
	float    y = 45.12 + 2.0;
	int    z = (2 * (3 + cos(0)));
	struct    s_foo
	{
		int    bar;
		int    baz;
	}    quux = {3, 4};
}

void    basic_cassignment_operator(void)
{
	/* Compound assignment operators perform an operation involving both the 
	left and right operands, and then assign the resulting expression to the 
	left operand. Here is a list of the compound assignment operators, and a 
	brief description of what they do : 
		+= - Adds the two operands together, and then assign the result of the 
		addition to the left operand.
		-= - Subtract the right operand from the left operand, and then assign
		the result of the subtraction to the left operand.
		*= - Multiply the two operands together, and then assign the result of 
		the multiplication to the left operand.
		/= - Divide the left operand by the right operand, and assign the 
		result of the division to the left operand.
		%= - Perform modular division on the two operands, and assign the
		result of the division to the left operand.
	*/
	short    n = 10;

	printf("n = %i\n", n);
	printf("n = n + 15 = %i\n", n += 15); // n += 15, a shortcut for n = n + 15 
	printf("n = n - 10 = %i\n", n -= 10);
	printf("n = n * 10 = %i\n", n *= 10);
	printf("n = n / 10 = %i\n", n /= 10);
	printf("n = n %% 3 = %i\n\n", n %= 3);
}

void    rlshift_cassignment_operator(void)
{
	/* Compound assignment operators perform an operation involving both the 
	left and right operands, and then assign the resulting expression to the 
	left operand. Here is a list of the compound assignment operators, and a 
	brief description of what they do : 
		<<= - Perform a left shift operation on the left operand, shifting by 
		the number of bits specified by the right operand, and assign the 
		result of the shift to the left operand.
		>>= - Perform a right shift operation on the left operand, shifting by
		the number of bits specified by the right operand, and assign the result
		of the shift to the left operand.
	*/
	short    b = 0b0111; // 07

	printf("b = %d\n", b); // 0b0111 or 7
	printf("b = b << 1 = %d\n", b <<= 1); // 0b1110 or 7*2^1 or 14
	printf("b = b >> 2 = %d\n\n", b >>= 2); // 0b0011 or 14/2^2 or 3(!)
}

void    bitwise_cassignment_operator(void)
{
	/* Compound assignment operators perform an operation involving both the 
	left and right operands, and then assign the resulting expression to the 
	left operand. Here is a list of the compound assignment operators, and a 
	brief description of what they do : 
		&= - Perform a bitwise conjunction (AND) operation on the two operands,
		and assign the result of the operation to the left operand. Biwise 
		conjunction examines each bit in its two operands, and when two 
		corresponding bits are both 1, the resulting bit is 1. All other 
		resulting bits are 0. 
		^= - Performs a bitwise exclusive disjunction (XOR) operation on the 
		two operands, and assign the result of the operation to the left 
		operand. Bitwise exclusive disjunction examines each bit in its two 
		operands, and when two corresponding bits are different, the 
		resulting bit is 1. All other resulting bits are 0.
		|= - Performs a bitwise inclusive disjunction operation (OR) on the two 
		operands, and assign the result of the operation to the left operand. 
		Bitwise inclusive disjunction examines each bit in its two operands, 
		and when two corresponding bits are both 0, the resulting bit is 0. 
		All other resulting bits are 1.
	*/
	unsigned char    b1 = 0b0001;

	printf("b1 = %d\n", b1); // 0b0001
	printf("b1 = b1 & 0b1110 = %d\n", b1 &= 0b1110); // 0b0000 or 0
	printf("b1 = %d\n", b1); // 0b0000
	printf("b1 = b1 ^ 0b1111 = %d\n", b1 ^= 0b1111); // 0b1111 or 15
	printf("b1 = b1 >> 4 = %d\n", b1 >>= 4); // 0b0000
	printf("b1 = b1 | 0b1100 = %d\n\n", b1 |= 0b1100); // 0b1100 or 12
}

int    main(void)
{
	basic_cassignment_operator();
	rlshift_cassignment_operator();
	bitwise_cassignment_operator();
}