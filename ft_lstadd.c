#include "libft.h"

/*
** ft_lastadd() adds the element new at the beginning of the list.
** Return value: none.
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*lst_root;

	lst_root = *alst;
	*alst = new;
	new->next = lst_root;
}
