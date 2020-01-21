/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number_with_flags.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:22:52 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/21 17:20:53 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_print_len(char *str, t_flag flags, int negative)
{
	int	len;

	len = ft_strlen(str);
	if (negative || flags.space || flags.plus)
		len++;
	return (len);
}

static char	*join_sign(char *src, int negative, int plus, int space)
{
	char	*str;

	str = NULL;
	if (negative)
		str = ft_strjoin("-", src);
	else if (plus)
		str = ft_strjoin("+", src);
	else if (space)
		str = ft_strjoin(" ", src);
	else
		str = ft_strdup(src);
	if (!str)
		return (NULL);
	return (str);
}

char		*newstr_fill(size_t zero, size_t len, int can_put_zero)
{
	char	*str;
	size_t	i;
	char	filler;

	if (zero && !can_put_zero)
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

static char	*get_joinedstr(char *str, t_flag flags, int negative, int len)
{
	char	*temp;
	char	*res;
	int		width;

	width = flags.width_num;
	if (flags.minus)
	{
		temp = newstr_fill(flags.zero, width - len, flags.minus);
		res = join_sign(str, negative, flags.plus, flags.space);
		res = ft_strjoin(res, temp);
	}
	else
	{
		temp = newstr_fill(flags.zero, width - len, flags.precision_exist);
		if (flags.zero && !flags.precision_exist)
		{
			res = ft_strjoin(temp, str);
			res = join_sign(res, negative, flags.plus, flags.space);
		}
		else
		{
			res = join_sign(str, negative, flags.plus, flags.space);
			res = ft_strjoin(temp, res);
		}
	}
	free(temp);
	return (res);
}

int			print_number_with_flags(char *str, t_flag flags, int negative)
{
	int		len;
	int		width;
	char	*res;

	width = flags.width_num;
	len = get_print_len(str, flags, negative);
	if (width > len)
	{
		res = get_joinedstr(str, flags, negative, len);
		len = ft_strlen(res);
		write(1, res, len);
		free(res);
	}
	else
	{
		res = join_sign(str, negative, flags.plus, flags.space);
		len = ft_strlen(res);
		write(1, res, len);
		free(res);
	}
	return (len);
}
