// CONDITIONAL EXPRESSION (p38)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>
#include <stdbool.h>

void    ternary_example(bool truth_value)
{
	/* You use the conditional operator to cause the entire conditional 
	expression to evaluate to either its second or its third operand, based on
	the truth value of its first operand. 
		Ex : oper1 ? oper2 : oper3.
	If expression in the first operand is true, then expression in the second 
	operand is evaluated and the third operand is never evaluated. Otherwise, 
	expression in the third opererand is evaluated and the second operand is
	never evaluated. 
	The first operand is always evaluated.
	Expresions in oper2 and oper3 must be compatible. That is, they must be both
		1 / arithmetic types (char, short, int...)
		2 / compatible struct or union types
		3 / pointers to compatible types (one of which might be NULL)
	*/
	char    *truth_str;

	truth_str = truth_value ? "TRUE" : "FALSE";
	printf("As of now, truth_str returns %s\n", truth_str);
}

void    ternary_replacement(bool truth_value)
{
	/* The conditional operator can be considered a shorthand method for 
	writing a simple if...else statement. The following example will accomplish
	the same task as the previous one. */
	char    *truth_str;

	if (truth_value)
		truth_str = "TRUE";
	else
		truth_str = "FALSE";
	printf("As of now, truth_str returns %s\n", truth_str);
}

int    main(void)
{
	ternary_example(false);
	ternary_replacement(1);
}