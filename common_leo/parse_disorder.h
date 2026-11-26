/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_disorder.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 03:00:22 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/26 04:18:44 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>

#ifndef PARSE_DISORDER_H
#define PARSE_DISORDER_H

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

typedef struct	s_list
{
	int	value;
	struct s_list *next;
}	t_list;

static int	is_space(char c);
static long long	skip_start(const char *nptr, long *neg);
long long	ft_atoi(const char *nptr);
int	how_many_args(char **argv);
int	skip_shit(char *argv);
t_list	*from_args_to_list(char **argv);
void	append_to_node(t_list **cursor, int value);
t_list	*create_node(int value);
double	calculate_disorder(t_list *list);
int	how_many_args(char **argv);
int	ft_strlen(char *a);
int	atoi_stop(const char *a);
char	*re_process(char *a);
int	*linked_to_list(t_list **a, int nb_args);

#endif
