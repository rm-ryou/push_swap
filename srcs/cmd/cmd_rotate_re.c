/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate_re.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:17:17 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/20 16:12:42 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_info *info)
{
	t_dlist	*node;

	if (dlist_size(info->a) <= 1)
		return ;
	node = info->a->prev;
	node_erase(info->a->prev);
	node_insert(info->a, node);
	if (info->log->prev->value == RRB)
	{
		info->log->prev->value = RRR;
		return ;
	}
	else
		node_insert(info->log->prev, list_new(RRA));
}

void	rrb(t_info *info)
{
	t_dlist	*node;

	if (dlist_size(info->b) <= 1)
		return ;
	node = info->b->prev;
	node_erase(info->b->prev);
	node_insert(info->b, node);
	if (info->log->prev->value == RRA)
	{
		info->log->prev->value = RRR;
		return ;
	}
	else
		node_insert(info->log->prev, list_new(RRB));
}

void	rrr(t_info *info)
{
	rra(info);
	rrb(info);
}
