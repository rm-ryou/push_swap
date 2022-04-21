#include "../include/push_swap.h"

int	check_value(t_info *info, char *value)
{
	int	i;
	int	res;

	i =  0;
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