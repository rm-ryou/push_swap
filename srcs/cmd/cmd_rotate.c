#include "../../includes/push_swap.h"

void	ra(t_info *info)
{
	t_dlist	*node;

	node = info->a->next;
	node_erase(info->a->next);
	node_insert(info->a->prev, node);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_info *info)
{
	t_dlist	*node;

	node = info->b->next;
	node_erase(info->b->next);
	node_insert(info->b->prev, node);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_info *info)
{
	t_dlist	*node_a;
	t_dlist	*node_b;

	node_a = info->a->next;
	node_b = info->b->next;
	node_erase(info->a->next);
	node_erase(info->b->next);
	node_insert(info->a->prev, node_a);
	node_insert(info->b->prev, node_b);
	ft_putstr_fd("rr\n", 1);
}
