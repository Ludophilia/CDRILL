// CODING STYLE
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h> /* This header contains the part of the C lib that contains 
printf function */

void    comment(void) 
{
    // This a comment 
    /* This is a comment
    on multiple lines */
}

void    whitespace(void) 
{
    /* White space is the collective term used for several characters: 
    - the space character ( ), 
    - the tab character (\t), 
    - the newline character (\n), 
    - the vertical tab character (\v), 
    - and the form-feed character (\f). 
    White space is ignored (outside of string and character constants), and is 
    therefore optional, except when it is used to separate tokens. */

    /* That means that a source code spreaded on multiple lines is functionally
     identical to same source code written on only 1 or 2 lines */

    /* Although you must use white space to separate many tokens, no white space
    is required between operators and operands ...nor is it required between 
    other separators and that which they separate.*/
    int     x = 0, y = 0, z = 0;  
    x ++; x ++; y = x + x; z = x + y; 

    printf("x: %d, y: %d, z: %d\n", x, y, z);
}

int     main(void) 
{
    /* Every program requires at least one function, called ‘main’. This is 
    where the program begins executing. You do not need to write a declaration 
    or prototype for main, but you do need to define it. */
    /* You can write your main function to have no parameters (that is, as 
    int main (void)), or to accept parameters from the command line. */
	/* The return type for main is always int. You do not have to 
	specify the return type for main, but you can. However, you cannot specify 
	that it has a return type other than int. */
	/* In general, the return value from main indicates the program
    ’s exit status. A value of zero or EXIT SUCCESS indicates success and EXIT 
    FAILURE indicates an error. */
    /* Reaching the } at the end of main without a return, or executing a 
    return statement with no value (that is, return;) are both equivalent. 
    In C89, the effect of this is undefined, but in C99 the effect is 
    equivalent to return 0;.*/
    comment();
    whitespace();
    return (0); 
}