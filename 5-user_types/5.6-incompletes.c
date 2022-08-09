// INCOMPLETE TYPES (P25)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

void    incomplete_types(void)
{
    /* You can define structures, unions, and enumerations without listing 
	their members (or values, in the case of enumerations). Doing so results in
	an incomplete type. 
	You can't declare variables of incomplete types, but you can work with poin-
	-ters to those types.
	At some time later in your program you will want to complete the type. You 
	do this by defining it as you usually would. */
    struct    s_point; 
    struct s_point    *pointer_point_p1;
    struct    s_point
	{
        int    x;
		int    y;
    };
}

int    main(void)
{
    return (0);
}