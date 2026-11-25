/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 13:40:04 by timbert           #+#    #+#             */
/*   Updated: 2026/11/24 13:40:05 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	rra(t_stack *stack_a, int i)
{
	push_front(pop_back(stack_a), stack_a);
	if (i > 0)
		printf("rra\n");
}

void	rrb(t_stack *stack_b, int i)
{
	push_front(pop_back(stack_b), stack_b);
	if (i > 0)
		printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	printf("rrr\n");
}