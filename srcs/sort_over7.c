/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:17:17 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/20 17:40:26 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_info *info, int pa_num)
{
	while (pa_num > 0)
	{
		if (info->a->next->index == info->sorted)
		{
			ra(info);
			info->sorted += 1;
		}
		else
			pb(info);
		pa_num -= 1;
	}
}

void	sort_b(t_info *info, int mid)
{
	t_dlist	*cur;
	int		ra_num;

	ra_num = 0;
	while (dlist_size(info->b) > 0)
	{
		cur = info->b->next;
		check_list(info, cur, &ra_num, &mid);
	}
	re_rotate(info, ra_num);
}

void	divide_util(t_info *info, int *pa_num, int mid)
{
	t_dlist	*node;

	node = info->b->next;
	if (node->index == info->sorted)
		pa_and_ra(info);
	else if (node->index > mid)
	{
		pa(info);
		*pa_num += 1;
	}
	else
		rb(info);
}

bool	divide_under10(t_info *info, int pa_num, int i)
{
	int		mid;
	int		size;

	mid = get_pivo(info->b);
	size = dlist_size(info->b);
	pa_num = 0;
	if (dlist_size(info->b) <= 13)
		return (true);
	while (i < size)
	{
		divide_util(info, &pa_num, mid);
		i++;
	}
	divide_under10(info, pa_num, 0);
	sort_b(info, mid);
	push_b(info, pa_num);
	return (false);
}

void	sort_over7(t_info *info)
{
	if (info->sorted == info->value_num + 1)
		return ;
	divide_first(info);
	while (dlist_size(info->b) > 13)
		divide_under10(info, 0, 0);
	sort_b(info, info->mid_a);
	sort_over7(info);
}
