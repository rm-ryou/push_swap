#include "../includes/push_swap.h"
void	divide_first(t_info *info);




void	push_b(t_info *info, int pa_num)
{
	while (pa_num > 0)
	{
		if (info->a->next->index == info->sorted)
		{
			ra(info);
			info->sorted += 1;
		}
		else
			pb(info);
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
		if (info->b->prev->index == info->sorted)
		{
			rrb(info);
			pa(info);
			ra(info);
			info->sorted += 1;
		}
		else if (cur->index == info->sorted)
		{
			pa(info);
			ra(info);
			info->sorted += 1;
		}
		else if (cur->index == mid)
		{
			pa(info);
			ra_num += 1;
			mid -= 1;
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
	if (dlist_size(info->b) <= 13)
		return (true);
	int	i = 0;
	while (i < size)
	{
		cur = info->b->next;
		if (cur->index == info->sorted)
		{
			pa(info);
			ra(info);
			info->sorted += 1;
		}
		else if (cur->index > mid)
		{
			pa(info);
			pa_num += 1;
		}
		else
			rb(info);
		i++;
	}
	divide_under10(info, pa_num);
	sort_b(info, mid);
	push_b(info, pa_num);
	return (false);
}

void	sort_over7(t_info *info)
{
	if (info->sorted == info->value_num + 1)
		return ;
	divide_first(info);
	while (dlist_size(info->b) > 13)
		divide_under10(info, 0);
	sort_b(info, info->mid_a);
	sort_over7(info);
}

static void	divide_first_util(t_info *info, t_dlist *list)
{
	if (info->mid_a >= info->value_num)
	{
		if (list->index == info->sorted)
		{
			ra(info);
			info->sorted += 1;
		}
		else
			pb(info);
	}
	else
	{
		if (list->index < info->mid_a + 1)
			pb(info);
		else
			ra(info);
	}
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
	int	i = mid_pre;
	while (i < info->value_num)
	{
		cur = info->a->next;
		divide_first_util(info, cur);
		i++;
	}
}
