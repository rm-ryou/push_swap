#include "../include/push_swap.h"

__attribute__((destructor))
static void destructor() {
	system("leaks -q so_long");
}

void    put_message(t_info *info)
{
	printf("Error\n");
	free_all(info);
	exit(1);
}

int main(int argc, char **argv)
{
	t_info  *info;

	init_all(&info);
	set_list(info, argc, argv);
	compress_pre(info);

	int flg = sorted(info->a);
	if (flg)
		printf("is_sorted\n");
	else
		printf("not_sorted\n");
//	print_list(info);

	if (sorted(info->a))
		free_all(info);
	if (info->value_num <= 0)
		put_message(info);
	else if (info->value_num <= 3)
		under_3(info);
	else
		over_7(info);

//	print_list(info);
	free_all(info);
}