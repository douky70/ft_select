/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_misc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 06:06:46 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/14 10:40:49 by akeiflin         ###   ########.fr       */
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

void	term_change_clean(void)
{
	char *buff;

	buff = tgetstr("me", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar);
}

void	term_put(char *code)
{
	char *buff;

	buff = tgetstr(code, NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar);
}
