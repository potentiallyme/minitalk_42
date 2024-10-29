/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:18:21 by lmoran            #+#    #+#             */
/*   Updated: 2023/11/29 17:00:33 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_prchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_prstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_ttype(va_list args, const char type)
{
	int	prlen;

	prlen = 0;
	if (type == 'c')
		prlen += ft_prchar(va_arg(args, int));
	if (type == 's')
		prlen += ft_prstr(va_arg(args, char *));
	if (type == 'd' || type == 'i')
		prlen += ft_prnbr(va_arg(args, int));
	if (type == 'u')
		prlen += ft_pruns(va_arg(args, unsigned int));
	if (type == 'p')
		prlen += ft_prptr(va_arg(args, unsigned long));
	if (type == 'x' || type == 'X')
		prlen += ft_prhex(va_arg(args, unsigned int), type);
	if (type == '%')
		prlen += ft_prchar('%');
	return (prlen);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		prlen;
	va_list	args;

	i = 0;
	prlen = 0;
	va_start(args, s);
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			prlen += ft_ttype(args, s[(i + 1)]);
			i++;
		}
		else
			prlen += ft_prchar(s[i]);
		i++;
	}
	va_end(args);
	return (prlen);
}
