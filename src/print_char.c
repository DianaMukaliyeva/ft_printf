/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:10:33 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/22 19:47:47 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_chars_with_flag_minus(char c, int amount_of_spaces)
{
	int res;

	res = printf_putchar(c);
	while (amount_of_spaces-- > 0)
		res += printf_putchar(' ');
	return (res);
}

static int	print_chars_with_filler(char filler, char c, int amount)
{
	int res;

	res = 0;
	while (amount-- > 0)
		res += printf_putchar(filler);
	res += printf_putchar(c);
	return (res);
}

static int	print_with_width(char c, int width, int flag_zero, int flag_minus)
{
	if (flag_minus)
		return (print_chars_with_flag_minus(c, width - 1));
	else if (flag_zero)
		return (print_chars_with_filler('0', c, width - 1));
	else
		return (print_chars_with_filler(' ', c, width - 1));
}

int			print_char(t_flag flags, char c)
{
	if (flags.width_num == 0)
		return (printf_putchar(c));
	else
		return (print_with_width(c, flags.width_num, flags.zero, flags.minus));
}
