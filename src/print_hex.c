/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:05:45 by diana             #+#    #+#             */
/*   Updated: 2020/01/17 15:31:22 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(int num, int big)
{
	char	*big_hex;
	char	*small_hex;
	int		res;

	res = 0;
	big_hex = "0123456789ABCDEF";
	small_hex = "0123456789abcdef";
	if (num == 0)
		return (printf_putchar('0'));
	if (num >= 16)
		res += print_hex(num / 16, big);
	if (big)
		res += printf_putchar(big_hex[num % 16]);
	else
		res += printf_putchar(small_hex[num % 16]);
	return (res);
}
