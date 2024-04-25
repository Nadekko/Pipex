/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:54:55 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/11 18:57:15 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(unsigned int start, size_t len, size_t slen)
{
	if (len > slen - start)
		len = slen - start;
	return (len);
}

static char	*ft_nullmall(char *dst)
{
	dst = malloc(1);
	if (!dst)
		return (NULL);
	dst[0] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*dst;

	i = 0;
	dst = NULL;
	if (!s)
		return (ft_nullmall((char *)s));
	slen = ft_strlen(s);
	if (start >= slen || len == 0)
		return (ft_nullmall(dst));
	len = ft_len(start, len, slen);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/*int	main(void)
{
	char	src[] = "Good night, World !";

	char	*dst = ft_substr(src, 5, 15);
	printf("MINE >> %s", dst);

	return (0);
}*/
