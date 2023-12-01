// Assignment name  : ft_range
// Expected files   : ft_range.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_range(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at start and end at end (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 1, 2 and 3.
// - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing 0, -1, -2 and -3.

#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
	int	*result;
	int aux;
	int	i;

	aux = start;
	if (end >= start)
	{
		i = 1;
		while (start < end)
		{
			start++;
			i++;
		}
		result = (int *)malloc((sizeof(int) * i) + 1);
		i = 0;
		while (aux <= end)
		{
			result[i] = aux;
			aux++;
			i++;
		}
	}
	else
	{
		i = 1;
		while (end < start)
		{
			start--;
			i++;
		}
		result = (int *)malloc((sizeof(int) * i) + 1);
		i = 0;
		while (end <= aux)
		{
			result[i] = aux;
			aux--;
			i++;
		}

	}
	return (result);
}

int	main(void)
{
	int	start = 0;
	int	end = 1;
	int	*result;

	result = ft_range(start, end);

	int i = 0;
	while (i <= abs(end - start))
	{
		printf("%d, ", result[i]);
		i++;
	}
	return (0);
}