/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:53:09 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/13 13:37:16 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_percent(t_tag *tags, va_list list)
{
	int	res;
	int	num;

	res = 0;
	num = va_arg(list, int);
	if (tags->width.is_exist)
		printf("\namount-num = %d\n", tags->width.num);
	if (tags->flags.sign && num > 0)
		res += printf_putchar('+');
	res += printf_putnbr(num);
	return (res);
}
