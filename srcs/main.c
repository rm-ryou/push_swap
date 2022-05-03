#include "../includes/push_swap.h"

__attribute__((destructor))
static void destructor() {
	system("leaks -q push_swap");
}

void	put_message(t_info *info)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	free_all(info);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_info	info;

	init_all(&info);
	set_list(&info, argc, argv);
	compress(&info);
	print_list(&info);
	if (info.value_num < 0)
		put_message(&info);
	else if (info.value_num <= 6)
		sort_under6(&info);
	else
		sort_over7(&info);
	print_list(&info);
	free_all(&info);
	return (0);
}