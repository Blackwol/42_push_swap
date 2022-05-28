/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:42:50 by pcardoso          #+#    #+#             */
/*   Updated: 2022/05/02 23:42:51 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	find_elem_index(long *stack_list, int node_value, int size)
{
	int	index;

	index = 0;
	while (size)
	{
		if (stack_list[index] == node_value)
			break ;
		index++;
		size--;
	}
	return (index);
}

void	convert_stack(t_node **root, long *stack_list, long *long_list)
{
	int	index;
	int	size;

	size = count_stack(root);
	while (*root)
	{
		index = find_elem_index(stack_list, (*root)->value, size);
		(*root)->value = long_list[index];
		*root = (*root)->next;
		if (!(*root)->next)
		{
			index = find_elem_index(stack_list, (*root)->value, size);
			(*root)->value = long_list[index];
			break ;
		}
	}
	while ((*root)->previous)
		*root = (*root)->previous;
	free_big_sort_lists(stack_list);
	free_big_sort_lists(long_list);
	return ;
}

void	bubble_sort(long *arr, int arr_length)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr_length)
	{
		j = 0;
		while (j < arr_length - 1)
		{
			if (arr[j] > arr[j + 1])
				swap_elements(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
	return ;
}

void	swap_elements(long *xp, long *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}
