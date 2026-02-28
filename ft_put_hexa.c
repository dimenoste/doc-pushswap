/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:44:15 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2025/12/08 14:53:38 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexa(unsigned long long nb, int case_arg)
{
	const char	*base;
	int			size;

	if (case_arg == 0)
	{
		base = "0123456789abcdef";
	}
	else
	{
		base = "0123456789ABCDEF";
	}
	size = 0;
	if (nb >= 16)
		size += ft_put_hexa(nb / 16, case_arg);
	size += ft_putchar((base[nb % 16]));
	return (size);
}
