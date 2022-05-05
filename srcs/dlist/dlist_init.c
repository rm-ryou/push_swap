#include "../../includes/push_swap.h"

static bool	init(t_dlist **list)
{
	*list = (t_dlist *)malloc(sizeof(t_dlist));
	if (*list == NULL)
		return (false);
	(*list)->value = 0;
	(*list)->index = -1;
	(*list)->is_compress = false;
	(*list)->next = *list;
	(*list)->prev = *list;
	return (true);
}

void	init_all(t_info *info)
{
	info->value_num = 0;
	info->sorted = 1;
	info->mid_a = 0;
	if (init(&info->a) == false)
		put_message(info);
	if (init(&info->b) == false)
		put_message(info);
}
