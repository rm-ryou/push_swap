#include "../include/push_swap.h"

void	sort_to_mid(t_info *info, int turn)
{
	int	i;
	t_dlist	*a;
	t_dlist	*cur;

	i = info->sorted + 1;
	a = info->a;
	while (i <= info->mid_a)
	{
		cur = a->next;
		if (cur->index == i)
			ra(info, info->turn);
		else
			pb(info, info->turn);
		i += 1;
	}
	print_list(info);
}


void	sort_b(t_info *info, int turn)
{
	t_dlist	*b;
	t_dlist	*cur;

	if (info->mid_b == 0)
		info->mid_b = dlist_size(info->b) / 2;
	b = info->b;
	while (dlist_size(info->b) != 0)
	{
		cur = b->next;
		if (cur->index == info->sorted + 1)
		{
			info->sorted += 1;
			pa(info, turn);
			ra(info, turn += 1);
		}
		else if (cur->index > info->mid_b)
			pa(info, turn);
		else
			rb(info, turn);
		turn += 1;
	}
	print_list(info);
	sort_to_mid(info, info->turn);
}

void	divide(t_info *info, int turn)
{
	int		i;
	int		rra_num;
	t_dlist	*a;
	t_dlist	*tmp_cur;

	i = info->sorted;
	rra_num = 0;
	if (i == info->value_num - 1)
		info->mid_a = info->value_num;
	else
		info->mid_a = (info->value_num + i) / 2;
	a = info->a;
	while (i < info->value_num)
	{
		tmp_cur = a->next;
		if (tmp_cur->index <= info->mid_a)
			pb(info, turn);
		else
		{
			ra(info, turn);
			rra_num += 1;
		}
		turn += 1;
		i += 1;
	}
	while (rra_num != 0)
	{
		rra(info, turn);
		rra_num -= 1;
	}
	info->turn += turn;
}

void	over_7(t_info *info)
{
	if (sorted(info->a) && dlist_size(info->b) == 0)
		return ;
	divide(info, 0);
	while (sorted(info->b) == false)
		sort_b(info, info->turn);
	print_list(info);
	//over_7(info);
	//ソートbとsort_to_midで再帰を作りたい
}