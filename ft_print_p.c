
#include "ft_printf.h"

static unsigned int	print_p(t_format format, char *char_p, int len)
{
	unsigned int	counter;

	counter = 0;
	if (((!format.minus && !format.null) || (format.null
	&& format.precision > 0
	&& format.precision < format.width) || (!format.minus
	&& format.precision == 0 && format.width > len)))
		counter += print_format(format.width - max(len,
		max(format.precision, 0)) - 2, 1);
	if (!(format.precision == -1 && *char_p == '0'))
		counter += print_str("0x");
	if ((format.null && format.precision < len))
		counter += print_format(format.width - max(len + counter,
		format.precision), 0);
	if (format.precision > len)
		counter += print_format(format.precision - len, 0);
	if (format.precision != 0 || *char_p != '0')
		counter += print_str(char_p);
	if ((format.minus && counter < (unsigned int)format.width)
	|| *char_p == '0')
		counter += print_format(format.width - counter, 1);
	return (counter);
}

int					ft_print_p(t_format format, va_list list)
{
	unsigned long long int	p;
	int						len;
	char					*char_p;
	int						retrn;

	p = va_arg(list, unsigned long long int);
	char_p = ft_ptoa(p);
	if (!p && format.precision == -1)
	{
		free(char_p);
		char_p = "0x0";
	}
	len = ft_strlen(char_p);
	if (format.precision == 0 && !p)
		len = 0;
	else if (format.precision == -1 && !p)
		len = 1;
	retrn = print_p(format, char_p, len);
	if (!(!p && format.precision == -1))
		free(char_p);
	return (retrn);
}
