/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 13:40:07 by timbert           #+#    #+#             */
/*   Updated: 2026/11/24 13:40:08 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ra(t_stack *stack_a, int i)
{
	push_back(pop_front(stack_a), stack_a);
	if (i > 0)
		printf("ra\n");
}

void	rb(t_stack *stack_b, int i)
{
	push_back(pop_front(stack_b), stack_b);
	if (i > 0)
		printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	printf("rr\n");
}
