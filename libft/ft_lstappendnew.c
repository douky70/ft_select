/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappendnew.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 07:17:02 by akeiflin          #+#    #+#             */
/*   Updated: 2019/02/11 17:59:31 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstappendnew(t_list **alst, void const *content,
			size_t content_size)
{
	t_list	*new;
	t_list	*head;

	head = *alst;
	new = ft_lstnew(content, content_size);
	if (*alst)
	{
		while ((*alst)->next)
			*alst = (*alst)->next;
		(*alst)->next = new;
		*alst = new;
		return (head);
	}
	else
		return (new);
}
