/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:49:24 by mlazar            #+#    #+#             */
/*   Updated: 2026/10/29 15:49:26 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	plus;
	int	space;
	int	hash;
	int	width;
	int	prec;
}	t_flags;

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_prnt(char c, int n);
int	ft_strlen(const char *s);
int	ft_putchar_bonus(char c, t_flags f);
int	ft_putstr_bonus(char *s, t_flags f);
int	ft_print_ptr_bonus(void *p, t_flags f);
int	ft_putnbr_bonus(int nb, t_flags f);
int	ft_putunsigned_bonus(unsigned int nb, t_flags f);
int	ft_puthex_bonus(unsigned int hex, t_flags f, char c);

#endif
