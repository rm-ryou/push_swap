#include "../../include/push_swap.h"

t_dlist *list_new(t_info *info, int value)
{
	t_dlist *new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (new == NULL)
		put_message(info);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void    set_list(t_info *info, int argc, char **argv)
{
	int i;
	int value;
	t_dlist *new;

	info->value_num = argc - 1;
	i = info->value_num;
	while (i > 0)
	{
		new = list_new(info, value);
	//	value = ft_atoi(argv[i]);
		value = check_value(info, argv[i]);
		node_insert(info->a, list_new(info, value));
		free(new);
		i -= 1;
	}
}