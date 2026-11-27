/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 13:40:07 by timbert           #+#    #+#             */
/*   Updated: 2026/11/27 14:42:49 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a, int i, t_count *count)
{
	push_back(pop_front(stack_a), stack_a);
	if (i > 0)
	{
		printf("ra\n");
		count->ra++;
	}
}

void	rb(t_stack *stack_b, int i, t_count *count)
{
	push_back(pop_front(stack_b), stack_b);
	if (i > 0)
	{
		printf("rb\n");
		count->rb++;
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_count *count)
{
	ra(stack_a, 0, count);
	rb(stack_b, 0, count);
	printf("rr\n");
	count->rr++;
}
