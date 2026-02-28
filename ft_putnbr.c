/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:51:49 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/02/28 03:03:03 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int		count;
	long	n;

	count = 0;
	n = nb;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_putnbr_u(unsigned long nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_putnbr_u(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

int	ft_putnbr_l(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr_l(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

int	ft_putnbr_zu(size_t nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_putnbr_zu(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}
