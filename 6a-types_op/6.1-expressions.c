// Expressions (p28) + (p37)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>
#include <math.h>

void    expressions_examples(void)
{
	/* An expression consists of at least one operand and zero or more 
	operators. 
	Operands are typed objects such as litterals, variables, and function calls
	that return values.
	Parentheses group subexpressions. Innermost expressions are evaluated 
	first. In the example below, 3 + 10 and 2 * 6 evaluate to 13 and 12, 
	respectively. Then 12 is subtracted from 13, resulting in 1. Finally, 1 is
	multiplied by 2, resulting in 2. The outermost parentheses are completely
	optional. 
	An operator specifies an operation to be performed on its operand(s). 
	Operators may have one, two, or three operands, depending on the operator.
	*/
	int    num_expr = 47;
	short    int_add_expr = 2 + 2;
	float    pi_cos_expr = cos(3.14159);
	char    complex_math_op_expr = (2 * ((3 + 10) - (2 * 6)));
}

int    freturns_100(void)
{
	return (100);
}

void    function_calls_as_expr(void)
{	
	/* A call to any function which returns a value is an expression. */
	int    hyakutooban = freturns_100() + 10;
	printf("hyakutooban = %i\n", hyakutooban);
}

int    main(void)
{
	function_calls_as_expr();
	return (0);
}