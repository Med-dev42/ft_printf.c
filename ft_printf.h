/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:53:38 by mlazar            #+#    #+#             */
/*   Updated: 2026/10/31 00:08:18 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(char a);
int	ft_putnbrs(int nb);
int	ft_print_str(char *s);
int	ft_print_point(void *x);
int	ft_print_sign(void);
int	ft_unsigned_nbr(unsigned int nb);
int	ft_puthexa(unsigned int hex, char c);

#endif
