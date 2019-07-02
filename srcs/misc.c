/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 21:06:53 by akeiflin          #+#    #+#             */
/*   Updated: 2019/07/02 03:53:34 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_select.h"

int		opt_len(t_opt *opt)
{
	int	res;

	res = 0;
	while (opt[res].word)
		++res;
	return (res);
}

int		ft_err(int err)
{
	if (err == -21)
		ft_putendl("Termios error");
	else if (err == -20)
		ft_putendl("Not in a terminal");
	else if (err == -4)
		ft_putendl("Term modification error");
	return ((err > 0) ? 1 : 0);
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

void	*opt_save(t_opt *new_opt, int *new_pos, int ret)
{
	static t_opt	*opt = NULL;
	static int		pos = 0;

	if (new_pos != NULL)
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
