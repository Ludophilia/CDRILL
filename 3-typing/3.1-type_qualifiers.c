// TYPE QUALIFIERS 
// P26 - https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

/* There are two type qualifiers that you can prepend to your variable 
declarations which change how the variables may be accessed: const and 
volatile. */
void	constant_variables(void) 
{
    /* const causes the variable to be read-only; // In addition to helping to 
	prevent accidental value changes, declaring variables with const can aid the
	compiler in code optimization. */
    const float	   pi = 3.14159f; 
    // pi = 3.161234f; // after initialization, its value may not be changed.
}

void	volatile_variables(void) 
{
    /* volatile tells the compiler that the variable is explicitly changeable, 
	and seemingly useless accesses of the variable (for instance, via pointers) 
	should not be optimized away. */
    volatile float    currentTemperature = 40.0; /* You might use volatile 
	variables to store data that is updated via callback functions or signal
	handlers. */
}

int    main(void) 
{
    return (0);
}