/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsewad <fsewad@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:37:35 by fsewad            #+#    #+#             */
/*   Updated: 2026/10/27 12:04:49 by fsewad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*head;
	void	*temp;

	head = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		temp = f(lst->content);
		ptr = ft_lstnew(temp);
		if (!ptr)
		{
			del(temp);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, ptr);
		lst = lst->next;
	}
	return (head);
}

/*int	main(void)
{
t_list	*node1, *node2, *node3, *node4, *new;

node1 = ft_lstnew(ft_strdup("fares"));
node2 = ft_lstnew(ft_strdup("mohammed"));
node3 = ft_lstnew(ft_strdup("abdul-hafez"));
node4 = ft_lstnew(ft_strdup("sewad"));
node1->next = node2;
node2->next = node3;
node3->next = node4;
new = ft_lstmap(node2, *lst_toupper, delet);
while (node1 != NULL)
{
printf("# %s\n", (char *) node1->content);
node1 = node1->next;
}
while (new != NULL)
{
printf("$ %s\n", (char *) new->content);
new = new->next;
}



void	*lst_toupper(void *k)
{
	char	*src;
	char	*dst;
	int		i;

	if (!k)
		return (NULL);
	src = (char *) k;
	dst = malloc(ft_strlen(src) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		if (dst[i] >= 'a' && dst[i] <= 'z')
			dst[i] = dst[i] - 32;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	delet(void *ptr)
{
	if (!ptr)
		return ;
	free(ptr);
}


return (0);
}*/
