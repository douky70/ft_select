/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:41:35 by akeiflin          #+#    #+#             */
/*   Updated: 2019/05/23 16:12:17 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# define TERM_INIT 10


# define KEY_UP 	1
# define KEY_DOWN	2
# define KEY_LEFT	3
# define KEY_RIGHT	4

typedef struct	s_opt
{
	char			*word;
	unsigned int	len;
	char			selected;
}				t_opt;

/*
**	print.c
*/

void			draw_list(t_opt *opt);
int				get_col_opt(t_opt *opt, int ligne, int pos);

/*
**	term_misc.c
*/

void			cur_mov(int y, int x);
void			move_to_opt(t_opt *opt, int pos);
void			underline_one(t_opt *opt, int pos);
struct termios	*save_term(void);
/*
**	termcapfonc.c
*/

void			term_clear(void);
void			term_home(void);
void			term_glow(void);
void			term_underline(void);
void			term_change_clean(void);

/*
**	action.c
*/

void			select_one(t_opt *opt, int cur);
int				move_pointer(int pos, t_opt *opt, int dir);

/*
**	misc.c
*/

int				opt_len(t_opt *opt);
int				ft_err(int err);
int				is_arrow(char *buff);
void			*opt_save(t_opt *new_opt, int *new_pos, int ret);
/*
**	signaux.c
*/

void			handler_resize(int signo);
#endif
