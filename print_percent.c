/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:53:09 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/14 11:31:07 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_chars_with_flag_minus(char c, int amount_of_spaces)
{
	int res;

	res = 0;
	res += printf_putchar(c);
	while (amount_of_spaces-- > 0)
		res += printf_putchar(' ');
	return (res);
}

static int	print_chars_with_flag_zero(char zero_or_space, char c, int amount)
{
	int res;

	res = 0;
	while (amount-- > 0)
		res += printf_putchar(zero_or_space);
	res += printf_putchar(c);
	return (res);
}

static int	print_with_width(char c, int width, int flag_zero, int flag_minus)
{
	int	res;

	res = 0;
	if (flag_minus)
		res += print_chars_with_flag_minus(c, width - 1);
	else if (flag_zero)
		res += print_chars_with_flag_zero('0', c, width - 1);
	else
		res += print_chars_with_flag_zero(' ', c, width - 1);
	return (res);
}

int			print_percent(t_tag *tags)
{
	int		res;
	char	c;
	int		width;
	int		flag_zero;
	int		flag_minus;

	res = 0;
	c = '%';
	width = tags->width.num;
	flag_zero = tags->flags.zero;
	flag_minus = tags->flags.left_align;
	if (width == 0)
		res += printf_putchar(c);
	else
		res += print_with_width(c, width, flag_zero, flag_minus);
	return (res);
}
