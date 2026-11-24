/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 13:40:10 by timbert           #+#    #+#             */
/*   Updated: 2026/11/24 13:40:11 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a, int i)
{
	t_node *node;

	if (!stack_a || stack_a->head == stack_a->tail)
		return ;
	node = stack_a->head;
	stack_a->head = node->next;
	node->prev = stack_a->head;
	node->next = stack_a->head->next;
	stack_a->head->next = node;
	stack_a->head->prev = NULL;
	if (i > 0)
		printf("sa\n");
}

void	sb(t_stack *stack_b, int i)
{
	t_node *node;

	if (!stack_b || stack_b->head == stack_b->tail)
		return ;
	node = stack_b->head;
	stack_b->head = node->next;
	node->prev = stack_b->head;
	node->next = stack_b->head->next;
	stack_b->head->next = node;
	stack_b->head->prev = NULL;
	if (i > 0)
		printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	printf("ss\n");
}
