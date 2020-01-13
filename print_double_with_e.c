/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double_with_e.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:14:08 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/13 10:33:37 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_double_with_e(t_tag *tags, va_list list)
{
	int		res;
	double	num;

	res = 0;
	num = va_arg(list, double);
	if (tags->precision.is_exist)
		res += printf_putnbr((int)num);
	return (res);
}
