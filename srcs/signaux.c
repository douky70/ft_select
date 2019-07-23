/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:10:04 by akeiflin          #+#    #+#             */
/*   Updated: 2019/07/23 20:37:07 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <unistd.h>
#include <term.h>
#include <signal.h>
#include "libft.h"
#include "ft_select.h"

void	handler_resize(int signo)
{
	t_opt	*opt;
	int		pos;

	opt = opt_save(NULL, NULL, 1);
	pos = *((int *)opt_save(NULL, NULL, 2));
	redraw(opt, pos);
	(void)signo;
}

void	signal_pause(void)
{
	struct termios	s_termios;
	char			*buff;

	s_termios = *save_term();
	tcsetattr(STDIN_FILENO, 0, &s_termios);
	buff = tgetstr("ve", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar_tty);
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDOUT_FILENO, TIOCSTI, "\x1A");
}

void	signal_continue(void)
{
	signal(SIGTSTP, &signal_handler);
	init_term();
	handler_resize(0);
}

void	signal_handler(int signo)
{
	if (signo == SIGTSTP)
		signal_pause();
	else if (signo == SIGCONT)
		signal_continue();
	else
		soft_exit();
}

void	init_signal(void)
{
	int	i;

	i = 0;
	signal(SIGWINCH, &handler_resize);
	signal(SIGTSTP, &signal_handler);
	signal(SIGCONT, &signal_handler);
	while (++i <= 15)
		signal(i, &signal_handler);
	signal(24, &signal_handler);
	signal(25, &signal_handler);
	signal(26, &signal_handler);
	signal(27, &signal_handler);
	signal(30, &signal_handler);
	signal(31, &signal_handler);
}
