/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:14:50 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/10/28 18:06:44 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*temp;

	if (!lst)
		return (NULL);
	res = f(lst);
	temp = res;
	while (lst->next)
	{
		lst = lst->next;
		temp->next = f(lst);
		if (!(temp = temp->next))
			return (NULL);
	}
	return (res);
}
