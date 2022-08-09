// Pointer Operators (p35)
// // https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

static int    COUNT;

void    f(void)
{	
	printf("f function read %i times\n", COUNT += 1);
}

void    address_operator(void)
{
	/* You can use the address operator & to obtain the memory address of an 
	object. It is not necessary to use this operator (&) to obtain the address 
	of a function. 
	Function pointers and data pointers are not compatible, in the sense that 
	you cannot expect to store the address of a function into a data pointer, 
	and then copy that into a function pointer and call it successfully. It 
	might work on some systems, but it’s not a portable technique. */
	int    x;
	int    *px;
	void    (*pf1)(void); // Syntax for function pointers...
	void    (*pf2)(void);
	
	px = &x;
	pf1 = &f;
	pf2 = f;
}

void    indirection_operator(void)
{
	/* Given a memory address stored in a pointer, you can use the indirection 
	operator (*) to obtain the value stored at the address. Similarly to the 
	address-of operator, it's not necessary to use the indirection operator (*)
	on a function pointer to access the pointed function. */
	int    x = 8;
	int    *px = &x;
	void    (*pf1)(void) = &f; // Syntax for function pointers...
	void    (*pf2)(void) = f;
	
	printf("*px = %i\n", *px);
	(*pf1)();
	pf2();
}

int    main(void)
{
	COUNT = 0;
	indirection_operator();
	xyz();
}
