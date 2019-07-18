/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_misc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 06:06:46 by akeiflin          #+#    #+#             */
/*   Updated: 2019/07/18 18:07:30 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include <sys/ioctl.h>
#include "ft_select.h"
#include "libft.h"

void			cur_mov(int y, int x)
{
	char *buff;

	buff = tgetstr("cm", NULL);
	tputs(tgoto(buff, x, y), 1, &ft_putchar_tty);
}

void			move_to_opt(t_opt *opt, int pos)
{
	struct winsize sz;

	ioctl(0, TIOCGWINSZ, &sz);
	cur_mov(pos % sz.ws_row, get_col_opt(opt, sz.ws_row, pos));
}

void			underline_one(t_opt *opt, int pos)
{
	if (opt[pos].selected == 1)
		term_glow();
	term_underline();
	ft_putstr_fd(opt[pos].word, tty_fd());
	term_change_clean();
}

struct termios	*save_term(void)
{
	static int				i = 0;
	static struct termios	save;
	char					*term;

	if (i == 0)
	{
		term = getenv("TERM");
		if (term == NULL)
			return (NULL);
		if (tgetent(NULL, term) < 0)
			return (NULL);
		if (tcgetattr(STDIN_FILENO, &save) == -1)
			return (NULL);
		++i;
	}
	return (&save);
}

int				check_err_term_size(t_opt *opt)
{
	struct winsize	sz;
	int				len;
	int				max;
	int				tmp;
	int				i;

	ioctl(0, TIOCGWINSZ, &sz);
	len = opt_len(opt);
	i = (len / sz.ws_row) * sz.ws_row;
	max = 0;
	while (i <= len)
	{
		if (max <= (tmp = get_col_opt(opt, sz.ws_row, i)
				+ ft_strlen(opt[i].word)))
			max = tmp;
		++i;
	}
	if (sz.ws_col < max)
	{
		term_clear();
		ft_putstr_fd("Error term size", tty_fd());
		return (0);
	}
	else
		return (1);
}
