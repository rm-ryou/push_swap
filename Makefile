NAME := push_swap
CFLAGS := -fsanitize=address -fno-omit-frame-pointer -g # -Wall -Werror -Wextra
INCLUDE := ./include/
LIBFT_DIR := ./libft/
SRCS_DIR := ./srcs/
DLIST_DIR := ./srcs/dlist/
ORDER_DIR := ./srcs/order/
OBJS_DIR := ./objs/

.PHONY: all
all: $(NAME)

SRCS = $(SRCS_DIR)main.c\
		$(SRCS_DIR)check_sorted.c\
		$(SRCS_DIR)dfs.c\
		$(SRCS_DIR)compress.c\
		$(SRCS_DIR)over_7.c\
		$(SRCS_DIR)print_log.c\
		$(SRCS_DIR)radix_sort.c\
		$(SRCS_DIR)check_value.c\
		$(DLIST_DIR)dlist_free.c\
		$(DLIST_DIR)dlist_init.c\
		$(DLIST_DIR)dlist_print.c\
		$(DLIST_DIR)dlist_set.c\
		$(DLIST_DIR)dlist_util.c\
		$(ORDER_DIR)order_push.c\
		$(ORDER_DIR)order_reverse_rotate.c\
		$(ORDER_DIR)order_rotate.c\
		$(ORDER_DIR)order_swap.c

OBJS = $(patsubst $(SRCS_DIR)%,$(OBJS_DIR)%,$(SRCS:.c=.o))

.PHONY : all
all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)libft.a -o $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	mkdir -p $(OBJS_DIR)$(*D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean :
	make clean -C $(LIBFT_DIR)
	$(RM) -rf $(OBJS_DIR)

.PHONY : fclean
fclean : clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

.PHONY : re
re : fclean all
