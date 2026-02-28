/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:20:11 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/02/28 03:02:31 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr(void *ptr)
{
	unsigned long long	nbr;
	int					size;

	size = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	nbr = (unsigned long long)ptr;
	size += ft_putstr("0x");
	size += ft_put_hexa(nbr, 0);
	return (size);
}
