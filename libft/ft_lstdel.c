/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 02:45:02 by akeiflin          #+#    #+#             */
/*   Updated: 2018/11/16 04:48:52 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;

	if (!alst)
		return ;
	current = *alst;
	if ((*alst)->next != NULL)
	{
		*alst = (*alst)->next;
		ft_lstdel(alst, del);
	}
	*alst = current;
	ft_lstdelone(alst, del);
}
