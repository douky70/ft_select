/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:09:23 by akeiflin          #+#    #+#             */
/*   Updated: 2019/01/29 17:21:38 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** if sorting is positiv, desc sorting
** if sorting is negativ, asc sorting
*/

t_list	*ft_lstsort(t_list *lst, int s)
{
	char		*tmp;
	t_list		*head;
	int			change;

	head = lst;
	change = 1;
	while (change)
	{
		change = 0;
		while (lst->next)
		{
			if ((ft_strcmp(lst->content, lst->next->content) > 0 && s >= 0)
				|| (ft_strcmp(lst->content, lst->next->content) < 0 && s < 0))
			{
				change = 1;
				tmp = lst->content;
				lst->content = lst->next->content;
				lst->next->content = tmp;
			}
			lst = lst->next;
		}
		lst = head;
	}
	return (lst);
}
