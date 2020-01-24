/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:15:16 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/24 18:28:50 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		len;
	int		res;
	int		temp_res;

	i = 0;
	res = 0;
	len = ft_strlen(format);
	va_start(list, format);
	while (i < len)
	{
		if (format[i] == '%')
		{
			temp_res = parse_flags(list, format, &i, 1);
			if (temp_res == -1)
				return (-1);
			res += temp_res;
		}
		else
			res += printf_putchar(format[i], 1);
		i++;
	}
	va_end(list);
	return (res);
}

int	fd_printf(int fd, const char *format, ...)
{
	va_list	list;
	int		i;
	int		len;
	int		res;
	int		temp_res;

	i = 0;
	res = 0;
	len = ft_strlen(format);
	va_start(list, format);
	while (i < len)
	{
		if (format[i] == '%')
		{
			temp_res = parse_flags(list, format, &i, fd);
			if (temp_res == -1)
				return (-1);
			res += temp_res;
		}
		else
			res += printf_putchar(format[i], fd);
		i++;
	}
	va_end(list);
	return (res);
}
