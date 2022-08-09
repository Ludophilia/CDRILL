// TYPEDEF (p11, GNU C Reference Manual)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

// General syntax: typedef [existingtype] [newtypename]
void	typedef_on_primitives_types(void) 
{
    char	ean_barcode0[14]; /* Ex : A EAN Barcode is 13 digits long, so let's 
    define a EanBarCode as an array of 14 char.*/
    char	ean_barcode1[14]; /* instead of redefining the type each time... */
    typedef char	t_eanBarcode[14]; /* the typedef keyword is used to define 
    (or rather, rename) an existing or personalized type. */
    int	   i;

    t_eanBarcode	ean_barcode2 = { "0123456789123" }; /* It's possible to 
	define a shortcut to the type once (like what's been done above); and just
	use it to mean array of 14 characters */
    for (i = 0 ; i < 3 ; i ++)
	{
        printf("ean_barcode2[%i] : %c\n", i, ean_barcode2[i]);
    }
}

void	typedef_on_user_types1(void) 
{
	struct    s_point
	{ 
		int    x;
		int    y; 
	};
    typedef struct s_point	  t_point; /* This constraint disappears when 
	defining a personalized type for this structure type. */
    
    struct s_point	  point1 = { .x = 0, .y = 0 }; /* Declaring structure 
	variables requires us to use the struct s_point2d type... */
	t_point    point2 = { .x = -5, .y = 4 }; /* Thanks to the typedef 
	definition, point is an alias of struct s_point2d. */
    printf("point1: {%i, %i}\n", point1.x, point1.y); 
    printf("point2: {%i, %i}\n", point2.x, point2.y);
}

void	typedef_on_user_types2(void) 
{
	/* An anonymous structure can be renamed during initial declaration this
	way. And another way to rename a structure during declaration, this time 
	the structure has already been named */
    typedef struct
	{
		int	   x; 
		int	   y; 
	}	 t_point; 
    typedef struct    s_figure_rect
	{
		t_point    topLeft;
		t_point    bottomRight; 
	}    t_rectangle; 
	
    t_rectangle    rectangle1 = { {0,0}, {3,3} };
    printf("rectangle1: { {%i, %i}, {%i, %i}}\n", rectangle1.topLeft.x, 
    rectangle1.topLeft.y, rectangle1.bottomRight.x, rectangle1.bottomRight.y);
}

int    main(void)
{
    typedef_on_primitives_types();
    typedef_on_user_types1();
    typedef_on_user_types2();
}