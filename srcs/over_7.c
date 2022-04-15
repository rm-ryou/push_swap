#include "../include/push_swap.h"

void	rotate(t_info *info, int *turn, int ra_num)
{
	int	i;
	t_dlist	*a;
	t_dlist	*tmp_cur;

	i = 0;
	a = info->a;
	while (i < ra_num)
	{
		tmp_cur = a->next;
		ra(info);
		*turn += 1;
		i += 1;
		info->sorted += 1;
	}
}

void	sort_to_mid_util(t_info *info, int *turn)
{
	int		ra_num;
	int		mid_a_tmp;
	t_dlist	*b;
	t_dlist	*cur;

	ra_num = 0;
	b = info->b;
	mid_a_tmp = info->mid_a;
	while (dlist_size(info->b) != 0)
	{
		cur = b->next;
		if (cur->index == mid_a_tmp)
		{
			pa(info);
			ra_num += 1;
			mid_a_tmp -= 1;
		}
		else if (cur->index == info->sorted + 1)
		{
			info->sorted += 1;
			pa(info);
			*turn += 1;
			ra(info);
		}
		else
			rb(info);
		*turn += 1;
	}
	rotate(info, &info->turn, ra_num);
}

void	sort_to_mid(t_info *info, int *turn)
{
	int	i;
	t_dlist	*a;
	t_dlist	*cur;

	t_dlist	*b;
	t_dlist	*cur_b;

	i = info->sorted;
	a = info->a;
	b = info->b;
	while (i < info->mid_a)
	{
		cur = a->next;
		cur_b = b->next;

		if (cur_b->index == info->sorted + 1)
		{
			info->sorted += 1;
			pa(info);
			*turn += 1;
			ra(info);			
		}
		else if (cur->index == info->sorted + 1)
		{
			rr(info);
			info->sorted += 1;
		}

/*		if (cur->index == info->sorted + 1)
		{
			ra(info);
			info->sorted += 1;
		}*/

		else
			pb(info);
		i += 1;
	}
	if (dlist_size(info->b) > 0)
		sort_to_mid_util(info, &info->turn);
//		sort_b(info, &info->turn);
}

void	sort_b(t_info *info, int *turn)
{
	t_dlist	*b;
	t_dlist	*cur;

	info->mid_b = dlist_size(info->b) / 2;
	b = info->b;
	while (dlist_size(info->b) != 0)
	{
		cur = b->next;
		if (cur->index == info->sorted + 1)
		{
			info->sorted += 1;
			pa(info);
			*turn += 1;
			ra(info);
		}
		else if (cur->index > info->mid_b)
			pa(info);
		else
			rb(info);
		*turn += 1;
	}
	sort_to_mid(info, &info->turn);
}

void	re_rotate(t_info *info, int *turn, int rra_num)
{
	int	i;
	t_dlist	*b;
	t_dlist	*tmp_cur;

	i = 0;
	b = info->b;
	while (i < rra_num)
	{
		tmp_cur = b->next;
		if (tmp_cur->index != info->sorted + 1)
			rrr(info);
		else
			rra(info);
		*turn += 1;
		i += 1;
	}
}

void	divide(t_info *info, int *turn)
{
	int		i;
	int		rra_num;
	t_dlist	*a;
	t_dlist	*tmp_cur;

	t_dlist	*b;
	t_dlist	*tmp_cur_b;

	i = info->sorted;
	rra_num = 0;
	info->mid_a = (info->value_num + i) / 2;
	a = info->a;
	b = info->b;
	while (i < info->value_num)
	{
		tmp_cur = a->next;
		tmp_cur_b = b->next;
		if (tmp_cur->index <= info->mid_a)
			pb(info);
		else if (tmp_cur_b->index > info->mid_b)
		{
			rr(info);
			rra_num += 1;
		}
		else
		{
			ra(info);
			rra_num += 1;
		}
		*turn += 1;
		i += 1;
	}
	re_rotate(info, &info->turn, rra_num);
}

void	over_7(t_info *info)
{
	if (info->sorted == info->value_num - 1)
	{
		ra(info);
		info->turn += 1;
	}
	if (sorted(info->a) && dlist_size(info->b) == 0)
		return ;
	divide(info, &info->turn);
	sort_b(info, &info->turn);
//	print_list(info);
//	printf("----------------------------------------------\n");
//	divide(info, &info->turn);
	over_7(info);
}




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
    while(sorted(a))
    {
        //size = dlist_size(a);
		printf("test_00\n");
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
