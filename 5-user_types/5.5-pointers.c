// POINTERS - (p23, GNU C Reference Manual)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

/* Pointers hold MEMORY ADDRESSES of stored CONSTANTS or VARIABLES. For any 
DATA TYPE, including both primitive types and custom types, you CAN CREATE a 
POINTER that holds the MEMORY ADDRESS of an INSTANCE of that type. */

void    declaring_pointers(void)
{
    /* You declare a pointer by specifying a name for it and a data type. The 
	data type indicates of what type of variable the pointer will hold memory 
	addresses.
	To declare a pointer, include the indirection operator (*) before the 
	identifier. White space is not significant around the indirection operator.
	Be careful, though: when declaring multiple pointers in the same 
	statement, you must explicitly declare each as a pointer, using the 
	indirection operator. */
    int    *p1; 
    int*    p2; 
    int    *foo, *bar; 
    int    *baz, quux; // NOTE - a pointer and an integer variable.
}

void    initializing_pointers(void)
{
	/* You can initialize a pointer when you first declare it by specifying a 
	variable address to store in it. Note the use of the address operator (&),
	used to get the memory address of a variable.
	The value stored in a pointer is an int or hex number (ex : 138200396 or 
	0x304fd151c): a location within the computer’s memory space.
    If you are so inclined, you can assign pointer values explicitly using 
	literal integers, casting them to the appropriate pointer type. However, we
	do not recommend this practice unless you need to have extremely fine-tuned
	control over what is stored in memory, and you know exactly what you are
	doing. It would be all too easy to accidentally overwrite something that
	you did not intend to. Most uses of this technique are also non-portable.
	It is important to note that if you do not initialize a pointer with the
	address of some other existing object, it points nowhere in particular and
	will LIKELY make your program crash if you use it (formally, this kind of
	thing is called undefined behavior). */
    int    i; 
    int    *ip = &i;
    int    *jp;

    printf("*ip: %i or %p\n", ip, ip); 
	printf("*jp: %p\n", jp); 
}

void    pointers_access(void)
{
    /* After you declare a pointer, DO NOT use the indirection operator (*) with
	the pointer’s name when assigning it a new address to point to. On the 
	contrary, that would CHANGE the VALUE of the VARIABLE that the POINTS TO 
	(j1), not the value of the pointer itself.
	In the next example, the pointer ip is initialised with the address of "i".
	A line later ip holds the address of "j". One more line after that, 'j' 
	holds the address of 'i', which shouldn't be possible as j is just a normal
	variable, not a pointer (hence why gcc raises a warning). */
    int    i;
	int    j;
    int    *ip = &i;

    ip = &j;
    *ip = &i;
}

void    pointers_to_unions(void)
{
	/* You can create a pointer to a union type just as you can a pointer to a 
	primitive data type. 
	You can access the members of a union variable through a pointer, but you 
	can’t use the regular member access operator (.) anymore. Instead, you have
	to use the indirect member access operator (->). */
    union     u_numbers
	{ 
		int    i; 
		float    f; 
	};
    union u_numbers    foo = { .i = 4 };
    union u_numbers    *p_foo = &foo; 

    p_foo->i = 450;
    printf("foo: {%i, %.2f}\n", foo.i, foo.f);
}

void    pointers_to_structures(void)
{
    /* You can access the members of a structure variable through a pointer,
	but you can’t use the regular member access operator anymore. Instead, you
	have to use the indirect member access operator (->). */
    struct    s_fish
	{
        float    length;
		float    weight;
    };
    struct s_fish    salmon = { 4.3, 5.8 }; 
    struct s_fish    *p_salmon = &salmon; 

    printf("salmon: {%.2f, %.2f}\n", salmon.length, salmon.weight);
    p_salmon->length = 5.1;
    p_salmon->length = 6.2;
    printf("salmon: {%.2f, %.2f}\n", salmon.length, salmon.weight);
}

void    on_linked_lists(void)
{
    /* Strctures and pointers to structures are commonly used to build linked
	lists. A singly linked list is a data structure which consists of a series
	of nodes usually represented by a structure. This structure is comprised of
	one or more data related members and one other member, usually a pointer,
	meant to give the address to the next node. The first node is usually a
	pointer to the first structure realated to data. */
    struct s_linked_list_node
	{
        int    x;
        struct s_linked_list_node    *nextNode;
    };
    struct s_linked_list_node    *head_node;
    struct s_linked_list_node    node0 = { .x = 0, .nextNode = NULL };
	
    head_node = &node0;
	printf("head: %p\n", head_node);
    printf("node0: {%i, %p}\n", node0.x, node0.nextNode);
}

int    main(void) 
{
    initializing_pointers();
    pointers_to_unions();
    pointers_to_structures();
	on_linked_lists();
    return (0);
}