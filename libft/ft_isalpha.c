/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:50:02 by andjenna          #+#    #+#             */
/*   Updated: 2023/12/02 19:56:24 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

/*
int	main(void)
{
	char	c;

	c = 'A';
	printf("Result when uppercase alpha is passed : %d", ft_isalpha(c));
	c = 'a';
	printf("\nResult when lowercase alpha is passed : %d", ft_isalpha(c));
	c = 'a';
	printf("\nResult when reel function is passed : %d\n", isalpha(c));
	return (0);
}*/
