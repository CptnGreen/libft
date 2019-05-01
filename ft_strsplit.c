#include "libft.h"

/*
** ft_strsplit() allocates (with malloc(3)) and returnes an array of "fresh" strings
** (all ending with '\0', including the array itself) obtained by splitting s using
** the character c as a delimeter. If the allocation fails the function returnes NULL.
** Example: ft_split("*hello*fellow***students*", '*') returnes the array ["hello", 
** "fellow", "students"].
*/

#include <stdio.h>

char	**ft_strsplit(char const *s, char c)
{
	//char	**ar;
	//char	*str;
	int	i;
	int	isSep;
	int	num; //word counter

	isSep = 0;
	num = 0;
	// word counter
	while (s[i])
	{
		while (s[i] == c) //while sep
		{
			if (isSep == 0)
				num++;
			isSep = 1;
			i++;
		}
		isSep = 0;
		i++;
	}
	printf("words: %d\n", num);
	return (NULL);
}
