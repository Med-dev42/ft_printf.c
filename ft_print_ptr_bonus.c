/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:50:48 by mlazar            #+#    #+#             */
/*   Updated: 2026/10/29 15:50:49 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_ptr_len(unsigned long n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static int	ft_put_long_hex(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_put_long_hex(n / 16);
	count += ft_putchar("0123456789abcdef"[n % 16]);
	return (count);
}

int	ft_print_ptr_bonus(void *p, t_flags f)
{
	int	count;
	int	len;

	len = 5;
	if (p)
		len = 2 + ft_ptr_len((unsigned long)p);
	count = 0;
	if (!f.minus)
		count += ft_prnt(' ', f.width - len);
	if (!p)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		count += ft_put_long_hex((unsigned long)p);
	}
	if (f.minus)
		count += ft_prnt(' ', f.width - len);
	return (count);
}
