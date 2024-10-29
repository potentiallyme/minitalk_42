/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:35:09 by lmoran            #+#    #+#             */
/*   Updated: 2023/11/23 16:39:11 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prnbr(int n)
{
	int	prlen;

	prlen = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n < 0)
	{
		prlen += ft_prchar('-');
		prlen += ft_prnbr(n * (-1));
	}
	else if (n > 9)
	{
		prlen += ft_prnbr(n / 10);
		prlen += ft_prnbr(n % 10);
	}
	else if (n >= 0 && n <= 9)
		prlen += ft_prchar(n + 48);
	return (prlen);
}

int	ft_pruns(unsigned int n)
{
	int	prlen;

	prlen = 0;
	if (n > 9)
	{
		prlen += ft_prnbr(n / 10);
		prlen += ft_prnbr(n % 10);
	}
	else if (n >= 0 && n <= 9)
		prlen += ft_prchar(n + 48);
	return (prlen);
}
