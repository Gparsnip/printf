
#include "ft_printf.h"

static int		check_format(const char *line, int i)
{
	while (line[i])
	{
		if (ft_isspecifier(line[i]))
			return (1);
		i++;
	}
	return (0);
}

static t_format	initialize_format(void)
{
	t_format format;

	format.minus = 0;
	format.null = 0;
	format.width = 0;
	format.precision = -1;
	return (format);
}

static int		ft_final(t_format format, va_list list, char spec)
{
	int	retrn;

	retrn = 0;
	if (spec == 'd' || spec == 'i')
		retrn = ft_print_di(format, list);
	if (spec == 'u')
		retrn = ft_print_u(format, list);
	if (spec == 'x' || spec == 'X')
		retrn = ft_print_x(format, list, spec);
	if (spec == 'p')
		retrn = ft_print_p(format, list);
	if (spec == 'c')
		retrn = ft_print_c(format, list);
	if (spec == 's')
		retrn = ft_print_s(format, list);
	if (spec == '%')
		retrn = ft_print_procent(format);
	return (retrn);
}

static int		print_specifier(va_list list, int *i, const char *line)
{
	t_format	format;

	format = initialize_format();
	while (line[*i])
	{
		if (!ft_isspecifier(line[*i])
		&& !ft_isdigit(line[*i]) && !ft_isflag(line[*i]))
			return (0);
		if (line[*i] == '-' && ++(*i))
		{
			format.minus = 1;
			format.null = 0;
		}
		if (line[*i] == '0' && !format.minus && ++(*i))
			format.null = 1;
		if (line[*i] == '*' || ft_isdigit(line[*i]))
			format = set_width(format, line, i, list);
		if (line[*i] == '.')
			format = set_precision(format, line, i, list);
		if (ft_isspecifier(line[*i]))
			return (ft_final(format, list, line[++(*i) - 1]));
	}
	return (0);
}

int				ft_printf(const char *line, ...)
{
	int		return_value;
	va_list	list;
	int		i;

	va_start(list, line);
	i = 0;
	return_value = 0;
	while (line[i])
	{
		if (line[i] == '%' && check_format(line, i))
		{
			i++;
			return_value += print_specifier(list, &i, line);
		}
		else
			return_value += print_char(line[i++]);
	}
	va_end(list);
	line = NULL;
	return (return_value);
}
