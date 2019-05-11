/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 04:14:55 by akeiflin          #+#    #+#             */
/*   Updated: 2018/11/14 05:49:05 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	size_t	len;
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (ft_is_space(s[i++]) && len != 0)
		len--;
	i = (ft_strlen(s) == 0) ? 1 : ft_strlen(s) - 1;
	while (ft_is_space(s[i--]) && len != 0)
		len--;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (ft_is_space(*(s)))
		s++;
	i = 0;
	while (i < len)
		str[i++] = *(s++);
	return (str);
}
