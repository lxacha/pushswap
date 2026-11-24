/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_timo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 23:51:35 by timbert           #+#    #+#             */
/*   Updated: 2026/11/24 01:31:27 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	// Test tableau de int
	int	tab[10] = {3, 1, 5, 4, 2, 74, 85, -26, 8, 6};
	int	size = 10;
	//
	t_stack	stack_a; 
	t_stack	stack_b;

	// Créer stack_a à partir du tab et stack_b vide ; write error si int en double
	stack_a = (t_stack){NULL, NULL, 0};
	stack_b = (t_stack){NULL, NULL, 0};
	if (!create_stack(tab, size, &stack_a))
		return (0);
	
	// Test des fonctions de base : déplacer haut de a vers bas de b et bas de a vers haut de b
	t_node	*test_a;
	t_node	*test_b;
	t_node	*node;
	node = pop_back(&stack_a);
	push_front(node, &stack_b);
	node = pop_front(&stack_a);
	push_back(node, &stack_b);
	test_a = stack_a.head;
	test_b = stack_b.head;
	printf("Stack A :\n");
	while (test_a)
	{
		printf("%d\n", test_a->value);
		test_a = test_a->next;
	}
	printf("Tête : %d\nQueue : %d\nTaille : %d\n\n", stack_a.head->value, stack_a.tail->value, stack_a.size);
	printf("Stack B :\n");
	while (test_b)
	{
		printf("%d\n", test_b->value);
		test_b = test_b->next;
	}
	printf("Tête : %d\nQueue : %d\nTaille : %d\n", stack_b.head->value, stack_b.tail->value, stack_b.size);

}
