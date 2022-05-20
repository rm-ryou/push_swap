/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:17:17 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/20 16:12:24 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*list_new(long value)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->is_compress = false;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	set_list(t_info *info, int argc, char **argv)
{
	t_dlist	*new;
	int		i;
	long	value;

	info->value_num = argc - 1;
	i = info->value_num;
	while (i > 0)
	{
		value = check_value(info, argv[i]);
		new = list_new(value);
		if (new == NULL)
			put_message(info);
		node_insert(info->a, new);
		i -= 1;
	}
}
