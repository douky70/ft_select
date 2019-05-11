/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:59:58 by akeiflin          #+#    #+#             */
/*   Updated: 2019/03/23 13:34:02 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
**	Copies bytes from string src to string dst.
**	If the character c occurs in the string src,
**	the copy stops and a pointer to the byte after
**	the copy of c in the string dst is returned.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char*)dst) = ((unsigned char*)src)[i];
		dst++;
		if (((unsigned char *)src)[i] == (unsigned char)c)
		{
			return (dst);
		}
		i++;
	}
	return (NULL);
}
