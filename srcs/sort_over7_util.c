/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over7_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:17:17 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/20 16:06:12 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_rotate(t_info *info, int ra_num)
{
	int	i;

	i = 0;
	while (i < ra_num)
	{
		ra(info);
		info->sorted += 1;
		i += 1;
	}
}

void	pa_and_ra(t_info *info)
{
	pa(info);
	ra(info);
	info->sorted += 1;
}

int	get_pivo(t_dlist *list)
{
	t_dlist	*cur;
	int		size;
	int		i;

	cur = list->next;
	size = 0;
	i = 0;
	while (i < dlist_size(list))
	{
		size += cur->index;
		cur = cur->next;
		i += 1;
	}
	return (size / i);
}

static void	divide_first_util(t_info *info, t_dlist *list)
{
	if (info->mid_a >= info->value_num)
	{
		if (list->index == info->sorted)
		{
			ra(info);
			info->sorted += 1;
		}
		else
			pb(info);
	}
	else
	{
		if (list->index < info->mid_a + 1)
			pb(info);
		else
			ra(info);
	}
}

void	divide_first(t_info *info)
{
	t_dlist	*cur;
	int		mid;
	int		mid_pre;
	int		i;

	mid_pre = info->mid_a;
	if (info->mid_a > 0)
		mid = info->value_num + 1;
	else
		mid = dlist_size(info->a) / 2 + 1;
	info->mid_a = mid - 1;
	i = mid_pre;
	while (i < info->value_num)
	{
		cur = info->a->next;
		divide_first_util(info, cur);
		i++;
	}
}
