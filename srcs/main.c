/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:17:17 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/10 20:19:14 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_message(t_info *info)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	free_all(info);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_info	info;

	init_all(&info);
	set_list(&info, argc, argv);
	compress(&info);
	if (info.value_num < 0)
		put_message(&info);
	else if (info.value_num <= 6)
		sort_under6(&info);
	else
		sort_over7(&info);
	print_log(&info);
	free_all(&info);
	return (0);
}
