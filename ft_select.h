/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:41:35 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/11 09:30:04 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# define TERM_INIT 10


# define KEY_UP 	1
# define KEY_DOWN	2
# define KEY_LEFT	3
# define KEY_RIGHT	4

typedef struct s_opt
{
	char			*word;
	unsigned int	len;
	char			selected;
}				t_opt;

#endif
