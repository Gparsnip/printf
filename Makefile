
NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
OPTION = -c -I $(HEADER)
 SRCS =		ft_printf.c	\
 			ft_diutoa.c	\
			ft_is.c	\
			ft_print_csproc.c	\
			ft_print_di.c	\
			ft_print_p.c	\
			ft_print_u.c	\
			ft_print_x.c	\
			ft_xptoa.c	\
			print_char.c

OBJS =		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(OPTION) $(SRCS)
			ar rcs $(NAME) $(OBJS)
			ranlib $(NAME)

clean:
				rm -f $(OBJS)

fclean:		clean
				rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
