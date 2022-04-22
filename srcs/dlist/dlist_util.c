/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:21:56 by rmoriya           #+#    #+#             */
/*   Updated: 2022/04/22 19:41:43 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	node_erase(t_dlist *node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
}

void	node_insert(t_dlist *list, t_dlist *node)
{
	node->next = list->next;
	list->next->prev = node;
	list->next = node;
	node->prev = list;
}

int	dlist_size(t_dlist *list)
{
	t_dlist	*tmp;
	int		size;

	tmp = list;
	size = 0;
	while (tmp->next != list)
	{
		tmp = tmp->next;
		size += 1;
	}
	return (size);
}
