/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:16:46 by akeiflin          #+#    #+#             */
/*   Updated: 2019/06/04 23:01:30 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <term.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft.h"
#include "ft_select.h"

int		tty_fd(void)
{
	static int	fd = -1;
	char		*tty_name;

	if (fd < 0)
	{
		tty_name = ttyname(STDOUT_FILENO);
		if (tty_name)
		{
			if ((fd = open(tty_name, O_WRONLY)) < 0)
				return (-1);
		}
		else
			return (-1);
	}
	return (fd);
}

void	key_handler(t_opt *opt)
{
	char	buff[4];
	int		res;
	int		pos;

	pos = 0;
	ft_bzero(buff, sizeof(char) * 4);
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
		else if (buff[0] == 127 || (buff[0] == 27 && buff[1] == 91 
				&& buff[2] == 51 && buff[3] == 126))
			opt = del_item(opt, &pos);
		else if (buff[0] == 27)
			soft_exit();
		ft_bzero(buff, sizeof(char) * 3);
		}
}

int		main(int argc, char **argv)
{
	t_opt	*opt;

	if (argc == 1)
		soft_exit();
	init_signal();
	if ((ft_err(init_term())))
	{
		opt = create_data_struc(argc, ++argv);
		if (opt_len(opt) <= 0)
			soft_exit();
		key_handler(opt);		
	}
	return (0);
}

//TODO
//ecirire sur tty pour faire fonctionner les ls `./ft_select`
//safe mallocs
//isatty
//Signaux
//pas d'affichage taille de la fenetre
//27 91 51 126
// termcapt 'ti' ry 'te' (save et restore term) ????
