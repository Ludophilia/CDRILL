// VARIABLES & CONSTANTS

// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf
// (p2, GNU C Reference Manual)

#include <stdio.h>

void	declaration(void)
{
    int		a_variable;
}

void	assignation(void)
{
    int		a_variable = 0;
	
    printf("a_variable: %d\n", a_variable);
}

void	declaration_and_assignation(void)
{
    int		a_variable;

    a_variable = 42;
    printf("a_variable: %d\n", a_variable);
}

void	identifiers(void) 
{
    /* IDENTIFIERS are sequences of characters used for naming variables, 
	functions, new data types, and preprocessor macros. */
    /* char 42students; */ /* The first character of an identifier CANNOT be 
	a digit.*/
    int		a_number_that_10people_like_v2; /* You CAN include letters, decimal 
	digits, and the underscore character ‘_’ in identifiers. // When using GNU 
	extensions, you CAN also include the dollar sign character ‘$’ 
	in identifiers. */
    char	foo[] = "bar";
	char	FoO[] = "BaR"; /* Lowercase letters and uppercase letters are 
	distinct, such that foo and FOO are two different identifiers.*/

    printf("foo: %s, FoO: %s\n", foo, FoO);
}

int    main(void) 
{ 
    declaration();
    assignation();
    declaration_and_assignation();
    identifiers();
}
