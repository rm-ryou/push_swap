#include "../../include/push_swap.h"

void    print_list(t_info *info)
{
	t_dlist *cur_a = info->a->next;
	t_dlist *cur_b = info->b->next;

	printf("---a----a->index------b----b->index\n");
	for (; cur_a != info->a; cur_a = cur_a->next, cur_b = cur_b->next)
	    printf(" %3d     %3d        %3d     %3d\n", cur_a->value, cur_a->index, cur_b->value, cur_b->index);
	printf("-----------------------------------\n");
	//printf("--a-----b--\n");
	//for (; cur_a != info->a; cur_a = cur_a->next, cur_b = cur_b->next)
	//	printf("%3d   %3d\n", cur_a->value, cur_b->value);
	//printf("-----------\n");
}