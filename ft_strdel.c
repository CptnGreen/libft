#include "libft.h"

/*
** Description: ft_strdel() takes as a parameter the address of a memory area 
** that needs to be freed with free (3), then puts the pointer to NULL.
*/

void	ft_strdel(char **as)
{
	free(*as);
	*as = NULL;
}
