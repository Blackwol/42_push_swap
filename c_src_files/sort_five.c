/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:44:08 by pcardoso          #+#    #+#             */
/*   Updated: 2022/05/02 23:44:09 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_five(t_node **root_a, t_node **root_b)
{
	send_smaller_nbs(root_a, root_b);
	sort_three(root_a);
	pa(root_a, root_b);
	pa(root_a, root_b);
	return ;
}

void	send_smaller_nbs(t_node **root_a, t_node **root_b)
{
	t_sort_five_vars	vars;

	set_smaller_number(&vars, root_a);
	check_send(root_a, root_b, vars);
	return ;
}

void	check_send(t_node **root_a, t_node **root_b, t_sort_five_vars vars)
{
	if (count_stack(root_a) == 5)
	{
		send_to_b(vars.nbr_position, root_a, root_b);
		set_smaller_number(&vars, root_a);
		send_to_b_2(vars.nbr_position, root_a, root_b);
	}
	else
		send_to_b_2(vars.nbr_position, root_a, root_b);
	return ;
}

void	send_to_b(int index, t_node **root_a, t_node **root_b)
{
	if (index == 0)
		pb(root_a, root_b);
	else if (index == 1)
	{
		ra(root_a);
		pb(root_a, root_b);
	}
	else if (index == 2)
	{
		ra(root_a);
		ra(root_a);
		pb(root_a, root_b);
	}
	else if (index == 3)
	{
		rra(root_a);
		rra(root_a);
		pb(root_a, root_b);
	}
	else if (index == 4)
	{
		rra(root_a);
		pb(root_a, root_b);
	}
	return ;
}

void	send_to_b_2(int ind, t_node **root_a, t_node **root_b)
{
	if (ind == 0)
		pb(root_a, root_b);
	else if (ind == 1)
	{
		ra(root_a);
		pb(root_a, root_b);
	}
	else if (ind == 2)
	{
		ra(root_a);
		ra(root_a);
		pb(root_a, root_b);
	}
	else if (ind == 3)
	{
		rra(root_a);
		pb(root_a, root_b);
	}
	return ;
}
