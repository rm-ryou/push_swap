/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:21:56 by rmoriya           #+#    #+#             */
/*   Updated: 2022/04/22 20:00:25 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	divide_under6(t_info *info, int *turn)
{
	int		i;
	int		mid_a;
	t_dlist	*cur;

	i = 0;
	mid_a = info->value_num / 2;
	while (i < info->value_num)
	{
		cur = info->a->next;
		if (cur->index <= mid_a)
			pb(info);
		else
			ra(info);
		*turn += 1;
		i += 1;
	}
	print_log(info);
}

bool	dfs_under3_b(t_info *info, int turn)
{
	info->turn = turn;
	if (turn >= 3)
		return (false);
	if (sorted_re(info->b))
		return (true);
	if (dfs_under3_b(sb(info), turn + 1))
		return (true);
	info->turn = turn;
	sb(info);
	if (dfs_under3_b(rb(info), turn + 1))
		return (true);
	info->turn = turn;
	rrb(info);
	if (dfs_under3_b(rrb(info), turn + 1))
		return (true);
	info->turn = turn;
	rb(info);
	return (false);
}

bool	dfs_under3_a(t_info *info, int turn)
{
	info->turn = turn;
	if (turn >= 3)
		return (false);
	if (sorted(info->a))
		return (true);
	if (dfs_under3_a(sa(info), turn + 1))
		return (true);
	info->turn = turn;
	sa(info);
	if (dfs_under3_a(ra(info), turn + 1))
		return (true);
	info->turn = turn;
	rra(info);
	if (dfs_under3_a(rra(info), turn + 1))
		return (true);
	info->turn = turn;
	ra(info);
	return (false);
}

void	push_b(t_info *info, int *turn)
{
	while (dlist_size(info->b) != 0)
	{
		pa(info);
		*turn += 1;
	}
	print_log(info);
}

void	under_3(t_info *info)
{
	if (sorted(info->a))
		return ;
	if (info->value_num == 1)
		free_all(info);
	else if (info->value_num <= 3)
	{
		dfs_under3_a(info, 0);
		print_log(info);
	}
	else
	{
		divide_under6(info, &info->turn);
		dfs_under3_a(info, 0);
		print_log(info);
		dfs_under3_b(info, 0);
		print_log(info);
		push_b(info, &info->turn);
	}
}
