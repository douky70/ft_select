/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:41:35 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/17 23:29:43 by akeiflin         ###   ########.fr       */
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


void	term_clear(void);
void	term_home(void);
void	term_glow(void);
void	term_put(char *code);
void	term_change_clean(void);
void	select_one(t_opt *opt, int cur);

int		move_pointer(int pos, t_opt *opt, int dir);
int		get_col_opt(t_opt *opt, int ligne, int pos);

void	cur_mov(int y, int x);
#endif
