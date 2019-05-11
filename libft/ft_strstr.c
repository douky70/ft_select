/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:39:31 by akeiflin          #+#    #+#             */
/*   Updated: 2019/03/23 13:48:08 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
**	The strstr() function locates the first occurrence
**	of the null-terminated string needle in the
**	null-terminated string haystack.
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	haystack_len;
	size_t	needle_len;

	i = 0;
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return (char *)haystack;
	while (i <= ((haystack_len >= needle_len) ? haystack_len - needle_len : 0))
	{
		j = 0;
		while (j < needle_len)
		{
			if (haystack[i + j] != needle[j])
				break ;
			j++;
		}
		if (j == needle_len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
