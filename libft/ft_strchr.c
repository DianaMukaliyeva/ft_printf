/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:44:25 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/10/17 18:44:26 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*temp;

	temp = (char*)s;
	while (*temp)
	{
		if (*temp == c)
			return (temp);
		temp++;
	}
	if (c == '\0')
		return (temp);
	return (NULL);
}
