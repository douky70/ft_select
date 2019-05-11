/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:58:20 by akeiflin          #+#    #+#             */
/*   Updated: 2019/03/23 13:35:55 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
**	The memset() function writes len bytes
**	of value c (converted to an unsigned char)
**	to the string b.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*res;

	res = b;
	i = 0;
	while (i < len)
	{
		res[i] = (unsigned char)c;
		i++;
	}
	return ((void *)res);
}
