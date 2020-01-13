/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:10:33 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/13 10:57:09 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(t_tag *tags, va_list list)
{
	int		res;

	res = 0;
	res += printf_putchar(va_arg(list, int));
	if (tags->precision.is_exist)
		res += printf_putchar(va_arg(list, int));
	return (res);
}
