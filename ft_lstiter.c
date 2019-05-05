#include "libft.h"

/*
** ft_lstiter() iterates the list *lst* and applies the function *f*
** to each link. Return value: none. 
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
