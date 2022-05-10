/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya   <rmoriya@student.42tokyo.j>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:17:17 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/10 20:17:17 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	check_value(t_info *info, char *value)
{
	int		i;
	int		value_len;
	char	*str;

	value_len = ft_strlen(value);
	str = ft_itoa(ft_atoi(value));
	if (ft_strncmp(value, str, value_len) != 0)
	{
		free(str);
		put_message(info);
	}
	free(str);
	i = 0;
	if (value[i] == '\0')
		put_message(info);
	else if (value[i] == '-')
		i += 1;
	while (value[i] != '\0')
	{
		if (value[i] < '0' || value[i] > '9')
			put_message(info);
		i += 1;
	}
	return (ft_atoi(value));
}
