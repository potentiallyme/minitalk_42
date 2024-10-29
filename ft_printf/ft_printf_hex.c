/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:47:27 by lmoran            #+#    #+#             */
/*   Updated: 2023/11/23 17:11:02 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prtype(unsigned long n)
{
	int	prlen;

	prlen = 0;
	if (n >= 16)
	{
		prlen += ft_prtype(n / 16);
		prlen += ft_prtype(n % 16);
	}
	else if (n <= 9)
		prlen += ft_prchar(n + 48);
	else
		prlen += ft_prchar((n - 10) + 'a');
	return (prlen);
}

int	ft_prhex(unsigned int n, const char type)
{
	int	prlen;

	prlen = 0;
	if (!n)
		return (ft_prchar('0'));
	if (n >= 16)
	{
		prlen += ft_prhex((n / 16), type);
		prlen += ft_prhex((n % 16), type);
	}
	else if (n <= 9)
		prlen += ft_prchar(n + 48);
	else
	{
		if (type == 'x')
			prlen += ft_prchar((n - 10) + 'a');
		else if (type == 'X')
			prlen += ft_prchar((n - 10) + 'A');
	}
	return (prlen);
}

int	ft_prptr(unsigned long n)
{
	if (!n)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + ft_prtype(n));
}
