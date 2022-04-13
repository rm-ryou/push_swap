#include "../include/push_swap.h"

void	sort_to_mid(t_info *info, int *turn)
{
	int	i;
	t_dlist	*a;
	t_dlist	*cur;

	i = info->sorted;
	a = info->a;
	while (i < info->mid_a)
	{
		cur = a->next;
		if (cur->index == info->sorted + 1)
		{
			ra(info);
			info->sorted += 1;
		}
		else
			pb(info);
		i += 1;
	}
	if (dlist_size(info->b) > 0)
		sort_b(info, &info->turn);
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

	i = 0;
	while (i < rra_num)
	{
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

	i = info->sorted;
	rra_num = 0;
	info->mid_a = (info->value_num + i) / 2;
	a = info->a;
	while (i < info->value_num)
	{
		tmp_cur = a->next;
		if (tmp_cur->index <= info->mid_a)
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
	if (info->sorted == info->value_num - 1)
	{
		ra(info);
		info->turn += 1;
	}
	if (sorted(info->a) && dlist_size(info->b) == 0)
		return ;
	divide(info, &info->turn);
	sort_b(info, &info->turn);
	over_7(info);
}