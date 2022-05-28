/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:43:57 by pcardoso          #+#    #+#             */
/*   Updated: 2022/05/02 23:43:58 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	create_stack(t_node **root, int argc, char **argv)
{
	int	argc_tmp;

	argc_tmp = argc - 1;
	while (argc_tmp > 0)
	{
		check_not_number(root, argv[argc_tmp]);
		check_duplicates(root, argv[argc_tmp]);
		check_max_min_number(root, argv[argc_tmp]);
		check_stack_size(root);
		push(root, ft_atoi(argv[argc_tmp]));
		argc_tmp--;
	}
	return ;
}

int	count_stack(t_node **root)
{
	int		count;
	t_node	*tmp_root;

	tmp_root = *root;
	count = 0;
	while (*root)
	{
		count++;
		*root = (*root)->next;
	}
	*root = tmp_root;
	return (count);
}

void	sort_stack(t_node **root_a, t_node **root_b)
{
	if (count_stack(root_a) <= 3)
		sort_three(root_a);
	else if (count_stack(root_a) <= 5)
		sort_five(root_a, root_b);
	else
		big_sort(root_a, root_b);
	return ;
}

int	stack_sorted(t_node **root)
{
	t_node	*tmp_root;

	tmp_root = *root;
	while (*root && (*root)->next)
	{
		if ((*root)->value > (*root)->next->value)
		{
			*root = tmp_root;
			return (0);
		}
		*root = (*root)->next;
	}
	*root = tmp_root;
	return (1);
}

void	set_smaller_number(t_sort_five_vars *vars, t_node **root_a)
{
	vars->node_tmp = *root_a;
	vars->current_position = 0;
	vars->nbr_position = vars->current_position;
	vars->last_nbr = vars->node_tmp->value;
	vars->node_tmp = vars->node_tmp->next;
	while (vars->current_position < count_stack(root_a) - 1)
	{
		vars->current_position++;
		if (vars->last_nbr > vars->node_tmp->value)
		{
			vars->nbr_position = vars->current_position;
			vars->last_nbr = vars->node_tmp->value;
		}
		vars->node_tmp = vars->node_tmp->next;
	}
	return ;
}
