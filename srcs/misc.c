/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 21:06:53 by akeiflin          #+#    #+#             */
/*   Updated: 2019/07/18 18:08:04 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "libft.h"
#include "ft_select.h"

int		opt_len(t_opt *opt)
{
	int	res;

	res = 0;
	while (opt[res].word)
		++res;
	return (res);
}

int		ft_err(int err)
{
	if (err == -21)
		ft_putendl("Termios error");
	else if (err == -20)
		ft_putendl("Not in a terminal");
	else if (err == -4)
		ft_putendl("Term modification error");
	return ((err > 0) ? 1 : 0);
}

int		is_arrow(char *buff)
{
	if (buff[0] == 27 && buff[1] == 91)
	{
		if (buff[2] == 65)
			return (KEY_UP);
		else if (buff[2] == 66)
			return (KEY_DOWN);
		else if (buff[2] == 67)
			return (KEY_RIGHT);
		else if (buff[2] == 68)
			return (KEY_LEFT);
	}
	return (0);
}

void	*opt_save(t_opt *new_opt, int *new_pos, int ret)
{
	static t_opt	*opt = NULL;
	static int		pos = 0;

	if (new_pos != NULL)
		pos = *new_pos;
	if (new_opt != NULL)
		opt = new_opt;
	if (ret == 1)
		return (opt);
	else if (ret == 2)
		return (&pos);
	else
		return (NULL);
}

void	redraw(t_opt *opt, int pos)
{
	struct winsize	sz;

	ioctl(0, TIOCGWINSZ, &sz);
	if (sz.ws_col > 0 && sz.ws_row > 0)
	{
		if (check_err_term_size(opt))
		{
			term_clear();
			draw_list(opt);
			move_to_opt(opt, pos);
			underline_one(opt, pos);
		}
	}
}
