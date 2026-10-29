/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:53:02 by mlazar            #+#    #+#             */
/*   Updated: 2026/10/29 15:53:03 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_lennbr(unsigned int nb)
{
	int	i;

	i = 1;
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static int	ft_putunbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_putunbr(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

static int	ft_zeros(int len, t_flags f)
{
	int	zeros;

	zeros = 0;
	if (f.prec > len)
		zeros = f.prec - len;
	else if (f.zero && !f.minus && f.prec < 0)
		zeros = f.width - len;
	if (zeros < 0)
		zeros = 0;
	return (zeros);
}

int	ft_putunsigned_bonus(unsigned int nb, t_flags f)
{
	int	count;
	int	len;
	int	zeros;

	len = ft_lennbr(nb);
	if (f.prec == 0 && nb == 0)
		len = 0;
	zeros = ft_zeros(len, f);
	f.width -= len + zeros;
	count = 0;
	if (!f.minus)
		count += ft_prnt(' ', f.width);
	count += ft_prnt('0', zeros);
	if (len)
		count += ft_putunbr(nb);
	if (f.minus)
		count += ft_prnt(' ', f.width);
	return (count);
}
