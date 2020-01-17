/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:11:35 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/17 13:41:11 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_memory(t_tag *tags, va_list list)
{
	int		res;
	double	num;

	res = 0;
	num = va_arg(list, double);
	if (tags->precision.is_exist)
		res += printf_putnbr((int)num, 10);
	return (res);
}
