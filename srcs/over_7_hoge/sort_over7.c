#include "../includes/push_swap.h"
void	check_rb_mid(t_info *info, int mid);
void	check_rrb_mid(t_info *info, int mid);
void	divide_first(t_info *info);


void	push_b(t_info *info, int pa_num)
{
	printf("pa_num = %d\n", pa_num);
	while (pa_num > 0)
	{
		pb(info);
		pa_num -= 1;
	}
//	print_list_a(info);
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

int	get_pivo(t_info *info)
{
	t_dlist	*cur;
	int		size;
	int		i;

	cur = info->b->next;
	size = 0;
	i = 0;
	while (i < dlist_size(info->b))
	{
		size += cur->index;
		cur = cur->next;
		i += 1;
	}
	return (size / i);
}

bool	push_under10(t_info *info, int pa_num)
{
	t_dlist	*cur;
	int		i = 0;
	int		mid = get_pivo(info);
	printf("mid = %d\n", mid);

	pa_num = 0;
	if (dlist_size(info->b) <= 10)
		return (true);
	int	size = dlist_size(info->b);
	while (i < size)
	{
		cur = info->b->next;
		if (cur->index > mid)
		{
			pa(info);
			pa_num += 1;
		}
		else
			rb(info);
		i += 1;
	}
	push_under10(info, pa_num);
	sort_b(info, mid);
	push_b(info, pa_num);
}

void	divide_under10(t_info *info)
{
	int	mid;
	int	pa_num;

	pa_num = info->mid_a;
	push_under10(info, 0);
//	push_under10(info, 0);
//	push_under10(info, 0);
	printf("sorted = %ld\n", info->sorted);
	print_list_a(info);
	printf("sorted = %ld\n", info->sorted);

}

void	sort_over7(t_info *info)
{
	divide_first(info);
	divide_under10(info);
//	divide_half(info);
//	print_list_a(info);
//	divide_under10(info);
}

void	divide_first(t_info *info)
{
	t_dlist	*cur;
	int		mid;
	int		mid_pre;

	mid = dlist_size(info->a) / 2 + 1;
	info->mid_a = mid - 1;	
	mid_pre = 0;
	while (dlist_size(info->b) != mid - 1)
	{
		cur = info->a->next;
		if (cur->index < mid)
			check_rb_mid(info, (mid -mid_pre) / 2 + mid_pre);
		else if (info->a->prev->index < mid)
			rra(info);
		else
			ra(info);
	}
	check_rrb_mid(info, (mid -mid_pre) / 2 + mid_pre);
}

void	check_rb_mid(t_info *info, int mid)
{
	t_dlist	*cur;

	pb(info);
	cur = info->b->next;
	if (dlist_size(info->b) == 1)
		return ;
	else if (cur->index >= mid)
		rb(info);
}

void	check_rrb_mid(t_info *info, int mid)
{
	t_dlist	*cur;

	cur = info->b->prev;
	while (cur->index >= mid)
	{
		rrb(info);
		cur = info->b->prev;
	}
	info->b->next->is_mid = true;
}

void	divide_half(t_info *info)
{
	t_dlist	*cur;
	int		mid;

	mid = dlist_size(info->a) / 2 + 1;
	while (dlist_size(info->b) < mid - 1)
	{
		cur = info->a->next;
		if (cur->index < mid)
			pb(info);
		else if (info->a->prev->index < mid)
			rra(info);
		else
			ra(info);
	}
}

/*
void	divide_first(t_info *info);


void	divide_more(t_info *info)
{
	int	pa_num;

	pa_num = 0;
	if (dlist_size(info->b) > 10)
		return (true);
}

bool	push(t_info *info, int pa_num)
{
	if ()
}

void	divide_until_10(t_info *info)
{
	int	pa_num;

	pa_num = 0;

	push(info, pa_num);
	sort_until10(info, pa_num);
}

void	sort_over7(t_info *info)
{
	divide_first(info);
	divide_until_10(info);
}


void	divide_first(t_info *info)
{
	t_dlist	*cur;
	int		mid;

	mid = dlist_size(info->a) / 2 + 1;
	while (dlist_size(info->b) < mid - 1)
	{
		cur = info->a->next;
		if (cur->index < mid)
			pb(info);
		else if (info->a->prev->index < mid)
			rra(info);
		else
			ra(info);
	}
}
*/
