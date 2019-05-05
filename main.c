/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:48:17 by slisandr          #+#    #+#             */
/*   Updated: 2019/05/04 22:06:46 by ak               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/string.h>
#include <strings.h>
#include <ctype.h>

#define FILENAME "./test"

void		toupper_for_striter(char *c)
{
	*c = toupper(*c);
}

int		main(int ac, char **av)
{
	char	*tmp1;
	char	*tmp2;
	char	**tmp;
	int	res_or;
	int	res_ft;
	int	num;
	int	num1;
	int	num2;
	int	fd;
	char	sym1;
	char	sym2;
	char	*res;
	int	i;

	printf("\n--------------------------------\n");
	printf("WELCOME TO LIBFT CHECK PROGRAM!");
	printf("\n--------------------------------\n");

	// opening test file
	fd = open(FILENAME, O_WRONLY);
	if (fd == -1)
		printf("Failed to open test file %s.\n", FILENAME);
	else
		printf("Successfully opened %s, fd = %d\n", FILENAME, fd);

	if (ac > 1)
	{
		sym1 = av[1][0];

		// ft_putendl
		if (fd != -1)
		{
			ft_putendl_fd(av[1], fd);
			printf("ft_putendl_fd() has just successfully printed \"%s\\n\" to %s, check it!\n", \
					av[1], FILENAME);
		}
		else
			printf("ft_putendl_fd(): ERROR! - test file failed to open");

		// ft_putendl
		printf("ft_putendl(\"%s\"):\n", av[1]);
		ft_putendl(av[1]);

		// ft_isascii
		res = (isascii(sym1) == ft_isascii(sym1)) ? ("OK") : ("ERROR!");
		if (strcmp(res, "ERROR!") == 0)
		{
			printf("------------ERROR!--------------\n");
			printf("or_isascii(\'%c\') = %d\n", sym1, isascii(sym1)); 
			printf("ft_isascii(\'%c\') = %d\n", sym1, ft_isascii(sym1)); 
			printf("--------------------------------\n");
		}
		else
			printf("ft_isascii(\'%c\'): %s\n", sym1, res); 

		// ft_isprint
		res = (isprint(sym1) == ft_isprint(sym1)) ? ("OK") : ("ERROR!");
		if (strcmp(res, "ERROR!") == 0)
		{
			printf("------------ERROR!--------------\n");
			printf("or_isprint(\'%c\') = %d\n", sym1, isprint(sym1)); 
			printf("ft_isprint(\'%c\') = %d\n", sym1, ft_isprint(sym1)); 
			printf("--------------------------------\n");
		}
		else
			printf("ft_isprint(\'%c\'): %s\n", sym1, res);

		// ft_isalnum
		res = (isalnum(sym1) == ft_isalnum(sym1)) ? ("OK") : ("ERROR!");
		if (strcmp(res, "ERROR!") == 0)
		{
			printf("------------ERROR!--------------\n");
			printf("or_isalnum(\'%c\') = %d\n", sym1, isalnum(sym1)); 
			printf("ft_isalnum(\'%c\') = %d\n", sym1, ft_isalnum(sym1)); 
			printf("--------------------------------\n");
		}
		else
			printf("ft_isalnum(\'%c\'): %s\n", sym1, res); 

		// ft_isalpha
		res = (isalpha(sym1) == ft_isalpha(sym1)) ? ("OK") : ("ERROR!");
		if (strcmp(res, "ERROR!") == 0)
		{
			printf("------------ERROR!--------------\n");
			printf("or_isalpha(\'%c\') = %d\n", sym1, isalpha(sym1)); 
			printf("ft_isalpha(\'%c\') = %d\n", sym1, ft_isalpha(sym1)); 
			printf("--------------------------------\n");
		}
		else
			printf("ft_isalpha(\'%c\'): %s\n", sym1, res); 

		// ft_isdigit
		res = (isdigit(sym1) == ft_isdigit(sym1)) ? ("OK") : ("ERROR!");
		if (strcmp(res, "ERROR!") == 0)
		{
			printf("------------ERROR!--------------\n");
			printf("or_isdigit(\'%c\') = %d\n", sym1, isdigit(sym1)); 
			printf("ft_isdigit(\'%c\') = %d\n", sym1, ft_isdigit(sym1)); 
			printf("--------------------------------\n");
		}
		else
			printf("ft_isdigit(\'%c\'): %s\n", sym1, res);

		// ft_toupper
		res = (toupper(sym1) == ft_toupper(sym1)) ? ("OK") : ("ERROR!");
		printf("ft_toupper(\'%c\'): %s\n", sym1, res);

		// ft_tolower
		res = (tolower(sym1) == ft_tolower(sym1)) ? ("OK") : ("ERROR!");
		printf("ft_tolower(\'%c\'): %s\n", sym1, res);

		// ft_strlen
		res = (strlen(av[1]) == ft_strlen(av[1])) ? ("OK") : ("ERROR!");
		printf("ft_strlen(\"%s\"): %s\n", av[1], res);

		// ft_strdup
		res = (strcmp(strdup(av[1]), ft_strdup(av[1])) == 0) ? ("OK") : ("ERROR!");
		printf("ft_strdup(\"%s\"): %s\n", av[1], res);

		// ft_strdel
		tmp1 = strdup(av[1]);
		ft_strdel(&tmp1);
		res = (tmp1 == NULL) ? ("OK") : ("ERROR!");
		printf("ft_strdel(\"%s\"): %s\n", av[1], res);

		// ft_strclr
		tmp1 = strdup(av[1]);
		res = "OK";
		num = strlen(tmp1);
		ft_strclr(tmp1);
		while (num >= 0)
		{
			if (tmp1[num--] != '\0')
			{
				res = "ERROR!";
				break ;
			}
		}
		printf("ft_strclr(\"%s\"): %s\n", av[1], res);
		free(tmp1);

		// ft_striter
		tmp1 = strdup(av[1]);
		ft_striter(tmp1, &toupper_for_striter);
		printf("ft_striter(\"%s\", &toupper_for_striter): %s\n", av[1], tmp1);
		free(tmp1);

		//ft_strtrim
		tmp1 = ft_strtrim(av[1]);
		printf("ft_strtrim(\"%s\") = %s\n", av[1], tmp1);
		free(tmp1);
	}
	if (ac > 2)
	{
		sym2 = av[2][0];

		// ft_strcmp
		num1 = strcmp(av[1], av[2]);
		num2 = ft_strcmp(av[1], av[2]);
		res = (num1 == num2) ? ("OK") : ("ERROR!");
		printf("ft_strcmp(\"%s\", \"%s\"): %s\n", av[1], av[2], res);

		// ft_strequ
		num1 = strcmp(av[1], av[2]);
		num2 = ft_strequ(av[1], av[2]);
		if ((num2 == 1 && num1 == 0) || (num2 != 1 && num1 != 0))
			res = "OK";
		else if ((num2 == 1 && num1 != 0) || (num2 != 1 && num1 == 0))
			res = "ERROR!";
		printf("ft_strequ(\"%s\", \"%s\"): %s\n", av[1], av[2], res);

		// ft_strcpy
		tmp1 = strdup(av[1]);
		tmp2 = strdup(av[2]);
		strcpy(tmp1, av[2]);
		ft_strcpy(tmp2, av[2]);
		printf("ft_strcpy(\"%s\", \"%s\"): %s\n", \
				av[1], av[2], \
				((strcmp(tmp1, tmp2) == 0) ? ("OK") : ("ERROR!")));
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

		// ft_strjoin
		tmp1 = ft_strjoin(av[1], av[2]);
		printf("ft_strjoin(\"%s\", \"%s\") = %s\n", av[1], av[2], tmp1);
		free(tmp1);

		// ft_strchr
		if (strchr(av[1], sym2) == NULL)
			printf("ft_strchr(\"%s\", \'%c\'): %s\n", \
					av[1], sym2, (ft_strchr(av[1], sym2) == NULL) ? ("OK") : ("ERROR!"));
		else
			printf("ft_strchr(\"%s\", \'%c\'): %s\n", \
					av[1], sym2, \
					((strcmp(strchr(av[1], sym2), ft_strchr(av[1], sym2)) == 0) ? \
					 ("OK") : ("ERROR!")));

		// ft_strrchr
		if (strrchr(av[1], sym2) == NULL)
			printf("ft_strrchr(\"%s\", \'%c\'): %s\n", \
					av[1], sym2, (ft_strrchr(av[1], sym2) == NULL) ? ("OK") : ("ERROR!"));
		else
			printf("ft_strchr(\"%s\", \'%c\'): %s\n", \
					av[1], sym2, \
					((strcmp(strrchr(av[1], sym2), ft_strrchr(av[1], sym2)) == 0) ? \
					 ("OK") : ("ERROR!")));

		// ft_strstr
		if (strstr(av[1], av[2]) == NULL)
			printf("ft_strstr(\"%s\", \"%s\"): %s\n", \
					av[1], av[2], (ft_strstr(av[1], av[2]) == NULL) ? ("OK") : ("ERROR!"));
		else
			printf("ft_strstr(\"%s\", \"%s\"): %s\n", \
					av[1], av[2], \
					((strcmp(strstr(av[1], av[2]), ft_strstr(av[1], av[2])) == 0) ? \
					 ("OK") : ("ERROR!")));

		// ft_strsplit
		tmp = ft_strsplit(av[1], sym2);
		printf("ft_strsplit(\"%s\", \'%c\') = {", av[1], sym2);
		i = 0;
		while (tmp[i])
		{
			printf("\"%s\"", tmp[i]);
			i++;
			res = (tmp[i]) ? (", ") : ("}\n");
			printf("%s", res);
		}
		i = 0;
		free(tmp);
	}
	if (ac > 3)
	{
		num = atoi(av[3]);
		// ft_putnbr_fd
		if (fd != -1)
		{
			ft_putnbr_fd(num, fd);
			printf("ft_putnbr_fd() has just successfully printed %d to %s, check it!\n", \
					num, FILENAME);
		}
		else
			printf("ft_putnbr_fd(%d, \"%s\"): ERROR!\n", num, FILENAME);

		// ft_putnbr
		printf("ft_putnbr(%d):\n", num);
		ft_putnbr(num);
		printf("\n");

		// ft_atoi
		res = (atoi(av[3]) == ft_atoi(av[3])) ? ("OK") : ("ERROR!");
		printf("ft_atoi(\"%s\"): %s\n", av[3], res);

		// ft_itoa
		printf("ft_itoa(%d) = %s\n", num, ft_itoa(num));
	}
	if (ac > 3 && num >= 0)
	{
		// ft_strncpy
		tmp1 = strdup(av[1]);
		tmp2 = strdup(av[1]);
		strncpy(tmp1, av[2], num);
		ft_strncpy(tmp2, av[2], num);
		if (tmp1 == NULL && tmp2 == NULL)
			res = "OK";
		else if ((tmp1 == NULL && tmp2 != NULL) || (tmp1 != NULL && tmp2 == NULL))
			res = "ERROR!";
		else
			res = (strcmp(tmp1, tmp2) == 0) ? ("OK") : ("ERROR!");
		if (strcmp(res, "ERROR!") == 0)
		{
			printf("------------ERROR!--------------\n");
			printf("or_strncpy(\"%s\", \"%s\", %d) = %s\n", av[1], av[2], num, tmp1);
			printf("ft_strncpy(\"%s\", \"%s\", %d) = %s\n", av[1], av[2], num, tmp2);
			printf("--------------------------------\n");
		}
		else
			printf("ft_strncpy(\"%s\", \"%s\", %d): %s\n", av[1], av[2], num, res);
		if (tmp1)
			free(tmp1);
		if (tmp2)
			free(tmp2);

		//ft_strlcpy
		tmp1 = strdup(av[1]);
		tmp2 = strdup(av[1]);
		num1 = strlcpy(tmp1, av[2], num);
		num2 = ft_strlcpy(tmp2, av[2], num);
		res = (strcmp(tmp1, tmp2) == 0 && num1 == num2) ? ("OK") : ("ERROR!");
		printf("ft_strlcpy(\"%s\", \"%s\", %d): %s\n", av[1], av[2], num, res);
		if (strcmp(res, "ERROR!") == 0)
		{
			printf("------------ERROR!--------------\n");
			printf("or_strlcpy(\"%s\", \"%s\", %d) = %d ==> %s\n", av[1], av[2], num, num1, tmp1);
			printf("ft_strlcpy(\"%s\", \"%s\", %d) = %d ==> %s\n", av[1], av[2], num, num2, tmp2);
			printf("--------------------------------\n");
		}
		free(tmp1);
		free(tmp2);

		// ft_strncmp
		printf("ft_strncmp(\"%s\", \"%s\", %d): %s\n", \
				av[1], av[2], num, \
				(ft_strncmp(av[1], av[2], num) == strncmp(av[1], av[2], num)) ? \
				("OK") : ("ERROR!"));

		// ft_strnstr
		if (strnstr(av[1], av[2], num) == 0)
			printf("ft_strnstr(\"%s\", \"%s\", %d): %s\n", \
					av[1], av[2], num, \
					(ft_strnstr(av[1], av[2], num) == NULL) ? ("OK") : ("ERROR!"));
		else
			printf("ft_strnstr(\"%s\", \"%s\", %d): %s\n", \
					av[1], av[2], num, \
					((strcmp(strnstr(av[1], av[2], num), \
						 ft_strnstr(av[1], av[2], num)) == 0) ? \
					 ("OK") : ("ERROR!")));

		// ft_memset
		tmp1 = strdup(av[1]);
		tmp2 = strdup(av[1]);
		memset(tmp1, sym2, num);
		ft_memset(tmp2, sym2, num);
		res = (memcmp(tmp1, tmp2, MAX_OF_TWO(num, strlen(av[1]))) == 0) ? ("OK") : ("ERROR!");
		printf("ft_memset(\"%s\", \'%c\', %d): %s\n", av[1], sym2, num, res); 
		if (strcmp(res, "ERROR!") == 0)
		{
			printf("memcmp(\"%s\", \"%s\", %zu) = %d\n", \
					tmp1, tmp2, MAX_OF_TWO(num, strlen(av[1])), \
					memcmp(tmp1, tmp2, MAX_OF_TWO(num, strlen(av[1]))));
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
		res = (memcmp(tmp1, tmp2, MAX_OF_TWO(num, strlen(av[1]))) == 0) ? ("OK") : ("ERROR!");
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
		printf("ft_strncat(\"%s\", \"%s\", %d): %s\n", av[1], av[2], num, res);
		free(tmp1);
		free(tmp2);

		// ft_strlcat
		tmp1 = strdup(av[1]);
		tmp2 = strdup(av[1]);
		num1 = strlcat(tmp1, av[2], num);
		num2 = ft_strlcat(tmp2, av[2], num);
		res = (strcmp(tmp1, tmp2) == 0 && num1 == num2) ? ("OK") : ("ERROR!");
		if (strcmp(res, "ERROR!") == 0)
		{
			printf("------------ERROR!--------------\n");
			printf("or_strlcat(\"%s\", \"%s\", %2d) = %2d ==> %s\n", av[1], av[2], num, num1, tmp1);
			printf("ft_strlcat(\"%s\", \"%s\", %2d) = %2d ==> %s\n", av[1], av[2], num, num2, tmp2);
			printf("--------------------------------\n");
		}
		else
			printf("ft_strlcat(\"%s\", \"%s\", %d): %s\n", av[1], av[2], num, res);
		free(tmp1);
		free(tmp2);

		// ft_memalloc
		tmp1 = (char *)ft_memalloc(num);
		printf("ft_memalloc(%d): WRITTEN, NOT CHECKED\n", num);
		free(tmp1);

		// ft_strnew
		tmp1 = ft_strnew(num);
		printf("ft_strnew(%d): WRITTEN, NOT CHECKED\n", num);
		free(tmp1);

		// ft_strsub
		num1 = 3;
		num2 = num;
		if (strlen(av[1]) >= num1)
		{
			res = ft_strsub(av[1], num1, num2);
			printf("ft_strsub(\"%s\", %d, %d) = %s\n", av[1], num1, num2, res);
			free(res);
		}
		
		// ft_memccpy
		sym1 = 'l';
		tmp1 = strdup(av[1]);
		tmp2 = strdup(av[1]);
		memccpy(tmp1, av[2], sym1, num);
		ft_memccpy(tmp2, av[2], sym1, num);
		res = (memcmp(tmp1, tmp2, MAX_OF_TWO(num, strlen(av[1]))) == 0) ? ("OK") : ("ERROR!");
		if (strcmp(res, "ERROR!") == 0 || 1)
		{
			printf("------------ERROR!--------------\n");
			printf("or_memccpy(\"%s\", \"%s\", %c, %2d) = %s\n", av[1], av[2], sym1, num, tmp1);
			printf("ft_memccpy(\"%s\", \"%s\", %c, %2d) = %s\n", av[1], av[2], sym1, num, tmp2);
			printf("--------------------------------\n");
		}
		else
			printf("ft_memccpy(\"%s\", \"%s\", %c, %2d): %s\n", av[1], av[2], sym1, num, res);

		// ft_memmove
		tmp1 = strdup(av[1]);
		tmp2 = strdup(av[1]);
		memmove(tmp1, av[2], num);
		ft_memmove(tmp2, av[2], num);
		res = (memcmp(tmp1, tmp2, MAX_OF_TWO(num, strlen(av[1]))) == 0) ? ("OK") : ("ERROR!");
		if (strcmp(res, "ERROR!") == 0)
		{
			printf("------------ERROR!--------------\n");
			printf("or_memmove(\"%s\", \"%s\", %2d) = %s\n", av[1], av[2], num, tmp1);
			printf("ft_memmove(\"%s\", \"%s\", %2d) = %s\n", av[1], av[2], num, tmp2);
			printf("--------------------------------\n");
		}
		else
			printf("ft_memmove(\"%s\", \"%s\", %2d): %s\n", av[1], av[2], num, res);

		// ft_memchr
		tmp1 = memchr(av[1], sym2, num);
		tmp2 = ft_memchr(av[1], sym2, num);
		if (tmp1 != NULL && tmp2 != NULL)
			res = (memcmp(tmp1, tmp2, strlen(av[1])) == 0 || (tmp1 == NULL && tmp2 == NULL)) ? ("OK") : ("ERROR!");
		if (strcmp(res, "ERROR!") == 0)
		{
			printf("------------ERROR!--------------\n");
			printf("or_memchr(\"%s\", \'%c\', %2d) = %s\n", av[1], sym2, num, tmp1);
			printf("ft_memchr(\"%s\", \'%c\', %2d) = %s\n", av[1], sym2, num, tmp2);
			printf("--------------------------------\n");
		}
		else
			printf("ft_memchr(\"%s\", \'%c\', %2d): %s\n", av[1], sym2, num, res);

		// ft_memcmp
		num1 = memcmp(av[1], av[2], num);
		num2 = ft_memcmp(av[1], av[2], num);
		res = (num1 == num2) ? ("OK") : ("ERROR!");
		if (strcmp(res, "ERROR!") == 0)
		{
			printf("------------ERROR!--------------\n");
			printf("or_memcmp(\"%s\", \"%s\", %2d) = %d\n", av[1], av[2], num, num1);
			printf("ft_memcmp(\"%s\", \"%s\", %2d) = %d\n", av[1], av[2], num, num2);
			printf("--------------------------------\n");
		}
		else
			printf("ft_memcmp(\"%s\", \"%s\", %2d): %s\n", av[1], av[2], num, res);

		// ft_strnequ
		num1 = strcmp(av[1], av[2]);
		num2 = ft_strnequ(av[1], av[2], num);
		if ((num2 == 1 && num1 == 0) || (num2 != 1 && num1 != 0))
			res = "OK";
		else if ((num2 == 1 && num1 != 0) || (num2 != 1 && num1 == 0))
			res = "ERROR!";
		printf("ft_strnequ(\"%s\", \"%s\", %d): %s\n", av[1], av[2], num, res);
	}
	close(fd);
	printf("------------THE END-------------\n");
	return (0);
}
