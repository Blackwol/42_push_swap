/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:44:50 by pcardoso          #+#    #+#             */
/*   Updated: 2022/05/21 21:10:20 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

// structs
typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_sort_five_vars
{
	int		nbr_position;
	int		current_position;
	int		last_nbr;
	t_node	*node_tmp;
}	t_sort_five_vars;

typedef struct s_radix_vars
{
	int	i;
	int	j;
	int	max_bits;
	int	max_num;
	int	size;
	int	num;
}	t_radix_vars;

// stack.c
t_node	*new_node(int value);
int		stack_empty(t_node *root);
void	push(t_node **root, int value);
int		pop(t_node **root);

// push_swap_utils.c
void	create_stack(t_node **root, int argc, char **argv);
int		count_stack(t_node **root);
void	sort_stack(t_node **root_a, t_node **root_b);
int		stack_sorted(t_node **root);
void	set_smaller_number(t_sort_five_vars *vars, t_node **root_a);

// validations.c
void	check_duplicates(t_node **root, char *current_arg);
void	check_not_number(t_node **root, char *current_arg);
void	check_max_min_number(t_node **root, char *current_arg);
void	check_stack_size(t_node **root);

// free.c
void	free_stack(t_node **root);
void	free_big_sort_lists(long *list);

// push_ops.c
void	pa(t_node **root_a, t_node **root_b);
void	pb(t_node **root_a, t_node **root_b);

// swap_ops.c
void	swap(t_node **root);
void	sa(t_node **root);
void	sb(t_node **root);
void	ss(t_node **root_a, t_node **root_b);

// rotate_ops.c
void	rotate(t_node **root);
void	ra(t_node **root);
void	rb(t_node **root);
void	rr(t_node **root_a, t_node **root_b);

// rotate_reverse_ops.c
void	rotate_reverse(t_node **root);
void	rra(t_node **root);
void	rrb(t_node **root);
void	rrr(t_node **root_a, t_node **root_b);

// sort_three.c
void	sort_three(t_node **root_a);
void	sort_three_nbrs(int first, int sec, int third, t_node **root);

// sort_five.c
void	sort_five(t_node **root_a, t_node **root_b);
void	send_smaller_nbs(t_node **root_a, t_node **root_b);
void	send_to_b(int index, t_node **root_a, t_node **root_b);
void	send_to_b_2(int index, t_node **root_a, t_node **root_b);
void	check_send(t_node **root_a, t_node **root_b, t_sort_five_vars vars);

// big_sort.c
void	big_sort(t_node **root_a, t_node **root_b);
void	radix_sort(t_node **root_a, t_node **root_b);

// big_sort_utils.c
int		find_elem_index(long *stack_list, int node_value, int size);
void	bubble_sort(long *arr, int arr_length);
void	swap_elements(long *xp, long *yp);
void	convert_stack(t_node **root, long *stack_list, long *long_list);

#endif