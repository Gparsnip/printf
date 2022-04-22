
#include "ft_printf.h"

static unsigned int	print_u(t_format format, char *char_u, int len)
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
	if ((format.precision != 0 && *char_u == '0') || *char_u != '0')
		counter += print_str(char_u);
	if ((format.minus && counter < (unsigned int)format.width)
	|| *char_u == '0')
		counter += print_format(format.width - counter, 1);
	return (counter);
}

int					ft_print_u(t_format format, va_list list)
{
	unsigned int	u;
	int				len;
	char			*char_u;
	int				retrn;

	u = va_arg(list, unsigned int);
	char_u = ft_utoa(u);
	len = ft_strlen(char_u);
	if (!((format.precision != 0 && !u) || u))
		len = 0;
	retrn = print_u(format, char_u, len);
	free(char_u);
	return (retrn);
}
