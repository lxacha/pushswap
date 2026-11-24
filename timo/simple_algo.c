/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 20:41:03 by timbert           #+#    #+#             */
/*   Updated: 2026/11/24 22:23:07 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_min(t_stack *stack_a)
{
	t_node	*node;
	t_node	*min;

	node = stack_a->head;
	min = stack_a->head;
	while (node)
	{
		if (node->value < min->value)
			min = node;
		node = node->next;
	}
	return (min);
}

static int	is_bottom(t_node *min, t_stack *stack)
{
	if (get_indice(min, stack) > (stack->size / 2))
		return (1);
	return (0);
	
}

void	simple_algo(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*min;
	
	while (stack_a && stack_a->head)
	{
		min = get_min(stack_a);
		if (is_bottom(min, stack_a))
			while (stack_a->head != min)
				rra(stack_a, 1);
		else
			while (stack_a->head != min)
				ra(stack_a, 1);
		pa(stack_a, stack_b);
	}
	while (stack_b && stack_b->head)
		pb(stack_b, stack_a);
}
