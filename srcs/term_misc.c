/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_misc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 06:06:46 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/19 16:48:39 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"

void	cur_mov(int y, int x)
{
	char *buff;

	buff = tgetstr("cm", NULL);
	tputs(tgoto(buff, x, y), 1, &ft_putchar);
}


