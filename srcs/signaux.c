/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:10:04 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/31 18:45:39 by akeiflin         ###   ########.fr       */
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
}

void	handler_kill(void)
{
	soft_exit();
}

void	signal_pause(void)
{
	struct termios	s_termios;
	char			*buff;

	s_termios = *save_term();
	tcsetattr(STDIN_FILENO, 0, &s_termios);
	buff = tgetstr("ve", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar);
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDIN_FILENO, TIOCSTI, "\x1A");
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
	if (signo == SIGCONT)
		signal_continue();
	if (signo == SIGINT)
		handler_kill();
}
