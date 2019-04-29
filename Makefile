# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slisandr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 21:31:09 by slisandr          #+#    #+#              #
#    Updated: 2019/04/22 22:32:16 by slisandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

LIB = libft.a
SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
	  ft_atoi.c ft_itoa.c \
	  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_toupper.c ft_tolower.c \
	  ft_bzero.c ft_memset.c ft_memcpy.c ft_strdup.c ft_strcmp.c ft_strncmp.c ft_strchr.c ft_strrchr.c \
	  ft_strstr.c ft_strcpy.c ft_strncpy.c ft_strlcpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strnstr.c ft_strlen.c
OBJ = $(SRC:.c=.o)

TEST_FILE = /Users/slisandr/libft/test
EXEC = program

.PHONY: all clean fclean re norm

all: $(LIB)

$(LIB): $(OBJ)
	@ ar rc $(LIB) $(OBJ)
	@ ranlib $(LIB)
$(OBJ): $(SRC)
	@ gcc $(CFLAGS) -I. -c $(SRC)


clean:
	@ rm -f $(OBJ)
fclean: clean
	@ rm -f $(LIB)
re: fclean all exec



exec: $(LIB)
	@ gcc -I. main.c -L . -lft -lbsd -o $(EXEC)
norm:
	@ norminette $(SRC) libft.h
