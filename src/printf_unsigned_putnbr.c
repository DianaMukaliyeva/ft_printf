/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned_putnbr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:48:16 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/17 18:51:03 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_unsigned_putnbr(uintmax_t n, int base)
{
	int		res;

	res = 0;
	
	if (n / base > 0)
		res += printf_putnbr(n / base, base);
	res += printf_putchar((n % base) + '0');
	return (res);
}
