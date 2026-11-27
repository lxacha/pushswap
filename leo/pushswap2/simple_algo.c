/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 20:41:03 by timbert           #+#    #+#             */
/*   Updated: 2026/11/27 14:43:07 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_algo(t_stack *stack_a, t_stack *stack_b, t_count *count)
{
	t_node	*min;

	while (stack_a && stack_a->head)
	{
		min = get_min(stack_a);
		if (is_bottom(min, stack_a))
			while (stack_a->head != min)
				rra(stack_a, 1, count);
		else
			while (stack_a->head != min)
				ra(stack_a, 1, count);
		pb(stack_a, stack_b, count);
	}
	while (stack_b && stack_b->head)
		pa(stack_b, stack_a, count);
}
