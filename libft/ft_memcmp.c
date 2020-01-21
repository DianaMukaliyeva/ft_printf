/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:42:24 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/10/26 13:59:48 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*cpy1;
	char	*cpy2;

	i = 0;
	cpy1 = (char*)s1;
	cpy2 = (char*)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (cpy1[i] != cpy2[i])
			return ((unsigned char)cpy1[i] - (unsigned char)cpy2[i]);
		i++;
	}
	return (0);
}
