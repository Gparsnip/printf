
#include "ft_printf.h"

static int		int_count(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		j;

	j = int_count(n);
	str = (char *)malloc(j + 1);
	if (str == NULL)
		return (NULL);
	str[j] = '\0';
	while (j != 0)
	{
		if (n >= 0)
			str[j-- - 1] = n % 10 + '0';
		else
			str[j-- - 1] = (n % 10 - '0') * -1;
		n = n / 10;
	}
	return (str);
}

static int		u_count(unsigned int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_utoa(unsigned int n)
{
	char	*str;
	int		j;

	j = u_count(n);
	str = (char *)malloc(j + 1);
	if (str == NULL)
		return (NULL);
	str[j] = '\0';
	while (j != 0)
	{
		str[j-- - 1] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

int				max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
