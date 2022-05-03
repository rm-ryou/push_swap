#include "../../includes/push_swap.h"

static long	search_min(t_info *info)
{
	long	min;
	t_dlist	*cur_node;

	cur_node = info->a->next;
	min = LONG_MAX;
	while (cur_node != info->a)
	{
		if (!cur_node->is_compress && min > cur_node->value)
			min = cur_node->value;
		cur_node = cur_node->next;
	}
	return (min);
}

void	compress(t_info *info)
{
	t_dlist	*cur_node;
	long	min_value;
	int		i;
	int		j;

	i = 0;
	while (i < dlist_size(info->a))
	{
		min_value = search_min(info);
		cur_node = info->a->next;
		j = 0;
		while (j < dlist_size(info->a))
		{
			if (cur_node->is_compress && min_value == cur_node->value)
				put_message(info);
			else if (!cur_node->is_compress && min_value == cur_node->value)
			{
				cur_node->index = i + 1;
				cur_node->is_compress = true;
				break ;
			}
			cur_node = cur_node->next;
			j += 1;
		}
		i += 1;
	}
}
