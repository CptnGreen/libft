# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slisandr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 21:31:09 by slisandr          #+#    #+#              #
#    Updated: 2019/05/05 16:55:19 by ak               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = libft.a
SRC = ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_atoi.c ft_itoa.c \
	  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_toupper.c ft_tolower.c \
	  ft_bzero.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_strdup.c \
	  ft_strcmp.c ft_strncmp.c ft_memcmp.c \
	  ft_strchr.c ft_strrchr.c \
	  ft_memchr.c \
	  ft_strstr.c ft_strnstr.c \
	  ft_strcpy.c ft_strncpy.c ft_strlcpy.c \
	  ft_strcat.c ft_strncat.c ft_strlcat.c \
	  ft_strlen.c \
	  ft_memalloc.c ft_strnew.c \
	  ft_memdel.c ft_strdel.c ft_strclr.c \
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	  ft_strequ.c ft_strnequ.c \
	  ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	  ft_lstnew.c ft_lstdelone.c ft_lstadd.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)

TEST_FILE = /Users/slisandr/libft/test
EXEC = program

.PHONY: all clean fclean re norm

all: $(NAME)

$(NAME): $(OBJ)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)
$(OBJ): $(SRC)
	@ gcc $(CFLAGS) -I. -c $(SRC)


clean:
	@ rm -f $(OBJ)
fclean: clean
	@ rm -f $(NAME)
re: fclean all



exec: $(NAME)
	@ gcc -I. main.c -L . -lft -lbsd -o $(EXEC) # -lbsd
norm:
	@ norminette $(SRC) libft.h

so: $(OBJ)
	@ gcc -shared -o libft.so $(OBJ)
