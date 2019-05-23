/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:10:04 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/23 16:18:08 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"
#include "ft_select.h"

void	handler_resize(int signo)
{
	t_opt	*opt;
	int		pos;

	opt = opt_save(NULL, NULL, 1);
	pos = *((int *)opt_save(NULL, NULL, 2));
	term_clear();
	draw_list(opt);
	move_to_opt(opt, pos);
	underline_one(opt, pos);
}
