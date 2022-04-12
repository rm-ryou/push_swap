#include "../../include/push_swap.h"

t_info	*sa(t_info *info, int turn)
{
	t_dlist *a;
	t_dlist *tmp_cur;
	t_dlist *tmp_next;

	a = info->a;
	tmp_cur = a->next;
	tmp_next = a->next->next;
	a->next = tmp_next;
	tmp_next->next->prev = tmp_cur;
	tmp_cur->prev = tmp_next;
	tmp_cur->next = tmp_next->next;
	tmp_next->prev = a;
	tmp_next->next = tmp_cur;
	info->log[info->turn + turn] = 's';
	return (info);
}

t_info	*sb(t_info *info, int turn)
{
	t_dlist *b;
	t_dlist *tmp_cur;
	t_dlist *tmp_next;

	b = info->b;
	tmp_cur = b->next;
	tmp_next = b->next->next;
	b->next = tmp_next;
	tmp_next->next->prev = tmp_cur;
	tmp_cur->prev = tmp_next;
	tmp_cur->next = tmp_next->next;
	tmp_next->prev = b;
	tmp_next->next = tmp_cur;
	info->log[info->turn + turn] = 'S';
	return (info);
}

/*bool    sa(t_info *info)
{
	t_dlist *a;
	t_dlist *tmp_cur;
	t_dlist *tmp_next;

	a = info->a;
	tmp_cur = a->next;
	tmp_next = a->next->next;
	a->next = tmp_next;
	tmp_next->next->prev = tmp_cur;
	tmp_cur->prev = tmp_next;
	tmp_cur->next = tmp_next->next;
	tmp_next->prev = a;
	tmp_next->next = tmp_cur;
	info->log[info->turn] = 's';
	return (true);
}

bool    sb(t_info *info)
{
	t_dlist *b;
	t_dlist *tmp_cur;
	t_dlist *tmp_next;

	b = info->b;
	tmp_cur = b->next;
	tmp_next = b->next->next;
	b->next = tmp_next;
	tmp_next->next->prev = tmp_cur;
	tmp_cur->prev = tmp_next;
	tmp_cur->next = tmp_next->next;
	tmp_next->prev = b;
	tmp_next->next = tmp_cur;
	info->log[info->turn] = 'S';
	return (true);
}
*/