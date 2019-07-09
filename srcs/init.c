/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 21:26:10 by akeiflin          #+#    #+#             */
/*   Updated: 2019/07/09 21:44:18 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <term.h>
#include "ft_select.h"
#include "libft.h"

int		ft_putchar_tty(int c)
{
	int fd;

	fd = tty_fd();
	write(fd, &c, 1);
	return (1);
}

int		tty_fd(void)
{
	static int	fd = -1;
	char		*tty_name;

	if (fd < 0)
	{
		tty_name = ttyname(STDIN_FILENO);
		if (tty_name)
		{
			if ((fd = open(tty_name, O_RDWR | O_NOCTTY )) < 0)
				return (-1);
		}
		else
			return (-1);
	}
	return (fd);
}

int		init_term(void)
{
	struct termios	*s_termios;
	char			*buff;

	if (!isatty(STDIN_FILENO))
		return (-20);
	s_termios = save_term();
	if (s_termios == NULL)
		return (-21);
	s_termios->c_lflag &= ~(ICANON | ECHO);
	if (tcsetattr(STDIN_FILENO, 0, s_termios) == -1)
		return (-4);
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