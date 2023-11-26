# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiamant <mdiamant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 09:28:12 by mdiamant          #+#    #+#              #
#    Updated: 2023/03/10 10:47:33 by mdiamant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	printf.c \
			printf_utils.c

OBJS		= ${SRCS:.c=.o}


NAME		= libftprintf.a
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror



all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}
			ranlib $(NAME)

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJSBONUS}
fclean:		clean
			${RM} ${NAME}
re:			fclean all
