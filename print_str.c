/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:07:18 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/13 10:32:30 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_str(t_tag *tags, va_list list)
{
	if (tags->width.asterisk == 0)
		printf_putstr(va_arg(list, char*));
	return (0);
}
