/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya   <rmoriya@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:52:16 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/20 16:52:29 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list_b(t_info *info)
{
	t_dlist	*cur_a = info->a->next;
	t_dlist	*cur_b = info->b->next;

	printf("---a----a->index------b----b->index\n");
	for (; /*cur_a != info->a*/  cur_b != info->b; cur_a = cur_a->next, cur_b = cur_b->next)
		printf(" %3ld     %3d        %3ld     %3d\n", cur_a->value, cur_a->index, cur_b->value, cur_b->index);
	printf("-----------------------------------\n");
}

void	print_list_a(t_info *info)
{
	t_dlist	*cur_a = info->a->next;
	t_dlist	*cur_b = info->b->next;

	printf("---a----a->index------b----b->index\n");
	for (; cur_a != info->a  /*cur_b != info->b*/; cur_a = cur_a->next, cur_b = cur_b->next)
		printf(" %3ld     %3d        %3ld     %3d\n", cur_a->value, cur_a->index, cur_b->value, cur_b->index);
	printf("-----------------------------------\n");
}