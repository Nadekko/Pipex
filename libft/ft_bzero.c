/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:49:06 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/09 11:49:19 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr++ = 0;
		n--;
	}
}

/*
int main(void)
{
	unsigned char buffer[10]; // Crée un tampon de 10 octets
	size_t size = sizeof(buffer);

	for (size_t i = 0; i < size; i++) 
		buffer[i] = i;
	printf("Avant bzero:\n");
	for (size_t i = 0; i < size; i++)
		printf("%d ", buffer[i]);
	printf("\n");

	ft_bzero(buffer, size);

	printf("Après bzero:\n");
	for (size_t i = 0; i < size; i++)
	printf("%d ", buffer[i]);
	printf("\n");

	return (0);
}*/
