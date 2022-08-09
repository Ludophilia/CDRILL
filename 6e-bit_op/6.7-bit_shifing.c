// BIT SHIFTING OPERATIONS (p33)
// https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf

#include <stdio.h>

void    lshifting(void)
{
	/* You use the left-shift operator << to shift its first operand’s bits to 
	the left. The second operand denotes the number of bit places to shift. 
	Bits shifted off the left side of the value are discarded; new bits added 
	on the right side will all be 0. A value lshifted n times is multiplied
	by 2^n */
	char    n;
	
	n = 47; 
	printf("n = %i\n", n); // 0010 1111
	printf("n << 2 = %i\n\n", n << 2); // 1011 1100 or 47*2^2 or 188
}

void    rshifting(void)
{
	/* Similarly, you use the right-shift operator >> to shift its first 
	operand’s bits to the right. 
	Bits shifted off the right side are discarded; new bits added on the left 
	side are usually 0, but if the first operand is a signed negative value, 
	then the added bits will be either 0 or whatever value was previously in 
	the leftmost bit position.
	A value rshifted n times is multiplied by 2^-n and truncated down to the 
	lowest closest integer if the resulting number is not an integer */
	char    n;
	char    m;

	n = 47;
	m = -47;
	printf("n = %i, m = %i\n", n, m); // 0010 1111 in both cases
	printf("n >> 2 = %i, m >> 2 = %i\n\n", n >> 2, m >> 2); /* 0000 1011 or 
	47*2^-2 or 11 (11,75 exp) ; m = -12 */
}

void    rlshifting_gotcha(void)
{
	/* For both << and >>, if the second operand is greater than the bit-width 
	of the first operand, or the second operand is negative, the behavior is 
	undefined.*/
	char    n;
	char    m;

	n = 47;
	m = 47;
	printf("n = %i, m = %i\n", n, m); // 0010 1111 in both cases
	printf("n << 10 = %i\n", n << 10); /* supposed to be 0000 0000 but weirdly 
	enough gaves 48128 or 47*2^10, the right answer! How can a char (8bit) store
	such a long number */
	printf("m >> 2 = %i\n\n", m >> -1); /* 0001 0111 or 23 (23,5 trunc dwn) but 0 
	is returned. */
}

void    rlshifting_hack(void)
{
	/* You can use the shift operators to perform a variety of interesting 
	hacks. For example, given a date with the day of the month numbered as d,
	the month numbered as m, and the year y, you can store the entire date in
	a single number x. 
	x is a 32 bits integer. y, m, d are stored on 15, 4 and 5 bits respectively,
	so 23 bits if they are stored one after the other. We start to add the year
	to x (14 bits), then shift the values on x 4 times to the left to make 4 
	empty bits that will be used to store m (4 bits) into x via an addition. 
	We shift the resulting value again 5 times to the left to make 5 empty bits
	that we'll use to store d (5 bits) into x via an other addition. */
	/* To then extract d, m and y from x, many tricks then come into play : 
		- Extracting d : in x, the last 5 bits are used to store d. What if x 
		was expressed as the sum of 5 bits numbers (32 units) such as (x = x1 
		+ x2 ... + xn) ? Most numbers obviously would worth 32, leaving one 
		member with a value from 0 to 31, this member being the day d. One way 
		to calculte that is to use the modulo operator as seen below. Another 
		and simpler way of extracting x is to use bit masking. Buy doing a 
		conjuction of x and a number that hides any non interesting bits by 
		multiplying them by 0, it's possible to extract x.
		- Extracting m : The two techniques above are usable. The modulo 
		technique relies on splitting the value x on units that have same bit 
		length as what's being looked for. As the month m is coded on 4 bits, 
		x has to be divided into chunks of 4 bits or 16 units. The other 
		technique is bitmasking. m is 4 bits so x has to be multiplied by 0xF to 
		remove non significant bits. To avoid miscalculations, x has to be 
		shifted by 5 to the right so m occupy the 4 first spots of x.
		- Extracting y : The simplest thing to do is to shift x to the right by
		9 spots (4 of m, 5 of d). */
	int    d;
	int    m;
	int    y;
	int    x;

	d = 12;
	m = 6;
	y = 1983;
	x = (((y << 4) + m) << 5) + d;
	
	printf("x = %i or Ox%x\n", x, x);
	printf("d1 = x %% 32 = %i\n", x % 32);
	printf("d2 = x & 0x1F = %i\n", x & 0x1F);
	printf("m1 = (x >> 5) %% 16 = %i\n", (x >> 5) % 16);
	printf("m2 = (x >> 5) & 0xF = %i\n", (x >> 5) & 0xF);
	printf("y = x >> (5 + 4) = %i\n", x >> (5 + 4));
}

int    main(void)
{
	lshifting();
	rshifting();
	rlshifting_gotcha();
	rlshifting_hack();
}