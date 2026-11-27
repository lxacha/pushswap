/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_timo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 23:51:35 by timbert           #+#    #+#             */
/*   Updated: 2026/11/27 01:52:02 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc , char **argv)
{
	// double  disorder;
	// int	nb_args;
	t_count count;
	
	// nb_args = how_many_args(argv) * 10;
    // disorder = 0;
	if (!argv[1] || argc == 1)
			return 0;

    // disorder = calculate_disorder(*list);      
	//
	t_stack	stack_a; 
	t_stack	stack_b;

	stack_a = (t_stack){NULL, NULL, 0};
	stack_b = (t_stack){NULL, NULL, 0};
	count = (t_count){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	from_args_to_list(argv, &stack_a);

	t_node	*test_a;
	// t_node	*test_b;
	
	butterfly(&stack_a, &stack_b, &count);
	// simple_algo(&stack_a, &stack_b, &count);
	test_a = stack_a.head;
	calcul_total_ops(&count);
	printf("Stack A :\n");
	// while (test_a)
	// {
	// 	printf("Value :%d\n", test_a->value);
	// 	printf("Rank :%d\n", test_a->rank);
	// 	test_a = test_a->next;
	// }
	printf("Tête : %d\nQueue : %d\nTaille : %d\n\n", stack_a.head->value, stack_a.tail->value, stack_a.size);
	printf("Count :\n sa : %d\n sb : %d\n ss : %d\n pa : %d\n pb : %d\n ra : %d\n rb : %d\n rr : %d\n rra : %d\n rrb : %d\n rrr : %d\nTotal : %d\n", count.sa, count.sb, count.ss, count.pa, count.pb, count.ra, count.rb, count.rr, count.rra, count.rrb, count.rrr, count.total);
}
