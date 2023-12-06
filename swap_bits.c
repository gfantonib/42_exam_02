// Assignment name  : swap_bits
// Expected files   : swap_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that takes a byte, swaps its halves (like the example) and
// returns the result.

// Your function must be declared as follows:

// unsigned char	swap_bits(unsigned char octet);

// Example:

//   1 byte
// _____________
//  0100 | 0001
//      \ /
//      / \
//  0001 | 0100

#include <stdio.h>
#include <unistd.h>

unsigned char	swap_bits(unsigned char octet)
{
	unsigned char left;
	unsigned char right;
	unsigned char res;

	left = octet << 4; 
	right = octet >> 4;
	res = left | right;

	return (res);
}

void	print_bits(unsigned char octet)
{
	int	bit;
	int	i;

	i = 8;
	while (i--)
	{
		bit = ((octet >> i) & 1) + '0';
		write (1, &bit, 1);
	}
}
int	main(void)
{
	unsigned char	octet;
	unsigned char	res;

	octet = 22;
	print_bits(octet);
	printf("\n");
	res = swap_bits(octet);
	print_bits(res);
	printf("\n");
	return (0);
}
