/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:52:33 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/24 18:08:55 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = src;
	d = dest;
	if (!src || !dest)
		return (NULL);
	while (n-- > 0)
		*d++ = *s++;
	return (dest);
}

/*int	main(void)
{
	char src[] = "Hellllllllo, World !";
	char dest[30];
	char idest[30];

	ft_memcpy(dest, src, 5);
	printf("Copied string is : %s\n", dest);
	memcpy(idest, src, 5);
	printf("Coped string is : %s\n", idest);
	return (0);
}*/
