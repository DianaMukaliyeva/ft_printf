/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:05:42 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/17 19:55:39 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putstr(char const *str)
{
	int	res;

	res = 0;
	while (str && *str)
	{
		res += printf_putchar(*str);
		str++;
	}
	return (res);
}
