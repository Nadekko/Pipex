/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:51:43 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/09 16:49:01 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const void	*a;

	i = 0;
	a = s;
	while (i < n)
	{
		if (((unsigned char *)a)[i] == (unsigned char)c)
			return ((void *)(a + i));
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char	*str = "Looking for character 'f'";
	const char	ch = 'f';

	printf("str = %s\n\n", str);
	printf("NOT MINE >> 
		Remaining string after '%c' : %s\n", ch, (char *)memchr(str, ch, 20));
	printf("MINE >> 
		Remaining string after '%c' : %s\n", ch, (char *)ft_memchr(str, ch, 20));
	return (0);
}*/
