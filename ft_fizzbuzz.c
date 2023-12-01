// Assignment name  : fizzbuzz
// Expected files   : fizzbuzz.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that prints the numbers from 1 to 100, each separated by a
// newline.

// If the number is a multiple of 3, it prints 'fizz' instead.

// If the number is a multiple of 5, it prints 'buzz' instead.

// If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

// Example:

// $>./fizzbuzz
// 1
// 2
// fizz
// 4
// buzz
// fizz
// 7
// 8
// fizz
// buzz
// 11
// fizz
// 13
// 14
// fizzbuzz
// [...]
// 97
// 98
// fizz
// buzz
// $>

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int number)
{
	char	c;
	if (number <= 9)
	{
		c = number + '0';
		write(1, &c, 1);
	}
	if (number > 9)
	{
		ft_putnbr(number / 10);
		ft_putnbr(number % 10);
	}
}

int	main(void)
{
	int	number;

	number = 1;
	while (number <= 100)
	{
		if ((number % 3 == 0) && (number % 5 == 0))
			ft_putstr("fizzbuzz");
		else if (number % 3 == 0)
			ft_putstr("fizz");
		else if (number % 5 == 0)
			ft_putstr("buzz");
		else
			ft_putnbr(number);
		number++;
		write(1, "\n", 1);
	}
	return (0);
}