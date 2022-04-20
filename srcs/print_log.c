#include "../include/push_swap.h"

void	print_log(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->turn)
	{
		if (info->log[i] == 's')
            printf("sa\n");
		else if (info->log[i] == 'S')
            printf("sb\n");
        else if (info->log[i] == 'r')
            printf("ra\n");
		else if (info->log[i] == 'R')
            printf("rb\n");
		else if (info->log[i] == 'w')
            printf("rra\n");
        else if (info->log[i] == 'W')
            printf("rrb\n");
		else if (info->log[i] == 'p')
            printf("pa\n");
		else if (info->log[i] == 'P')
            printf("pb\n");
		i += 1;
	}
	info->turn = 0;
}