#include "libft.h"

/* Description: Lexicographical comparison between s1 and s2 up to n
** characters or until '\0' is reached. If 2 strings are identical the function
** returnes 1, or 0 otherwise.
*/

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	res;
	res = (ft_strncmp(s1, s2, n) == 0) ? (1) : (0);
	return (res);
}
