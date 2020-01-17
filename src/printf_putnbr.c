/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:04:27 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/17 14:59:12 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putnbr(intmax_t n, int base)
{
	int		res;

	res = 0;
	if (n + 1 == -9223372036854775807)
		return (printf_putstr("9223372036854775808"));
	if (n < 0)
	{
		res += printf_putchar('-');
		n *= -1;
	}
	if (n / base > 0)
		res += printf_putnbr(n / base, base);
	res += printf_putchar((n % base) + '0');
	return (res);
}
