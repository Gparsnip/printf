
#include "ft_printf.h"

int			ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_isspecifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == '%'
	|| c == 'd' || c == 'u' || c == 'i' || c == 'x'
	|| c == 'X')
		return (1);
	return (0);
}

int			ft_isflag(char c)
{
	if (c == '0' || c == '-' || c == '.' || c == '*')
		return (1);
	return (0);
}

t_format	set_width(t_format format, const char *line, int *i, va_list list)
{
	if (line[*i] == '*')
	{
		format.width = va_arg(list, int);
		if (format.width < 0)
		{
			format.width = -format.width;
			format.minus = 1;
			format.null = 0;
		}
		(*i)++;
	}
	else
	{
		format.width = 0;
		while (ft_isdigit(line[*i]))
		{
			format.width = (format.width * 10) + line[*i] - 48;
			(*i)++;
		}
	}
	return (format);
}

t_format	set_precision(t_format format,
			const char *line, int *i, va_list list)
{
	(*i)++;
	if (line[*i] == '*')
	{
		format.precision = va_arg(list, int);
		if (format.precision < 0)
			format.precision = -1;
		(*i)++;
	}
	else if (ft_isspecifier(line[*i]))
		format.precision = 0;
	else
	{
		format.precision = 0;
		while (ft_isdigit(line[*i]))
		{
			format.precision = (format.precision * 10) + line[*i] - 48;
			(*i)++;
		}
	}
	return (format);
}
