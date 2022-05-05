#include "../../includes/push_swap.h"

void	sa(t_info *info)
{
	t_dlist	*node;

	node = info->a->next->next;
	node_erase(info->a->next->next);
	node_insert(info->a, node);
	if (info->log->prev->value == SB)
	{
		info->log->prev->value = SS;
		return ;
	}
	else
		node_insert(info->log->prev, list_new(SA));
//	ft_putstr_fd("sa\n", 1);
}

void	sb(t_info *info)
{
	t_dlist	*node;

	node = info->b->next->next;
	node_erase(info->b->next->next);
	node_insert(info->b, node);
	if (info->log->prev->value == SA)
	{
		info->log->prev->value = SS;
		return ;
	}
	else
		node_insert(info->log->prev, list_new(SB));
//	ft_putstr_fd("sb\n", 1);
}

void	ss(t_info *info)
{
	t_dlist	*node_a;
	t_dlist	*node_b;

	node_a = info->a->next->next;
	node_b = info->b->next->next;
	node_erase(info->a->next->next);
	node_erase(info->b->next->next);
	node_insert(info->a, node_a);
	node_insert(info->b, node_b);
	node_insert(info->log->prev, list_new(SS));
//	ft_putstr_fd("ss\n", 1);
}
