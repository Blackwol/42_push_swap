/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:43:49 by pcardoso          #+#    #+#             */
/*   Updated: 2022/05/02 23:43:50 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	pa(t_node **root_a, t_node **root_b)
{
	if (*root_b)
	{
		push(root_a, pop(root_b));
		ft_putstr_fd("pa\n", 1);
	}
	return ;
}

void	pb(t_node **root_a, t_node **root_b)
{
	if (*root_a)
	{
		push(root_b, pop(root_a));
		ft_putstr_fd("pb\n", 1);
	}
	return ;
}
