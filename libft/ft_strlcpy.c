/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:54:15 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/09 13:13:04 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

/*int main(void)
{
	char dest[20];
	const char *src = "Hello, world!";
	size_t size = 5;
	size_t result = ft_strlcpy(dest, src, size);

	printf("Copied string: %s\n", dest);
	printf("Resulting length: %zu\n", result);
	char dest2[20];
	size_t rst = strlcpy(dest2, src, 5);
	printf("Real function: %s\n", dest2);
	printf("Real function: %zu\n", rst);
	return (0);
}*/
