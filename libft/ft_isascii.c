/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:50:28 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/09 11:50:37 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*
int	main(void)
{
	char	c;

	c = 65;
	printf("\nResult when ascii is passed : %d", ft_isascii(c));
	c = 125;
	printf("\nResult when ascii is passed : %d\n", ft_isascii(c));
	c = -1;
	printf("Result when non-ascii is passed : %d\n", ft_isascii(c));
	c = -125;
	printf("Result when non-ascii is passed : %d\n", ft_isascii(c));
	return (0);
}*/
