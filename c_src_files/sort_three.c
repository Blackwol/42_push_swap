/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:44:14 by pcardoso          #+#    #+#             */
/*   Updated: 2022/05/21 23:25:08 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_three(t_node **root_a)
{
	int	first;
	int	second;
	int	third;

	first = 0;
	second = 0;
	third = 0;
	if (count_stack(root_a) == 3)
		sort_three_nbrs(first, second, third, root_a);
	else
		ra(root_a);
	return ;
}

void	sort_three_nbrs(int first, int sec, int third, t_node **root)
{
	first = (*root)->value;
	sec = (*root)->next->value;
	third = (*root)->next->next->value;
	if (first > sec && first < third && sec < third)
		sa(root);
	if (first > sec && first > third && sec < third)
		ra(root);
	if (first < sec && first > third && sec > third)
		rra(root);
	if (first > sec && first > third && sec > third)
	{
		sa(root);
		rra(root);
	}
	if (first < sec && first < third && sec > third)
	{
		sa(root);
		ra(root);
	}
	return ;
}
