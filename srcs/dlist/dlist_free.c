#include "../../include/push_swap.h"

void    lst_clear(t_dlist *list)
{
    t_dlist *tmp;
    t_dlist *for_free;

    tmp = list;
    while (tmp->next != list)
    {
        for_free = tmp->next;
        node_erase(for_free);
        for_free->next = NULL;
        for_free->prev = NULL;
        free(for_free);
        for_free = NULL;
    }
    free(list);
    list = NULL;
}

void    free_all(t_info *info)
{
    lst_clear(info->a);
    lst_clear(info->b);
    free(info);
    info = NULL;
    exit(1);
}