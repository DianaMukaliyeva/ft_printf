/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:49:05 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/10/24 18:11:54 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	int		i;

	i = 0;
	if (!s || !(res = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (*s)
		res[i++] = f(*(s++));
	res[i] = '\0';
	return (res);
}
