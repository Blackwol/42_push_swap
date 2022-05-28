/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:44:00 by pcardoso          #+#    #+#             */
/*   Updated: 2022/05/02 23:44:01 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	t_node	*root_a;
	t_node	*root_b;

	root_a = NULL;
	root_b = NULL;
	create_stack(&root_a, argc, argv);
	if (!stack_sorted(&root_a))
		sort_stack(&root_a, &root_b);
	free_stack(&root_a);
	free_stack(&root_b);
	return (0);
}
