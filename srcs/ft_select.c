/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:16:46 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/19 17:22:02 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		++i;
	}
	return (list);
}

int		main(int argc, char **argv)
{
	t_opt	*opt;
	char	buff[4] = {0};
	int		res;
	int		pos = 0;

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
			if (res != 0)
				pos = move_pointer(pos, opt, res);
			if (buff[0] == ' ')
				select_one(opt, pos);
			ft_bzero(buff, sizeof(char) * 3);
		}
	}
	return (0);
}
