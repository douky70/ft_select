/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:52:16 by akeiflin          #+#    #+#             */
/*   Updated: 2018/11/16 00:51:17 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haystack,
		const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	haystack_len;
	size_t	needle_len;
	size_t	looking_len;

	i = 0;
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return (char *)haystack;
	if (needle_len > len)
		return (NULL);
	looking_len = (len < haystack_len) ? len : haystack_len;
	while (i <= ((looking_len >= needle_len) ? looking_len - needle_len : 0))
	{
		j = -1;
		while (++j < needle_len)
			if (haystack[i + j] != needle[j])
				break ;
		if (j == needle_len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
