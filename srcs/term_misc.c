/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_misc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 06:06:46 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/23 17:00:36 by akeiflin         ###   ########.fr       */
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
	tputs(tgoto(buff, x, y), 1, &ft_putchar);
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
	ft_putstr(opt[pos].word);
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
