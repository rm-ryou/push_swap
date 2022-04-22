/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:21:56 by rmoriya           #+#    #+#             */
/*   Updated: 2022/04/22 19:56:28 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	*set_array(t_info *info)
{
	t_dlist	*list;
	int		*array;
	int		i;
	int		size;

	list = info->a->next;
	size = info->value_num;
	array = (int *)malloc(sizeof(int) * (size + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = list->value;
		list = list->next;
		i += 1;
	}
	array[i] = '\0';
	return (array);
}

static void	my_swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

static void	quick_sort(int *array, int left, int right)
{
	int	i;
	int	j;
	int	mid;
	int	mid_index;

	if (right - left <= 1)
		return ;
	mid_index = left + (right - left) / 2;
	mid = array[mid_index];
	my_swap(&array[mid_index], &array[right - 1]);
	i = left;
	j = left;
	while (j < right - 1)
	{
		if (array[j] < mid)
		{
			my_swap(&array[i], &array[j]);
			i += 1;
		}
		j += 1;
	}
	my_swap(&array[i], &array[right - 1]);
	quick_sort(array, left, i);
	quick_sort(array, i + 1, right);
}

static void	compress(t_info *info, int *a, int *b)
{
	t_dlist	*list;
	int		i;
	int		j;
	bool	flg;

	list = info->a->next;
	i = 0;
	while (i < info->value_num)
	{
		flg = false;
		j = 0;
		while (j < info->value_num)
		{
			if (b[j] == a[i])
			{
				if (flg == true)
					put_message(info);
				list->index = j + 1;
				flg = true;
			}
			j += 1;
		}
		list = list->next;
		i += 1;
	}
}

void	compress_pre(t_info *info)
{
	int	*array;
	int	*array_sorted;

	array = set_array(info);
	array_sorted = set_array(info);
	quick_sort(array_sorted, 0, info->value_num);
	compress(info, array, array_sorted);
	free(array);
	free(array_sorted);
}
