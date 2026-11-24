/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 20:43:36 by timbert           #+#    #+#             */
/*   Updated: 2026/11/11 01:42:33 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...) __attribute__ ((format (printf, 1, 2)));
int	print_char(char c);
int	print_str(char *str);
int	print_nb(long nbr);
int	print_unsigned(unsigned int nbr);
int	print_hexa(unsigned long nbr, char *base);
int	print_ptr(unsigned long nbr, char *base);

#endif