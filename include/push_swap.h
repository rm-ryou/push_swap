/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya   <rmoriya@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:21:56 by rmoriya           #+#    #+#             */
/*   Updated: 2022/04/22 18:15:57 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_dlist
{
	int 			value;
	int				index;
	struct s_dlist  *next;
	struct s_dlist  *prev;
}   t_dlist;

typedef struct  s_info
{
	t_dlist *a;
	t_dlist *b;
	int     value_num;
	int		sorted;
	int		mid_a;
	int		mid_b;
	int     turn;
	char    log[1024];
}   t_info;


//dlist
void    free_all(t_info *info);
void    init_all(t_info **info);
void    set_list(t_info *info, int argc, char **argv);
int     dlist_size(t_dlist *list);
void    node_insert(t_dlist *list, t_dlist *node);
void    node_erase(t_dlist *node);
bool	sorted(t_dlist *list);
bool	sorted_re(t_dlist *list);
int		check_value(t_info *info, char *value);

void	print_log(t_info *info);

//dlist_tmp
void    print_list(t_info *info);

//sort_util
void	under_3(t_info *info);
void	over_7(t_info *info);
void    radix_sort(t_info *info, int *turn);
void	sort_b(t_info *info, int *turn);

//else
void    put_message(t_info *info);
void    compress_pre(t_info *info);

//order
t_info	*sa(t_info *info);		//s
t_info	*sb(t_info *info);		//S
t_info	*pa(t_info *info);		//p
t_info	*pb(t_info *info);		//P
t_info	*ra(t_info *info);		//r
t_info	*rb(t_info *info);		//R
t_info	*rra(t_info *info);		//w
t_info	*rrb(t_info *info);		//W
t_info	*rrr(t_info *info);		//T
t_info	*rr(t_info *info);		//F

#endif
