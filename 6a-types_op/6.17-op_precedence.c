// OPERATOR PRECEDENCE (p40)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

int    dbl(int x)
{
	int    rs;
	
	rs = 2 * x;
	return (rs);
}

void    intro_precedence(void)
{
	/* When an expression contains multiple operators, such as 3 + 2 * dbl(10), 
	the operators are grouped based on rules of precedence.
	For instance, the meaning of that expression is to call the function dbl,
	multiply the result by 2, then add that result to 3.
	That’s what the C rules of operator precedence determine for this 
	expression.
	The following functions contains a list of types of expressions, presented 
	in order of highest precedence first. Sometimes two or more operators have
	equal precedence; all those operators are applied from left to right unless
	stated otherwise. */
	printf("lv0: 3 + 2 * dbl(10) = %i\n\n", 3 + 2 * dbl(10)); /* 
	43 = 3 + 2 * 20 */
}

void    level1_fsmba(void)
{
	/* 1. Function calls, array subscripting, and membership access operator 
	expressions. */
	int    first_int[5] = { 0, 1, 2, 3, 4 };
	struct   s_randos { int a; int b;};

	struct s_randos    ex = { .a = 10, .b = 11 };

	printf("lv1: -ex.b + --first_int[3] * dbl(10) = %i\n\n", -ex.b +
		--first_int[3] * dbl(10)); // -11 + 2 * 20 = 29
}

void    level2_unaries(void)
{
	/* 2. Unary operators, including logical negation, bitwise complement, 
	increment, decrement, unary positive, unary negative, indirection
	operator (*), address operator (&), type casting, and sizeof expressions.
	When several unary operators are consecutive, the later ones are nested 
	within the earlier ones: !-x means !(-x). */
	int    a = 4;
	int    *p = &a;

	printf("lv2: !0 * dbl(0x1) / --*p + (int)10.0 %% sizeof(int) = %lu\n\n", 
		!0 * dbl(0x1) / --*p + (int)10.0 % sizeof(int)); // 1 * 2 / 3 + 2 = 2
}

void    level3_mdm(void)
{
	/* 3. Multiplication, division, and modular division expressions. */
	int    i = 4;

	printf("lv3: (int)45.667 * !1 + ++i / 0x01 = %i\n\n", 
		(int)45.667 * !1 + i++ / 0x02); // 45 * 0 + 5 / 2 = 2
}

void    level4_as(void)
{
	/* 4. Addition and subtraction expressions. */
	printf("lv4: 10 + 0x04 >> 2 %% 0x01 << 2 = %i\n\n", 
		10 + 0x04 >> 2 % 0x01 << 2); // 14 >> 0x0 << 2 // 14 << 2 = 0x38 =
		// 14*2**2 = 56
}

void    level5_bts(void)
{
	/* 5. Bitwise shifting expressions. */
	printf("lv5: 10 - 0x04 >> 2 > 0 + 0xB = %i\n\n", 
		10 - 0x04 >> 2 > 0 + 0xB); // 6 >> 2 > 11 // 1 > 11 = 0
}

void    level6_gtlt(void)
{
	/* 6. Greater-than, less-than, greater-than-or-equal-to, and 
	less-than-or-equal-to expressions. */
	printf("lv6: 0x1 >> 1 < 0xC == 12 >= 0b1100 != 1 = %i\n\n", 
		0x1 >> 1 < 0xC == 12 >= 0b1100 != 1); /* 0 < 12 == 12 >= 12 != 1 // 
		1 == 1 != 1 // 0 */
}

void    level7_eq(void)
{
	/* 7. Equal-to and not-equal-to expressions. */
	printf("lv7: 0b0000 == '0' > '\\0' & 0xF = %i\n\n", 
		0b0000 == '0' > '\0' & 0xF); /* 0 == 1 & 15 <=> 0 & 15 <=> 0 */ 
}

void    level8_bwand(void)
{
	/* 8. Bitwise AND expressions. */
	printf("lv8: '\\5' ^ 0b1010 & 15 != 0xF = %i\n\n", 
	'\x5' ^ 0b1010 & 15 != 0xF); /* 5 ^ 10 & 0 <=> 5 ^ 0 <=> 5 */
}

void    level9_bwxor(void)
{
	/* 9. Bitwise exclusive OR expressions. */
	printf("lv9: 0b1110 | 01 ^ 0xA & '\\xF'= %i\n\n", 
	0b1110 | 01 ^ 0xA & '\\xF'); /* 14 | 1 ^ 10 <=> 14 | 11 <=> 15 */
}

void    level10_bwor(void)
{
	/* 10. Bitwise inclusive OR expressions. */
	// bwxor (^) bwxor (|) logand (&&)
	printf("lv10: 69 && 0xB ^ 0x5 | '3' - '0' = %i\n\n",
	69 && 0xB ^ 0x5 | '3' - '0'); /* 69 && 15 | 3 <=> 69 && 15 <=> 1 */
}

void    level11_logand(void)
{
	/* 11. Logical AND expressions. */
	printf("\n\n");
}

void    level12_logor(void)
{
	/* 12. Logical OR expressions. */
	printf("\n\n");
}

void    level13_terns(void)
{
	/* 13. Conditional expressions (using ?:). When used as subexpressions, 
	these are evaluated right to left. */
	printf("\n\n");
}

void    level14_assign(void)
{
	/* 14.  All assignment expressions, including compound assignment. When 
	multiple assign- ment statements appear as subexpressions in a single 
	larger expression, they are eval- uated right to left. */
	printf("\n\n");
}

void    level15_commas(void)
{
	/* 15.  Commas operators expressions. */
	printf("\n\n");
}

void    use_parentheses(void)
{
	/* The above list is somewhat dry and is apparently straightforward, but it 
	does hide some pitfalls. Take this example:
	foo = *p++;
	Here p is incremented as a side effect of the expression, but foo takes the
	value of *(p++) rather than (*p)++, since the unary operators bind right to
	left. There are other examples of potential surprises lurking behind the C
	precedence table. For this reason if there is the slightest risk of the
	reader misunderstanding the meaning of the program, you should use
	parentheses to make your meaning clear. */
}

int    main(void)
{
	intro_precedence();
	level1_fsmba();
	level2_unaries();
	level3_mdm();
	level4_as();
	level5_bts();
	level6_gtlt();
	level7_eq();
	level8_bwand();
	level9_bwxor();
	level10_bwor();
}