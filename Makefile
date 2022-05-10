NAME := push_swap
CFLAGS := -Wall -Werror -Wextra
INCLUDE := ./include
LIBFT_DIR := ./libft
SRCS_DIR :=	./srcs
DLIST_DIR := ./srcs/dlist
CMD_DIR := ./srcs/cmd
UNDER6_DIR := ./srcs/under6
OBJS_DIR := ./objs
SRCS := $(SRCS_DIR)/main.c \
		$(SRCS_DIR)/sort_over7.c \
		$(SRCS_DIR)/sort_over7_util.c \
		$(SRCS_DIR)/print_log.c \
		$(SRCS_DIR)/check_value.c \
		$(UNDER6_DIR)/sort_under6.c \
		$(UNDER6_DIR)/sort_under6_util.c \
		$(DLIST_DIR)/dlist_free.c \
		$(DLIST_DIR)/dlist_init.c \
		$(DLIST_DIR)/dlist_set.c \
		$(DLIST_DIR)/dlist_util.c \
		$(DLIST_DIR)/dlist_compress.c \
		$(CMD_DIR)/cmd_push.c \
		$(CMD_DIR)/cmd_rotate.c \
		$(CMD_DIR)/cmd_swap.c \
		$(CMD_DIR)/cmd_rotate_re.c
OBJS := $(patsubst $(SRCS_DIR)%,$(OBJS_DIR)%,$(SRCS:.c=.o))

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)/$(*D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	make clean -C $(LIBFT_DIR)
	$(RM) -rf $(OBJS_DIR)

.PHONY: fclean
fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

.PHONY: re
re: fclean all
