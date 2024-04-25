/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:55:32 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/09 18:39:39 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
		ptr++;
	if (c == '\0')
		return ((char *)ptr);
	while (--ptr >= s)
	{
		if ((unsigned char)c == *ptr)
			return ((char *) ptr);
	}
	return (NULL);
}

/*int	main(void)
{
	char s[] = "some,data,in,comas";
	char *comma = strrchr(s, ',');
	printf("%s\n", comma);

	char t[] = "some,data,in,comas";
	char *comma2 = ft_strrchr(t, ',');
	printf("%s\n", comma2);
	return (0);
}*/
