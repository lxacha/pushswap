/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 13:40:01 by timbert           #+#    #+#             */
/*   Updated: 2026/11/26 17:28:28 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b, t_count *count)
{
	push_front(pop_front(stack_a), stack_b);
	count->pa++;
	printf("pa\n");
}

void	pb(t_stack *stack_b, t_stack *stack_a, t_count *count)
{
	push_front(pop_front(stack_b), stack_a);
	count->pb++;
	printf("pb\n");
}
