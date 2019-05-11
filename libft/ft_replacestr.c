/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replacestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 13:03:58 by akeiflin          #+#    #+#             */
/*   Updated: 2019/03/27 14:38:50 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Replace all occurence of toreplace in src
**	by resplacestr
**	return a new string
*/

char	*ft_strreplace(char *src, char *toreplace,
						char *replacestr)
{
	char	*occ;
	int		lencpy;
	char	*tmp;
	char	*c_src;

	tmp = NULL;
	c_src = ft_strdup(src);
	while ((occ = ft_strstr(c_src, toreplace)))
	{
		lencpy = occ - c_src;
		tmp = ft_strduplen(c_src, lencpy);
		tmp = ft_strljoin(tmp, replacestr, FIRST);
		tmp = ft_strljoin(tmp, occ + ft_strlen(toreplace), FIRST);
		c_src = ft_free(c_src);
		c_src = ft_strdup(tmp);
		tmp = ft_free(tmp);
	}
	return (c_src);
}
