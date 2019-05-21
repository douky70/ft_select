/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 06:29:07 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/21 15:00:26 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <sys/ioctl.h>
#include "ft_select.h"
#include "libft.h"

void	select_one(t_opt *opt, int pos)
{
	int		cur;
	struct	winsize sz;

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
	struct	winsize	sz;
	int				optlen = opt_len(opt) - 1;
	
	ioctl(0, TIOCGWINSZ, &sz);
	if (dir == KEY_UP)
	{
		if (pos > 0)
			--pos;
		else
			pos = optlen;
		cur_mov(pos % sz.ws_row, get_col_opt(opt, sz.ws_row, pos));
	}
	if (dir == KEY_DOWN)
	{
		if (pos < optlen)
			++pos;
		else
			pos = 0;
		cur_mov(pos % sz.ws_row, get_col_opt(opt, sz.ws_row, pos));
		
	}
	if (dir == KEY_RIGHT)
	{
			if (pos > optlen - sz.ws_row)
			{
				if (((pos + 1) % sz.ws_row == 0) || (sz.ws_row > optlen && pos == optlen))
					pos = 0;
				else
					pos = pos % sz.ws_row + 1;
			}
			else
				pos += sz.ws_row;
			cur_mov(pos % sz.ws_row, get_col_opt(opt, sz.ws_row, pos));
	}
	if (dir == KEY_LEFT)
	{
		if (pos < sz.ws_row)
		{
			int tmp;
			if (sz.ws_row > optlen && pos == 0)
				pos = optlen;
			else
			{
				if (pos == 0)
					tmp = sz.ws_row - 1;
				else
					tmp = pos % sz.ws_row - 1;
				while (tmp + sz.ws_row <= optlen)
					tmp += sz.ws_row;
				pos = tmp;
			}
		}
		else
			pos -= sz.ws_row;
		cur_mov(pos % sz.ws_row, get_col_opt(opt, sz.ws_row, pos));
	}
	return (pos);
}
