/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:49:57 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/10/24 19:20:37 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*result;

	if (!s || !(result = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	result = ft_strncpy(result, s + start, len);
	result[len] = '\0';
	return (result);
}
