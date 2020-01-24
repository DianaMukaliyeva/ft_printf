/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:10:33 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/24 18:42:09 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_chars_with_flag_minus(char c, int amount_of_spaces, int fd)
{
	int res;

	res = printf_putchar(c, fd);
	while (amount_of_spaces-- > 0)
		res += printf_putchar(' ', fd);
	return (res);
}

static int	print_chars_with_filler(char filler, char c, int amount, int fd)
{
	int res;

	res = 0;
	while (amount-- > 0)
		res += printf_putchar(filler, fd);
	res += printf_putchar(c, fd);
	return (res);
}

static int	print_with_width(char c, t_flag flags)
{
	if (flags.minus)
		return (print_chars_with_flag_minus(c, flags.width_num - 1, flags.fd));
	else if (flags.zero)
		return (print_chars_with_filler('0', c, flags.width_num - 1, flags.fd));
	else
		return (print_chars_with_filler(' ', c, flags.width_num - 1, flags.fd));
}

int			print_char(t_flag flags, char c)
{
	if (flags.width_num == 0)
		return (printf_putchar(c, flags.fd));
	else
		return (print_with_width(c, flags));
}
