/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:44:05 by akeiflin          #+#    #+#             */
/*   Updated: 2019/03/23 13:43:55 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

/*
**	The strcat() function append a copy of the
**	null-terminated string s2 to the end of the null-terminated
**	string s1, then add a terminating `\0'.  The string s1 must
**	have sufficient space to hold the result.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	ft_strcpy(s1 + ft_strlen(s1), s2);
	return (s1);
}
