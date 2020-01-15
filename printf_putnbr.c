/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:04:27 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/15 19:58:57 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putnbr(intmax_t n)
{
	int	res;

	res = 0;
	if (n < 0)
	{
		res += printf_putchar('-');
		n *= -1;
	}
	if (n / 10 > 0)
		res += printf_putnbr(n / 10);
	res += printf_putchar((n % 10) + '0');
	return (res);
}
