/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:21:56 by rmoriya           #+#    #+#             */
/*   Updated: 2022/04/22 19:56:45 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	sorted(t_dlist *list)
{
	t_dlist	*node_cur;

	node_cur = list->next;
	while (node_cur->next != list)
	{
		if (node_cur->index > node_cur->next->index)
			return (false);
		node_cur = node_cur->next;
	}
	return (true);
}

bool	sorted_re(t_dlist *list)
{
	t_dlist	*node_cur;

	node_cur = list->next;
	while (node_cur != list)
	{
		if (node_cur->index < node_cur->next->index)
			return (false);
		node_cur = node_cur->next;
	}
	return (true);
}
