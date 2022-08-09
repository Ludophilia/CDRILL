// STRUCTURES (p15)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

void	struct_example(void)
{
    /* You define a structure using the struct keyword followed by the 
	declarations of the structure’s members, enclosed in braces. You should 
	also include a name for the structure in between the struct keyword and the
	opening brace. This is optional, but if you leave it out, you can’t refer 
	to that structure data type later on (without a typedef of course). */
	/* You declare each member of a structure just as you would normally 
	declare a variable, using the data type followed by one or more variable
	names separated by commas, and ending with a semicolon. */
	/* Structures (and unions) may contain instances of other structures and
	unions, but of course not themselves. It is possible for a structure or
	union type to contain a field which is a pointer to the same type. */
	struct    s_point
	{ 
        int    x;
		int    y;
    };
    struct    s_rectangle
	{
        struct s_point    origin;
    };
}

void    struct_vars_decl(void)
{
    /* Just as enums and unions, you can declare variables of a structure type 
	when you define the structure type by putting the variable names after
	the closing brace of the structure definition, but before the final 
	semicolon. You can declare more than one such variable by separating the 
	names with commas. */
	/* You can also declare variables of a structure type after defining the 
	structure by using the struct keyword and the name you gave the structure
	type, followed by one or more variable names separated by commas. */
    struct    s_point
	{
        int    x;
		int    y;
    }    point1, point2; 
    struct s_point    point3, point4;
}

void    struct_vars_init(void)
{
    /* You can initialize the members of a structure type to have certain 
	(default) values when you declare structure variables. 
	If you DO NOT initialize a structure variable, the effect depends on whether
	it has static storage or not (auto, extern...). If it is, members with 
	integral types are initialized with 0 and pointer members are initialized 
	to NULL; otherwise, the value of the structure’s members is indeterminate.
    One way to initialize a structure is to specify the values in a set of 
	braces and separated by commas. Those values are assigned to the structure 
	members in the same order that the members are declared in the structure in
	definition. 
	Another way to initialize the members is to specify the name of the member
	to initialize. This way, you can initialize the members in any order you 
	like, and even leave some of them uninitialized.
	The first (and preferred) method is available in C99 and as a C89 extension
	in GCC. You can also omit the period and use a colon (:) instead of ‘=’, 
	though this is a GNU C extension. */
	struct    s_point
	{ 
        int    x;
		int    y;
    };

    struct s_point    point5 = { 5, 10 };
    struct s_point    point6 = { .y = 1, .x = 0 };
    struct s_point    point7 = { y: 0, x: 1 };
}

void    struct_vars_init2(void) 
{
	/* You can also initialize the structure variable’s members when you declare
	the variable during the structure definition. You can also initialize fewer
	than all of a structure variable’s members */
	/* The rectangle structure below consist of two point structure variables.
	While initializing a variable of this type, we'll use an extra set of braces
	surrounding the members that belong to the s_point structure variables. 
	However, those extra braces are not necessary; they just make the code 
	easier to read. */
	struct    s_point
	{ 
        int    x;
		int    y;
    }    point8 = { 5, 10 }, point9 = { 0 }; 
    struct    s_rectangle
	{ 
        struct s_point    top_left, bottom_right;
    };

    struct s_rectangle    rectangle1 = { {0, 0}, {3, 1} };
}

void    accessing_structures(void)
{
    /* You can access the members of a structure variable using the member
	access operator. You put the name of the structure variable on the 
	left side of the operator, and the name of the member on the right side.
	You can also access the members of a structure variable which is itself
	a member of a structure variable. */
	struct    s_point
	{ 
        int    x;
		int    y;
    }; 
    struct    s_rectangle
	{ 
        struct s_point    top_left, bottom_right;
    };
	struct s_point    point10;
	struct s_rectangle    rectangle2;

	point10.x = 10;
	point10.y = -10;
    rectangle2.top_left.x = 0; 
    rectangle2.top_left.y = 5;
    rectangle2.bottom_right.x = 10;
    rectangle2.bottom_right.y = 0;
    printf("point10: {%i, %i}\n", point10.x, point10.y);
    printf("rectangle2 - {{%i, %i}, {%i, %i}}\n\n", rectangle2.top_left.x, 
	rectangle2.top_left.y, rectangle2.bottom_right.x, rectangle2.
	bottom_right.y);
}

void    bit_fields(void)
{
    /* You can create structures with integer members of nonstandard sizes, 
	called bit fields. Those non-standard sizes can be set by specifying an 
	integer member as usual, and inserting a colon and the number of bits that 
	the member should occupy in between the member’s name and the semicolon.
	'Card' below is a structure type with two bit fields, suit and face_value,
	which take up 2 bits and 4 bits, respectively. suit can hold values from 
	0 to 3, and face_value, 0 to 15. Notice that these bit fields were declared 
	as unsigned int; had they been signed integers, then their ranges would have
	been from −2 to 1 and −8 to 7, respectively. */
    struct    s_card
	{
        unsigned int    suit: 2; 
        unsigned int    face_value: 4; 
    };
	/* Bit fields can be specified without a name in order to control which 
	actual bits within the containing unit are used. However, the effect of this
	is not very portable and it is rarely useful. 
	They are also used for padding.
	You can also specify a bit field of size 0, which indicates that subsequent
	bit fields (not further bit fields) should be packed into the unit 
	containing the previous bit field. This is likewise not generally useful. 
	NOTE - You may not take the address of a bit field with the address
	operator & (see Section 3.10 [Pointer Operators], page 35).
	A chessboard is 8 by 8 squares. As log2(8) is 3, 3 bits is enough to store 
	one axis of this board, 6 bits for both axis, and 2 bits of padding for
	optimization purposes; for 8 bits in total. */
    struct    s_chessboard_pos
	{
        unsigned int    x: 3;
        unsigned int    : 2; 
        unsigned int    y: 3;
        unsigned int    : 0; 
    };
}
    
void    structures_sizes(void)
{
    /* The size of a structure type is equal to the sum of the size of all of
	its members, possibly including padding to cause the structure type to
	align to a particular byte boundary.
	The details vary depending on your computer platform, but it would not be
	atypical to see structures padded to align on four or eight-byte boundaries.
	This is done in order to speed up memory accesses of instances of the 
	structure type. */
	/* As a GNU extension, GCC allows structures with no members. Such 
	structures have zero size. If you wish to explicitly omit padding from 
	your structure types (which may, in turn, decrease the speed of structure 
	memory accesses), then GCC provides multiple methods of turning packing 
	off. The quick and easy method is to use the -fpack-struct compiler option. 
    For more details on omitting packing, please see the GCC manual which 
	corresponds to your version of the compiler. */
	struct    s_point
	{ 
        int    x;
		int    y;
    }; 
    struct    s_chessboard_pos
	{
        unsigned int    x: 3;
        unsigned int    y: 3;
    };
    struct    s_mu
	{
	}; 

	struct s_point    point11 = { 0, 0 };
	struct s_chessboard_pos    cb_pos = { 0, 0 };
	struct s_mu   mu;
    printf("point11: %lu bits\n", 8 * sizeof    (point11)); // 64 bits.
    printf("cb_pos: %lu bits\n", 8 * sizeof    (cb_pos)); // 32 bits.
    printf("mu: %lu bits\n", 8 * sizeof    (mu));  // 0. 
}

int    main(void)
{
    accessing_structures();
    structures_sizes();
    return (0);
}