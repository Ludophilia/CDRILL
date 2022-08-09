// STRING CONSTANTS - (p5, GNU C Reference Manual)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

void	basic_string(void)
{
    const char    basic_str[] = "Hello everyone"; /* A string constant is a 
	sequence of zero or more characters, digits, and escape sequences enclosed 
	within double quotation marks. A string constant is of type “array of 
	characters”. All string constants contain a null termination character 
	(\0) as their last character. // The null termination character lets
	 string-processing functions know where the string ends. */
    
	printf("%s\n", &basic_str[0]); /* The conversion specifier %s writes a
	character string. The argument must be a pointer to the initial element of 
	an array of characters. */
    printf("No difference: %s\n", basic_str); // but does it have to?
}

void	about_double_quotes(void)
{
    char	almost_forbidden_str[] = "\"hello world with double quotes\""; /* A 
	string CANNOT contain double quotation marks, as double quotation marks are 
	used to enclose the string. To include the double quotation mark character 
	in a string, use the \" escape sequence. */

    printf("%s\n", almost_forbidden_str);
}

void	multiline_string(void)
{
    char	multiline_str[] = "Today's special is a pastrami sandwich on rye \
	bread with a potato knish and a cherry soda."; /* If a string is too long 
	to fit on one line, you can use a backslash \ to break it up onto separate 
	lines. */

    printf("%s\n", multiline_str);
}

void	string_concatenation(void)
{
    char	conct_str[] = "this will " "be concanated " "into a single "
	"string btw"; /* Adjacent string constants are concatenated (combined) into 
	one string, with the null termination character added to the end of the 
	final concatenated string. */

    printf("%s\n", conct_str);
}

void	adjacent_strings(void)
{
    char	adjacent_str[] = "Tomorrow's special is a corned beef sandwich on "
    "pumpernickel bread with a kasha knish and seltzer water."; /* Adjacent 
	strings are automatically concatenated, so you can also have string 
	constants span multiple lines by writing them as separate, adjacent, 
	strings. */
    
	printf("%s\n", &adjacent_str[0]);
}

void	new_line(void)
{
    printf ("new line after potato: potato\nknish\n"); /* To insert a new_line 
	character into the string, so that when the string is printed it will be 
	printed on two different lines, you can use the new_line escape sequence 
	‘\n’. */
}

int    main(void)
{
    basic_string();
    string_concatenation();
    about_double_quotes();
    multiline_string();
    adjacent_strings();
    new_line();
    return (0);
}

