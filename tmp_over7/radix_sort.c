#include "../include/push_swap.h"

void    sort(t_info *info, int *turn)
{
	int		i;
	int		size;
	t_dlist	*a;
	t_dlist	*b;
	t_dlist	*cur_a;
	t_dlist	*cur_b;
    
    i = 0;
	//cur_a = a->next;
	a = info->a;
	cur_b = b->next;
	size = 0;
    while(sorted(a) == false)
    {
        //size = dlist_size(a);
		printf("test_00\n");
		size = 0;
        while(size < info->value_num)
        {
			cur_a = a->next;
            if ((cur_a->index >> i) & 1)
                ra(info);
            else
                pb(info);
			*turn += 1;
			size += 1;
			printf("test_01\n");
        }
        while(dlist_size(info->b) != 0)
		{
            pa(info);
			*turn += 1;
			printf("test_02\n");
		}
		printf("test_03\n");
        i++;
		print_list(info);
    }
}
