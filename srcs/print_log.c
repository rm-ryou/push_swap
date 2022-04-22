/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:21:56 by rmoriya           #+#    #+#             */
/*   Updated: 2022/04/22 19:52:15 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_log(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->turn)
	{
		if (info->log[i] == 's')
			ft_putstr_fd("sa\n", 1);
		else if (info->log[i] == 'S')
			ft_putstr_fd("sb\n", 1);
		else if (info->log[i] == 'r')
			ft_putstr_fd("ra\n", 1);
		else if (info->log[i] == 'R')
			ft_putstr_fd("rb\n", 1);
		else if (info->log[i] == 'w')
			ft_putstr_fd("rra\n", 1);
		else if (info->log[i] == 'W')
			ft_putstr_fd("rrb\n", 1);
		else if (info->log[i] == 'p')
			ft_putstr_fd("pa\n", 1);
		else if (info->log[i] == 'P')
			ft_putstr_fd("pb\n", 1);
		i += 1;
	}
	info->turn = 0;
}
