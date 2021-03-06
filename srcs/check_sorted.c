/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:08:46 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/20 16:11:47 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_dlist *list)
{
	t_dlist	*node_cur;

	node_cur = list->next;
	while (node_cur->next != list)
	{
		if (node_cur->index > node_cur->next->index)
			return (false);
		node_cur = node_cur->next;
	}
	return (true);
}
