/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 21:02:46 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/25 01:25:59 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

typedef struct	s_list
{
	int	number;
	struct s_list *next;
}	t_list;

static int	is_space(char c);
static int	skip_start(const char *nptr, int *neg);
int	ft_atoi(const char *nptr);
int	how_many_args(char **argv);
int	skip_shit(char *argv);
t_list	*from_args_to_list(char **argv);
void	append_to_node(t_list **cursor, int value);
t_list	*create_node(int value);

#endif
