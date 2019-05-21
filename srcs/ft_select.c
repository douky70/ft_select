/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:16:46 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/21 18:10:24 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <term.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft.h"
#include "ft_select.h"

struct termios	*save_term(void)
{
	static			int	i = 0;
	static struct	termios	save;
	char	*term;

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

void	soft_exit(void)
{
	struct	termios s_termios;
	char	*buff;

	s_termios = *save_term();
	tcsetattr(STDIN_FILENO, 0, &s_termios);
	buff = tgetstr("ve", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar);
	term_clear();
	exit(1);
}

int		init_term(void)
{
	int		ret;
	char	*term;
	struct	termios s_termios;
	char	*buff;
	s_termios = *save_term();
	s_termios.c_lflag &= ~(ICANON); /* Met le terminal en mode non canonique. La fonction read recevra les entrées clavier en direct sans attendre qu'on appuie sur Enter */
    s_termios.c_lflag &= ~(ECHO); /* Les touches tapées au clavier ne s'affficheront plus dans le terminal */
	if (tcsetattr(STDIN_FILENO, 0, &s_termios) == -1)
        return (-4 - TERM_INIT);
	buff = tgetstr("vi", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar);
	return (1);
}

t_opt	*create_data_struc(int argc, char **argv)
{
	t_opt	*list;
	int		i;

	i = 0;
	if (!(list = malloc(sizeof(t_opt) * argc)))
		exit(-1);
	ft_bzero(list, sizeof(t_opt) * argc);
	while (i < argc)
	{
		list[i].word = argv[i];
		list[i].len = ft_strlen(argv[i]);
		list[i].selected = 0;
		++i;
	}
	return (list);
}

void	return_res(t_opt *opt)
{
	char	*buff;
	int		i;
	
	buff = tgetstr("ve", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar);
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
	exit(0);
}

void	*opt_save(t_opt *new_opt, int *new_pos, int ret)
{
	static t_opt	*opt = NULL;
	static int		pos = 0;

	if (new_opt != NULL)
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

void handler(int signo)
{
	t_opt	*opt;
	int		pos;

	opt = opt_save(NULL, NULL, 1);
	pos = *((int *)opt_save(NULL, NULL, 2));
	term_clear();
	draw_list(opt);
	move_to_opt(opt, pos);
	underline_one(opt, pos);
}

int		main(int argc, char **argv)
{
	t_opt	*opt;
	char	buff[4] = {0};
	int		res;
	int		pos = 0;

	signal(SIGWINCH, handler);
	if ((ft_err(init_term())))
	{
		opt = create_data_struc(argc, ++argv);
		while (1)
		{
			opt_save(opt, &pos, 0);
			term_clear();
			draw_list(opt);
			move_to_opt(opt, pos);
			underline_one(opt, pos);
			read(STDIN_FILENO, buff, 3);
			res = is_arrow(buff);
			if (res != 0)
				pos = move_pointer(pos, opt, res);
			else if (buff[0] == ' ')
				select_one(opt, pos);
			else if (buff[0] == '\n')
				return_res(opt);
			else if (buff[0] == 27)
				soft_exit();
			ft_bzero(buff, sizeof(char) * 3);
		}
	}
	return (0);
}
