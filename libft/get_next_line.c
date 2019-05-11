/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:01:06 by akeiflin          #+#    #+#             */
/*   Updated: 2019/03/26 16:00:10 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

t_list		*ft_looking_fd(t_list *list, int fd)
{
	t_fd	*content;
	t_fd	*tmp;

	tmp = (t_fd *)list->content;
	while (((t_fd *)list->content)->fd != fd)
	{
		if (!list->next)
			break ;
		list = list->next;
		tmp = (t_fd *)list->content;
	}
	if (((t_fd *)list->content)->fd != fd)
	{
		if (!(content = malloc(sizeof(t_fd))))
			return (NULL);
		if (!(list->next = ft_lstnew(content, sizeof(t_fd))))
			return (NULL);
		free(content);
		((t_fd *)list->next->content)->fd = fd;
		((t_fd *)list->next->content)->buff = NULL;
		list = list->next;
	}
	return (list);
}

static char	*until_n(t_fd *ref)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	char	*res;
	int		ret;

	ret = 1;
	while (!(res = ft_strchr(ref->buff, '\n')) && ret > 0)
	{
		ret = read(ref->fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
		tmp = ref->buff;
		ref->buff = ft_strljoin(ref->buff, buff, NONE);
		ft_strdel(&tmp);
	}
	return (res);
}

static int	ft_read_line(t_fd *fd, char **line)
{
	char	*tmp;
	char	*tofree;

	if ((tmp = until_n(fd)))
	{
		*line = ft_strsub(fd->buff, 0, tmp - fd->buff);
		tofree = fd->buff;
		fd->buff = ft_strdup(tmp + 1);
		ft_strdel(&tofree);
	}
	else
	{
		*line = ft_strdup(fd->buff);
		ft_strdel(&(fd->buff));
		if (**line == '\0')
			return (0);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*list = NULL;
	t_list			*working;
	t_fd			*content;

	if (fd < 0 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	if (!list)
	{
		if (!(content = malloc(sizeof(t_fd))))
			return (-1);
		if (!(list = ft_lstnew(content, sizeof(t_fd))))
			return (-1);
		free(content);
		((t_fd *)list->content)->fd = fd;
		((t_fd *)list->content)->buff = NULL;
		working = list;
	}
	else
	{
		working = list;
		if (!(working = ft_looking_fd(working, fd)))
			return (-1);
	}
	return (ft_read_line((t_fd *)working->content, line));
}
