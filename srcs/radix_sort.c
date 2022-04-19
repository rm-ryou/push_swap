#include "../include/push_swap.h"

void    radix_sort(t_info *info, int *turn)
{
	int		i;
	int		size;
	t_dlist	*cur_a;
    
    i = 0;
	while(sorted(info->a) == false)
	{
		size = 0;
        while(size < info->value_num)
        {
			cur_a = info->a->next;
            if ((cur_a->index >> i) & 1)
                ra(info);
            else
                pb(info);
			*turn += 1;
			size += 1;
        }
        while(dlist_size(info->b) > 0)
		{
            pa(info);
			*turn += 1;
		}
        i++;
	}
}
