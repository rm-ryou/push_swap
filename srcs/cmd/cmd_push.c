/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:17:17 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/20 16:12:36 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_info *info)
{
	t_dlist	*node;

	if (info->b->next == info->b)
		return ;
	node = info->b->next;
	node_erase(info->b->next);
	node_insert(info->a, node);
	node_insert(info->log->prev, list_new(PA));
}

void	pb(t_info *info)
{
	t_dlist	*node;

	if (info->a->next == info->a)
		return ;
	node = info->a->next;
	node_erase(info->a->next);
	node_insert(info->b, node);
	node_insert(info->log->prev, list_new(PB));
}
