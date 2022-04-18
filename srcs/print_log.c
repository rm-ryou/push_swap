#include "../include/push_swap.h"

void	print_log(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->turn)
	{
		if (info->log[i] == 's')
            printf("sa\n");
		else if (info->log[i] == 'r')
            printf("ra\n");
        else if (info->log[i] == 'w')
            printf("rra\n");
        else
            continue;
		i += 1;
	}
}