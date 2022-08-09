// MEMBER ACCESS EXPRESSIONS (p38)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>
#include <stdlib.h>

void    member_access_op(void)
{
	/* You can use the member access operator . to access the members of a 
	structure or union variable. You put the name of the structure variable on
	the left side of the operator, and the name of the member on the right 
	side. */
	struct    s_point
	{
		int    x;
		int    y;
	};
	struct s_point    first_point = { .x = 0, .y = 5 };

	printf("first_point : x: %i, y: %i\n", first_point.x, first_point.y);
}

void   indirect_member_access_op(void)
{
	/* You can also access the members of a structure or union variable via a 
	pointer by using the indirect member access operator ->. x->y is equivalent
	to (*x).y. */
	struct    s_fish
	{
		int    length;
		int    weight;
	};
	struct s_fish    *salmon_p;
	
	salmon_p = NULL;
	salmon_p = (struct s_fish *)malloc(sizeof(struct s_fish));
	salmon_p->length = 3;
	(*salmon_p).weight = 9;
	printf("salmon : length: %i, weight: %i\n", (*salmon_p).length, 
	salmon_p->weight);
	free(salmon_p);
}

int    main(void)
{
	member_access_op();
	indirect_member_access_op();
}