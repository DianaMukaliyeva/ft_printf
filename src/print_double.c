/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:02:40 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/17 13:41:04 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_double(t_tag *tags, va_list list)
{
	int		res;
	double	num;

	res = 0;
	num = va_arg(list, double);
	if (tags->precision.is_exist)
		res += printf_putnbr((int)num, 10);
	return (res);
}
