#include "../includes/push_swap.h"

static void	check_ss(t_info *info)
{
	t_dlist	*node;

	node = info->b->next;
	if (dlist_size(info->b) && node->index < node->next->index)
		ss(info);
	else
		sa(info);
}

static void	check_rr(t_info *info)
{
	t_dlist	*node;

	node = info->b->next;
	if (dlist_size(info->b) && node->index < node->next->index)
		rr(info);
	else
		ra(info);
}

static void	check_rrr(t_info *info)
{
	t_dlist	*node;

	node = info->b->next;
	if (dlist_size(info->b) && node->index < info->b->prev->index)
		rrr(info);
	else
		rra(info);
}

void	under3(t_info *info)
{
	int	a_1;
	int	a_2;
	int	a_3;

	a_1 = info->a->next->index;
	a_2 = info->a->next->next->index;
	a_3 = info->a->next->next->next->index;
	if (a_1 < a_2 && a_2 > a_3 && a_1 < a_3)
	{
		check_ss(info);
		check_rr(info);
	}
	else if (a_1 > a_2 && a_2 < a_3 && a_1 < a_3)
		check_ss(info);
	else if (a_1 < a_2 && a_2 > a_3 && a_1 > a_3)
		check_rrr(info);
	else if (a_1 > a_2 && a_2 < a_3 && a_1 > a_3)
		check_rr(info);
	else if (a_1 > a_2 && a_2 > a_3 && a_1 > a_3)
	{
		check_ss(info);
		check_rrr(info);
	}
}