/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:16:46 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/20 01:17:39 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <term.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft.h"
#include "ft_select.h"

void	soft_exit(void)
{
	struct termios	s_termios;
	char			*buff;

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
	int				ret;
	char			*term;
	struct termios	s_termios;
	char			*buff;

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

t_opt	*del_item(t_opt *old_opt, int pos)
{
	t_opt	*new_opt;
	int		old_opt_len;
	int		i;

	old_opt_len = opt_len(old_opt);
	new_opt = malloc(sizeof(t_opt) * (old_opt_len));
	i = 0;
	while (i < old_opt_len)
	{
		if (i == pos)
			++old_opt;
		ft_memcpy(&(new_opt[i]), &(old_opt[i]), sizeof(t_opt));
		++i;
	}
	--old_opt;
	free(old_opt);
	return (new_opt);
}

int		main(int argc, char **argv)
{
	t_opt	*opt;
	char	buff[4] = {0};
	int		res;
	int		pos = 0;

	if (argc == 1)
		soft_exit();
	signal(SIGWINCH, &handler_resize);
	signal(SIGINT, &signal_handler);
	signal(SIGTSTP, &signal_handler);
	signal(SIGCONT, &signal_handler);
	if ((ft_err(init_term())))
	{
		opt = create_data_struc(argc, ++argv);
		if (opt_len(opt) <= 0)
					soft_exit();
		while (1)
		{
			opt_save(opt, &pos, 0);
			redraw(opt, pos);
			read(STDIN_FILENO, buff, 4);
			res = is_arrow(buff);
			if (res != 0)
				pos = move_pointer(pos, opt, res);
			else if (buff[0] == ' ')
				select_one(opt, pos);
			else if (buff[0] == '\n')
				return_res(opt);
			else if (buff[0] == 127 || (buff[0] == 27 && buff[1] == 91 && buff[2] == 51 && buff[3] == 126))
			{
				opt = del_item(opt, pos);
				if (pos == opt_len(opt))
					--pos;
				if (opt_len(opt) <= 0)
					soft_exit();
			}
			else if (buff[0] == 27)
				soft_exit();
			ft_bzero(buff, sizeof(char) * 3);
		}
	}
	return (0);
}

//TODO
//ecirire sur /dev/tty pour faire fonctionner les ls `./ft_select`
//safe mallocs
//isatty
//Signaux
//pas d'affichage taille de la fenetre
//27 91 51 126
// termcapt 'ti' ry 'te' (save et restore term) ????
