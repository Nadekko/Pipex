/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:58:11 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/13 20:19:49 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_content;

	new_content = malloc(sizeof(t_list));
	if (new_content == NULL)
		return (NULL);
	new_content->content = content;
	new_content->next = NULL;
	return (new_content);
}
