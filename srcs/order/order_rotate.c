#include "../../include/push_swap.h"

t_info	*ra(t_info *info)
{
    t_dlist *a;
    t_dlist *tmp_cur;
    t_dlist *tmp_prev;

    a = info->a;
    tmp_cur = a->next;
    tmp_prev = a->prev;
    a->next = tmp_cur->next;
    tmp_cur->next->prev = a;
    node_insert(a->prev, tmp_cur);
	if (info->value_num <= 3)
	    info->log[info->turn] = 'r';
	else
		ft_putstr_fd("ra\n", 1);
    return (info);
}

t_info	*rb(t_info *info)
{
    t_dlist *b;
    t_dlist *tmp_cur;
    t_dlist *tmp_prev;

    b = info->b;
    tmp_cur = b->next;
    tmp_prev = b->prev;
    b->next = tmp_cur->next;
    tmp_cur->next->prev = b;
    node_insert(b->prev, tmp_cur);
	ft_putstr_fd("rb\n", 1);
    return (info);
}

t_info	*rr(t_info *info)
{
	t_dlist *a;
    t_dlist *tmp_cur_a;
    t_dlist *tmp_prev_a;
    t_dlist *b;
    t_dlist *tmp_cur_b;
    t_dlist *tmp_prev_b;

	a = info->a;
    tmp_cur_a = a->next;
    tmp_prev_a = a->prev;
    a->next = tmp_cur_a->next;
    tmp_cur_a->next->prev = a;
    node_insert(a->prev, tmp_cur_a);
    b = info->b;
    tmp_cur_b = b->next;
    tmp_prev_b = b->prev;
    b->next = tmp_cur_b->next;
    tmp_cur_b->next->prev = b;
    node_insert(b->prev, tmp_cur_b);
	ft_putstr_fd("rr\n", 1);
    return (info);
}
