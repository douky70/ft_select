/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 21:24:37 by akeiflin          #+#    #+#             */
/*   Updated: 2018/11/15 23:48:28 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nlong;

	nlong = (long)n;
	if (nlong < 0)
	{
		ft_putchar_fd('-', fd);
		nlong = ft_abs(n);
	}
	if (nlong < 10)
		ft_putchar_fd('0' + nlong % 10, fd);
	else if (nlong)
	{
		ft_putnbr_fd(nlong / 10, fd);
		ft_putchar_fd('0' + nlong % 10, fd);
	}
}
