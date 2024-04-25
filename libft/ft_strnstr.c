/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:28:00 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/24 18:05:35 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!big || len == 0)
		return (NULL);
	if (!*little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[j])
		{
			while (little[j] && big[i + j] == little[j] && i + j < len)
				j++;
			if (!little[j])
				return ((char *)&big[i]);
			j = 0;
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	//const char *largest = "aaabcabcd";
	char *ptr;
	char *str;

	ptr = strnstr("1", "a", 1);
	str = ft_strnstr("22", "b", 2);
	printf("reel function ptr = %s\n", ptr);
	printf("my funcion str = %s\n", str);
	return (0);
}*/
