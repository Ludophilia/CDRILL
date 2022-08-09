// ARRAYS (p19)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

void	array_example(int length)
{
    int	   array_of_integers[10]; /* You declare an array by specifying the 
	data type for its elements, its name, and the number of elements it can 
	store. For standard C code, the number of elements in an array must be 
	positive. As a GNU extension, the number of elements can be as small 
	as zero. */
    int	   flexible_array[length]; /* Another GNU extension allows you to 
	declare an array size using variables, rather than only constants. // For
	example, here is a function definition that declares an array using its 
	parameter as the number of elements. */
    int	   unsized_array[] = { 0, 1, 2, 3, 4 }; /* If you initialize every 
	element of an array, then you do not have to specify its size; its size is 
	determined by the number of elements you initialize. */

    /* array_of_integers[10] = { 0, 1, 2 }; */ /* NOTE - IT'S NOT POSSIBLE TO 
	ASSIGN AN ARRAY TO A VARIABLE AFTER ITS INITIALIZATION. */
}

void	array_initialization(void)
{
    int	   array_of_integers[10];
    int	   an_array_fully_initd[5] = { 0, 1, 2, 3, 4 }; /* You can initialize 
	the elements in an array when you declare it by listing the initializing 
	values, separated by commas, in a set of braces. */
    int	   an_array_partly_initd[5] = { 0, 1, 2 }; /* You don’t have to 
	explicitly initialize all of the array elements. For example, this code 
	initializes the first three elements as specified, and then initializes 
	the last two elements to a DEFAULT VALUE of ZERO. */

    printf("array_of_integers[1] : %i\n\n", array_of_integers[1]);
}

void	undeclared_array_size(void)
{
    int	   unsized_array1[] = { 0, 1, 2, 3, 4 }; /* Again, if you initialize 
	every element of an array, then you do not have to specify its size; its 
	size is determined by the number of elements you initialize. */
    int	   unsized_array2[] = { 0, 1, 2, [99] = 99 }; /* Array of 100 - (
	0, 1, 2, ..., 99). Alternately, if you specify which elements to initialize,
	then the size of the array is equal to the highest element number 
	initialized, plus one. */
}

void	out_of_order_array_ini(void)
{
    int	   o3_array_ini1[5] = { [2] 5, [4] 9 }; /* (0 0 5 0 9) - When using 
	either ISO C99, or C89 with GNU extensions, you can initialize array 
	elements out of order, by specifying which array indices to initialize.
	To do this, include the array index in brackets */
    int	   o3_array_ini2[5] = { [2] = 5, [4] = 9 }; /* (0 0 5 0 9) and 
	optionally the assignment operator, before the value. */
}

void	in_bulk_array_ini(void)
{
    int	   array_in_bulk_ini[100] = { [0 ... 9] = 1, [10 ... 98] = 2, 3 }; /* 
	When using GNU extensions, you can initialize a range of elements to 
	the same value, by specifying the first and last indices, in the form 
	[first ... last]. // This initializes elements [0 through 9] to 1, elements 
	[10 through 98] to 2, and element 99 to 3. You also could explicitly write 
	[99] = 3. Also, notice that you MUST HAVE SPACES on BOTH SIDES of the 
	‘...’ */
}

void	accessing_arrays(void)
{
    int i;
    int arr_of_ints[] = { [3] = 3 }; 
    struct s_point { int x ; int y; }; 
    struct s_point arr_of_spoints[] = { {0,0}, {0, 1} };

    printf("arr_of_ints[0] : %i \n", arr_of_ints[0]); /* 0 - You can access 
	the elements of an array by specifying the array name, followed by the 
	element index, enclosed in brackets. Just remember that the array elements 
	are numbered starting with zero... */
    for (i = 0; i < (sizeof(arr_of_spoints) / sizeof(arr_of_spoints[0])); i ++) 
	{
        printf("arr_of_spoints[%i] : {%i, %i}\n\n", i, 
		arr_of_spoints[i].x, arr_of_spoints[i].y);
    }
}

void	accessing_nd_arrays(void)
{
    int	   i;
    int	   d2_int_array1[2][3]; /* You can make multidimensional arrays, or 
	“arrays of arrays”. You do this by adding an extra set of brackets and 
	array lengths for every additional dimension you want your array to have. */
    int    d2_int_array2[2][3] = { {1, 2, 3}, {4, 5, 6} };

    d2_int_array1[0][0] = 1; /* Multidimensional array elements are accessed by
	specifying the desired index of both dimensions: */
    d2_int_array1[0][1] = 2;
    d2_int_array1[0][2] = 3;
    d2_int_array1[1][0] = 4;
    d2_int_array1[1][1] = 5;
    d2_int_array1[1][2] = 6;
    for (i = 0; i < sizeof(d2_int_array1) / sizeof(d2_int_array1[0]); i ++)
	{
        printf("d2_int_array1[%i] - {%i, %i, %i}\n\n", i,
		d2_int_array1[i][0], d2_int_array1[i][1], d2_int_array1[i][2]); /* 
		i0 - {1, 2, 3} */
    }
}

