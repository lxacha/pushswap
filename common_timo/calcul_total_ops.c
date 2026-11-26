/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_total_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 17:54:55 by timbert           #+#    #+#             */
/*   Updated: 2026/11/26 17:57:41 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calcul_total_ops(t_count *count)
{
	count->total = (count->pa + count->pb + count->ra + count->rb + count->rr + count->rra + count->rrb + count->rrr + count->sa + count->sb + count->ss);
}