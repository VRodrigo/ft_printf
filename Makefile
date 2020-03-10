SRCS	= adj_prec_width.c data_display.c display_c.c display_fill.c display_i.c display_p.c display_perc.c display_s.c display_u.c display_x.c flags.c flag_mz.c ft_printf.c
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra
.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C ./libft/
			cp libft/libft.a ${NAME}
			ar rc  ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}
clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}
re:			fclean all
