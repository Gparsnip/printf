
#include "ft_printf.h"

int			ft_print_c(t_format format, va_list list)
{
	int		counter;

	counter = 0;
	if (format.minus)
		counter += print_char((char)va_arg(list, int));
	counter += print_format(format.width - 1, 1);
	if (!(format.minus))
		counter += print_char((char)va_arg(list, int));
	return (counter);
}

int			ft_print_s(t_format format, va_list list)
{
	int		counter;
	char	*s;
	int		len;

	s = va_arg(list, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	counter = 0;
	if (len > format.precision && format.precision >= 0)
		len = format.precision;
	if (format.width < format.precision)
		format.precision = 0;
	if (format.width > len && !format.minus && format.width < format.precision)
		counter += print_format(format.width - len, 0);
	if (format.width > len && !format.minus
	&& format.width >= format.precision && !format.null)
		counter += print_format(format.width - len, 1);
	if (format.width > len && !format.minus
	&& format.width >= format.precision && format.null)
		counter += print_format(format.width - len, 0);
	counter += print_str_n(s, len);
	if (format.width > len && format.minus)
		counter += print_format(format.width - len, 1);
	return (counter);
}

int			ft_print_procent(t_format format)
{
	int		counter;

	counter = 0;
	if (format.width > 1 && !format.minus && !format.null)
		counter += print_format(format.width - 1, 1);
	if (format.width > 1 && !format.minus && format.null)
		counter += print_format(format.width - 1, 0);
	counter += print_char('%');
	if (format.width > 1 && format.minus)
		counter += print_format(format.width - 1, 1);
	return (counter);
}
