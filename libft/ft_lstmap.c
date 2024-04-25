/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:16:07 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/13 20:18:36 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	t_list	*start;

	if (lst)
	{
		temp = lst;
		start = ft_lstnew(f(temp->content));
		if (!start)
			return (NULL);
		temp = temp->next;
		while (temp)
		{
			new = ft_lstnew(f(temp->content));
			if (!new)
			{
				ft_lstclear(&start, del);
				return (NULL);
			}
			ft_lstadd_back(&start, new);
			temp = temp->next;
		}
		return (start);
	}
	return (NULL);
}
