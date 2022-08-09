// COMMA OPERATOR (p37)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>
#include <stdarg.h>

void    print_ints(int arg_length, ...)
{	
	/* Treating variadic parameters in C is quite of a challenge that relies on 
	<stdarg.h> to be overcome. In this library: 
		- va_list is a structure type that holds the variadic parameters. This 
		type is suitable for holding info needed by the three macros va_start(), 
		va_arg() and va_end().
		- the va_start(va_list, T) macro enables access to the variable 
		arguments va_list following the named argument parmN.
		- va_arg(va_list, T) returns an expression of type T that corresponds 
		to the next parameter from the va_list. Prior to calling va_arg, a 
		va_list instance must be initialized by a call to either va_start or
		va_copy, with no intervening call to va_end. EACH invocation of the 
		va_arg macro modifies va_list instance to point to the next variable 
		argument.
		- va_end(va_list) - the va_end macro performs cleanup for an va_list 
		instance initialized by a call to va_start or va_copy. va_end may 
		modify ap so that it is no longer usable.
	*/
	va_list    list_args;
	int    next_arg;

	va_start(list_args, arg_length); 
	printf("%i ARGS declared --", arg_length);
	while (arg_length > 0)
	{
		next_arg = va_arg(list_args, int);
		printf(" %i ", next_arg);
		arg_length--;
	}
	printf("\n");
	va_end(list_args);
}

void    comma_def(void)
{
	/* You use the comma operator , to separate two (ostensibly related) 
	expressions. For instance, the first expression might produce a value that
	is used by the second expression. */
	int    x;
	int    y;

	x = 0;
	x++, y = x * x;
}

void    comma_and_for_loops(void)
{
	/* More commonly, the comma operator is used in for statements. This lets 
	you conveniently set, monitor, and modify multiple control expressions for
	the for statement. */
	int    x;
	int    y;

	for (x = 1, y = 10 ; x <= 5 || y >= 1 ; x += 2, y--)
	{
		printf("x = %i, y = %i\n", x, y);
	}
}

void    comma_and_functions(void)
{
	/* A comma is also used to separate function parameters; however, this is
	not the comma operator in action. 
	In fact, if the comma operator is used as we have discussed here in a
	function call, then the compiler will interpret that as calling the
	function with an extra parameter.
	If you want to use the comma operator in a function argument, you need to
	put PARENTHESES around it. That’s because COMMAS in a function argument 
	list have a different meaning: they SEPARATE ARGUMENTS. 
	Thus, f(w, x = 47, y, z) is interpreted as a function call with four 
	arguments, but f(w, (x = 47, y), z) is a function call with just three 
	arguments where the second argument is (x = 47, y).) */
	print_ints(4, 2, 3, 4, 5);
	print_ints(4, (2, 3), 4, 5); /* 3 VLargs in this function but 4 declared,
	the last will be a random int value*/
}

int    main(void)
{
	comma_and_for_loops();
	comma_and_functions();
}