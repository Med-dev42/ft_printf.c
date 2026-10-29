/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:51:45 by mlazar            #+#    #+#             */
/*   Updated: 2026/10/29 15:51:49 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_lennbr(unsigned int nb)
{
	int	len;

	len = 1;
	while (nb >= 16)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

static int	ft_put_hex(unsigned int hex, char c)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	count = 0;
	if (hex >= 16)
		count += ft_put_hex(hex / 16, c);
	count += ft_putchar(base[hex % 16]);
	return (count);
}

static int	ft_zeros(int len, int prefix, t_flags f)
{
	int	zeros;

	zeros = 0;
	if (f.prec >= 0)
		zeros = f.prec - len;
	else if (f.zero && !f.minus)
		zeros = f.width - prefix - len;
	if (zeros < 0)
		zeros = 0;
	return (zeros);
}

int	ft_puthex_bonus(unsigned int hex, t_flags f, char c)
{
	int	count;
	int	len;
	int	prefix;
	int	zeros;

	prefix = 0;
	if (f.hash && hex != 0)
		prefix = 2;
	len = ft_lennbr(hex);
	if (f.prec == 0 && hex == 0)
		len = 0;
	zeros = ft_zeros(len, prefix, f);
	f.width -= prefix + len + zeros;
	count = 0;
	if (!f.minus)
		count += ft_prnt(' ', f.width);
	if (prefix)
		count += write(1, (char []){'0', c}, 2);
	count += ft_prnt('0', zeros);
	if (len > 0)
		count += ft_put_hex(hex, c);
	if (f.minus)
		count += ft_prnt(' ', f.width);
	return (count);
}
