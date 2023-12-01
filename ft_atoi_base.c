// Assignment name  : ft_atoi_base
// Expected files   : ft_atoi_base.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str (base N <= 16)
// to an integer (base 10) and returns it.

// The characters recognized in the input are: 0123456789abcdef
// Those are, of course, to be trimmed according to the requested base. For
// example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

// Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

// Minus signs ('-') are interpreted only if they are the first character of the
// string.

// Your function must be declared as follows:

// int	ft_atoi_base(const char *str, int str_base);

#include <stdio.h>

int	ft_power(int number, int pow)
{
	int	aux;
	if (pow == 0)
		return (1);

	aux = number;
	while (pow > 1)
	{
		number = number * aux;
		pow--;
	}
	return (number);
}

int	ft_strlen(const char *str)
{
	int	i = 0;

	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if ((str[i] < '0')
		|| (str[i] > '9' && str[i] < 'A')
		|| (str[i] > 'F' && str[i] < 'a')
		|| (str[i] > 'f'))
		break ;
		i++;
	}
	return (i);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	len;
	int	expo;
	int	neg;
	int	i;

	len = ft_strlen(str);
	neg = 1;
	result = 0;
	expo = len - 1;
	i = 0;
	if (str[0] == '-')
	{
		i++;
		len++;
		expo--;
		neg = neg * -1;
		//printf("%d\n", i);
	}
	//printf("%d\n", len);
	while (i < len)
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result + ((str[i] - '0') * ft_power(str_base, expo));
		else if (str[i] == 'a' || str[i] == 'A')
			result = result + (10 * ft_power(str_base, expo));
		else if (str[i] == 'b' || str[i] == 'B')
			result = result + (11 * ft_power(str_base, expo));
		else if (str[i] == 'c' || str[i] == 'C')
			result = result + (12 * ft_power(str_base, expo));
		else if (str[i] == 'd' || str[i] == 'D')
			result = result + (13 * ft_power(str_base, expo));
		else if (str[i] == 'e' || str[i] == 'E')
			result = result + (14 * ft_power(str_base, expo));
		else if (str[i] == 'f' || str[i] == 'F')
			result = result + (15 * ft_power(str_base, expo));
		i++;
		expo--;
	}
	return (result * neg);
}

int	main(void)
{
	int		result;
	int		tester = 8;
	char	*str[tester];
	int		base[tester];

	str[0] = "10010";
	str[1] = "2aff5";
	str[2] = "1969";
	str[3] = "abCF";
	str[4] = "-1999";
	str[5] = "-0";
	str[6] = "Cec";
	str[7] = "Ceci permet de decouvrir le fonctionnement de ton ft_atoi_base.";

	base[0] = 2;
	base[1] = 16;
	base[2] = 10;
	base[3] = 16;
	base[4] = 10;
	base[5] = 10;
	base[6] = 16;
	base[7] = 16;
 
	int		i = 0; 
	while (i < tester)
	{
		printf("str: %s, base: %d\n", str[i], base[i]);
		result = ft_atoi_base(str[i], base[i]);
		printf("result = %d\n", result);
		printf("------------------------------------------\n");
		i++;
	}
	return (0);
}