/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:06:13 by akeiflin          #+#    #+#             */
/*   Updated: 2019/04/03 08:26:16 by akeiflin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_table		*create_table(int size)
{
	t_table	*t;
	int		i;

	if (size <= 0)
		return (NULL);
	t = malloc(sizeof(t_table));
	t->size = size;
	t->list = malloc(sizeof(t_tnode *) * size);
	i = 0;
	while (i < size)
	{
		t->list[i] = NULL;
		++i;
	}
	return (t);
}

int			hash_code(t_table *t, char *key)
{
	int	sum;

	sum = 0;
	while (*key)
	{
		sum += *key;
		++key;
	}
	if (sum < 0)
		return (-(sum % t->size));
	return (sum % t->size);
}

int			insert_sub(t_tnode *temp, char *key, size_t size, void *value)
{
	if (ft_strcmp(temp->key, key) == 0)
	{
		if (temp->value)
			free(temp->value);
		temp->value = value;
		temp->size = size;
		return (1);
	}
	return (0);
}

void		insert(t_table *t, char *key, void *value, size_t size)
{
	int		pos;
	t_tnode	*list;
	t_tnode	*new_node;
	t_tnode	*temp;

	if (t == NULL)
		return ;
	pos = hash_code(t, key);
	list = t->list[pos];
	temp = list;
	while (temp)
	{
		if (insert_sub(temp, key, size, value))
			return ;
		temp = temp->next;
	}
	new_node = malloc(sizeof(t_tnode));
	new_node->key = ft_strdup(key);
	new_node->value = value;
	new_node->size = size;
	new_node->next = list;
	t->list[pos] = new_node;
}

void		*lookup(t_table *t, char *key)
{
	int		pos;
	t_tnode	*list;
	t_tnode	*temp;

	if (t == NULL)
		return (NULL);
	pos = hash_code(t, key);
	list = t->list[pos];
	temp = list;
	while (temp)
	{
		if (ft_strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}
