/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 05:32:43 by akeiflin          #+#    #+#             */
/*   Updated: 2018/11/18 08:56:28 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*core;
	t_list	*next;

	if (!lst)
		return (NULL);
	if (!(head = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	lst = lst->next;
	if (lst)
	{
		if (!(core = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (NULL);
		head->next = core;
		lst = lst->next;
	}
	while (lst)
	{
		if (!(next = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (NULL);
		core->next = next;
		core = next;
		lst = lst->next;
	}
	return (head);
}
