/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 06:29:07 by akeiflin          #+#    #+#             */
/*   Updated: 2019/07/18 18:05:42 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_select.h"
#include "libft.h"

void	soft_exit(void)
{
	struct termios	s_termios;
	char			*buff;

	s_termios = *save_term();
	tcsetattr(STDIN_FILENO, 0, &s_termios);
	buff = tgetstr("ve", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar_tty);
	term_clear();
	close(tty_fd());
	exit(1);
}

void	return_res(t_opt *opt)
{
	char	*buff;
	int		i;

	buff = tgetstr("ve", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar_tty);
	term_clear();
	i = 0;
	while (opt->word)
	{
		if (opt->selected)
		{
			if (++i != 1)
				ft_putchar(' ');
			ft_putstr(opt->word);
		}
		++opt;
	}
	close(tty_fd());
	exit(0);
}

t_opt	*del_item(t_opt *old_opt, int *pos)
{
	t_opt	*new_opt;
	int		old_opt_len;
	int		i;

	old_opt_len = opt_len(old_opt);
	if (old_opt_len - 1 == 0)
		soft_exit();
	if (!(new_opt = malloc(sizeof(t_opt) * (old_opt_len))))
		exit(-1);
	i = 0;
	while (i < old_opt_len)
	{
		if (i == *pos)
			++old_opt;
		ft_memcpy(&(new_opt[i]), &(old_opt[i]), sizeof(t_opt));
		++i;
	}
	if (*pos == old_opt_len - 1)
		--(*pos);
	free(--old_opt);
	return (new_opt);
}

void	select_one(t_opt *opt, int pos)
{
	struct winsize	sz;

	ioctl(0, TIOCGWINSZ, &sz);
	if (sz.ws_col > 0 && sz.ws_row > 0)
	{
		if (opt[pos].selected == 0)
		{
			term_glow();
			opt[pos].selected = 1;
		}
		else
			opt[pos].selected = 0;
		ft_putstr_fd(opt[pos].word, tty_fd());
		cur_mov(pos % sz.ws_row, get_col_opt(opt, sz.ws_row, pos));
		term_change_clean();
	}
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
