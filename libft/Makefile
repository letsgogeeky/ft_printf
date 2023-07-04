# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 18:55:03 by ramoussa          #+#    #+#              #
#    Updated: 2023/03/28 20:47:17 by ramoussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
SOURCE = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c  \
		ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c  \
		ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c  \
		ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
		ft_strlcat.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS_SOURCE = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SOURCE:%.c=%.o)
BONUS_OBJ = $(BONUS_SOURCE:%.c=%.o)

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SOURCE)
	ar rcs $(NAME) $(OBJ)

bonus:
	gcc -c -Wall -Wextra -Werror $(BONUS_SOURCE)
	ar rcs $(NAME) $(BONUS_OBJ)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all