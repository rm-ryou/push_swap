/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:21:56 by rmoriya           #+#    #+#             */
/*   Updated: 2022/04/22 19:43:28 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	lst_clear(t_dlist *list)
{
	t_dlist	*for_free;

	while (list->next != list)
	{
		for_free = list->next;
		node_erase(for_free);
		for_free->next = NULL;
		for_free->prev = NULL;
		free(for_free);
		for_free = NULL;
	}
	free(list);
	list = NULL;
}

void	free_all(t_info *info)
{
	lst_clear(info->a);
	lst_clear(info->b);
	free(info);
	info = NULL;
}
