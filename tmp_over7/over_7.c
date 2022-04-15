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

void	sort_b(t_info *info, int *turn)
{
	int		mid_b_tmp;
	int		ra_num;
	t_dlist	*b;
	t_dlist	*cur;

	info->mid_b = dlist_size(info->b) / 2;
	mid_b_tmp = info->mid_b;
	b = info->b;
	int	i = info->sorted;
	while (i < info->mid_a)
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
		i += 1;
	}
	ra_num = 0;
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
		else if (cur->index == mid_b_tmp)
		{
			pa(info);
			ra_num += 1;
			mid_b_tmp -= 1;
		}
		else
			rb(info);
		*turn += 1;
	}
	rotate(info, &info->turn, ra_num);
}

void	re_rotate(t_info *info, int *turn, int rra_num)
{
	int	i;
	t_dlist	*b;
	t_dlist	*cur;

	i = 0;
	b = info->b;
	while (i < rra_num)
	{
		cur = b->next;
		if (cur->index != info->sorted + 1)
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
	int	mid_a;
	t_dlist	*a;
	t_dlist	*cur_a;

	t_dlist	*b;
	t_dlist	*cur_b;

	i = info->sorted;
	rra_num = 0;
	info->mid_a = ((info->value_num - info->mid_a) / 2) + info->mid_a;
	a = info->a;
	b = info->b;
	while (i < info->value_num)
	{
		cur_a = a->next;
		cur_b = b->next;
		if (cur_a->index <= info->mid_a)
			pb(info);
		else if (cur_b->index > info->mid_b)
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
	over_7(info);
}