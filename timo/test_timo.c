/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_timo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 23:51:35 by timbert           #+#    #+#             */
/*   Updated: 2026/11/24 22:35:06 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{

	int tab[100] = {
    -13, 24, -40, -3, 34, -30, 7, 44, -20, 17,
    -47, -10, 27, -37, 0, 37, -27, 10, 47, -17,
    20, -44, -7, 30, -34, 3, 40, -24, 13, 50,
    -14, 23, -41, -4, 33, -31, 6, 43, -21, 16,
    -48, -11, 26, -38, -1, 36, -28, 9, 46, -18,
    19, -45, -8, 29, -35, 2, 39, -25, 12, 49,
    -15, 22, -42, -5, 32, -32, 5, 42, -22, 15,
    -49, -12, 25, -39, -2, 35, -29, 8, 45, -19,
    18, -46, -9, 28, -36, 1, 38, -26, 11, 48,
    -16, 21, -43, -6, 31, -33, 4, 41, -23, 14
};
	//int tab2[3] = {11, 12, 13};
	int size1;
	//int size2;
	//
	t_stack	stack_a; 
	t_stack	stack_b;


	stack_a = (t_stack){NULL, NULL, 0};
	stack_b = (t_stack){NULL, NULL, 0};
	size1 = sizeof(tab) / sizeof(tab[0]); // A garder pour calculer taille tab
	//size2 = sizeof(tab2) / sizeof(tab2[0]);
	if (!create_stack(tab, &stack_a, size1))
		return (0);
	//if (!create_stack(tab2, &stack_b, size2))
	//	return (0);
	

	t_node	*test_a;
	t_node	*test_b;
	
	simple_algo(&stack_a, &stack_b);

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
	//while (test_b)
	//{
	//	printf("%d\n", test_b->value);
	//	test_b = test_b->next;
	//}
	//printf("Tête : %d\nQueue : %d\nTaille : %d\n", stack_b.head->value, stack_b.tail->value, stack_b.size);

}
