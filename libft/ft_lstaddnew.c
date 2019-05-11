/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 20:24:13 by akeiflin          #+#    #+#             */
/*   Updated: 2019/01/29 17:32:19 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddnew(t_list **alst, void const *content, size_t content_size)
{
	t_list	*new;

	new = ft_lstnew(content, content_size);
	if (alst)
	{
		new->next = *alst;
		*alst = new;
	}
	return (new);
}
