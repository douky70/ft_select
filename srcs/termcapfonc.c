/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcapfonc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 21:18:18 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/19 21:53:34 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"

void	term_clear(void)
{
	char *buff;

	buff = tgetstr("cl", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar);
}

void	term_home(void)
{
	char *buff;

	buff = tgetstr("ho", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar);
}

void	term_glow(void)
{
	char *buff;

	buff = tgetstr("mr", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar);
}

void	term_underline(void)
{
	char *buff;

	buff = tgetstr("us", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar);
}

void	term_change_clean(void)
{
	char *buff;

	buff = tgetstr("me", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar);
}