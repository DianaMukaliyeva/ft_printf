/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:49:37 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/10 19:51:09 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// static int	ft_atoi(const char *str)
// {
// 	const char	*copy;
// 	long		result;
// 	long		sign;
// 	long		prev_result;

// 	sign = 1;
// 	result = 0;
// 	copy = str;
// 	while ((*copy >= 9 && *copy <= 13) || *copy == 32)
// 		copy++;
// 	if (*copy == '-' || *copy == '+')
// 		sign = *copy++ == '-' ? -1 : 1;
// 	while (*copy >= 48 && *copy <= 57)
// 	{
// 		prev_result = result;
// 		result = result * 10 + (*copy - 48);
// 		if (prev_result > result)
// 			return (sign == 1 ? -1 : 0);
// 		copy++;
// 	}
// 	return ((int)result * sign);
// }

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putchar('2');
			n = -147483648;
		}
		n *= -1;
	}
	if (n / 10 > 0)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

static void	ft_putstr(char const *str)
{
	while (str && *str)
	{
		write(1, &(*str), 1);
		str++;
	}
}

int		is_in_arr(char target, const char *src)
{
	while (*src)
	{
		if (*src == target)
			return (1);
		src++;
	}
	return (0);
}

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	start(va_list list, const char *format)
{
	// t_flag	
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (i < len && !is_type(format[i]))
			{
				if (!is_modifier(format[i]) && !is_precision(format[i], format, i) && !is_width(format[i]) && !is_flag(format[i]))
				{
					ft_putchar(format[i]);
					break;
				}
				i++;
			}
			if (is_type(format[i]))
				ft_putstr(va_arg(list, char*));
				ft_putnbr(va_arg(list, int));
		}
		else
			ft_putchar(format[i]);
		i++;
	}
}
