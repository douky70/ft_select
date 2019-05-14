/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 06:29:07 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/14 11:01:49 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "ft_select.h"
#include "libft.h"

void	move_cur(t_opt *opt, int direction)
{
	int		len;
	int		i;

	len = 0;
	while (opt[len].word)
		++len;
	i = 0;
	while (i < len)
	{
		if (opt[i].cursor == 1)
		{
			if (direction == 1 && i > 0)
			{
				cur_up();
				opt[i].cursor = 0;
				opt[i - 1].cursor = 1;
			}
			else if (direction == 2 && i < len - 1)
			{
				cur_down();
				opt[i].cursor = 0;
				opt[i + 1].cursor = 1;
			}
			break ;
		}
		++i;
	}
}

void	select_one(t_opt *opt)
{
	int	cur;

	cur = 0;
	while (opt[cur].word)
	{
		if (opt[cur].cursor == 1)
			break;
		++cur;
	}
	if (opt[cur].selected == 0)
	{
			term_glow();
			opt[cur].selected = 1;
	}
	else
		opt[cur].selected = 0;
	ft_putstr(opt[cur].word);
	for (int j = 0; j < ft_strlen(opt[cur].word) + 1; ++j)
		cur_left();
	term_change_clean();
}

void	cur_right(void)
{
	char *buff;

	buff = tgetstr("ri", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar);
}

void	cur_left(void)
{
	char *buff;

	buff = tgetstr("le", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar);
}

void	cur_up(void)
{
	char *buff;

	buff = tgetstr("up", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar);
}

void	cur_down(void)
{
	char *buff;

	buff = tgetstr("do", NULL);
	if (buff)
		tputs(buff, 1, &ft_putchar);
}
