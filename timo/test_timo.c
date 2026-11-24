/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_timo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 23:51:35 by timbert           #+#    #+#             */
/*   Updated: 2026/11/24 19:10:48 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{

	int	tab[10] = {3, 1, 5, 4, 2, 74, 85, -26, 8, 6};
	int tab2[3] = {11, 12, 13};
	int size1;
	int size2;
	//
	t_stack	stack_a; 
	t_stack	stack_b;


	stack_a = (t_stack){NULL, NULL, 0};
	stack_b = (t_stack){NULL, NULL, 0};
	size1 = sizeof(tab) / sizeof(tab[0]); // A garder pour calculer taille tab
	size2 = sizeof(tab2) / sizeof(tab2[0]);
	if (!create_stack(tab, &stack_a, size1))
		return (0);
	if (!create_stack(tab2, &stack_b, size2))
		return (0);
	

	t_node	*test_a;
	t_node	*test_b;
	
	ss(&stack_a, &stack_b);

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
