// Assignment name  : ft_itoa
// Expected files   : ft_itoa.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes an int and converts it to a null-terminated string.
// The function returns the result in a char array that you must allocate.

// Your function must be declared as follows:

// char	*ft_itoa(int nbr);

#include <stdlib.h>
#include <stdio.h>

int	ft_count_algarism(int nbr)
{
	int	size;

	if (nbr < 0)
		nbr = nbr * -1;
	size = 0;
	while (nbr > 0) 
	{
		nbr = nbr / 10;
		size = size + 1;
	}
	return (size);
}

char	*ft_itoa(int nbr)
{
	char	*number_str;
	int		len;

	if (nbr == -2147483648)
		return ("-2147483648");
	len = ft_count_algarism(nbr);
	if (nbr < 0)
		len++;
	number_str = malloc((sizeof(char) * len) + 1);
	if (nbr == 0)
	{
		number_str[0] = '0';
		return (number_str);
	}
	if (nbr < 0)
	{
		number_str[0] = '-';
		nbr = nbr * -1;
	}
	number_str[len] = '\0';
	len--;
	while (nbr > 0)
	{
		number_str[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (number_str);
}

int	main(void)
{
	int		number_int;
	char	*number_str;

	number_int = -2147483648;
	number_str = ft_itoa(number_int);
	printf("%s\n", number_str);
	return (0);
}