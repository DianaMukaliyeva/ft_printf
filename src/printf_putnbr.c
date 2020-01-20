/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:04:27 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/20 13:11:22 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putnbr(uintmax_t n, int base)
{
	int		res;

	res = 0;
	if (n / base > 0)
		res += printf_putnbr(n / base, base);
	res += printf_putchar((n % base) + '0');
	return (res);
}
