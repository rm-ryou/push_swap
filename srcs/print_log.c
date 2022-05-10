/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya   <rmoriya@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:17:17 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/10 20:17:17 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	print_str(int value)
{
	if (value == SA)
		ft_putstr_fd("sa\n", 1);
	else if (value == SB)
		ft_putstr_fd("sb\n", 1);
	else if (value == SS)
		ft_putstr_fd("ss\n", 1);
	else if (value == RA)
		ft_putstr_fd("ra\n", 1);
	else if (value == RB)
		ft_putstr_fd("rb\n", 1);
	else if (value == RR)
		ft_putstr_fd("rr\n", 1);
	else if (value == PA)
		ft_putstr_fd("pa\n", 1);
	else if (value == PB)
		ft_putstr_fd("pb\n", 1);
	else if (value == RRA)
		ft_putstr_fd("rra\n", 1);
	else if (value == RRB)
		ft_putstr_fd("rrb\n", 1);
	else if (value == RRR)
		ft_putstr_fd("rrr\n", 1);
}

void	print_log(t_info *info)
{
	t_dlist	*cur;

	cur = info->log->next;
	while (cur != info->log)
	{
		print_str(cur->value);
		cur = cur->next;
	}
}
