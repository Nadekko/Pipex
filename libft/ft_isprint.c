/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:51:16 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/09 11:51:24 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*
int	main(void)
{
	char	c;

	c = 32;
	printf("\nResult when printable is passed : %d", ft_isprint(c));
	c = 80;
	printf("\nResult when printable is passed : %d", ft_isprint(c));
	c = 127;
	printf("\nResult when printable is passed : %d\n", ft_isprint(c));
	return (0);
}*/
