// STORAGE CLASS SPECIFIERS (p26)

// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

/* There are four storage class specifiers that you can prepend to your variable
declarations which change how the variables are stored in memory: auto, register
, extern, and static. */

void	auto_class_specifier(int value) 
{
	/* Scope : within block (could be top-level block)lifetime : till 
	end of block. */
    auto int	x1 = value; /* You use auto for variables which are local to a 
	function and whose values should be DISCARDED UPON RETURN from the function 
	in which they are declared. */
    
    return; /* This is the default behavior for variables declared WITHIN 
	functions. */
}

void	register_class_specifier(int value) 
{
	/* Scope : within block (could be top-level block) | lifetime :
	till end of block. */
    register int	x2 = value; /* register is nearly identical in purpose to
	auto, except that it also suggests to the compiler that the variable will be 
	HEAVILY used, and, IF POSSIBLE, should be stored in a (processor) register 
	(note : register variables are much faster to access than that of the 
	variables stored in the memory during the runtime of the program). */
    
    return; /* GCC normally makes good choices about which values to hold in 
	registers, and so register is not often used. */
}

void	register_class_limitations(int value) 
{
    register int	array_of_x[] = { value }; 
    /* int    *px = &x2; // You CANNOT use the address-of operator (&) to 
	obtain the address of a variable declared with register. (Makes sense, the 
	variable may not be in memory...) */
    
    /* printf("x2 :%i\n", array_of_x[0]); // This means that you CANNOT refer to 
	the elements of an array declared with storage class register. (Same, may 
	not be in memory...) */
    printf("x2 size : %lu bytes\n", sizeof(array_of_x)); /* In fact the only 
	thing you CAN DO with such an array is measure its size with sizeof. */ 
}

void	static_class_specifier(void) 
{
	/* Scope : within block (could be top-level block) | lifetime : till the end
	of the program. */
    static int	  count1 = 0; /* static is essentially the opposite of auto: 
	when applied to VARIABLES within a function or block, these VARIABLES will 
	RETAIN their VALUE even when the function or block is finished. */

    count1 += 2;
    printf("Value of count1: %i\n", count1); /* This is known as STATIC STORAGE 
	DURATION. */
}

static void    static_class_specifier2(void) 
{ 
    /* You can also declare VARIABLES (or FUNCTIONS) at the TOP LEVEL (that is, 
	not inside a function) to be static; such variables are VISIBLE (global) to 
	the CURRENT SOURCE file (but NOT OTHER SOURCE files). */

    return; /* This gives an unfortunate double meaning to static; this second 
	meaning is known as STATIC LINKAGE. // Two functions or variables having 
	static linkage in separate files are entirely separate; NEITHER is VISIBLE 
	OUTSIDE the file in which it is declared. */
}

void	extern_class_specifier(void)
{
	/* Scope : top level/global, multiple files | lifetime : till the end of 
	the program. extern is useful for declaring variables that you want to be 
	VISIBLE to ALL SOURCE FILES that are linked into your project. */
    /* extern	 int i1; // You CANNOT INITIALIZE a variable in an extern 
	declaration, as NO SPACE is ACTUALLY ALLOCATED during the declaration. */
    /* extern 	 int i1; // The extern declaration may be repeated multiple 
	times.*/

    return; /* You MUST MAKE BOTH 1/ an EXTERN DECLARATION (typically IN a 
	HEADER FILE that IS #INCLUDED by the OTHER SOURCE FILES which need to 
	access the variable) and 2/ a NON-EXTERN DECLARATION (WHERE ??) which is 
	where SPACE IS ACTUALLY ALLOCATED to store the variable. */ 
}

void	extern_class_specifier2(void) 
{
    /* extern int	 i1; */
   /* auto int	  *p2; */

 	/* printf("extern i1: %i\n", i1); // Uninitialized variables that are 
	declared as extern are given default values of 0, 0.0, or NULL, depending on
	the type.... */
	/* printf("extern p2: %p\n", p2); // ...contrary to uninitialized variables
	that are declared as auto or register (including the default usage of auto) 
	are left uninitialized or with a random value. */
}

int		main(void) 
{
    auto_class_specifier(8);
    register_class_specifier(8);
    register_class_limitations(8);
    static_class_specifier();
    static_class_specifier();
    extern_class_specifier();
    // printf("x2: %i\n", x2); // no x2 at THIS level
    // printf("x1: %i\n", x1); // no x1 at THIS level
    // printf("count1: %i\n", count1);  // no count1 at THIS level
    return (0);
}