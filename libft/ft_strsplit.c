/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 05:52:59 by akeiflin          #+#    #+#             */
/*   Updated: 2018/11/14 07:34:47 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static size_t	ft_count_word(char const *str, char c)
{
	size_t	res;
	int		b;

	b = 0;
	res = 0;
	while (*str)
	{
		if (b == 0 && *str != c)
		{
			b = 1;
			res++;
		}
		if (b == 1 && *str == c)
			b = 0;
		str++;
	}
	return (res);
}

static size_t	ft_count_letter(char const *str, char c)
{
	size_t	res;

	res = 0;
	while (*str && *str != c)
	{
		res++;
		str++;
	}
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**res;
	int		b;

	if (!s)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1))))
		return (NULL);
	ft_bzero(res, sizeof(char *) * (ft_count_word(s, c) + 1));
	b = 0;
	i = 0;
	while (*s)
	{
		if (*s == c && b == 1)
			b = 0;
		else if (*s != c && b == 0)
		{
			b = 1;
			if (!(res[i] = ft_strsub(s, 0, ft_count_letter(s, c))))
				return (NULL);
			i++;
		}
		s++;
	}
	return (res);
}
