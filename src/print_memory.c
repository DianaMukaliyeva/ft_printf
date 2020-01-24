/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:11:35 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/24 19:09:29 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_memory(t_flag flags, void *p)
{
	int			res;
	uintmax_t	address;
	char		*print_str;

	res = 0;
	address = (uintmax_t)p;
	flags.hash = 1;
	print_str = get_with_precision(address, flags, 16, 0);
	if (!print_str)
		return (-1);
	res = print_unsigned_number(print_str, flags, 16, address, -1);
	free(print_str);
	return (res);
}
