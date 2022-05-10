/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya   <rmoriya@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:17:17 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/10 20:17:17 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_info *info)
{
	t_dlist	*node;

	if (dlist_size(info->a) <= 1)
		return ;
	node = info->a->next->next;
	node_erase(info->a->next->next);
	node_insert(info->a, node);
	if (info->log->prev->value == SB)
	{
		info->log->prev->value = SS;
		return ;
	}
	else
		node_insert(info->log->prev, list_new(SA));
}

void	sb(t_info *info)
{
	t_dlist	*node;

	if (dlist_size(info->b) <= 1)
		return ;
	node = info->b->next->next;
	node_erase(info->b->next->next);
	node_insert(info->b, node);
	if (info->log->prev->value == SA)
	{
		info->log->prev->value = SS;
		return ;
	}
	else
		node_insert(info->log->prev, list_new(SB));
}

void	ss(t_info *info)
{
	sa(info);
	sb(info);
}

/*
void	ss(t_info *info)
{
	t_dlist	*node_a;
	t_dlist	*node_b;

	node_a = info->a->next->next;
	node_b = info->b->next->next;
	node_erase(info->a->next->next);
	node_erase(info->b->next->next);
	node_insert(info->a, node_a);
	node_insert(info->b, node_b);
	node_insert(info->log->prev, list_new(SS));
}*/
