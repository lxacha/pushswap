/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_disorder_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 21:10:21 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/27 21:18:54 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *a)
{
	printf("%s\n",a);
}

int	is_there_duplicates(t_stack *stack_a)
{
	t_node *cursor1;
	t_node *cursor2;

	cursor1 = stack_a->head;
	cursor2 = stack_a->head->next;
	while(cursor1 && cursor1->next)
	{
		while (cursor2)
		{
			if (cursor2->value == cursor1->value)
			{
				return (TRUE);
			}	
			cursor2 = cursor2->next;
		}
		cursor1 = cursor1->next;
		cursor2 = cursor1->next;
	}
	return (FALSE);
}

int	ft_strlen(char *a)
{
	int	index;

	index = 0;
	while(a[index] != '\0')
		index++;
	return (index);
}

static int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
// atoi related skips spaces newline carriage return and so on
static long long	skip_start(const char *nptr, long *neg)
{
	long long		i;

	i = 0;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			*neg = -1;
		i++;
	}
	return (i);
}
// atoi related skips + - and retains if -
long long	ft_atoi(const char *nptr)
{
	int		i;
	int		y;
	long	converted;
	long		neg;

	neg = 1;
	y = 1;
	converted = 0;
	i = skip_start(nptr, &neg);
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		converted = (converted * y) + nptr[i] - '0';
		y = 10;
		i++;
	}
	return (converted * neg);
}
// parsing related atoi converts iterating by dozens

int	skip_shit(char *argv)
{
	int	index;
	//int	value;

	index = 0;
	while(argv[index] != '\0')
	{
		if (argv[index] >= '0' && argv[index] <= '9')
			return (FALSE);
		if (argv[index] == '+' || argv[index] == '-' || argv[index] == ' ' || (argv[index] >= 9 && argv[index] <= 13))
		{
			index++;	
			continue ;
		}
		else
			return (TRUE);

	}
	return (TRUE);
}
// parsing related skips initial bullshit and if not valid argument

int	how_many_args(char **argv)
{
	int	args;
	int	number_of_valid_args;
	
	args = 1;
	number_of_valid_args = 0;
	while (argv[args])
	{
		if (skip_shit(argv[args]) == FALSE)
			number_of_valid_args++;
		args++;
	}
	return number_of_valid_args;
}

// t_list	*create_node(int value)
// {
// 	t_list *new_node = malloc(sizeof(t_list));
// 	if (new_node == NULL)
// 		return (t_list *)NULL;
// 	new_node->value = value;
// 	new_node->next = NULL;
// 	return (new_node);
// }
// // linked list = appends to new node the desired content
// void	append_to_node(t_list **cursor, int value)
// {
// 	t_list *new_node = create_node(value);

// 	if (*cursor == NULL) {
// 		*cursor = new_node;
// 		return;
// 	}

// 	t_list *current = *cursor;
// 	while (current->next != NULL)
// 	{
// 		current = current->next;
// 	}
// 	current->next = new_node;
// }
// manage if head not declared head = new_node with value inside otherwise value is stored to next

int	atoi_stop(const char *a)
{
	int		i;
	int		y;
	long	converted;
	long		neg;

	neg = 1;
	y = 1;
	converted = 0;
	i = skip_start(a, &neg);
	while (a[i] >= 48 && a[i] <= 57)
	{
		converted = (converted * y) + a[i] - '0';
		y = 10;
		i++;
	}
	return (i);
}
// takes where atoi stops
char	*re_process(char *a)
{
	char	*str_return;
	int	index_start;
	int	index_str_return;

	index_start = 0;
	index_str_return = 0;
	str_return = malloc(ft_strlen(a) * sizeof(char));	
	index_start = atoi_stop(a);

	while (a[index_start] != '\0')
	{
		str_return[index_str_return] = a[index_start];
		index_start++;
		index_str_return++;
	}
	str_return[index_str_return] = '\0';
	return (str_return);
}

//takes from where atoi stop and return rest of string
void	from_args_to_list(char **argv, t_stack *stack)
{
	int		index;
	char	*saved;

	index = 1;
	while (argv[index])
	{
		if (skip_shit(argv[index]) == TRUE)
		{
			index++;
			continue ;
		}
		if (ft_atoi(argv[index]) >= 2147483647 || ft_atoi(argv[index]) <= -2147483648)
		{
			index++;
			continue;	
		}
		push_back(new_node(ft_atoi(argv[index]), stack), stack);
		saved = re_process(argv[index]);
		while (skip_shit(saved) != TRUE && ft_strlen(saved) != 0)
		{
			if (skip_shit(saved) == TRUE)
				break ;
			push_back(new_node(ft_atoi(saved), stack), stack);
			saved = re_process(saved);
		}		
		index++;
	}
	get_rank(stack);
}

// double	calculate_disorder(t_list *list)
// {
// 	double	mistakes;
// 	double	total_pairs;
// 	t_list	*dup_list;

//         mistakes = 0;
//         total_pairs = 0;
//         while(list->next != NULL)
//         {
//                 dup_list = list->next;
//                 while (dup_list->next != NULL)
//                 {
//                         if (list->value > dup_list->value)
//                                 mistakes++;
//                         dup_list = dup_list->next;
//                         total_pairs++;
//                 }
//                 list = list->next;
//         }
//         return (mistakes / total_pairs);
// }
