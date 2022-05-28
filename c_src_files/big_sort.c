/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:42:59 by pcardoso          #+#    #+#             */
/*   Updated: 2022/05/02 23:43:00 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	big_sort(t_node **root_a, t_node **root_b)
{
	long	*long_list;
	long	*stack_list;
	long	index;
	t_node	*head;

	head = *root_a;
	long_list = malloc(sizeof(long) * count_stack(root_a));
	stack_list = malloc(sizeof(long) * count_stack(root_a));
	index = 0;
	while (index < count_stack(root_a))
	{
		long_list[index] = index;
		index++;
	}
	index = 0;
	while (head)
	{
		stack_list[index] = head->value;
		head = head->next;
		index++;
	}
	bubble_sort(stack_list, count_stack(root_a));
	convert_stack(root_a, stack_list, long_list);
	radix_sort(root_a, root_b);
	return ;
}

void	radix_sort(t_node **root_a, t_node **root_b)
{
	t_radix_vars	vars;

	vars.size = count_stack(root_a);
	vars.max_num = vars.size - 1;
	vars.max_bits = 0;
	vars.i = 0;
	while (vars.max_num >> vars.max_bits != 0)
		vars.max_bits++;
	while (vars.i < vars.max_bits)
	{
		vars.j = 0;
		while (vars.j < vars.size)
		{
			vars.num = (*root_a)->value;
			if (((vars.num >> vars.i) & 1) == 1)
				ra(root_a);
			else
				pb(root_a, root_b);
			vars.j++;
		}
		vars.i++;
		while (!(stack_empty(*root_b)))
			pa(root_a, root_b);
	}
	return ;
}
