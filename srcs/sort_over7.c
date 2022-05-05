#include "../includes/push_swap.h"
void	check_rb_mid(t_info *info, int mid);
void	check_rrb_mid(t_info *info, int mid);
void	divide_first(t_info *info);

void	push_b(t_info *info, int pa_num, int min)
{
	t_dlist	*cur;
	int		mid;
	
	mid = pa_num / 2 + min;
	while (pa_num > 0)
	{
		pb(info);
		cur = info->b->next;
		if (cur->index < mid)
			rb(info);
		pa_num -= 1;
	}
}

void	sort_b(t_info *info, int mid)
{
	t_dlist	*cur;
	int		ra_num;

	ra_num = 0;
	while (dlist_size(info->b) > 0)
	{
		cur = info->b->next;
		if (cur->index == mid)
		{
			pa(info);
			ra_num += 1;
			mid -= 1;
		}
		else if (cur->index == info->sorted)
		{
			pa(info);
			ra(info);
			info->sorted += 1;
		}
		else
			rb(info);

	}
	while (ra_num > 0)
	{
		ra(info);
		info->sorted += 1;
		ra_num -= 1;
	}
}

int	get_pivo(t_dlist *list)
{
	t_dlist	*cur;
	int		size;
	int		i;

	cur = list->next;
	size = 0;
	i = 0;
	while (i < dlist_size(list))
	{
		size += cur->index;
		cur = cur->next;
		i += 1;
	}
	return (size / i);
}

bool	divide_under10(t_info *info, int pa_num)
{
	t_dlist	*cur;
	int		mid = get_pivo(info->b);
	int		size = dlist_size(info->b);

	pa_num = 0;
	if (dlist_size(info->b) <= 10)
		return (true);
	if (size % 2 != 0)
		size += 1;
	while (dlist_size(info->b) != size / 2)
	{
		cur = info->b->next;
		if (cur->index > mid)
		{
			pa(info);
			pa_num += 1;
		}
		else
			rb(info);
	}
	divide_under10(info, pa_num);
	sort_b(info, mid);
	push_b(info, pa_num, mid + 1);
}

void	sort_over7(t_info *info)
{
	if (info->sorted == info->value_num + 1)
		return ;
	divide_first(info);
	while (dlist_size(info->b) > 10)
		divide_under10(info, 0);
	sort_b(info, info->mid_a);
	sort_over7(info);
}

void	divide_first(t_info *info)
{
	t_dlist	*cur;
	int		mid;
	int		mid_pre;

	mid_pre = info->mid_a;
	if (info->mid_a > 0)
		mid = info->value_num + 1;
	else
		mid = dlist_size(info->a) / 2 + 1;
	info->mid_a = mid - 1;	
	while (dlist_size(info->b) != (mid - 1) - mid_pre)
	{
		cur = info->a->next;
		if (cur->index < mid)
			check_rb_mid(info, (mid - mid_pre) / 2 + mid_pre);
		else if (info->a->prev->index < mid)
			rra(info);
		else
			ra(info);
	}
	check_rrb_mid(info, (mid - mid_pre) / 2 + mid_pre);
}

void	check_rb_mid(t_info *info, int mid)
{
	t_dlist	*cur;

	pb(info);
	cur = info->b->next;
	if (dlist_size(info->b) == 1)
		return ;
	else if (cur->index > mid)
		rb(info);
}

void	check_rrb_mid(t_info *info, int mid)
{
	t_dlist	*cur;

	cur = info->b->prev;
	while (cur->index >= mid)
	{
		if (info->a->next->index != info->mid_a + 1)
			rrr(info);
		else
			rrb(info);
		cur = info->b->prev;
	}
}