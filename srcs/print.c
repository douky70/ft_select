/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 21:57:53 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/21 15:00:49 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <term.h>
#include "libft.h"
#include "ft_select.h"

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
	struct 	winsize sz;
	int		i;

	i = 0;
	ioctl(0, TIOCGWINSZ, &sz);
	while (opt[i].word)
	{
		cur_mov(i % sz.ws_row , get_col_opt(opt, sz.ws_row , i));
		if (opt[i].selected)
			term_glow();
		ft_putstr(opt[i].word);
		if (opt[i].selected)
			term_change_clean();
		++i;
	}
}
