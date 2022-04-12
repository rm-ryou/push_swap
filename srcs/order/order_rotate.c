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
    info->log[info->turn] = 'r';
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
    info->log[info->turn] = 'R';
    return (info);
}
