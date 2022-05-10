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
	if (info.value_num < 0)
		put_message(&info);
	else if (info.value_num <= 6)
		sort_under6(&info);
	else
		sort_over7(&info);
	print_log(&info);
//	print_list_a(&info);
	free_all(&info);
	return (0);
}

//4 1 2 3 , 4 1 3 2でリーク

/*
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG 

python3 python_visualizer.py `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`

*/


//for i in {1..10} ; do <something command> ; done


/*
12回
min = 14
max = min + pa_num - 1

*/