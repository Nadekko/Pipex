/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:53:29 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/09 16:51:15 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

/*int	main(void)
{
	char *str = "This is MY string!";
	char *first_M = ft_strchr(str, 'M');
	printf("first_M : %s\n", first_M);
	char *first_Z = ft_strchr(str, 'Z');
	printf("first_Z : %s\n", first_Z);
	char *first_i = strchr(str, 'i');
	printf("first_i : %s\n", first_i);
	return (0);
}*/
