#include "../../include/push_swap.h"

t_info	*rra(t_info *info)
{
    t_dlist *a;
    t_dlist *tmp_cur;

    a = info->a;
    tmp_cur = a->prev;
    tmp_cur->prev->next = a;
    a->prev = tmp_cur->prev;
    node_insert(a, tmp_cur);
	if (info->value_num <= 3)
	    info->log[info->turn] = 'w';
	else
		ft_putstr_fd("rra\n", 1);
    return (info);
}

t_info	*rrb(t_info *info)
{
    t_dlist *b;
    t_dlist *tmp_cur;

    b = info->b;
    tmp_cur = b->prev;
    tmp_cur->prev->next = b;
    b->prev = tmp_cur->prev;
    node_insert(b, tmp_cur);
	ft_putstr_fd("rrb\n", 1);
    return (info);
}

t_info	*rrr(t_info *info)
{
    t_dlist *a;
	t_dlist *b;
    t_dlist *tmp_cur_a;
    t_dlist *tmp_cur_b;

    a = info->a;
    tmp_cur_a = a->prev;
    tmp_cur_a->prev->next = a;
    a->prev = tmp_cur_a->prev;
    node_insert(a, tmp_cur_a);
	b = info->b;
    tmp_cur_b = b->prev;
    tmp_cur_b->prev->next = b;
    b->prev = tmp_cur_b->prev;
    node_insert(b, tmp_cur_b);
	ft_putstr_fd("rrr\n", 1);
    return (info);
}