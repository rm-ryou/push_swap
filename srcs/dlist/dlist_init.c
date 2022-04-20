#include "../../include/push_swap.h"

void    init(t_info **info, t_dlist **list)
{
    *list = (t_dlist *)malloc(sizeof(t_dlist));
    if (*list == NULL)
        put_message(*info);
    (*list)->value = 0;
	(*list)->index = -1;
    (*list)->next = *list;
    (*list)->prev = *list;
}

void    init_all(t_info **info)
{
    *info = malloc(sizeof(t_info));
    if (*info == NULL)
        put_message(*info);
    (*info)->value_num = 0;
	(*info)->sorted = 0;
	(*info)->mid_a = 0;
	(*info)->mid_b = 0;
	(*info)->turn = 0;
    init(&(*info), &(*info)->a);
    init(&(*info), &(*info)->b);
}