// INTEGERS TYPES (p10, GNU C Reference Manual)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>
#include <complex.h>

/* GCC introduced some complex number types as an extension to C89. Similar 
features were introduced in C99, but there were a number of differences. We
describe the standard complex number types first. */

void	complex_float32(void)
{
    float _Complex	  a_complex_number1 = I; /* Complex types were introduced
	in C99. The type name begin with an underscore and an uppercase letter in
	order to avoid conflicts with existing programs’ identifiers. // I is a 
	constant of type const float _Complex having the value of the imaginary 
	unit normally referred to as i. */

    printf("a_complex_number1 - real part : %.2f, imaginary part : %.2f\n",
	creal(a_complex_number1), cimag(a_complex_number1)); /* The <complex.h> 
	header file also declares a number of functions for performing computations
	on complex numbers, for example the creal() and cimag() functions which
	respectively return the real and imaginary parts of a double complex
	number. */
}

void	complex_double64(void)
{
    double complex	  a_complex_number2 = 3e56 + 15 * I; /* complex expands to 
	_Complex. This allows a variable to be declared as double complex which
	seems more natural. */

    printf("a_complex_number2 - real part : %.2e, imaginary part : %.2f\n", 
	creal(a_complex_number2), cimag(a_complex_number2));
}

void	complex_long_double80(void)
{
    long double complex	   a_huge_complex = CMPLX(64e128, -15.0); /* CMPLX() 
	function creates complex number objects by taking real part and imaginary 
	parts as parameters. This function returns the object of complex 
	numbers. */

    printf("a_huge_complex - real part : %.2e, imaginary part : %.2f\n",
	creal(a_huge_complex), cimag(a_huge_complex));
}

int	   main(void)
{
    complex_float32();
    complex_double64();
    complex_long_double80();
    return (0);
}
