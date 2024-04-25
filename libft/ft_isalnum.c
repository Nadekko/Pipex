/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:49:40 by andjenna          #+#    #+#             */
/*   Updated: 2023/12/02 19:55:57 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
		|| (c >= 48 && c <= 57));
}

/*
int	main(void)
{
	char	c;

	c = 'a';
	printf("Result when lowercase alpha is passed : %d", ft_isalnum(c));
	c = 'A';
	printf("\nResult when uppercase alpha is passed : %d", ft_isalnum(c));
	c = '0';
	printf("\nResult when digit is passed : %d", ft_isalnum(c));
	c = '+';
	printf("\nResult when non-alpha is passed : %d", ft_isalnum(c));
	return (0);
}*/
