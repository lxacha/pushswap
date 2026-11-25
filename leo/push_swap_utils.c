/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 21:10:21 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/25 03:25:29 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
// atoi related skips spaces newline carriage return and so on
static int	skip_start(const char *nptr, int *neg)
{
	int		i;

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
int	ft_atoi(const char *nptr)
{
	int		i;
	int		y;
	long	converted;
	int		neg;

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
	return ((int)(converted * neg));
}
// parsing related atoi converts iterating by dozens

int	skip_shit(char *argv)
{
	int	true_or_nah;
	int	index;

	index = 0;
	true_or_nah = TRUE;
	while(argv[index])
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

}
// parsing related skips initial bullshit and if not valid argument
/*
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
*/
// init parsing related counts how many arguments there should be using skip shit
t_list	*create_node(int value)
{
	t_list *new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (t_list *)NULL;
	new_node->number = value;
	new_node->next = NULL;
	return (new_node);
}
// linked list = appends to new node the desired content
void	append_to_node(t_list **cursor, int value)
{
	t_list *new_node = create_node(value);

	if (*cursor == NULL) {
		*cursor = new_node;
		return;
	}

	t_list *current = *cursor;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_node;

}
// manage if head not declared head = new_node with value inside otherwise value is stored to next
t_list	*from_args_to_list(char **argv)
{
	int	index;
	int	args;
	t_list	*cursor;

	cursor = NULL;	
	index = 1;
	while (argv[index])
	{
		if (skip_shit(argv[index]) == TRUE)
		{
			index++;
			continue ;
		}
		append_to_node(&cursor, ft_atoi(argv[index]));
		index++;
	}
	return cursor;
}

double	calculate_disorder(t_list *list)
{
	int	mistakes;
	int	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	while(list->next != NULL);
	{
		if (list->number > list->next->number)
			mistakes++;
		list = list->next;
		total_pairs++;
	}
	return (mistakes / total_pairs);
}
