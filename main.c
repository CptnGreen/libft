/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:48:17 by slisandr          #+#    #+#             */
/*   Updated: 2019/04/22 22:55:17 by slisandr         ###   ########.fr       */
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
	int		res_or;
	int		res_ft;
	int		num;
	int		fd;
	char	sym1;
	char	sym2;
	char	*res;

	printf("\n--------------------------------\n");
	printf("WELCOME TO LIBFT CHECK PROGRAM!");
	printf("\n--------------------------------\n");
	// opening test file
	fd = open(FILENAME, O_WRONLY);
	if (fd == -1)
		printf("Failed to open test file %s.\n", FILENAME);
	else
		printf("Successfully opened %s, fd = %d\n", FILENAME, fd);
	printf("--------------------------------\n");
	if (ac > 1)
	{
		sym1 = av[1][0];

		// ft_putstr_fd
		if (fd != -1)
		{
			ft_putstr_fd(av[1], fd);
			ft_putchar_fd('\n', fd);
			printf("ft_putstr_fd() has just successfully printed \"%s\" + \'\\n\' to %s, check it!\n", av[1], FILENAME);
		}
		else
			printf("ft_putstr_fd(): ERROR! - test file failed to open");
		printf("--------------------------------\n");

		// ft_putchar
		printf("ft_putchar(sym1):\n");
		ft_putchar(sym1);
		printf("\n--------------------------------\n");

		// ft_putstr
		printf("ft_putstr(\"%s\"):\n", av[1]);
		ft_putstr(av[1]);
		printf("\n--------------------------------\n");

		// "is*" and "to*" functions
		printf("ft_isprint(\'%c\'): %s\n", sym1, (isascii(sym1) == ft_isascii(sym1)) ? ("OK") : ("ERROR!"));
		printf("ft_isprint(\'%c\'): %s\n", sym1, (isprint(sym1) == ft_isprint(sym1)) ? ("OK") : ("ERROR!"));
		printf("ft_isalnum(\'%c\'): %s\n", sym1, (isalnum(sym1) == ft_isalnum(sym1)) ? ("OK") : ("ERROR!"));
		printf("ft_isalpha(\'%c\'): %s\n", sym1, (isalpha(sym1) == ft_isalpha(sym1)) ? ("OK") : ("ERROR!"));
		printf("ft_isdigit(\'%c\'): %s\n", sym1, (isdigit(sym1) == ft_isdigit(sym1)) ? ("OK") : ("ERROR!"));
		printf("ft_toupper(\'%c\'): %s\n", sym1, (toupper(sym1) == ft_toupper(sym1)) ? ("OK") : ("ERROR!"));
		printf("ft_tolower(\'%c\'): %s\n", sym1, (tolower(sym1) == ft_tolower(sym1)) ? ("OK") : ("ERROR!"));
		printf("ft_strlen(\"%s\"): %s\n", av[1], (strlen(av[1]) == ft_strlen(av[1])) ? ("OK") : ("ERROR!"));
		printf("ft_strdup(\"%s\"): %s\n", av[1], (strcmp(strdup(av[1]), ft_strdup(av[1])) == 0) ? ("OK") : ("ERROR!"));
		printf("--------------------------------\n");
	}
	if (ac > 2)
	{
		sym2 = av[2][0];

		// ft_strcmp
		printf("ft_strcmp(\"%s\", \"%s\"): %s\n", av[1], av[2], (strcmp(av[1], av[2]) == ft_strcmp(av[1], av[2])) ? ("OK") : ("ERROR!"));

		// ft_strcpy
		tmp1 = strdup(av[1]);
		tmp2 = strdup(av[2]);
		strcpy(tmp1, av[2]);
		ft_strcpy(tmp2, av[2]);
		printf("ft_strcpy(\"%s\", \"%s\"): %s\n", av[1], av[2], ((strcmp(tmp1, tmp2) == 0) ? ("OK") : ("ERROR!")));
		free(tmp1);
		free(tmp2);

		// ft_strcat
		tmp1 = strdup(av[1]);
		tmp2 = strdup(av[1]);
		strcat(tmp1, av[2]);
		ft_strcat(tmp2, av[2]);
		res = (strcmp(tmp1, tmp2) == 0) ? ("OK") : ("ERROR!");
		printf("ft_strcat(\"%s\", \"%s\"): %s\n", av[1], av[2], res);
		if (strcmp(res, "OK") != 0)
		{
			printf("or_strcat(\"%s\", \"%s\") = %s\n", av[1], av[2], tmp1);
			printf("ft_strcat(\"%s\", \"%s\") = %s\n", av[1], av[2], tmp2);
		}
		free(tmp1);
		free(tmp2);

		// ft_strchr
		if (strchr(av[1], sym2) == NULL)
			printf("ft_strchr(\"%s\", \'%c\'): %s\n", av[1], sym2, (ft_strchr(av[1], sym2) == NULL) ? ("OK") : ("ERROR!"));
		else
			printf("ft_strchr(\"%s\", \'%c\'): %s\n", av[1], sym2, ((strcmp(strchr(av[1], sym2), ft_strchr(av[1], sym2)) == 0) ? ("OK") : ("ERROR!")));

		// ft_strrchr
		if (strrchr(av[1], sym2) == NULL)
			printf("ft_strrchr(\"%s\", \'%c\'): %s\n", av[1], sym2, (ft_strrchr(av[1], sym2) == NULL) ? ("OK") : ("ERROR!"));
		else
			printf("ft_strchr(\"%s\", \'%c\'): %s\n", av[1], sym2, ((strcmp(strrchr(av[1], sym2), ft_strrchr(av[1], sym2)) == 0) ? ("OK") : ("ERROR!")));

		// ft_strstr
		if (strstr(av[1], av[2]) == NULL)
			printf("ft_strstr(\"%s\", \"%s\"): %s\n", av[1], av[2], (ft_strstr(av[1], av[2]) == NULL) ? ("OK") : ("ERROR!"));
		else
			printf("ft_strstr(\"%s\", \"%s\"): %s\n", av[1], av[2], ((strcmp(strstr(av[1], av[2]), ft_strstr(av[1], av[2])) == 0) ? ("OK") : ("ERROR!")));
		printf("--------------------------------\n");
	}
	if (ac > 3)
	{
		num = atoi(av[3]);
		// ft_putnbr_fd
		if (fd != -1)
		{
			ft_putnbr_fd(num, fd);
			printf("ft_putnbr_fd() has just successfully printed %d to %s, check it!\n", num, FILENAME);
		}
		else
			printf("ft_putnbr(%d, \"%s\"): ERROR!", num, FILENAME);
		printf("--------------------------------\n");
		if (num >= 0)
		{
			// ft_strncpy
			tmp1 = strdup(av[1]);
			tmp2 = strdup(av[1]);
			strncpy(tmp1, av[2], num);
			ft_strncpy(tmp2, av[2], num);
			res = (strcmp(tmp1, tmp2) == 0) ? ("OK") : ("ERROR!");
			printf("ft_strncpy(\"%s\", \"%s\", %d): %s\n", av[1], av[2], num, res);
			if (strcmp(res, "ERROR!") == 0)
			{
				printf("or_strncpy(\"%s\", \"%s\", %d) = %s\n", av[1], av[2], num, tmp1);
				printf("ft_strncpy(\"%s\", \"%s\", %d) = %s\n", av[1], av[2], num, tmp2);
			}
			free(tmp1);
			free(tmp2);

			// ft_strncmp
			printf("ft_strncmp(\"%s\", \"%s\", %d): %s\n", av[1], av[2], num, (ft_strncmp(av[1], av[2], num) == strncmp(av[1], av[2], num)) ? ("OK") : ("ERROR!"));

			// ft_strnstr
			if (strnstr(av[1], av[2], num) == NULL)
				printf("ft_strnstr(\"%s\", \"%s\", %d): %s\n", av[1], av[2], num, (ft_strnstr(av[1], av[2], num) == NULL) ? ("OK") : ("ERROR!"));
			else
				printf("ft_strnstr(\"%s\", \"%s\", %d): %s\n", av[1], av[2], num, ((strcmp(strnstr(av[1], av[2], num), ft_strnstr(av[1], av[2], num)) == 0) ? ("OK") : ("ERROR!")));

			// ft_memset
			tmp1 = strdup(av[1]);
			tmp2 = strdup(av[1]);
			memset(tmp1, sym2, num);
			ft_memset(tmp2, sym2, num);
			res = (memcmp(tmp1, tmp2, MAX_OF_TWO(num, strlen(av[1]))) == 0) ? ("OK") : ("ERROR!");
			printf("ft_memset(\"%s\", \'%c\', %d): %s\n", av[1], sym2, num, res); 
			if (strcmp(res, "ERROR!") == 0)
			{
				printf("memcmp(\"%s\", \"%s\", %zu) = %d\n", tmp1, tmp2, MAX_OF_TWO(num, strlen(av[1])), memcmp(tmp1, tmp2, MAX_OF_TWO(num, strlen(av[1]))));
				printf("or_memset(\"%s\", \'%c\', %d) = %s\n", av[1], sym2, num, tmp1); 
				printf("ft_memset(\"%s\", \'%c\', %d) = %s\n", av[1], sym2, num, tmp2); 
			}
			free(tmp1);
			free(tmp2);

			// ft_bzero
			tmp1 = strdup(av[1]);
			tmp2 = strdup(av[1]);
			bzero(tmp1, num);
			ft_bzero(tmp2, num);
			res = ((memcmp(tmp1, tmp2, MAX_OF_TWO(num, strlen(av[1]))) == 0) ? ("OK") : ("ERROR!"));
			printf("ft_bzero(\"%s\", %d): %s\n", av[1], num, res);
			if (strcmp(res, "ERROR!") == 0)
			{
				printf("or_bzero(\"%s\", %d) = %s\n", av[1], num, tmp1);
				printf("ft_bzero(\"%s\", %d) = %s\n", av[1], num, tmp2);
			}
			free(tmp1);
			free(tmp2);

			// ft_memcpy
			tmp1 = strdup(av[1]);
			tmp2 = strdup(av[1]);
			memcpy(tmp1, av[2], num);
			memcpy(tmp2, av[2], num);
			res = (memcmp(tmp1, tmp2, MAX_OF_TWO(num, strlen(av[1]))) == 0) ? ("OK") : ("ERROR!");
			printf("ft_memcpy(\"%s\", \"%s\", %d): %s\n", av[1], av[2], num, res);
			free(tmp1);
			free(tmp2);

			// ft_strncat
			tmp1 = strdup(av[1]);
			tmp2 = strdup(av[1]);
			strncat(tmp1, av[2], num);
			ft_strncat(tmp2, av[2], num);
			res = (strcmp(tmp1, tmp2) == 0) ? ("OK") : ("ERROR!");
			printf("or_strncat(\"%s\", \"%s\", %d): %s\n", av[1], av[2], num, res);
			free(tmp1);
			free(tmp2);

			printf("--------------------------------\n");
		}
		// ft_putnbr
		printf("ft_putnbr(%d):\n", num);
		ft_putnbr(num);
		printf("\n--------------------------------\n");

		// ft_atoi
		res = (atoi(av[3]) == ft_atoi(av[3])) ? ("OK") : ("ERROR!");
		printf("ft_atoi(\"%s\"): %s\n", av[3], res);

		// ft_itoa
		printf("ft_itoa(%d) = %s\n", num, ft_itoa(num));
		printf("\n--------------------------------\n");
	}
	close(fd);
	return (0);
}
