/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:44:05 by pcardoso          #+#    #+#             */
/*   Updated: 2022/05/02 23:44:06 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rotate_reverse(t_node **root)
{
	int		node_value;
	t_node	*root_node;

	if (stack_empty(*root))
		return ;
	root_node = *root;
	while (*root)
	{
		if ((*root)->next == NULL)
		{
			node_value = (*root)->value;
			*root = (*root)->previous;
			free((*root)->next);
			(*root)->next = NULL;
			break ;
		}
		*root = (*root)->next;
	}
	*root = root_node;
	push(root, node_value);
	return ;
}

void	rra(t_node **root)
{
	rotate_reverse(root);
	ft_putstr_fd("rra\n", 1);
	return ;
}

void	rrb(t_node **root)
{
	rotate_reverse(root);
	ft_putstr_fd("rrb\n", 1);
	return ;
}

void	rrr(t_node **root_a, t_node **root_b)
{
	rotate_reverse(root_a);
	rotate_reverse(root_b);
	ft_putstr_fd("rrr\n", 1);
	return ;
}
