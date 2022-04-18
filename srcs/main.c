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
	if (sorted(info->a))
		free_all(info);
	if (info->value_num <= 0)
		put_message(info);
	else if (info->value_num <= 3)
	{
		under_3(info);
		print_log(info);
	}
	else
		over_7(info);

//	print_list(info);
	free_all(info);
}

//ruby -e "puts (0..100).to_a.shuffle.join(' ')"; 

//ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG 

//./push_swap 66 21 8 95 47 74 15 38 96 48 49 20 35 17 28 51 68 52 12 63 19 29 39 67 7 2 100 91 46 44 90 85 6 30 92 57 98 88 50 1 53 60 37 18 24 73 76 58 83 64 3 80 94 43 97 9 82 5 59 45 34 54 84 86 56 87 36 4 78 70 32 65 99 62 79 26 75 33 25 22 31 11 69 13 89 41 40 81 16 55 23 61 72 42 27 71 10 77 93 14