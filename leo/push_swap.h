/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 21:02:46 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/24 22:21:06 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

static int	is_space(char c);
static int	skip_start(const char *nptr, int *neg);
int	ft_atoi(const char *nptr);
int	how_many_args(char **argv);
int	skip_shit(char *argv);

#endif
