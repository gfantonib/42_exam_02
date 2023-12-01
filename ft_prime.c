// Assignment name  : fprime
// Expected files   : fprime.c
// Allowed functions: printf, atoi
// --------------------------------------------------------------------------------

// Write a program that takes a positive int and displays its prime factors on the
// standard output, followed by a newline.

// Factors must be displayed in ascending order and separated by '*', so that
// the expression in the output gives the right result.

// If the number of parameters is not 1, simply display a newline.

// The input, when there is one, will be valid.

// Examples:

// $> ./fprime 225225 | cat -e
// 3*3*5*5*7*11*13$
// $> ./fprime 8333325 | cat -e
// 3*3*5*5*7*11*13*37$
// $> ./fprime 9539 | cat -e
// 9539$
// $> ./fprime 804577 | cat -e
// 804577$
// $> ./fprime 42 | cat -e
// 2*3*7$
// $> ./fprime 1 | cat -e
// 1$
// $> ./fprime | cat -e
// $
// $> ./fprime 42 21 | cat -e
// $

#include <stdio.h>
#include <stdlib.h>

int	ft_is_prime(int	number)
{
	int div;
	if (number == 1 || number == 0)
		return (0);
	if ((number == 2)
		|| (number == 3)
		|| (number == 5)
		|| (number == 7))
		return (1);
	if ((number % 2 == 0)
		|| (number % 3 == 0)
		|| (number % 5 == 0)
		|| (number % 7 == 0))
		return (0);
	div = 11;
	while (div * div <= number)
	{
		if (number % div == 0)
			return (0);
		div++;
	}
	return (1);
}

void	ft_prime(int number)
{
	int	prime;

	prime = 2;
	while (number != 1)
	{
		if (ft_is_prime(prime))
		{
			if (number % prime == 0)
			{
				printf("%d", prime);
				number = number / prime;
				if (number != 1)
					printf("*");
			}
		}
		if (number % prime != 0)
			prime++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	int	number;

	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	number = atoi(argv[1]);
	if (number <= 0)
	{
		printf("\n");
		return (0);
	}
	if (number == 1)
	{
		printf("%d\n", number);
		return (0);
	}
	ft_prime(number);
	return (0);
}