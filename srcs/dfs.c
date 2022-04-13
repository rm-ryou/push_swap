#include "../include/push_swap.h"

bool	dfs_under3(t_info *info, int turn)
{
	info->turn = turn;
	if (turn >= 3)
		return (false);
	if (sorted(info->a))
		return (true);
	if (dfs_under3(sa(info), turn + 1))
		return (true);
	info->turn = turn;
	sa(info);
	if (dfs_under3(ra(info), turn + 1))
		return (true);
	info->turn = turn;
	rra(info);
	if (dfs_under3(rra(info), turn + 1))
		return (true);
	info->turn = turn;
	ra(info);
	return (false);
}

void	under_3(t_info *info)
{
	if (info->value_num == 1)
		free_all(info);
	else if (info->value_num <= 3)
		dfs_under3(info, 0);
}