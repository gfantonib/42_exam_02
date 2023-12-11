// Assignment name  : ft_strrev
// Expected files   : ft_strrev.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that reverses (in-place) a string.

// It must return its parameter.

// Your function must be declared as follows:

// char    *ft_strrev(char *str);

#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char *ft_strrev(char *str)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	char	aux[len--];
	i = 0;
	while (len > -1)
	{
		aux[i] = str[len]; 
		len--;
		i++;
	}
	aux[i] = '\0';
	i = 0;
	while (str[i])
	{
		str[i] = aux[i];
		i++;
	}
	return (str);
}

int	main(void)
{
	char src[] = "Melvin";
	char *dest;

	printf("%s\n", src);
	dest = ft_strrev(src);
	printf("%s\n", dest);
}