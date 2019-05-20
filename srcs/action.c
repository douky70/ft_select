/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 06:29:07 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/20 17:13:57 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "ft_select.h"
#include "libft.h"

void	select_one(t_opt *opt, int pos)
{
	int	cur;
	int	ligne;

	if (opt[pos].selected == 0)
	{
			term_glow();
			opt[pos].selected = 1;
	}
	else
		opt[pos].selected = 0;
	ft_putstr(opt[pos].word);
	ligne = tgetnum("li");
	cur_mov(pos % ligne, get_col_opt(opt, ligne, pos));
	term_change_clean();
}

int		move_pointer(int pos, t_opt *opt, int dir)
{
	int ligne = tgetnum("li");
	int	optlen = opt_len(opt) - 1;
	
	if (dir == KEY_UP)
	{
		if (pos > 0)
			--pos;
		else
			pos = optlen;
		cur_mov(pos % ligne, get_col_opt(opt, ligne, pos));
	}
	if (dir == KEY_DOWN)
	{
		if (pos < optlen)
			++pos;
		else
			pos = 0;
		cur_mov(pos % ligne, get_col_opt(opt, ligne, pos));
		
	}
	if (dir == KEY_RIGHT)
	{
			if (pos > optlen - ligne)
			{
				if (((pos + 1) % ligne == 0) || (ligne > optlen && pos == optlen))
					pos = 0;
				else
					pos = pos % ligne + 1;
			}
			else
				pos += ligne;
			cur_mov(pos % ligne, get_col_opt(opt, ligne, pos));
	}
	if (dir == KEY_LEFT)
	{
		if (pos < ligne)
		{
			int tmp;
			if (ligne > optlen && pos == 0)
				pos = optlen;
			else
			{
				if (pos == 0)
					tmp = ligne - 1;
				else
					tmp = pos % ligne - 1;
				while (tmp + ligne <= optlen)
					tmp += ligne;
				pos = tmp;
			}
		}
		else
			pos -= ligne;
		cur_mov(pos % ligne, get_col_opt(opt, ligne, pos));
	}
	return (pos);
}
