/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:51:57 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/09 15:41:37 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	while (n-- > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}

/*int	main(void)
{
	const char	s1[] = "ABC";
	const char	s2[] = "ABCDEF";
	int	i;
	int	a;

	i = ft_memcmp(s1, s2, 5);
	a = memcmp(s1, s2, 5);
	if (i < 0)
		printf("MINE = s1 is less than s2\n");
	else if (i > 0)
		printf("MINE = s2 is less than s1\n");
	else
		printf("MINE = s1 is equal to s2\n");
	if (a < 0)
		printf("NOT MINE = s1 is less than s2\n");
	else if (a > 0)
		printf("NOT MINE = s2 is less than s1\n");
	else
		printf("NOT MINE = s1 is equal to s2\n");
	return (0);
}*/
