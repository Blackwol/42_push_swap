/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:43:42 by pcardoso          #+#    #+#             */
/*   Updated: 2022/05/02 23:43:43 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	free_stack(t_node **root)
{
	t_node	*free_node_tmp;

	while (*root)
	{
		free_node_tmp = *root;
		*root = (*root)->next;
		free(free_node_tmp);
	}
}

void	free_big_sort_lists(long *list)
{
	free(list);
	return ;
}
