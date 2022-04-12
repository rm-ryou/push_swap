#include "../include/push_swap.h"

bool	dfs_under3(t_info *info, int turn)
{
	if (turn >= 3)
		return (false);
	if (sorted(info->a))
	{
		info->turn += turn;
		return (true);
	}
	if (dfs_under3(sa(info, turn), turn + 1))
		return (true);
	sa(info, turn);
	if (dfs_under3(ra(info, turn), turn + 1))
		return (true);
	rra(info, turn);
	if (dfs_under3(rra(info, turn), turn + 1))
		return (true);
	ra(info, turn);
	return (false);
}

void	under_3(t_info *info)
{
	print_list(info);

	if (info->value_num == 1)
		free_all(info);
	else if (info->value_num <= 3)
		dfs_under3(info, 0);


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
        else
            continue;
    }
	print_list(info);
}