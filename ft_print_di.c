
#include "ft_printf.h"

static int	print_di(t_format format, int minus, char *char_di, int len)
{
	int counter;

	counter = 0;
	if ((!format.minus && !format.null) || (format.null
	&& format.precision > 0 &&
	format.precision < format.width) || (!format.minus
	&& format.precision == 0 && format.width > len))
		counter += print_format(format.width - max(len + minus,
		max(format.precision, 0) + minus), 1);
	if (minus)
		counter += print_char('-');
	if (format.null && format.precision < len)
		counter += print_format(format.width - max(len + counter,
		format.precision), 0);
	if (format.precision > len)
		counter += print_format(format.precision - len, 0);
	if ((format.precision != 0 && *char_di == '0') || *char_di != '0')
		counter += print_str(char_di);
	if ((format.minus && counter < format.width) || *char_di == '0')
		counter += print_format(format.width - counter, 1);
	return (counter);
}

int			ft_print_di(t_format format, va_list list)
{
	int		di;
	int		len;
	char	*char_di;
	int		retrn;
	int		minus;

	di = va_arg(list, int);
	char_di = ft_itoa(di);
	len = ft_strlen(char_di);
	if (!((format.precision != 0 && !di) || di))
		len = 0;
	minus = 0;
	if (di < 0)
		minus++;
	retrn = print_di(format, minus, char_di, len);
	free(char_di);
	return (retrn);
}
