# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 21:36:19 by imorina           #+#    #+#              #
#    Updated: 2021/12/21 17:54:09 by imorina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf.c 		\
				ft_print_char.c 	\
				ft_print_str.c 		\
				ft_print_ptr.c 		\
				ft_print_hex.c 		\
				ft_print_hex_long.c \
				ft_print_int.c 		\
				ft_itoa_unsigned.c 

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)
