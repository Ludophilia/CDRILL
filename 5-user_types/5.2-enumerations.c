// ENUMERATIONS (p11, GNU C Reference Manual)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

/* An enumeration is a custom data type used for STORING CONSTANT INTEGER 
VALUES and referring to them by names. By default, THESES VALUES are of TYPE 
signed int; however, you can use the -fshort-enums GCC compiler option to cause
the smallest possible integer type to be used instead. Both of these 
behaviors conform to the C89 standard, but mixing the use of these options 
within the same program can produce incompatibilities. */

/* You define an enumeration using the enum keyword, followed by the name of
 the enumeration (this is optional), followed by a list of CONSTANT names 
 (separated by commas and enclosed in braces), and ending with a semicolon. */

/* You can’t use the same name for an enum as a struct or union in the same
 scope. You cannot change the values in an enumeration once it has been 
 defined; they are constant values. */

/* Enumerations are useful in conjunction with the switch statement, because 
the compiler can warn you if you have failed to handle one of the enumeration
values. Using the example above, if your code handles banana, apple and mango
only but not blueberry, GCC can generate a warning. */

void	enum_example(void)
{
	/* That example defines an enumeration, fruit, which contains four constant
	integer values, grape, cherry, lemon, and kiwi, whose values are, by 
	default, 0, 1, 2, and 3, respectively. */
    enum	e_fruit1
	{ 
		grape, 
		cherry, 
		lemon, 
		kiwi 
	}; 
	/* You can also specify one or more of the values explicitly. That 
	example defines banana to be −17, and the remaining values are incremented 
	by 1: apple is −16, blueberry is −15, and mango is -14. */
    enum	e_fruit2
	{ 
		banana = -17, 
		apple, 
		blueberry, 
		mango 
	}; 
	/* You can also refer to an enumeration value defined earlier in the same 
	enumeration. In that example, kumquat is 0, raspberry is 1, peach is 2,
	and plum is 4. */
    enum	e_fruit3
	{ 
		kumquat, 
		raspberry, 
		peach, 
		plum = peach + 2 
	}; 

	/* Once defined, enumerators constants can be accessed without even using 
	the enumaration name. As enumerators constants are... constants, they can 
	be used as operands or starting values or bounds in a for loop... */
    printf("e_fruit1 - grape: %i, kiwi: %i, cherry: %i, lemon: %i\n", grape,
	kiwi, cherry, lemon);
    printf("e_fruit2 - banana: %i, blueberry: %i, mango: %i, apple: %i\n",
	banana, blueberry, mango, apple);
	printf("Sum of all e_fruit3 constants: %i\n\n", kumquat + raspberry + peach 
	+ plum);
}

void	assigning_enums(void)
{
    /* You can declare variables of an enumeration type both when the 
	enumeration is defined and afterward. This example declares one variable, 
	named my_fruit of type enum fruit, all in a single statement. The next 
	example declares the type and variable separately */
    enum	e_fruit1
	{ 
		banana,
		apple, 
		blueberry, 
		mango
	}	 my_fruit_var1;
    enum e_fruit2
	{ 
		grape = 6, 
		cherry, 
		lemon, 
		kiwi
	}; 
	int my_fruit_var3;
    enum e_fruit2	 my_fruit_var2; 

    my_fruit_var1 = blueberry; /* The variables newly created can then be 
	assigned one of the enumerators of the enum type. */
    my_fruit_var2 = 120; /* Although such variables are considered 
	to be of an enumeration type, you can assign them any value that you could
	assign to an int variable, including values from other enumerations. */
    my_fruit_var3 = grape; /* Furthermore, any variable that can be assigned 
	an int value can be assigned a value from an enumeration. */
    printf("my_fruit_var1 : %i\n", my_fruit_var1); // 2
    printf("my_fruit_var2 : %i\n", my_fruit_var2); // 120
    printf("my_fruit_var3 : %i\n", my_fruit_var3); // 6 
}

int	   main(void)
{
    enum_example();
    assigning_enums();
    return (0);
}
