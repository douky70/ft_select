/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:16:46 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/16 12:34:54 by akeiflin         ###   ########.fr       */
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
	if (!(list = malloc(sizeof(t_opt) * argc)))
		exit(-1);
	ft_bzero(list, sizeof(t_opt) * argc);
	while (i < argc)
	{
		list[i].word = argv[i];
		list[i].len = ft_strlen(argv[i]);
		list[i].selected = 0;
		list[i].cursor = 0;
		++i;
	}
	list[0].cursor = 1;
	return (list);
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

int		get_max(int ligne, int i, t_opt *opt)
{
	int	start;
	int	j;
	int	max;
	int	len;

	max = 0;
	j = 0;
	start = (i - (i % ligne));
	while (opt[start + j].word && j < 3)
	{
		if (max < (len = ft_strlen(opt[start + j].word)))
			max = len;
		j++;
	}
	return (max);
}

int		get_col_opt(t_opt *opt, int ligne, int pos)
{
	int res;
	int	i;

	res = 0;
	i = 0;
	while (i < pos && opt[i].word)
	{
		if ((i % ligne) == (pos % ligne))
		{
			res += get_max(ligne, i, opt) + 1;
		}
		++i;
	}
	return (res);
}

void	draw_list(t_opt *opt)
{
	int 	ligne;
	int		i;

	i = 0;
	ligne = tgetnum("li");
	while (opt[i].word)
	{
		cur_mov(i % ligne, get_col_opt(opt, ligne, i));
		ft_putstr(opt[i].word);
		++i;
	}
}

int		main(int argc, char **argv)
{
	t_opt	*opt;
	char	buff[4] = {0};
	int		res;

	if ((ft_err(init_term())))
	{
		opt = create_data_struc(--argc, ++argv);
		term_clear();
		draw_list(opt);
		term_home();
		while (1)
		{
			read(STDIN_FILENO, buff, 3);
			res = is_arrow(buff);
			if (res == KEY_UP)
				move_cur(opt, KEY_UP);
			else if (res == KEY_DOWN)
				move_cur(opt, KEY_DOWN);
			if (buff[0] == ' ')
				select_one(opt);
			ft_bzero(buff, sizeof(char) * 3);
		}
	}
	return (0);
}
