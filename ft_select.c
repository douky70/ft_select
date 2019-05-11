/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:16:46 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/11 11:48:46 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_select.h"

int		ft_err(int err)
{
	if (err == 0)
		ft_putendl("TERM must be set.");
	else if (err == 0 - 10)
		ft_putendl("Could not access to the termcap database.");
	else if (err == -1 - 10)
		ft_putendl("Terminal type is not defined in termcap database.");
	return ((err > 0) ? 1 : 0);
}

int		init_term(void)
{
	int		ret;
	char	*term;
	struct	termios s_termios;

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
	return (1);
}

t_opt	*create_data_struc(int argc, char **argv)
{
	t_opt	*list;
	int		i;

	i = 0;
	if (!(list = malloc(sizeof(t_opt) * (argc))))
		exit(-1);
	while (i < argc)
	{
		list[i].word = argv[i];
		list[i].len = ft_strlen(argv[i]);
		list[i].selected = 0;
		++i;
	}
	ft_bzero(&(list[i]), sizeof(t_opt));
	return (list);
}
void	term_clear(void)
{
	char *buff;

	buff = tgetstr("cl", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar);
}

void	term_home(void)
{
	char *buff;

	buff = tgetstr("ho", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar);
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

int		main(int argc, char **argv)
{
	t_opt	*opt;
	char	buff[4] = {0};
	int		curseur = 0;
	if ((ft_err(init_term())))
	{

		tgetnum("co");
		opt = create_data_struc(--argc, ++argv);
		term_clear();
		int i = 0;
		while (opt[i].word)
		{
			ft_putchar(0xE2);
			ft_putchar(0x9E);
			ft_putchar(0x94);
			ft_putstr(opt[i].word);
			if ((&opt[i] + 1)->word)
				ft_putchar(' ');
			++i;
		}
		ft_putchar('\n');
		term_home();
		while (1)
		{
			read(STDIN_FILENO, buff, 3);
			int res = is_arrow(buff);
			if (res == KEY_RIGHT)
			{
				if (curseur < argc - 1)
				{
					for (int j = 0; j < ft_strlen(opt[curseur].word) + 2; ++j)
						ft_putstr("\e[C");
					++curseur;
				}
			}
			if (res == KEY_LEFT)
			{
				if (curseur > 0)
				{
					for (int j = 0; j < ft_strlen(opt[curseur - 1].word) + 2; ++j)
						ft_putstr("\e[D");
					--curseur;
				}
			}
			if (buff[0] == 10)
			{
				char *termbuff;
				termbuff = tgetstr("mr", NULL);
				tputs(termbuff, 1, &ft_putchar);
				ft_putstr("\e[C");
				ft_putstr(opt[curseur].word);
				for (int j = 0; j < ft_strlen(opt[curseur].word) + 1; ++j)
						ft_putstr("\e[D");
			}
			ft_bzero(buff, sizeof(char) * 3);
		}
	}
	return (0);
}
