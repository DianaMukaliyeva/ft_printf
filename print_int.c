/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:43:24 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/12 22:56:47 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_int(t_tag *tags, va_list list)
{
	int	res;
	int	num;

	res = 0;
	num = va_arg(list, int);
	if (tags->width.is_exist)
	{
		printf("\namount-num = %d\n", tags->width.num);
	} 
		// printf("0 flag == %d\n", tags->flags.zero);
	if (tags->flags.sign && num > 0)
			res += printf_putchar('+');
	res += printf_putnbr(num);
	return (res);
}
