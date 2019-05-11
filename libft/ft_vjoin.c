/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vjoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 08:47:49 by akeiflin          #+#    #+#             */
/*   Updated: 2019/03/15 08:52:01 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

char	*ft_vjoin(int n, ...)
{
	va_list		var;
	int			i;
	char		*working_var;
	char		*str;

	str = NULL;
	i = 0;
	va_start(var, n);
	while (i < n)
	{
		working_var = va_arg(var, char *);
		str = ft_strljoin(str, working_var, FIRST);
		++i;
	}
	va_end(var);
	return (str);
}
