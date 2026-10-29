/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:51:57 by mlazar            #+#    #+#             */
/*   Updated: 2026/10/29 15:51:58 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_numlen(long n)
{
	int	len;

	if (n < 0)
		n = -n;
	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_putnbr(long nb)
{
	int	count;

	if (nb < 0)
		nb = -nb;
	count = 0;
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

static char	ft_sign(int nb, t_flags f)
{
	if (nb < 0)
		return ('-');
	if (f.plus)
		return ('+');
	if (f.space)
		return (' ');
	return (0);
}

static int	ft_zeros(int len, int sign, t_flags f)
{
	int	zero;

	zero = 0;
	if (f.prec > len)
		zero = f.prec - len;
	else if (f.zero && !f.minus && f.prec < 0)
		zero = f.width - len - sign;
	if (zero < 0)
		zero = 0;
	return (zero);
}

int	ft_putnbr_bonus(int nb, t_flags f)
{
	int		len;
	int		zeros;
	int		count;
	char	sign;

	sign = ft_sign(nb, f);
	len = ft_numlen(nb);
	if (f.prec == 0 && nb == 0)
		len = 0;
	zeros = ft_zeros(len, sign != 0, f);
	f.width -= len + zeros + (sign != 0);
	count = 0;
	if (!f.minus)
		count += ft_prnt(' ', f.width);
	if (sign)
		count += ft_putchar(sign);
	count += ft_prnt('0', zeros);
	if (len)
		count += ft_putnbr(nb);
	if (f.minus)
		count += ft_prnt(' ', f.width);
	return (count);
}
