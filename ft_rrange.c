// Assignment name  : ft_rrange
// Expected files   : ft_rrange.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_rrange(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at end and end at start (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 3, 2 and 1
// - With (-1, 2) you will return an array containing 2, 1, 0 and -1.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing -3, -2, -1 and 0.

#include <stdio.h>
#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int				*array = 0;
	int				len;
	unsigned long	i;

	len = (start - end);
	if (len == 0)
	{
		array = malloc(sizeof(int) * 1);
		array[0] = end;
		return (array);
	}
	if (len < 0)
		len = (-1) * len;
	len++;
	array = malloc(sizeof(int) * len);
	i = 0;
	if (end < start)
	{
		while (end <= start)
		{
			array[i] = end;
			end++;
			i++;
		}
	}
	else if (end > start)
	{
		while (end >= start)
		{
			array[i] = end;
			end--;
			i++;
		}
	}
	return (array);
}

int	main(int argc, char **argv)
{
	int	*array = 0;
	int	start;
	int	end;
	int	len;
	int	i;

	if (argc != 3)
	{
		printf("\n");
		return (0);
	}
	start = atoi(argv[1]);
	end = atoi(argv[2]);
	len = abs(start - end);
	array = ft_rrange(start, end);
	i = 0;
	while (i <= len)
	{
		printf("%d, ", array[i]);
		i++;
	}
	printf("\n");
	return (0);
}