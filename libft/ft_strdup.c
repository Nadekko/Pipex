/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:14:34 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/26 17:07:46 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*dup;
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	dup = ptr;
	while (*s)
	{
		*ptr = *s;
		ptr++;
		s++;
	}
	*ptr = '\0';
	return (dup);
}

/*int	main()
{
	char	str[20] = "Hello, world!";
	char	*ptr;
	char	*dup;


	printf("The first string is : %s\n", str);
	ptr = ft_strdup(str);
	printf("MINE >> The duplicated string is : %s\n", ptr);
	dup = strdup(str);
	printf("NOT MINE >> The duplicated string is : %s\n", dup);
	free(dup);
}*/
