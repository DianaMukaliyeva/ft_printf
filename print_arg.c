/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:00:47 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/12 23:10:10 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
		res += print_str(tags, list);
	if (modifier == 'd')
		res += print_int(tags, list);
	return (res);
}
