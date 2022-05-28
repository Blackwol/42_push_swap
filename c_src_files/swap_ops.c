/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:44:17 by pcardoso          #+#    #+#             */
/*   Updated: 2022/05/02 23:44:18 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap(t_node **root)
{
	int	stack_aux1;
	int	stack_aux2;

	stack_aux1 = pop(root);
	stack_aux2 = pop(root);
	push(root, stack_aux1);
	push(root, stack_aux2);
	return ;
}

void	sa(t_node **root)
{
	swap(root);
	ft_putstr_fd("sa\n", 1);
	return ;
}

void	sb(t_node **root)
{
	swap(root);
	ft_putstr_fd("sb\n", 1);
	return ;
}

void	ss(t_node **root_a, t_node **root_b)
{
	swap(root_a);
	swap(root_b);
	ft_putstr_fd("ss\n", 1);
	return ;
}
