// Assignment name  : rostring
// Expected files   : rostring.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays this string after rotating it
// one word to the left.

// Thus, the first word becomes the last, and others stay in the same order.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.

// Words will be separated by only one space in the output.

// If there's less than one argument, the program displays \n.

// Example:

// $>./rostring "abc   " | cat -e
// abc$
// $>
// $>./rostring "Que la      lumiere soit et la lumiere fut"
// la lumiere soit et la lumiere fut Que
// $>
// $>./rostring "     AkjhZ zLKIJz , 23y"
// zLKIJz , 23y AkjhZ
// $>
// $>./rostring "first" "2" "11000000"
// first
// $>
// $>./rostring | cat -e
// $
// $>

#include <unistd.h>

void	ft_rostring(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	while (str[i])
	{
		if (str[i] != ' ')
			write(1, &str[i], 1);
		if ((str[i] != ' ' && str[i + 1] == ' ')
			|| (str[i] != ' ' && str[i + 1] == '\0'))
			write(1, " ", 1);
		i++;
	}
	i = 0;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	while (str[i] != ' ' && str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}