# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 20:10:32 by imorina           #+#    #+#              #
#    Updated: 2021/11/29 15:32:18 by imorina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** 

NAME	=		libft.a
CCFLAGS =		-Wall -Werror -Wextra

SRCS	=		ft_isalpha.c	ft_isdigit.c	ft_isalnum.c		 \
			   	ft_isascii.c	ft_isprint.c	ft_strlen.c			 \
				ft_memset.c		ft_bzero.c		ft_memcpy.c			 \
				ft_memmove.c	ft_strlcpy.c	ft_atoi.c			 \
				ft_strlcat.c	ft_toupper.c	ft_tolower.c		 \
				ft_strrchr.c	ft_strchr.c		ft_strncmp.c		 \
				ft_memchr.c		ft_memcmp.c		ft_strnstr.c		 \
				ft_calloc.c		ft_split.c		ft_strdup.c			 \
				ft_substr.c		ft_strjoin.c	ft_strtrim.c	   	 \
				ft_itoa.c		ft_strmapi.c	ft_striteri.c	     \
				ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c		 \
				ft_putnbr_fd.c

SRCS_BONUS =	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	\
				ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c\
				ft_lstclear.c


OBJS	=		${SRCS:.c=.o}
OBJS_BONUS	=	${SRCS_BONUS:.c=.o }

all: $(NAME)

$(NAME): ${OBJS}
	ar rcs $@ $^

bonus: ${OBJS_BONUS}
	ar rcs ${NAME} $^

%.o : %.c
	gcc ${CCFLAGS} -o $@ -c $<

clean_bonus:
	rm -f ${OBJS_BONUS}

clean:
	rm -f ${OBJS} ${OBJS_BONUS}

fclean: clean
	rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re
