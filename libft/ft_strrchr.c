/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:44:37 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/10/17 18:44:41 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	int		flag;

	flag = 0;
	temp = (char*)s;
	while (*temp)
	{
		if (*temp == c)
			flag++;
		temp++;
	}
	if (c == '\0')
		return (temp);
	if (flag != 0)
	{
		while (*temp != c)
			temp--;
		return (temp);
	}
	return (NULL);
}
