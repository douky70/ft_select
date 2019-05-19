/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 21:06:53 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/19 16:40:30 by akeiflin         ###   ########.fr       */
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
	if (err == 0)
		ft_putendl("TERM must be set.");
	else if (err == 0 - 10)
		ft_putendl("Could not access to the termcap database.");
	else if (err == -1 - 10)
		ft_putendl("Terminal type is not defined in termcap database.");
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