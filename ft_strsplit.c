#include "libft.h"

/*
** ft_strsplit() allocates (with malloc(3)) and returnes an array of "fresh" strings
** (all ending with '\0', including the array itself) obtained by splitting s using
** the character c as a delimeter. If the allocation fails the function returnes NULL.
** Example: ft_split("*hello*fellow***students*", '*') returnes the array ["hello", 
** "fellow", "students"].
*/

static size_t	ft_strlen_delim(char const *s, char delim);
static size_t	count_words(char const *s, char c);
void		distribute_words_delim(char **ar, char const *s, char c);

#include <stdio.h>
#include <string.h>

char		**ft_strsplit(char const *s, char c)
{
	char	**ar;
	int	num;

	num = count_words(s, c);
	ar = (num == 0) ? (NULL) : ((char **)malloc(sizeof(char *) * (num + 1)));
	if (ar)
	{
		ar[num] = NULL;
		distribute_words_delim(ar, s, c);
		return (ar);
	}
	else
		return (NULL);
}

void		distribute_words_delim(char **ar, char const *s, char c)
{
	int	num;
	int	i;
	int	j;
	int	isSep;

	i = 0;
	while (s[i] == c)
		i++;
	isSep = 0;
	ar[num = 0] = ft_strnew(ft_strlen_delim(s + i, c) + 1);
	j = 0;
	while (s[i])
	{
		isSep = (s[i] == c) ? (1) : (isSep);
		if (s[i] != c)
		{
			num = (isSep == 1) ? (num + 1) : (num);
			ar[num] = (isSep == 1) ? \
				  (ft_strnew(ft_strlen_delim(s + i, c) + 1)) : (ar[num]);
			j = (isSep == 1) ? (0) : (j);
			ar[num][j++] = s[i];
			isSep = 0;
		}
		i++;
	}
}

static size_t		ft_strlen_delim(char const *s, char delim)
{
	size_t		i;

	i = 0;
	while (s[i] != delim && s[i] != '\0')
		i++;
	return (i);
}

static size_t		count_words(char const *s, char c)
{
	size_t		i;
	size_t		num;
	int		isSep;

	if (s[0] != '\0')
	{
		i = 0;
		isSep = (s[0] == c) ? (1) : (0);
		num = (s[0] == c) ? (0) : (1);
		while (s[i])
		{
			if (s[i] == c)
				isSep = 1;
			else
			{
				num = (isSep == 1) ? (num + 1) : (num);
				isSep = 0;
			}
			i++;
		}
		return (num);
	}
	else
		return (0);
}
