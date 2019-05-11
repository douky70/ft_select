/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 08:48:38 by akeiflin          #+#    #+#             */
/*   Updated: 2019/03/15 08:50:40 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

void	ft_vprint(int n, ...)
{
	va_list		var;
	int			i;
	char		*working_var;

	i = 0;
	va_start(var, n);
	while (i < n)
	{
		working_var = va_arg(var, char *);
		ft_putstr(working_var);
		++i;
	}
	va_end(var);
}
