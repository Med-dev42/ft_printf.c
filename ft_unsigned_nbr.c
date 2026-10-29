/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:52:27 by mlazar            #+#    #+#             */
/*   Updated: 2026/10/29 15:52:29 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_nbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_unsigned_nbr(nb / 10);
	count += ft_print_char((nb % 10) + '0');
	return (count);
}
