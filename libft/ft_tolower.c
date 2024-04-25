/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:55:49 by andjenna          #+#    #+#             */
/*   Updated: 2023/12/02 19:59:20 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	while (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

/*int	main(void)
{
	char	c;

	c = 'a';
	printf("when lowercase is passed : %d\n", ft_tolower(c));
	c = 'A';
	printf("when uppercase is passed : %d\n", ft_tolower(c));
	c = '-';
	printf("when non-alpha is passed : %d\n", ft_tolower(c));
	return (0);
}*/
