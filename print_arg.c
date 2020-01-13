/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:00:47 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/13 10:16:32 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	print_arg1(char modifier, t_tag *tags, va_list list)
{
	int	res;

	res = 0;
	if (modifier == 's')
		res += print_str(tags, list);
	else if (modifier == 'c')
		res += print_char(tags, list);
	else if (modifier == 'p')
		res += print_memory(tags, list);
	return (res);
}

static int	print_arg2(char modifier, t_tag *tags, va_list list)
{
	int	res;

	res = 0;
	if (modifier == 'o')
		res += print_unsigned_octal(tags, list);
	else if (modifier == 'd' || modifier == 'i')
		res += print_int(tags, list);
	else if (modifier == 'u')
		res += print_unsigned_int(tags, list);
	else if (modifier == 'x')
		res += print_unsigned_low_hex(tags, list);
	else if (modifier == 'X')
		res += print_unsigned_upper_hex(tags, list);
	return (res);
}

static int	print_arg3(char modifier, t_tag *tags, va_list list)
{
	int	res;

	res = 0;
	if (modifier == 'f')
		res += print_double(tags, list);
	else if (modifier == 'e')
		res += print_double_with_e(tags, list);
	else if (modifier == 'E')
		res += print_double_with_big_e(tags, list);
	else if (modifier == 'g')
		res += print_double(tags, list);
	return (res);
}

int			print_arg(char modifier, t_tag *tags, va_list list)
{
	int	res;

	res = 0;
	if (ft_strchr("csp", modifier))
		res += print_arg1(modifier, tags, list);
	else if (ft_strchr("diouxX", modifier))
		res += print_arg2(modifier, tags, list);
	else if (ft_strchr("feEg", modifier))
		res += print_arg3(modifier, tags, list);
	return (res);
}
