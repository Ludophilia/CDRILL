// UNIONS (p12, GNU C Reference Manual)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

/* A union is a custom data type used for storing several variables in the 
same memory space. Although you can access any of those variables at any time,
you should only read from ONE of THEM AT A TIME — assigning a value to one of
them overwrites the values in the others. */

void	union_example(void)
{	
	/* You define a union using the union keyword followed by the declarations 
	of the union’s members, enclosed in braces. You declare each member of a 
	union just as you would normally declare a variable—using the data type 
	followed by one or more variable names separated by commas and ending 
	with a semicolon. Then end the union definition with a semicolon after the
	closing brace. */
    union	 u_numbers1
	{
        int	   i;
        float	 f;
    };
	/* You should also include a name for the union between the union keyword
	and the opening brace. This is syntactically optional, but if you leave it
	out, you can’t refer to that union data type later on... That defines a 
	union, which contains 4 members of type int, i, n, t and j. */
    union 
	{
        int	   i;
		int	   n;
		int	   t;
		int	   j;
    };
}

void	union_and_variables(void)
{
    /* You can declare variables of a union type when both you initially define
	the union and after the definition, provided you gave the union type a
	name. That example declares two variables of type union numbers, 
	first_number1 and second_ number2. */
    union	 u_numbers2
	{
        int	   i;
        float	 f;
    }    number1, number2; 
    /* You can declare variables of a union type after you define the union 
	by using the union keyword and the name you gave the union type, followed
	by one or more variable names separated by commas. That example declares 
	two variables of type union numbers, first_number2 and second_number2. */
    union u_numbers2	number3, number4; 
}

void	initialization(void)
{
	/* You can initialize a union member when you declare the union variable 
	during the definition. */
    union	 u_numbers3
	{
        int	   i;
        float	 f;
    }	 number5 = { 5 };
    union u_numbers3	number6 = { 5 }; /* You can initialize the first
	member of a union variable when you declare it. In that example, the i 
	member of first_number gets the value 5. The f member is left alone. */
    union u_numbers3	number7 = { f: 3.14159 }; /* Another way to 
	initialize a union member is to specify the name of the member to 
	initialize. This way, you can initialize whichever member you want to,
	not just the first one. BEWARE, this GNU old-style of initializing 
	an union member is not preferred, see below. */
	union u_numbers3	number8 = { .f = 3.14159 }; /* Another way to 
	initialize a union member is to precede the member name with a period and 
	assign a value with the assignment operator. */
}

void	accessing_members(void)
{
    union	 u_numbers4
	{
        int	   i; 
        float	 f;
    }    number9 = { 5 };

    /* You can access the members of a union variable using the member access 
	operator. You put the name of the union variable on the left side of the 
	operator, and the name of the member on the right side.
	In the next example number9 {.i = 1078523331, .f = 3.14}. An union can only
	store one value at a time. Consequently, the value of i got corrupted. */
	number9.f = 3.14;
    printf("number9: {.i = %i, .f = %.2f}\n", number9.i, number9.f); 
}

void	size_of_unions(void)
{
	/* The size of a union is equal to the size of its largest member. In the 
	current example, The size of the union data type is the same as 
	sizeof (float), because the float type is larger than the int type. Since 
	all of the members of a union occupy the same memory space, the union data
	type size DOESN'T NEED to be large enough to hold the SUM of ALL their
	sizes; it JUST NEEDS to be LARGE ENOUGH to HOLD the LARGEST member. */
    union	 u_numbers5
	{
        int	   i;
        float	 f; 
    };
    union u_numbers5	number10 = { 5 };

    printf("number10 size: %lu bits\n", 8 * sizeof	 (number10)); /* 32 bits 
	or 4 bytes */
}

int    main(void)
{
    accessing_members();
    size_of_unions();
    return (0);
}