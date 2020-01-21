/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:43:16 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/10/17 18:43:17 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*temp;
	char	*result;

	result = dest;
	temp = (char*)src;
	while (*temp)
		*result++ = *temp++;
	*result = '\0';
	return (dest);
}
