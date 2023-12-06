// Assignment name  : reverse_bits
// Expected files   : reverse_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that takes a byte, reverses it, bit by bit (like the
// example) and returns the result.

// Your function must be declared as follows:

// unsigned char	reverse_bits(unsigned char octet);

// Example:

//   1 byte
// _____________
//  0010  0110
// 	 ||
// 	 \/
//  0110  0100

#include <unistd.h>
#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned int	res;

	i = 8;
	while (i--)
	{
		res = (2 * res) + (octet % 2);
		octet = octet / 2;
	}
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

	octet = 10;
	print_bits(octet);
	printf("\n");
	res = reverse_bits(octet);
	print_bits(res);
	printf("\n");
	return (0);
}