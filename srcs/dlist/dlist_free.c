/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:17:17 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/20 16:12:13 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	list_clear(t_dlist *list)
{
	t_dlist	*for_free;

	while (list->next != list)
	{
		for_free = list->next;
		node_erase(for_free);
		free(for_free);
		for_free = NULL;
	}
	free(list);
	list = NULL;
}

void	free_all(t_info *info)
{
	list_clear(info->a);
	list_clear(info->b);
	list_clear(info->log);
}
