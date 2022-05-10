/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya   <rmoriya@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:17:17 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/10 20:17:17 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	under2(t_info *info)
{
	if (dlist_size(info->a) != 2)
		return ;
	else if (info->a->next->index > info->a->next->next->index)
		sa(info);
}

static void	divide_a(t_info *info)
{
	int		mid;
	t_dlist	*cur;

	mid = dlist_size(info->a) / 2;
	while (dlist_size(info->a) > 3)
	{
		cur = info->a->next;
		if (cur->index <= mid)
			pb(info);
		else
		{
			if (info->b->next->index != mid)
				rr(info);
			else
				ra(info);
		}
	}
}

static void	under3_b(t_info *info)
{
	int	b_1;
	int	b_2;
	int	b_3;

	b_1 = info->b->next->index;
	b_2 = info->b->next->next->index;
	b_3 = info->b->next->next->next->index;
	if (b_1 < b_2 && b_2 < b_3 && b_1 < b_3)
	{
		sb(info);
		rrb(info);
	}
	else if (b_1 < b_2 && b_2 > b_3 && b_1 < b_3)
		rb(info);
	else if (b_1 > b_2 && b_2 < b_3 && b_1 < b_3)
		rrb(info);
	else if (b_1 < b_2 && b_2 > b_3 && b_1 > b_3)
		sb(info);
	else if (b_1 > b_2 && b_2 < b_3 && b_1 > b_3)
	{
		rrb(info);
		sb(info);
	}
}

static void	under6(t_info *info)
{
	divide_a(info);
	under3(info);
	if (dlist_size(info->b) < 3)
	{
		if (info->b->next->index == 1)
			sb(info);
	}
	else if (dlist_size(info->b) == 3)
		under3_b(info);
	while (dlist_size(info->b))
		pa(info);
}

void	sort_under6(t_info *info)
{
	if (info->value_num == 2)
		under2(info);
	else if (info->value_num <= 3)
		under3(info);
	else
		under6(info);
}
