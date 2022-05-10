/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya   <rmoriya@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:17:17 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/10 20:17:17 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_info *info)
{
	t_dlist	*node;

	if (dlist_size(info->a) <= 1)
		return ;
	node = info->a->next;
	node_erase(info->a->next);
	node_insert(info->a->prev, node);
	if (info->log->prev->value == RB)
	{
		info->log->prev->value = RR;
		return ;
	}
	else
		node_insert(info->log->prev, list_new(RA));
}

void	rb(t_info *info)
{
	t_dlist	*node;

	if (dlist_size(info->b) <= 1)
		return ;
	node = info->b->next;
	node_erase(info->b->next);
	node_insert(info->b->prev, node);
	if (info->log->prev->value == RA)
	{
		info->log->prev->value = RR;
		return ;
	}
	else
		node_insert(info->log->prev, list_new(RB));
}

void	rr(t_info *info)
{
	ra(info);
	rb(info);
}
