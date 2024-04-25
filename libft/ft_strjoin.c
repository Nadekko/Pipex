/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:31:46 by andjenna          #+#    #+#             */
/*   Updated: 2024/04/02 17:37:21 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1 != NULL && s1[i] != '\0')
		s3[j++] = s1[i++];
	i = 0;
	while (s2 != NULL && s2[i] != '\0')
		s3[j++] = s2[i++];
	s3[j++] = '\0';
	return (s3);
}

/*int	main(void)
{
	char	s1[] = "Hello, World ! ";
	char	s2[] = "How you doin ?\n";

	char	*s3 = ft_strjoin(s1, s2);
	printf("My string join >> %s", s3);
	return (0);
}*/
