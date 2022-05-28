CFLAGS = -Wall -Wextra -Werror
CC = gcc

# Libft
LIBFT_DIR = ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

# Files to compile push_swap
c_src_push_swap = ./c_src_files/push_swap_utils.c ./c_src_files/free.c ./c_src_files/rotate_reverse_ops.c \
									./c_src_files/rotate_ops.c ./c_src_files/stack.c ./c_src_files/validations.c \
									./c_src_files/push_ops.c ./c_src_files/swap_ops.c ./c_src_files/sort_three.c ./c_src_files/sort_five.c \
									./c_src_files/big_sort.c ./c_src_files/big_sort_utils.c
c_obj_push_swap=$(c_src_push_swap:.c=.o)

# Files with mains
main_push_swap = ./c_src_files/push_swap.c

# Exec files names
NAME = push_swap

all: $(NAME)

$(NAME): $(c_obj_push_swap) $(LIBFT)
	$(CC) $(CFLAGS) $(main_push_swap) $(c_obj_push_swap) $(LIBFT) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBFT):
	make all -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(c_obj_push_swap)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY:	all re clean fclean
