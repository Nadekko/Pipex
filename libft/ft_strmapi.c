/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:50:17 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/11 21:04:35 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*rst;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	rst = (char *)malloc(len + 1);
	if (!rst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		rst[i] = f(i, s[i]);
		i++;
	}
	rst[len] = '\0';
	return (rst);
}
