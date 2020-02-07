/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:07:18 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/28 16:45:35 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*newstr_with_char(size_t zero, size_t len, int minus)
{
	char	*str;
	size_t	i;
	char	filler;

	if (zero && !minus)
		filler = '0';
	else
		filler = ' ';
	i = 0;
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	while (i < len)
		str[i++] = filler;
	return (str);
}

int			print_with_flags(char *str, int width, t_flag flags)
{
	char	*print;
	int		len;
	char	*temp;
	int		minus;

	minus = flags.minus;
	len = ft_strlen(str);
	if (width > len)
	{
		temp = newstr_with_char(flags.zero, width - len, minus);
		if (minus)
			print = ft_strjoin(str, temp);
		else
			print = ft_strjoin(temp, str);
		if (!print)
			return (-1);
		len = ft_strlen(print);
		write(flags.fd, print, len);
		free(temp);
		free(print);
	}
	else
		write(flags.fd, str, len);
	return (len);
}

static char	*get_str_with_precision(char *str, t_flag flags)
{
	int		len;
	char	*res;

	if (flags.precision_exist)
		len = flags.precision_num;
	else
		len = ft_strlen(str);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	res = ft_strncpy(res, str, len);
	return (res);
}

int			print_str(t_flag flags, char *str)
{
	int		res;

	if (!str)
		str = "(null)";
	str = get_str_with_precision(str, flags);
	if (!str)
		return (-1);
	res = print_with_flags(str, flags.width_num, flags);
	free(str);
	return (res);
}
