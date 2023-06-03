# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 16:26:51 by ramoussa          #+#    #+#              #
#    Updated: 2023/06/03 14:11:12 by ramoussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft
CFLAGS = -Wall -Wextra -Werror
LIBFT_LIB = $(LIBFT)/libft.a

SRCS = ft_printf.c numeric_types.c string_types.c hex_types.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

$(NAME): libft $(OBJS)
	mv $(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_LIB)

re: fclean all

.PHONY: all libft clean fclean re