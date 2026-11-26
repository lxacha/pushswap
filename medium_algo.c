/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 16:15:36 by timbert           #+#    #+#             */
/*   Updated: 2026/11/26 21:35:51 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int chunk_size(t_stack *stack)
{
	int sqrt;
	int size;

	sqrt = 1;
	size = 0;
	while (sqrt * sqrt <= stack->size)
		sqrt++;
	size = sqrt; // A VERIFIER : 2*sqrt ? 1.5*sqrt ? need tests for opti
	return (sqrt);
}

void	butterfly(t_stack *stack_a, t_stack *stack_b, t_count *count)
{
	int	start;
	int	end;
	int	mid;
	int size;
	int	i;

	i = 1;
	size = chunk_size(stack_a);
	while (stack_a->head != NULL)
	{
		start = i;
		end = start + size;
		mid = (end - start) / 2;
		while (i < end)
		{
			if (stack_a->head->rank >= start && stack_a->head->rank < end)
			{
				pa(stack_a, stack_b, count);
				i++;
				if (stack_a->head->rank < mid)
					rb(stack_b, 1, count);
			}
			else
				ra(stack_a, 1, count);
		}
	}
	while (stack_b->head != NULL)
	{
		if (is_bottom(get_max(stack_b), stack_b))
			while (stack_b->head->value != get_max(stack_b)->value)
				rrb(stack_b, 1, count);
		else
			while (stack_b->head->value != get_max(stack_b)->value)
				rrb(stack_b, 1, count);
		pb(stack_b, stack_a, count);
	}
}

//static void fill_chunks(t_stack *stack)
//{
//	int	i;
	
//	while 
//}