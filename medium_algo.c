/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 16:15:36 by timbert           #+#    #+#             */
/*   Updated: 2026/11/26 23:46:54 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int chunk_size(t_stack *stack)
{
	int sqrt;

	sqrt = 1;
	while (sqrt * sqrt <= stack->size)
		sqrt++;
	return (sqrt);
}

void	butterfly(t_stack *stack_a, t_stack *stack_b, t_count *count)
{
	int	start;
	int	end;
	int	mid;
	int size;
	int	i;
	t_node *tmp;

	i = 1;
	size = chunk_size(stack_a);
	while (stack_a->head != NULL)
	{
		start = i;
		end = start + size;
		mid = start + size / 2;
		while (i <= end && stack_a->head != NULL)
		{
			if (stack_a->head->rank >= start && stack_a->head->rank <= end)
			{
				pb(stack_a, stack_b, count);
				i++;
				if (stack_b->head->rank < mid)
					rb(stack_b, 1, count);
			}
			else
				ra(stack_a, 1, count);
		}
	}
	while (stack_b->head != NULL)
	{
		tmp = get_max(stack_b);
		if (is_bottom(tmp, stack_b))
			while (stack_b->head->value != tmp->value)
				rrb(stack_b, 1, count);
		else
			while (stack_b->head->value != tmp->value)
				rb(stack_b, 1, count);
		pa(stack_b, stack_a, count);
	}
}

//static void fill_chunks(t_stack *stack)
//{
//	int	i;
	
//	while 
//}