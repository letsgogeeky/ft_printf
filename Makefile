# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 16:26:51 by ramoussa          #+#    #+#              #
#    Updated: 2023/04/19 18:59:40 by ramoussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft
LIBFT_LIB = $(LIBFT)/libft.a

SRCS = ft_printf.c

OBJS = $(SRCS:%.c=%.o)

all: libft $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_LIB)

re: fclean all

.PHONY: all libft clean fclean re