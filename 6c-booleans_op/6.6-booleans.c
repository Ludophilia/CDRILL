// BOOLEANS (p33)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

/* Logical operators test the truth value of a pair of operands. Any nonzero 
expression is considered true in C, while an expression that evaluates to zero
is considered false. */

void    conjunction_operator(void)
{
	/* The logical conjunction operator && tests if two expressions are both 
	true. If the first expression is false, then the second expression 
	is not evaluated. */
	puts("Conjuction (&&)");
	printf("1 && 1 is %i\n", 1 && 1);
	printf("0 && 1 is %i\n", 0 && 1);
	printf("1 && 0 is %i\n", 1 && 0);
	printf("0 && 0 is %i\n\n", 0 && 0);
}

void    disjunction_operator(void)
{
	/* The logical disjunction operator || tests if at least one of two 
	expressions it true. If the first expression is true, then the second 
	expression is not evaluated. */
	puts("Disjunction (||)");
	printf("1 || 1 is %i\n", 1 || 1);
	printf("0 || 1 is %i\n", 0 || 1);
	printf("1 || 0 is %i\n", 1 || 0);
	printf("0 || 0 is %i\n\n", 0 || 0);
}

void    negation_operator(void)
{
	/* You can prepend a logical expression with a negation operator ! to flip
	the truth value */
	puts("Negation (!)");
	printf("!1 is %i\n", !1);
	printf("!0 is %i\n", !0);
}

int    main(void)
{
	conjunction_operator();
	disjunction_operator();
	negation_operator();
}