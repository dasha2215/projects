#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;
	t_list	*n;

	if (!lst || !del)
		return ;
	p = *lst;
	while (p)
	{
		n = p->next;
		ft_lstdelone(p, del);
		p = n;
	}
	*lst = 0;
}
