/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:43:24 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/12 19:43:52 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(t_identifier *identifiers, va_list list)
{
	int	res;
	int	num;

	res = 0;
	num = va_arg(list, int);
	if (identifiers->width.is_width)
	{

	} else
	{
		if (identifiers->flags.sign && num > 0)
			res += printf_putchar('+');
	}
	res += printf_putnbr(num);
	return (res);
}
