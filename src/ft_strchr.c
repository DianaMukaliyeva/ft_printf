/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:57:01 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/12 21:49:52 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int ch)
{
	while (*str)
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}
	if (ch == 0 && *str == '\0')
		return ((char *)str);
	return (NULL);
}
