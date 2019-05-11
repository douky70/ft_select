/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 08:43:40 by akeiflin          #+#    #+#             */
/*   Updated: 2019/04/02 17:04:28 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(long long n)
{
	long long		numlen;
	int				positive;
	char			*str;
	long long		num;

	numlen = ft_numlen(n);
	positive = ft_ispositive(n);
	if (!positive)
		numlen++;
	if (!(str = ft_strnew(numlen)))
		return (NULL);
	if (!positive)
		str[0] = '-';
	num = ft_abs(n);
	while ((!positive) ? numlen - 1 : numlen)
	{
		str[--numlen] = '0' + num % 10;
		num /= 10;
	}
	return (str);
}
