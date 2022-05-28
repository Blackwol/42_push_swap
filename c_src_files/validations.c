/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:44:20 by pcardoso          #+#    #+#             */
/*   Updated: 2022/05/21 21:01:18 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	check_duplicates(t_node **root, char *current_arg)
{
	t_node	*node_tmp;

	node_tmp = *root;
	while (node_tmp)
	{
		if (node_tmp->value == ft_atoi(current_arg))
		{
			ft_putstr_fd("Error\n", 1);
			free_stack(root);
			exit (0);
		}
		node_tmp = node_tmp->next;
	}
	return ;
}

void	check_not_number(t_node **root, char *current_arg)
{
	int	index;

	index = 0;
	if (current_arg[index] == '-' && !current_arg[index + 1])
	{
		ft_putstr_fd("Error\n", 1);
		free_stack(root);
		exit (0);
	}
	if (current_arg[index] == '-')
		index++;
	while (current_arg[index])
	{
		if (!ft_isdigit(current_arg[index]))
		{
			ft_putstr_fd("Error\n", 1);
			free_stack(root);
			exit (0);
		}
		index++;
	}
	return ;
}

void	check_max_min_number(t_node **root, char *current_arg)
{
	if (ft_atoi_l(current_arg) < INT_MIN || ft_atoi_l(current_arg) > INT_MAX)
	{
		ft_putstr_fd("Error\n", 1);
		free_stack(root);
		exit (0);
	}
	return ;
}

void	check_stack_size(t_node **root)
{
	if (count_stack(root) > INT_MAX)
	{
		ft_putstr_fd("Error\n", 1);
		free_stack(root);
		exit (0);
	}
	return ;
}
