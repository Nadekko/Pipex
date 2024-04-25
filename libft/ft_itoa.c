/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:35:11 by andjenna          #+#    #+#             */
/*   Updated: 2024/03/11 10:53:02 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_count_itoa(long n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		digit++;
	}
	while (n)
	{
		n /= 10;
		digit++;
	}
	return ((int)digit);
}

char	*ft_itoa(int n)
{
	int		d_count;
	long	nb;
	char	*rst;

	nb = n;
	d_count = ft_digit_count_itoa(n);
	rst = (char *)malloc(d_count + 1);
	if (!rst)
		return (NULL);
	rst[d_count] = '\0';
	if (nb < 0)
	{
		rst[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		rst[0] = '0';
	while (nb)
	{
		rst[--d_count] = 48 + (nb % 10);
		nb /= 10;
	}
	return (rst);
}

/*#include <limits.h>
int	main(void)
{
		int n = -2147483648;
		printf("Integer : %d\n", n);
		printf("string : %s\n", ft_itoa(n));
	return (0);
}*/
