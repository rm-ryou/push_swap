#include "../include/push_swap.h"

__attribute__((destructor))
static void destructor() {
	system("leaks -q so_long");
}

void    put_message(t_info *info)
{
	printf("Error\n");
	free_all(info);
	exit(1);
}

int main(int argc, char **argv)
{
	t_info  *info;

	init_all(&info);
	set_list(info, argc, argv);
	compress_pre(info);

	print_list(info);

	if (sorted(info->a))
		free_all(info);
	if (info->value_num <= 0)
		put_message(info);
	else if (info->value_num <= 3)
		under_3(info);
	else// if (info->value_num <= 100)
		over_7(info);
/*	else
		sort(info, &info->turn);*/

	for (int i = 0; i < info->turn; i++)
    {
        if (info->log[i] == 's')
            printf("sa     i = %d\n", i);
        else if (info->log[i] == 'S')
            printf("sb     i = %d\n", i);
        else if (info->log[i] == 'p')
            printf("pa     i = %d\n", i);
        else if (info->log[i] == 'P')
            printf("pb     i = %d\n", i);
        else if (info->log[i] == 'r')
            printf("ra     i = %d\n", i);
        else if (info->log[i] == 'R')
            printf("rb     i = %d\n", i);
        else if (info->log[i] == 'w')
            printf("rra    i = %d\n", i);
        else if (info->log[i] == 'W')
            printf("rrb    i = %d\n", i);
		else if (info->log[i] == 'T')
            printf("rrr    i = %d\n", i);
		else if (info->log[i] == 'F')
            printf("rr     i = %d\n", i);
        else
            continue;
    }
	//print_list(info);
	free_all(info);
}

//ruby -e "puts (0..100).to_a.shuffle.join(' ')"; 

//ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG 