/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 21:26:10 by akeiflin          #+#    #+#             */
/*   Updated: 2019/07/01 02:07:02 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <term.h>
#include "ft_select.h"
#include "libft.h"

int		init_term(void)
{
	int				ret;
	char			*term;
	struct termios	s_termios;
	char			*buff;

	if (!isatty(STDIN_FILENO))
		return (-20);
	s_termios = *save_term();
	s_termios.c_lflag &= ~(ICANON | ECHO);
	if (tcsetattr(STDIN_FILENO, 0, &s_termios) == -1)
		return (-4 - TERM_INIT);
	buff = tgetstr("vi", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar_tty);
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