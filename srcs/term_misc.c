/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_misc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 06:06:46 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/19 22:43:33 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "ft_select.h"
#include "libft.h"

void	cur_mov(int y, int x)
{
	char *buff;

	buff = tgetstr("cm", NULL);
	tputs(tgoto(buff, x, y), 1, &ft_putchar);
}

void	move_to_opt(t_opt *opt, int pos)
{
	int	ligne;

	ligne = tgetnum("li");
	cur_mov(pos % ligne, get_col_opt(opt, ligne, pos));
}

void	underline_one(t_opt *opt, int pos)
{
	if (opt[pos].selected == 1)
		term_glow();
	term_underline();
	ft_putstr(opt[pos].word);
	term_change_clean();
}