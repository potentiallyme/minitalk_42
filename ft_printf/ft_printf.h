/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:57:40 by lmoran            #+#    #+#             */
/*   Updated: 2023/11/23 17:08:25 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_prchar(int c);
int	ft_prhex(unsigned int n, const char type);
int	ft_printf(const char *s, ...);
int	ft_prnbr(int n);
int	ft_prptr(unsigned long n);
int	ft_prstr(char *s);
int	ft_prtype(unsigned long n);
int	ft_pruns(unsigned int n);
int	ft_ttype(va_list args, const char type);

#endif
