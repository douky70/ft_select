/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrlenendl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:30:42 by akeiflin          #+#    #+#             */
/*   Updated: 2019/01/29 15:32:33 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "libft.h"

void		ft_putstrlenendl(char *s, size_t len)
{
	if (s)
		write(1, s, len);
	write(1, "\n", 1);
}
