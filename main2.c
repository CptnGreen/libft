/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:48:17 by slisandr          #+#    #+#             */
/*   Updated: 2019/04/16 04:37:57 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#define FILENAME "/Users/slisandr/libft/test"

int		main(int ac, char **av)
{
	char	*tmp1;
	char	*tmp2;
	int		num;
	int		fd;

	fd = open(FILENAME, O_WRONLY);
	if (fd == -1)
		printf("Failed to open test file.\n");
	printf("\n--------------------------------\n");
	printf("WELCOME TO LIBFT CHECK PROGRAM!");
	printf("\n--------------------------------\n");
	if (ac > 1)
	{
		if (fd != -1)
		{
			ft_putstr_fd("hello world\n", fd);
			ft_putchar('\n');
		}
		printf("ft_putchar(av[1][0]):\n");
		ft_putchar(av[1][0]);
		printf("\n--------------------------------\n");
		printf("or_isascii(\'%c\') = %2d , or_isprint(\'%c\') = %2d , or_isalnum(\'%c\') = %2d , or_isalpha(\'%c\') = %2d , or_isdigit(\'%c\') = %2d\n", \
				av[1][0], isascii(av[1][0]), av[1][0], isprint(av[1][0]), av[1][0], isalnum(av[1][0]), av[1][0], isalpha(av[1][0]), av[1][0], isdigit(av[1][0]));
		printf("ft_isascii(\'%c\') = %2d , ft_isprint(\'%c\') = %2d , ft_isalnum(\'%c\') = %2d , ft_isalpha(\'%c\') = %2d , ft_isdigit(\'%c\') = %2d\n", \
				av[1][0], ft_isascii(av[1][0]), av[1][0], ft_isprint(av[1][0]), av[1][0], ft_isalnum(av[1][0]), av[1][0], ft_isalpha(av[1][0]), av[1][0], ft_isdigit(av[1][0]));
		printf("ft_isascii(%c): %c\n", av[1][0], (isascii(av[1][0]) == ft_isascii(av[1][0])) ? ('+') : ('-');
		printf("\n--------------------------------\n");
		printf("or_toupper(\'%c\') = %2c , or_tolower(\'%c\') = %2c\n", av[1][0], toupper(av[1][0]), av[1][0], tolower(av[1][0]));
		printf("ft_toupper(\'%c\') = %2c , ft_tolower(\'%c\') = %2c", av[1][0], ft_toupper(av[1][0]), av[1][0], ft_tolower(av[1][0]));
		printf("\n--------------------------------\n");
		printf("ft_putstr(\"%s\"):\n", av[1]);
		ft_putstr(av[1]);
		printf("\n--------------------------------\n");
		printf("or_strlen(\"%s\") = %zu\n", av[1], strlen(av[1]));
		printf("ft_strlen(\"%s\") = %zu", av[1], ft_strlen(av[1]));
		printf("\n--------------------------------\n");
		printf("or_strdup(\"%s\") = %s\n", av[1], strdup(av[1]));
		printf("ft_strdup(\"%s\") = %s", av[1], ft_strdup(av[1]));
		printf("\n--------------------------------\n");
	}
	if (ac > 2)
	{
		printf("or_strchr(\"%s\", \'%c\') = %s\n", \
				av[1], av[2][0], strchr(av[1], av[2][0]));
		printf("ft_strchr(\"%s\", \'%c\') = %s", \
				av[1], av[2][0], ft_strchr(av[1], av[2][0]));
		printf("\n--------------------------------\n");
		printf("or_strrchr(\"%s\", \'%c\') = %s\n", \
				av[1], av[2][0], strrchr(av[1], av[2][0]));
		printf("ft_strrchr(\"%s\", \'%c\') = %s", \
				av[1], av[2][0], ft_strrchr(av[1], av[2][0]));
		printf("\n--------------------------------\n");
		tmp1 = strdup(av[1]);
		printf("or_strcpy(\"%s\", \"%s\") = ", tmp1, av[2]);
		printf("%s\n", strcpy(tmp1, av[2]));
		free(tmp1);
		tmp1 = strdup(av[1]);
		printf("ft_strcpy(\"%s\", \"%s\") = ", tmp1, av[2]);
		printf("%s", ft_strcpy(tmp1, av[2]));
		free(tmp1);
		printf("\n--------------------------------\n");
		printf("or_strcmp(\"%s\", \"%s\") = %d\n", \
				av[1], av[2], strcmp(av[1], av[2]));
		printf("ft_strcmp(\"%s\", \"%s\") = %d", \
				av[1], av[2], ft_strcmp(av[1], av[2]));
		printf("\n--------------------------------\n");
		printf("or_strstr(\"%s\", \"%s\") = %s\n", \
				av[1], av[2], strstr(av[1], av[2]));
		printf("ft_strstr(\"%s\", \"%s\") = %s", \
				av[1], av[2], ft_strstr(av[1], av[2]));
		printf("\n--------------------------------\n");
		tmp1 = strdup(av[1]);
		tmp2 = strdup(av[2]);
		printf("or_strcat(\"%s\", \"%s\") = %s\n", \
				av[1], av[2], strcat(tmp1, tmp2));
		free(tmp1);
		free(tmp2);
		tmp1 = strdup(av[1]);
		tmp2 = strdup(av[2]);
		printf("ft_strcat(\"%s\", \"%s\") = %s", \
				av[1], av[2], ft_strcat(tmp1, tmp2));
		free(tmp1);
		free(tmp2);
		printf("\n--------------------------------\n");
	}
	if (ac > 3)
	{
		if (fd != -1)
			ft_putnbr_fd(100, fd);
		num = atoi(av[3]);
		if (num >= 0)
		{
			tmp1 = strdup(av[1]);
			printf("or_strncpy(\"%s\", \"%s\", %d) = ", tmp1, av[2], num);
			printf("%s\n", strncpy(tmp1, av[2], num));
			free(tmp1);

			tmp1 = strdup(av[1]);
			printf("ft_strncpy(\"%s\", \"%s\", %d) = ", tmp1, av[2], num);
			printf("%s", ft_strncpy(tmp1, av[2], num));
			free(tmp1);

			printf("\n--------------------------------\n");

			printf("or_strncmp(\"%s\", \"%s\", %d) = %d\n", \
					av[1], av[2], num, strncmp(av[1], av[2], num));

			printf("ft_strncmp(\"%s\", \"%s\", %d) = %d", \
					av[1], av[2], num, ft_strncmp(av[1], av[2], num));

			printf("\n--------------------------------\n");

			printf("or_strnstr(\"%s\", \"%s\", %d) = %s\n", \
					av[1], av[2], num, strnstr(av[1], av[2], num));

			printf("ft_strnstr(\"%s\", \"%s\", %d) = %s", \
					av[1], av[2], num, ft_strnstr(av[1], av[2], num));

			printf("\n--------------------------------\n");

			tmp1 = strdup(av[1]);
			printf("or_bzero(\"%s\", %d) = ", tmp1, num);
			bzero(tmp1, num);
			printf("%s, ", tmp1);
			free(tmp1);

			tmp1 = strdup(av[1]);
			printf("or_memset(\"%s\", \'%c\', %d) = %s\n", av[1], av[2][0], num, memset(tmp1, av[2][0], num)); 
			free(tmp1);

			tmp1 = strdup(av[1]);
			printf("ft_bzero(\"%s\", %d) = ", tmp1, num);
			ft_bzero(tmp1, num);
			printf("%s, ", tmp1);
			free(tmp1);

			tmp1 = strdup(av[1]);
			printf("ft_memset(\"%s\", \'%c\', %d) = %s", av[1], av[2][0], num, ft_memset(tmp1, av[2][0], num)); 
			free(tmp1);

			printf("\n--------------------------------\n");
			tmp1 = strdup(av[1]);
			tmp2 = strdup(av[2]);
			printf("or_memcpy(\"%s\", \"%s\", %d) = %s\n", \
					av[1], av[2], num, memcpy(tmp1, tmp2, num));
			free(tmp1);
			free(tmp2);
			tmp1 = strdup(av[1]);
			tmp2 = strdup(av[2]);
			printf("ft_memcpy(\"%s\", \"%s\", %d) = %s", \
					av[1], av[2], num,  ft_memcpy(tmp1, tmp2, num));
			free(tmp1);
			free(tmp2);
			printf("\n--------------------------------\n");
			tmp1 = strdup(av[1]);
			tmp2 = strdup(av[2]);
			printf("or_strncat(\"%s\", \"%s\", %d) = %s\n", \
					av[1], av[2], num, strncat(tmp1, tmp2, num));
			free(tmp1);
			free(tmp2);
			tmp1 = strdup(av[1]);
			tmp2 = strdup(av[2]);
			printf("ft_strncat(\"%s\", \"%s\", %d) = %s", \
					av[1], av[2], num,  ft_strncat(tmp1, tmp2, num));
			free(tmp1);
			free(tmp2);
			printf("\n--------------------------------\n");
		}
		printf("ft_putnbr(%d):\n", num);
		ft_putnbr(num);
		printf("\n--------------------------------\n");
		printf("or_atoi(\"%s\") = %d\n", av[3], atoi(av[3]));
		printf("ft_atoi(\"%s\") = %d", av[3], ft_atoi(av[3]));
		printf("\n--------------------------------\n");
		printf("ft_itoa(%d) = %s", num, ft_itoa(num));
		printf("\n--------------------------------\n");
	}
	return (0);
}
