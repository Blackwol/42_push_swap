/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:44:11 by pcardoso          #+#    #+#             */
/*   Updated: 2022/05/02 23:44:12 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_node	*new_node(int value)
{
	t_node	*stack_node;

	stack_node = malloc(sizeof(t_node));
	stack_node->value = value;
	return (stack_node);
}

int	stack_empty(t_node *root)
{
	return (!root);
}

void	push(t_node **root, int value)
{
	t_node	*stack_node;

	stack_node = new_node(value);
	stack_node->next = *root;
	stack_node->previous = NULL;
	if (*root != NULL)
		(*root)->previous = stack_node;
	*root = stack_node;
	return ;
}

int	pop(t_node **root)
{
	int	popped;

	if (stack_empty(*root))
		return (0);
	popped = (*root)->value;
	if ((*root)->next)
	{
		*root = (*root)->next;
		free((*root)->previous);
		(*root)->previous = NULL;
	}
	else
	{
		free(*root);
		*root = NULL;
	}
	return (popped);
}
