/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlreplace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:37:24 by akeiflin          #+#    #+#             */
/*   Updated: 2019/03/27 14:38:12 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Replace all occurence of toreplace in src
**	by resplacestr
**	return a new string
*/

char	*ft_strlreplace(char *src, char *toreplace, char *replacestr,
							int nbrocc)
{
	char	*occ;
	int		lencpy;
	char	*tmp;
	char	*c_src;
	int		i;

	i = 0;
	tmp = NULL;
	c_src = ft_strdup(src);
	while ((nbrocc == 0 || i++ < nbrocc) && (occ = ft_strstr(c_src, toreplace)))
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
