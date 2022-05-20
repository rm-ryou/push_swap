/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over7_util2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:21:33 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/20 17:40:57 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_stack_a(t_info *info, int *ra_num)
{
	pa_and_ra(info);
	if (info->a->next->index == info->sorted && dlist_size(info->b))
	{
		ra(info);
		info->sorted += 1;
		*ra_num -= 1;
	}
}

void	check_sa(t_info *info)
{
	if (info->a->next->index == info->sorted + 1)
	{
		pa(info);
		sa(info);
	}
	else
		pa(info);
}

void	check_list(t_info *info, t_dlist *cur, int *ra_num, int *mid)
{
	if (info->b->prev->index == info->sorted)
	{
		rrb(info);
		check_stack_a(info, ra_num);	
	}
	else if (cur->index == info->sorted)
		check_stack_a(info, ra_num);
	else if (cur->index == info->sorted + 1)
	{
		pa(info);
		*ra_num += 1;
	}
	else if (cur->index == *mid)
	{
		check_sa(info);
		*ra_num += 1;
		*mid -= 1;
	}
	else
		rb(info);
}
