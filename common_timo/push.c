/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 13:40:01 by timbert           #+#    #+#             */
/*   Updated: 2026/11/24 14:28:46 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push_front(pop_front(stack_a), stack_b);
	printf("pa\n");
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	push_front(pop_front(stack_b), stack_a);
	printf("pb\n");
}
