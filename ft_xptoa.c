
#include "ft_printf.h"

static int		x_count(unsigned int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char			*ft_xtoa(unsigned int n, char x)
{
	char	*str;
	int		j;
	char	*alphabet;

	if (x == 'X')
		alphabet = "0123456789ABCDEF";
	else
		alphabet = "0123456789abcdef";
	j = x_count(n);
	str = (char *)malloc(j + 1);
	if (str == NULL)
		return (NULL);
	str[j] = '\0';
	while (j != 0)
	{
		str[j-- - 1] = alphabet[n % 16];
		n = n / 16;
	}
	return (str);
}

static int		p_count(unsigned long long int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char			*ft_ptoa(unsigned long long int n)
{
	char	*str;
	int		j;
	char	*alphabet;

	alphabet = "0123456789abcdef";
	j = p_count(n);
	str = (char *)malloc(j + 1);
	if (str == NULL)
		return (NULL);
	str[j] = '\0';
	while (j != 0)
	{
		str[j-- - 1] = alphabet[n % 16];
		n = n / 16;
	}
	return (str);
}
