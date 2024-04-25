/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:03:30 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/29 16:10:41 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (nmemb * size == 0)
	{
		s = malloc(0);
		if (!s)
			return (NULL);
		return (s);
	}
	if ((nmemb * size) / size != nmemb)
		return (NULL);
	s = malloc(nmemb * size);
	if (!s)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}

/*int	main(void)
{
	size_t nm = 5;
	size_t size = sizeof(int);

	int *arr = (int *)ft_calloc(nm, size);
	if (arr)
	{
		for (size_t i = 0; i < nm; i++)
			printf("MINE >> %d\n", arr[i]);
		free(arr);
	}
	else
		printf("Memory not allocated\n");
	int	*arr2 = (int *)calloc(nm, size);
	if (arr2)
	{
		for (size_t a = 0; a < nm; a++)
			printf("NOT MINE >> %d\n", arr2[a]);
		free(arr2);
	}
	else
		printf("Memory not allocated\n");
	return (0);
}*/
