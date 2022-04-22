
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_format
{
	int			minus;
	int			null;
	int			width;
	int			precision;
}				t_format;

int				ft_printf(const char *line, ...);
int				print_char(char c);
int				print_str_n(char *cc, int len);
int				ft_isdigit(char c);
int				ft_isflag(char c);
int				ft_isspecifier(char c);
t_format		set_width(t_format format,
				const char *line, int *i, va_list list);
t_format		set_precision(t_format format,
				const char *line, int *i, va_list list);
int				ft_print_di(t_format format, va_list list);
int				print_str(char *cc);
char			*ft_itoa(int n);
int				print_format(int len, int c);
int				max(int a, int b);
int				ft_strlen(char *line);
char			*ft_utoa(unsigned int n);
int				ft_print_u(t_format format, va_list list);
char			*ft_xtoa(unsigned int n, char x);
int				ft_print_x(t_format format, va_list list, char xx);
char			*ft_ptoa(unsigned long long int n);
int				ft_print_p(t_format format, va_list list);
int				ft_print_c(t_format format, va_list list);
int				ft_print_s(t_format format, va_list list);
int				ft_print_procent(t_format format);

#endif
