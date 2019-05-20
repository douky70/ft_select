/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:16:46 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/20 18:44:54 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <term.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft.h"
#include "ft_select.h"



int		init_term(void)
{
	int		ret;
	char	*term;
	struct	termios s_termios;
	char	*buff;
	
	term = getenv("TERM");
	if (term == NULL)
		return (0);
	if ((ret = tgetent(NULL, term) < 0))
		return (ret - TERM_INIT);
	if (tcgetattr(STDIN_FILENO, &s_termios) == -1)
    	return (-3 - TERM_INIT);
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

void handler(int signo)
{
	struct winsize sz;
  	ioctl(0, TIOCGWINSZ, &sz);
  	dprintf(2, "Screen width: %i  Screen height: %i\n", sz.ws_col, sz.ws_row);
	int ligne = tgetnum("li");
	dprintf(2, "LE SIGNAL EST TRIGGER --- Nombre de ligne:%i\n", ligne);
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
			term_clear();
			draw_list(opt);
			move_to_opt(opt, pos);
			underline_one(opt, pos);
			read(STDIN_FILENO, buff, 3);
			res = is_arrow(buff);
			if (res != 0)
				pos = move_pointer(pos, opt, res);
			if (buff[0] == ' ')
				select_one(opt, pos);
			if (buff[0] == '\n')
				return_res(opt);
			ft_bzero(buff, sizeof(char) * 3);
		}
	}
	return (0);
}
