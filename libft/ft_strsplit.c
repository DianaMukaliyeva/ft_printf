/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:50:30 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/10/28 14:16:30 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		size_of_two_dimensial_array(char const *s, char c)
{
	int	i;
	int	size;
	int	count;

	i = 0;
	size = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			size++;
		}
		if (size != 0)
			count++;
	}
	return (size * count);
}

int		size_of_array(char const *s, int *i, char c)
{
	int	i2;
	int	size;

	i2 = *i;
	size = 0;
	while (s[i2] && s[i2] == c)
		i2++;
	while (s[i2] && s[i2] != c)
	{
		i2++;
		size++;
	}
	*i = i2;
	return (size);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		j;
	int		i;
	int		size;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	size = size_of_two_dimensial_array(s, c);
	res = (char**)ft_memalloc(size);
	if (!res)
		return (NULL);
	if (size == 0)
		res[0] = (char*)'\0';
	while (s[i] && size > 0)
	{
		size = size_of_array(s, &i, c);
		if (size != 0)
			res[j] = ft_strsub(s, i - size, size);
		j++;
	}
	return (res);
}
