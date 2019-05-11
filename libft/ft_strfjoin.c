/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 03:28:25 by akeiflin          #+#    #+#             */
/*   Updated: 2018/12/21 06:15:56 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static	char	*ft_dupandfree(char *s1, char *s2)
{
	char *tmp;

	if (!s1 && s2)
	{
		tmp = ft_strdup(s2);
		free(s2);
		return (tmp);
	}
	else
	{
		tmp = ft_strdup(s1);
		free(s1);
		return (tmp);
	}
}

char			*ft_strfjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 && s2)
		return (ft_dupandfree(s1, s2));
	else if (s1 && !s2)
		return (ft_dupandfree(s1, s2));
	i = 0;
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	free(s1);
	free(s2);
	return (str);
}
