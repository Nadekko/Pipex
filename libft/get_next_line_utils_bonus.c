/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:27:10 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/23 17:17:18 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	s3 = NULL;
	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1[i] != '\0')
		s3[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		s3[j++] = s2[i++];
	s3[j] = '\0';
	free(s1);
	return (s3);
}

char	*ft_strchr_gnl(char *str, int c)
{
	char	*ptr;

	if (!str)
		return (NULL);
	ptr = (char *)str;
	while (*ptr != c && *ptr != '\0')
		ptr++;
	if (*ptr == c)
		return (ptr);
	else
		return (NULL);
}
