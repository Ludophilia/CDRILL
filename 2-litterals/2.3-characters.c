// CHARACTER CONSTANTS LITTERALS) (p4, GNU C Reference Manual)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

// ASCII Table - Google "ascii table c"

#include <stdio.h>

void	standard_characters(void)
{
    int    i;
    int    std_chars[] = { 'Q', 'z', 'a', 'm', '3' }; /* A character constant is 
	of type int by default (WTF) and is usually a single character enclosed 
	within single quotation marks. */ 
    
	for (i = 0; i < 5; i ++) 
	{
        printf("std_char %d: %c\n", i, std_chars[i]); /* the specifier %c 
		writes a single character. The argument is first converted to unsigned
		char. */
    }
}

void	special_characters(void)
{
    int    i;
    int    spcl_chars[] = { '\'', '\\', '\?', '\n', '\r'}; /* - To represent 
	certain characters like the sigle quotation mark, backlash, question mark, 
	newline, carriage, you'll need to use "escaping sequences" that 
	starts with \. */

    for (i = 0; i < 5; i ++)
	{
        printf("spcl_chars %d: %c\n", i, spcl_chars[i]);
    }
} 

void	octal_number_characters(void)
{
	/* While the length of possible hexadecimal or octal digit strings is 
	unlimited,the number of character constants in any given character set is 
	not. (The much-used extended ASCII character set, for example, has only 256 
	characters in it.) If you try to use an octal or hexadecimal value that is 
	OUTSIDE the range of characters, you will GET a COMPILE TIME ERROR. */
    int    i;
    int    octl_chars[] = { '\101', '\173', '\175', '\157' }; /*  - The octal 
	number escape sequence is the backslash character followed by one, two, 
	or three octal digits. 101 is the octal equivalent of the decimal 65, which 
	is the ASCII character ’A’. Thus, the character constant ’\101’ is the same 
	as the character constant ’A’. */ 

    for (i = 0; i < 4; i ++) 
	{
        printf("octl_chars %d: %c\n", i, octl_chars[i]); /* Those number are
		converted into characters, again, the octal number is just number */
    }
}

void	hex_number_characters(void)
{
	/* While the length of possible hexadecimal or octal digit strings is 
	unlimited,the number of character constants in any given character set is 
	not. (The much-used extended ASCII character set, for example, has only 256 
	characters in it.) If you try to use an octal or hexadecimal value that is 
	OUTSIDE the range of characters, you will GET a COMPILE TIME ERROR. */
    int    i;
    int    hex_chars[] = { '\x65', '\x5B', '\x5E', '\x3d'}; /* The hexadecimal 
	escape sequence is the backslash character, followed by x and an unlimited 
	number of hexadecimal digits (0 to 9, and a to f or A to F). */

    for (i = 0; i < 4; i ++)
	{
        printf("hex_chars %d: %c\n", i, hex_chars[i]);
    }
}

int    main(void)
{
    standard_characters();
    special_characters();
    octal_number_characters();
    hex_number_characters();
	return (0);
}