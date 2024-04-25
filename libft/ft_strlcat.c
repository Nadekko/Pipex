/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:53:52 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/24 18:07:59 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!src || !dst || size == 0)
		return (0);
	while (dst[i] && i < size)
		i++;
	j = i;
	while (src[j - i] && (j + 1) < size)
	{
		dst[j] = src[j - i];
		j++;
	}
	if (i < size)
		dst[j] = '\0';
	while (src[j - i])
		j++;
	return (j);
}

/*int	main(void)
{
	char	dst[20] = "Hello, ";
	const char	*src = "world !";
	size_t result = ft_strlcat(dst, src, 5);

	printf("MINE >> %zu\n", result);

	char	dst2[20] = "Hello, ";
	size_t rst = strlcat(dst2, src, 5);

	printf("NOT MINE >>  %zu\n", rst);
	return (0);
}*/
