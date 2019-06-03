/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:39:50 by akeiflin          #+#    #+#             */
/*   Updated: 2019/06/03 20:49:46 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "ft_select.h"
#include "libft.h"

int		move_up(t_opt *opt, int pos)
{
	int				optlen;
	struct winsize	sz;

	ioctl(0, TIOCGWINSZ, &sz);
	if (sz.ws_col > 0 && sz.ws_row > 0)
	{
		optlen = opt_len(opt) - 1;
		if (pos > 0)
			--pos;
		else
			pos = optlen;
		cur_mov(pos % sz.ws_row, get_col_opt(opt, sz.ws_row, pos));
	}
	return (pos);
}

int		move_down(t_opt *opt, int pos)
{
	int				optlen;
	struct winsize	sz;

	ioctl(0, TIOCGWINSZ, &sz);
	if (sz.ws_col > 0 && sz.ws_row > 0)
	{
		optlen = opt_len(opt) - 1;
		if (pos < optlen)
			++pos;
		else
			pos = 0;
		cur_mov(pos % sz.ws_row, get_col_opt(opt, sz.ws_row, pos));
	}
	return (pos);
}

int		move_right(t_opt *opt, int pos)
{
	int				optlen;
	struct winsize	sz;

	ioctl(0, TIOCGWINSZ, &sz);
	if (sz.ws_col > 0 && sz.ws_row > 0)
	{
		optlen = opt_len(opt) - 1;
		if (pos > optlen - sz.ws_row)
		{
			if (((pos + 1) % sz.ws_row == 0)
				|| (sz.ws_row > optlen && pos == optlen))
				pos = 0;
			else
				pos = pos % sz.ws_row + 1;
		}
		else
			pos += sz.ws_row;
		cur_mov(pos % sz.ws_row, get_col_opt(opt, sz.ws_row, pos));
	}
	return (pos);
}

int		move_left(t_opt *opt, int pos)
{
	int				tmp;
	int				optlen;
	struct winsize	sz;

	ioctl(0, TIOCGWINSZ, &sz);
	if (sz.ws_col > 0 && sz.ws_row > 0)
	{
		optlen = opt_len(opt) - 1;
		if (pos < sz.ws_row)
		{
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
