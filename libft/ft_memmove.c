/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:41:50 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/10/22 15:28:58 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*source;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (dest == NULL && source == NULL)
		return (NULL);
	if (dest > source)
		while (len-- > 0)
			dest[len] = source[len];
	else
		while (len-- > 0)
			*dest++ = *source++;
	return (dst);
}
