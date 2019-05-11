/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 08:56:33 by akeiflin          #+#    #+#             */
/*   Updated: 2018/11/14 09:46:52 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int nb)
{
	long	res;
	long	nbcp;

	nbcp = (long)nb;
	res = 0;
	if (nbcp == 0)
		return (1);
	nbcp = ft_abs(nb);
	while (nbcp >= 1)
	{
		res++;
		nbcp = nbcp / 10;
	}
	return (res);
}
