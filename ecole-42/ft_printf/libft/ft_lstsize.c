#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		count;

	count = 0;
	p = lst;
	while (p)
	{
		count++;
		p = p->next;
	}
	return (count);
}
