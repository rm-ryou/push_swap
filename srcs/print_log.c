#include "../includes/push_swap.h"

void	print_log(t_info *info)
{
	int		size = dlist_size(info->log);
	int		i = 0;
	t_dlist	*cur;

	cur = info->log->next;
	while (i < size)
	{
		if (cur->value == SA)
			ft_putstr_fd("sa\n", 1);
		else if (cur->value == SB)
			ft_putstr_fd("sb\n", 1);
		else if (cur->value == SS)
			ft_putstr_fd("ss\n", 1);
		else if (cur->value == RA)
			ft_putstr_fd("ra\n", 1);
		else if (cur->value == RB)
			ft_putstr_fd("rb\n", 1);
		else if (cur->value == RR)
			ft_putstr_fd("rr\n", 1);
		else if (cur->value == PA)
			ft_putstr_fd("pa\n", 1);
		else if (cur->value == PB)
			ft_putstr_fd("pb\n", 1);
		else if (cur->value == RRA)
			ft_putstr_fd("rra\n", 1);
		else if (cur->value == RRB)
			ft_putstr_fd("rrb\n", 1);
		else if (cur->value == RRR)
			ft_putstr_fd("rrr\n", 1);
		cur = cur->next;
		i += 1;
	}
}