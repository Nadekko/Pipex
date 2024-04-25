/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:54:33 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/10 17:28:32 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tr;
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	while (ft_get_set(set, s1[start]))
		start++;
	while (end > start && ft_get_set(set, s1[end - 1]))
		end--;
	tr = malloc(sizeof(char) * (end - start + 1));
	if (!tr)
		return (NULL);
	while (start < end)
		tr[i++] = s1[start++];
	tr[i] = '\0';
	return (tr);
}

/*int	main(void)
{
	char	s1[] = "tttttttttt***t**test*tt*ttt**t";

	printf("My string >> %s\n", ft_strtrim(s1, "tt"));
	return (0);
}*/
