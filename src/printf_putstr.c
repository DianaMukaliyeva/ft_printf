/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:05:42 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/17 01:26:09 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putstr(char const *str)
{
	int	res;

	res = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str && *str)
	{
		res += printf_putchar(*str);
		str++;
	}
	return (res);
}
