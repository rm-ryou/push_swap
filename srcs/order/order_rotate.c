/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:21:56 by rmoriya           #+#    #+#             */
/*   Updated: 2022/04/22 19:39:36 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_info	*ra(t_info *info)
{
	t_dlist	*a;
	t_dlist	*tmp_cur;

	a = info->a;
	tmp_cur = a->next;
	a->next = tmp_cur->next;
	tmp_cur->next->prev = a;
	node_insert(a->prev, tmp_cur);
	if (info->value_num <= 6)
		info->log[info->turn] = 'r';
	else
		ft_putstr_fd("ra\n", 1);
	return (info);
}

t_info	*rb(t_info *info)
{
	t_dlist	*b;
	t_dlist	*tmp_cur;

	b = info->b;
	tmp_cur = b->next;
	b->next = tmp_cur->next;
	tmp_cur->next->prev = b;
	node_insert(b->prev, tmp_cur);
	if (info->value_num <= 6)
		info->log[info->turn] = 'R';
	else
		ft_putstr_fd("rb\n", 1);
	return (info);
}

t_info	*rr(t_info *info)
{
	t_dlist	*a;
	t_dlist	*b;
	t_dlist	*tmp_cur_a;
	t_dlist	*tmp_cur_b;

	a = info->a;
	tmp_cur_a = a->next;
	a->next = tmp_cur_a->next;
	tmp_cur_a->next->prev = a;
	node_insert(a->prev, tmp_cur_a);
	b = info->b;
	tmp_cur_b = b->next;
	b->next = tmp_cur_b->next;
	tmp_cur_b->next->prev = b;
	node_insert(b->prev, tmp_cur_b);
	ft_putstr_fd("rr\n", 1);
	return (info);
}
