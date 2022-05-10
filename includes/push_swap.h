#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

typedef enum e_cmd
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	t_cmd;

typedef struct s_dlist	t_dlist;

typedef struct s_dlist
{
	long	value;
	int		index;
	bool	is_compress;
	t_dlist	*next;
	t_dlist	*prev;	
}	t_dlist;

typedef struct s_info
{
	t_dlist	*a;
	t_dlist	*b;
	t_dlist	*log;
	int		value_num;
	long	sorted;
	int		mid_a;
}	t_info;

//in main.c
void	put_message(t_info *info);
//in dlist_init.c
void	init_all(t_info *info);
//in dlist_free.c
void	free_all(t_info *info);
//in dlist_util.c
int		dlist_size(t_dlist *list);
void	node_insert(t_dlist *list, t_dlist *node);
void	node_erase(t_dlist *node);
//in dlist_compress.c
void	compress(t_info *info);
//in dlist_set.c
void	set_list(t_info *info, int argc, char **argv);
t_dlist	*list_new(long value);
//in check_value.c
long	check_value(t_info *info, char *value);
//in sort_under6.c
void	sort_under6(t_info *info);
void	under3(t_info *info);
void	under2(t_info *info);
//in sort_over7.c
void	sort_over7(t_info *info);

//commands
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);
void	pa(t_info *info);
void	pb(t_info *info);
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);

//in print_log.c
void	print_log(t_info *info);

void	print_list_a(t_info *info);
void	print_list_b(t_info *info);

#endif
