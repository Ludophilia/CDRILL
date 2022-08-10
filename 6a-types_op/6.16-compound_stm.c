// COMPOUND STATEMENTS (p39)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>
#define ID(x) ({ int _x = x; _x; })

void    compound_statement_ex(int x)
{
	/* As a GNU C extension, you can build an expression using compound 
	statement enclosed in parentheses. This allows you to include loops (???), 
	switches, and local variables within an expression. 
	Recall that a compound statement (also known as a block) is a sequence of
	statements surrounded by braces ({}). In this construct, parentheses go 
	around the braces. 
	The last thing in the compound statement should be an expression followed 
	by a semi-colon; the value of this subexpression serves as the value of 
	the entire construct. 
	If you use some other kind of statement last within the braces, the 
	construct has type void, and thus effectively no value.
	Below a valid though slightly more complex than necessary expression 
	for the absolute value of indentity ().
	Note : Embedded statements are not allowed in constant expressions, such as
	the value of an enumeration constant, the width of a bit field, or the 
	initial value of a static variable.
	*/
	int    abs_x;

	abs_x = ({ int _x = ID(x) ; int _abs_x;
        if (_x > 0) _abs_x = _x;
		else _abs_x = -_x;
		_abs_x; });

	printf("abs_x = %i\n\n", abs_x);	
}

void    cpst_and_macros(void)
{
	/* Coumpound statement feature is especially useful in making macro
	definitions “safe” so that they evaluate each operand exactly once. For 
	example, the “maximum” function is commonly defined as a macro in standard
	C as in line 47. But this definition computes either a or b twice, with 
	bad results if the operand has side effects. 
	In GNU C, if you know the type of the operands (here let’s assume int), you
	can define the macro safely as in line 48-49.
	*/
	#define maxv1(a,b) ((a) > (b) ? (a) : (b)) // Nothing wrong here officer 👌 
	#define maxv2(a,b) ({ int _a = a, _b = b; \
	 					_a > _b ? _a : _b; })

	printf("maxv1(23, 16): %i\n", maxv1((0xB + 0xC), (int)(4.1 * 4.1)));
	printf("maxv2(23, 16): %i\n", maxv2((0xB + 0xC), (int)(4.1 * 4.1)));
}

int    main(void)
{
	compound_statement_ex(667);
	cpst_and_macros();
}
