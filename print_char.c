
#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str_n(char *cc, int len)
{
	int	i;

	i = 0;
	while (cc[i] && i != len)
		i += print_char(cc[i]);
	return (i);
}

int	print_str(char *cc)
{
	int	i;

	i = 0;
	while (cc[i])
		i += print_char(cc[i]);
	return (i);
}

int	print_format(int len, int c)
{
	int retrn;

	retrn = 0;
	while (len-- > 0)
	{
		if (c)
			retrn += print_char(' ');
		else
			retrn += print_char('0');
	}
	return (retrn);
}

int	ft_strlen(char *line)
{
	int	i;

	i = 0;
	while (*line++)
		i++;
	return (i);
}
