# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/04 15:09:15 by mkaneko           #+#    #+#              #
#    Updated: 2026/05/18 19:25:16 by mkaneko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = libftprintf.a

CC       = cc
CFLAGS   = -Wall -Wextra -Werror

SRCS = \
	ft_printf.c \
	ft_printf_functions.c\
	ft_print_pointer.c
	 
AR       = ar
ARFLAGS  = rcs
RM       = rm -f

OBJS = $(SRCS:.c=.o)

all: $(NAME)


$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY	:	all clean fclean re
