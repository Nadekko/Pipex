/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:52:57 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/09 16:31:54 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (s < d)
		while (n--)
			d[n] = s[n];
	else
		ft_memcpy(d, s, n);
	return (dest);
}

/*int	main(void)
{
	const char src[] = "Hello, World !";
	char dest[] = "Good Night, World !";

	printf("dest before memmove : %s\n", dest);
	ft_memmove(dest, src, 5);
	printf("dest after MY_memmove : %s\n", dest);
	
	char dest2[] = "Good Nitgh, Wolrd !"; 
	void *result = memmove(dest2, src, 5);
	char	*rst = result;
	printf("reel function : %s\n", rst);

	char Rst[] = {67, 68, 67, 68, 69, 0, 45};
	char Rst2[] = {67, 67, 68, 68, 69, 0, 45};

	ft_memmove(Rst + 1, Rst2, 2);
	printf("MINE >> %s\n", Rst);

	char	Rst3[] = {67, 68, 67, 68, 69, 0,45};
	void	*Rst4 = memmove(Rst3 + 1, Rst2, 2);
	char	*Rst5 = Rst4;
	printf("NOT MINE >> %s\n", Rst5);
	return (0);
}*/
