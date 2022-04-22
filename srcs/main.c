/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:21:56 by rmoriya           #+#    #+#             */
/*   Updated: 2022/04/22 19:51:45 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	put_message(t_info *info)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	free_all(info);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	init_all(&info);
	set_list(info, argc, argv);
	compress_pre(info);
	if (info->value_num <= 0)
		put_message(info);
	else if (info->value_num <= 6)
		under_3(info);
	else if (info->value_num <= 100)
		over_7(info);
	else
		radix_sort(info, &info->turn);
	free_all(info);
	return (0);
}
