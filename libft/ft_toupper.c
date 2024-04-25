/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:56:11 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/20 12:10:13 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	while (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

// int	main(void)
// {
// 	char	c;

// 	c = 'A';
// 	ft_printf("when uppercase is passed : %d\n", ft_toupper(c));
// 	c = 'a';
// 	ft_printf("when lowercase is passed : %d\n", ft_toupper(c));
// 	c = '+';
// 	ft_printf("when non alpha is passe : %d\n", ft_toupper(c));
// 	return (0);
// }
