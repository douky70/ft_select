/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 06:29:07 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/23 17:09:24 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <sys/ioctl.h>
#include "ft_select.h"
#include "libft.h"

void	select_one(t_opt *opt, int pos)
{
	int				cur;
	struct winsize	sz;

	if (opt[pos].selected == 0)
	{
		term_glow();
		opt[pos].selected = 1;
	}
	else
		opt[pos].selected = 0;
	ft_putstr(opt[pos].word);
	ioctl(0, TIOCGWINSZ, &sz);
	cur_mov(pos % sz.ws_row, get_col_opt(opt, sz.ws_row, pos));
	term_change_clean();
}

int		move_pointer(int pos, t_opt *opt, int dir)
{
	if (dir == KEY_UP)
		pos = move_up(opt, pos);
	if (dir == KEY_DOWN)
		pos = move_down(opt, pos);
	if (dir == KEY_RIGHT)
		pos = move_right(opt, pos);
	if (dir == KEY_LEFT)
		pos = move_left(opt, pos);
	return (pos);
}
