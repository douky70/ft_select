/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:16:46 by akeiflin          #+#    #+#             */
/*   Updated: 2019/07/23 21:08:38 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_select.h"

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
		return (0);
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
