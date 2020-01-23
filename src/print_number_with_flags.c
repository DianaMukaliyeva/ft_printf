/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number_with_flags.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:22:52 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/23 22:46:31 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*add_sign_to_str(char const *str, int negative, int plus, int space)
{
	char	*res;

	res = NULL;
	if (negative)
		res = ft_strjoin("-", str);
	else if (plus)
		res = ft_strjoin("+", str);
	else if (space)
		res = ft_strjoin(" ", str);
	else
		res = ft_strdup(str);
	return (res);
}

static char	*newstr_fill(size_t zero, size_t len, int can_put_zero)
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

static char	*get_full_str2(char const *str, t_flag flags, int negative, int len)
{
	char	*res;
	char	*temp;
	char	*temp2;
	int		width;

	width = flags.width_num;
	temp = newstr_fill(flags.zero, width - len, flags.precision_exist);
	if (flags.zero && !flags.precision_exist)
	{
		temp2 = ft_strjoin(temp, str);
		if (!temp || !temp2)
			return (NULL);
		res = add_sign_to_str(temp2, negative, flags.plus, flags.space);
	}
	else
	{
		temp2 = add_sign_to_str(str, negative, flags.plus, flags.space);
		if (!temp || !temp2)
			return (NULL);
		res = ft_strjoin(temp, temp2);
	}
	free(temp2);
	free(temp);
	return (res);
}

static char	*get_full_str(char const *str, t_flag flags, int negative, int len)
{
	char	*res;
	char	*temp;
	char	*temp2;
	int		width;

	width = flags.width_num;
	if (flags.minus)
	{
		temp = newstr_fill(flags.zero, width - len, flags.minus);
		temp2 = add_sign_to_str(str, negative, flags.plus, flags.space);
		if (!temp || !temp2)
			return (NULL);
		res = ft_strjoin(temp2, temp);
		free(temp2);
		free(temp);
	}
	else
		res = get_full_str2(str, flags, negative, len);
	return (res);
}

int			print_number_with_flags(char *str, t_flag flags, int negative)
{
	int		len;
	int		width;
	char	*res;

	width = flags.width_num;
	len = ft_strlen(str);
	if (negative || flags.space || flags.plus)
		len++;
	if (width > len)
		res = get_full_str(str, flags, negative, len);
	else
		res = add_sign_to_str(str, negative, flags.plus, flags.space);
	if (!res)
		return (-1);
	len = ft_strlen(res);
	write(1, res, len);
	free(res);
	return (len);
}
