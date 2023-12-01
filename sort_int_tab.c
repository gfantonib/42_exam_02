// Assignment name  : sort_int_tab
// Expected files   : sort_int_tab.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write the following function:

// void sort_int_tab(int *tab, unsigned int size);

// It must sort (in-place) the 'tab' int array, that contains exactly 'size'
// members, in ascending order.

// Doubles must be preserved.

// Input is always coherent.
#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	aux;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			aux = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = aux;
			i = -1;
		}
		i++;
	}
	// i = 0;
	// while(i < size)
	// {
	// 	printf("%d ", tab[i]);
	// 	i++;
	// }
	// printf("\n");
}


int	main(void)
{
	int	i;
	int	size = 10;
	int	tab[size];

	tab[0] = 10; 
	tab[1] = 9;
	tab[2] = 8;
	tab[3] = 7;
	tab[4] = 6;
	tab[5] = 5;
	tab[6] = 4;
	tab[7] = 3;
	tab[8] = 2;
	tab[9] = 1;

	i = 0;
	while(i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	sort_int_tab(tab, size);
	return (0);
}