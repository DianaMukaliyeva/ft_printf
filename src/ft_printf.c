/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:15:16 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/13 09:50:04 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		len;
	int		res;

	i = 0;
	res = 0;
	len = ft_strlen(format);
	va_start(list, format);
	while (i < len)
	{
		if (format[i] == '%')
			res += parse_specifiers(list, format, &i);
		else
			res += printf_putchar(format[i]);
		i++;
	}
	va_end(list);
	return (res);
}
