#include "../include/push_swap.h"

void	sort_to_mid(t_info *info, int *turn)
{
	int	i;
	t_dlist	*cur_a;
	t_dlist	*cur_b;

	i = info->sorted;
	while (i < info->mid_a)
	{
		cur_a = info->a->next;
		cur_b = info->b->next;
		if (cur_b->index == info->sorted)
		{
			pa(info);
			*turn += 1;
			ra(info);
			info->sorted += 1;
		}
		else if (cur_a->index == info->sorted)
		{
			rr(info);
			info->sorted += 1;
		}
		else
			pb(info);
		*turn += 1;
		i += 1;
	}
}

void	sort_b(t_info *info, int *turn)
{
	t_dlist	*cur;

	info->mid_b += dlist_size(info->b) / 2;
	while (dlist_size(info->b) != 0)
	{
		cur = info->b->next;
		if (cur->index == info->sorted)
		{
			pa(info);
			*turn += 1;
			ra(info);
			info->sorted += 1;
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
	t_dlist	*cur;

	i = 0;
	while (i < rra_num)
	{
		cur = info->b->next;
		if (cur->index != info->sorted)
			rrr(info);
		else
			rra(info);
		*turn += 1;
		i += 1;
	}
}

void	divide(t_info *info, int *turn)
{
	int	i;
	int	rra_num;
	t_dlist	*cur_a;
	t_dlist	*cur_b;

	i = info->sorted;
	info->mid_a = info->mid_a;
	info->mid_a = ((info->value_num - info->mid_a) / 2) + info->mid_a;
	rra_num = 0;
	while (i < info->value_num)
	{
		cur_a = info->a->next;
		cur_b = info->b->next;
		if (cur_a->index <= info->mid_a)
			pb(info);
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
	if (sorted(info->a) && dlist_size(info->b) == 0)
		return ;
	else if (info->sorted == info->value_num - 1)
	{
		ra(info);
		info->turn += 1;
		return ;
	}
	divide(info, &info->turn);
	sort_b(info, &info->turn);
}