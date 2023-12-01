// Assignment name  : union
// Expected files   : union.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in either one of the strings.

// The display will be in the order characters appear in the command line, and
// will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Example:

// $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// zpadintoqefwjy$
// $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6vewg4thras$
// $>./union "rien" "cette phrase ne cache rien" | cat -e
// rienct phas$
// $>./union | cat -e
// $
// $>
// $>./union "rien" | cat -e
// $
// $>

#include <unistd.h>
int	ft_char_ok(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_char_n_ok(char *str, char c, int n)
{
	int i;

	i = 0;
	while (n)
	{
		if (str[i] == c)
			return (0);
		i++;
		n--;
	}
	return (1);
}

void	ft_union(char *str1, char *str2)
{
	int	i;

	i = 0;
	write(1, &str1[i], 1);
	i++;
	while (str1[i])
	{
		if (ft_char_n_ok(str1, str1[i], i))
			write(1, &str1[i], 1);
		i++;
	}
	i = 0;
	while (str2[i])
	{
		if ((ft_char_ok(str1, str2[i]))
			&& (ft_char_n_ok(str2, str2[i], i)))
			write(1, &str2[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}

