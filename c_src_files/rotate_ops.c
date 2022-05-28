/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:44:03 by pcardoso          #+#    #+#             */
/*   Updated: 2022/05/02 23:44:04 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rotate(t_node **root)
{
	int		node_value;
	t_node	*new_stack_node;
	t_node	*root_node;

	if (stack_empty(*root))
		return ;
	node_value = pop(root);
	root_node = *root;
	new_stack_node = new_node(node_value);
	new_stack_node->next = NULL;
	while ((*root)->next)
		*root = (*root)->next;
	(*root)->next = new_stack_node;
	new_stack_node->previous = *root;
	*root = root_node;
	return ;
}

void	ra(t_node **root)
{
	rotate(root);
	ft_putstr_fd("ra\n", 1);
	return ;
}

void	rb(t_node **root)
{
	rotate(root);
	ft_putstr_fd("rb\n", 1);
	return ;
}

void	rr(t_node **root_a, t_node **root_b)
{
	rotate(root_a);
	rotate(root_b);
	ft_putstr_fd("rr\n", 1);
	return ;
}
