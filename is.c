/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:57:01 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/10 19:20:21 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strchr(const char *str, int ch)
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

int	is_flag(char c)
{
	const char	*flags = "+- 0#";

	if (ft_strchr(flags, c) != NULL)
		return (1);
	return (0);
}

int	is_width(char c)
{
	const char	*flags = "1234567890*";

	if (ft_strchr(flags, c) != NULL)
		return (1);
	return (0);
}

int	is_precision(char c, const char *format, int i)
{
	const char	*flags = ".";

	if (ft_strchr(flags, c) != NULL)
		if (is_width(format[i + 1]))
			return (1);
	return (0);
}

int	is_modifier(char c)
{
	const char	*flags = "hHlL";

	if (ft_strchr(flags, c) != NULL)
		return (1);
	return (0);
}

int	is_type(char c)
{
	const char	*flags = "cspdiouxXf";

	if (ft_strchr(flags, c) != NULL)
		return (1);
	return (0);
}