void	arrays_as_strings(void)
{
    unsigned char	 arr_of_str[] = "bruh"; /* You can use an array of 
	characters to hold a string. The array may be built of either signed or 
	unsigned characters. */
    char	fixed_arr_of_str1[26] = ""; /* When you declare the array, you can 
	specify the number of elements it will have. That number will be the 
	MAXIMUM number of characters that should be in the string, including the
	null character (\0) used to end the string. */
    char	fixed_arr_of_str2[26]; /* If you choose to specify the number of 
	elements of the array, you do not have to initialize the array when you
	declare it. */
    char	arr_of_str_with_impl_size[] = "Erroneous assumption my brutha."; /* 
	(32 characters) Alternately, you can simply initialize the array to a value,
	and its size will then be exactly large enough to hold whatever string
	you used to initialize it. */
}

void	init_arrays_as_strings(void)
{    
    char	arr_as_str1[] = { 'h', 'e', 'l', 'l', 'o', '\0' }; /* You can 
	specify of comma-delimited list of characters enclosed in braces. The 
	null character \0 is included at the end of the string, even when not 
	explicitly stated. // Note that if you initialize a string using an array
	of individual characters, then the null character is not guaranteed to be
	épresent. It might be, but such an occurrence would be one of chance, and
	should not be relied upon. */
    char	arr_as_str2[] = "world"; /* you can specify a string literal
	enclosed in double quotation marks. Here again, The null character \0 
	is included at the end of the string, even when not explicitly stated. */
}

void	modify_arrays_as_strings(void)
{
    char	arr_as_str3[26] = "custard"; 

    /* arr_as_str3 = "gimme banana"; */ /* After initialization, you CANNOT 
	assign a new string literal to an array using the assignment operator. 
	However, there are functions in the GNU C library that perform operations
	(including copy) on string arrays. */
    printf("%s\n", arr_as_str3);
    arr_as_str3[0] = 'b'; /* You can also change one character at a time, by 
	accessing individual string elements as you would any other array */
    arr_as_str3[1] = 'a';
    printf("%s\n\n", arr_as_str3);
}

void	limits_arr_as_string(void)
{
    char	arr_as_str4[4] = "Y'a bon!"; /* It is possible for you to 
	explicitly state the number of elements in the array, and then initialize
	it using a string that has more characters than there are elements in 
	the array. // OBVIOUSLY, This is NOT a good thing. // The larger string 
	will not override the previously specified size of the array, and 
	you will get a compile-time warning. */

    printf("%s\n\n", arr_as_str4); /* Y'a p�N // Since the original array size
	remains, any part of the string that exceeds that original size is being 
	written to a memory location that was not allocated for it and reading
	errors can occur. */
}

void	array_of_unions(void)
{
    int	   i;
    union	 u_numbers { int i; float f; }; /* You can create an array of a 
	union type just as you can an array of a primitive data type. That example 
	creates a 3-element array of union numbers variables called 
	array_of_unumbers. */
    union	 u_numbers array_of_unumbers[3] = { {3}, {4}, {5} }; /* The 
	additional inner grouping braces are optional. */

    for (i = 0; i < 3; i ++) 
	{
        printf("array_of_unumbers[%i] : %i\n\n", i, 
		array_of_unumbers[i].i); /* After initialization, you can still access 
		the union members in the array using the member access operator. 
		You put the array name and element number (enclosed in brackets) to 
		the left of the operator, and the member name to the right. */
    }
}

void	array_of_structures(void)
{
    int	   i;
    struct	  s_point { int x; int y; }; 
    struct	  s_point arr_of_spoints1[3] = { {2, 3}, {4, 5}, {6, 7} }; /* You 
	can create an array of a structure type just as you can an array of a 
	primitive data type. As with initializing structures which contain 
	structure members, the additional inner grouping braces are optional. */
    struct	  s_point arr_of_spoints2[3] = { {2}, {4, 5}, {6, 7} } ; /* But,
	if you use the additional braces, then you can partially initialize some 
	of the structures in the array, and fully initialize others. // In that
	example, the first element of the array has only its x member initialized.
	Because of the grouping braces, the value 4 is assigned to the x member 
	of the second array element, not to the y member of the first element,
	as would be the case without the grouping braces. */

    arr_of_spoints2[0].y = 3; /* After initialization, you can still access 
	the structure members in the array using the member access operator. */
    for (i = 0; i < 3; i ++)
	{
        printf("arr_of_spoints2[%i] : {%i, %i}\n\n", i, 
		arr_of_spoints2[i].x, arr_of_spoints2[i].y);
    }   
}

int	   main(void)
{
    array_initialization();
    accessing_arrays();
    accessing_nd_arrays();
    modify_arrays_as_strings();
    limits_arr_as_string();
    array_of_unions();
    array_of_structures();
    return (0);
}