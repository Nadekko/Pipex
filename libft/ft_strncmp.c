/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:54:58 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/09 18:44:15 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (*s1 == '\0')
			break ;
		s1++;
		s2++;
	}
	return (0);
}

/*int	main(void)
{
	char s1[] = "ABC";
	char s2[] = "ABCDEF";
	int	i = ft_strncmp(s1, s2, 4);
	//int	a = strncmp(s1, s2, 4);

	if (i < 0)
		printf("s1 is less than s2\n");
	else if (i > 0)
		printf("s2 is less than s1\n");
	else
		printf("s1 is equal to s2\n");
	
	return (0);
}*/
