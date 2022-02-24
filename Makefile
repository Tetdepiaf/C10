SRCS			= main.c

OBJS			= ${SRCS:.c=.o}

NAME			= ft_display_file

RM			= rm -f

CFLAGS			= -Wall -Wextra -Werror

${NAME}:		${OBJS}
			gcc -o ${NAME} ${OBJS} ${CFLAGS}

all:			${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

