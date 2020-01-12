/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:49:37 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/12 22:57:11 by dmukaliy         ###   ########.fr       */
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	printf_putnbr(int n)
{
	int	res;

	res = 0;
	if (n < 0)
	{
		res += printf_putchar('-');
		if (n == -2147483648)
		{
			res += printf_putchar('2');
			n = -147483648;
		}
		n *= -1;
	}
	if (n / 10 > 0)
		res += printf_putnbr(n / 10);
	res += printf_putchar((n % 10) + '0');
	return (res);
}

void	ft_putstr(char const *str)
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

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	print_arg(char modifier, t_tag *tags, va_list list)
{
	int	res;

	res = 0;
	if (modifier == 's')
	{
		if (tags->width.asterisk == 0)
			ft_putstr(va_arg(list, char*));
	}
	if (modifier == 'd')
		res += print_int(tags, list);
	return (res);
}
