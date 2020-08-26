# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcyprien </var/mail/dcyprien>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 19:51:49 by dcyprien          #+#    #+#              #
#    Updated: 2020/08/18 21:56:26 by dcyprien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	libft/ft_strlen.c				\
		libft/ft_isalpha.c				\
		libft/ft_isdigit.c				\
		libft/ft_atoi.c					\
		libft/ft_strdup.c				\
		libft/ft_substr.c				\
		libft/ft_itoa.c					\
		libft/ft_putchar_fd.c			\
		libft/ft_putstr_fd.c			\
		libft/ft_putnbr_fd.c			\
		libft/ft_printf.c				\
		libft/ft_initialize.c			\
		libft/ft_setflags.c				\
		libft/ft_print.c				\
		libft/ft_set_stars.c			\
		libft/ft_print_padding.c		\
		libft/ft_size.c					\
		libft/ft_set_padding.c 			\
		libft/ft_print_next.c			\
		libft/ft_itoa_unsigned.c		\
		libft/ft_set_padding_next.c		\
		libft/ft_set_padding_null.c		\
		libft/ft_print_precision.c 		\
		libft/ft_print_padding_next.c	\
		libft/ft_memmove.c				\
		libft/ft_memcpy.c				

NAME	=	libftprintf.a

CC		=	gcc 

CFLAGS	=	-Wall -Wextra -Werror

CCLIB	=	ar

LIBFLAGS	=	rc

OBJS	=	${SRCS:.c=.o}

OBJSBONUS	=	${SRCSBONUS:.c=.o}

RM		=	rm -f


$(NAME):	${OBJS}
	${CCLIB} ${LIBFLAGS} ${NAME} ${OBJS}

all:		${NAME}

clean:		
	${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
	${RM} ${NAME}

bonus:		${OBJS}
	${CC} ${CFLAGS} -c ${SRCSBONUS}
	${CCLIB} ${NAME} ${OBJS} ${OBJSBONUS}

re:			fclean all

noflag:		
	${CC} ${SRCS} -o libftprintf.a

.PHONY = all clean fclean re bonus noflag

