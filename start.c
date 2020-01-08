/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:49:37 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/08 19:54:13 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	start(va_list list, const char *format)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'd')
				printf("%d", va_arg(list, int));
			if (format[i + 1] == 's')
				printf("%s", va_arg(list, char*));
			i++;
		}
		else
			printf("%c", format[i]);
		i++;
	}
}