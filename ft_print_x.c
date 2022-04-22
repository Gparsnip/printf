
#include "ft_printf.h"

static unsigned int	print_x(t_format format, char *char_x, int len)
{
	unsigned int counter;

	counter = 0;
	if ((!format.minus && !format.null) || (format.null
	&& format.precision > 0 && format.precision < format.width)
	|| (!format.minus
	&& format.precision == 0 && format.width > len))
		counter += print_format(format.width - max(len,
		max(format.precision, 0)), 1);
	if (format.null && format.precision < len)
		counter += print_format(format.width - max(len + counter,
		format.precision), 0);
	if (format.precision > len)
		counter += print_format(format.precision - len, 0);
	if ((format.precision != 0 && *char_x == '0') || *char_x != '0')
		counter += print_str(char_x);
	if ((format.minus && counter < (unsigned int)format.width)
	|| *char_x == '0')
		counter += print_format(format.width - counter, 1);
	return (counter);
}

int					ft_print_x(t_format format, va_list list, char xx)
{
	unsigned int	x;
	int				len;
	char			*char_x;
	int				retrn;

	x = va_arg(list, unsigned int);
	char_x = ft_xtoa(x, xx);
	len = ft_strlen(char_x);
	if (!((format.precision != 0 && !x) || x))
		len = 0;
	retrn = print_x(format, char_x, len);
	free(char_x);
	return (retrn);
}
