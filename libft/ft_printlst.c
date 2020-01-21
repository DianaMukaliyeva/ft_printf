/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:38:14 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/10/28 19:05:19 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlst(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp)
	{
		write(1, temp->content, temp->content_size);
		write(1, "\n", 1);
		temp = temp->next;
	}
}
