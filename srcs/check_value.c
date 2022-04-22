#include "../include/push_swap.h"

int	check_value(t_info *info, char *value)
{
	int		i;
	int		res;
	int		value_len;
	char	*str;

	value_len = ft_strlen(value);
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
	res = ft_atoi(value);
	str = ft_itoa(res);
	if (ft_strncmp(value, str, value_len) != 0)
	{
		free(str);
		put_message(info);
	}
	free(str);
	return (res);
}