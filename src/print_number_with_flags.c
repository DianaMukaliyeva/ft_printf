/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number_with_flags.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:22:52 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/21 16:40:09 by dmukaliy         ###   ########.fr       */
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

int			print_number_with_flags(char *str, t_flag flags, int negative)
{
	int		len;
	char	*temp;
	int		width;
	
	width = flags.width_num;
	len = get_print_len(str, flags, negative);
	if (width > len)
	{
		if (flags.minus)
		{
			temp = newstr_fill(flags.zero, width - len, flags.minus);
			str = join_sign(str, negative, flags.plus, flags.space);
			str = ft_strjoin(str, temp);
		}
		else
		{
			temp = newstr_fill(flags.zero, width - len, flags.precision_exist);
			if (flags.zero && !flags.precision_exist)
			{
				str = ft_strjoin(temp, str);
				str = join_sign(str, negative, flags.plus, flags.space);
			}
			else
			{
				str = join_sign(str, negative, flags.plus, flags.space);
				str = ft_strjoin(temp, str);
			}
		}
		len = ft_strlen(str);
		write(1, str, len);
		free(temp);
	}
	else
	{
		str = join_sign(str, negative, flags.plus, flags.space);
		len = ft_strlen(str);
		write(1, str, len);
	}
	free(str);
	return (len);
}
