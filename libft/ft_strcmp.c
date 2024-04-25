/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:30:47 by andjenna          #+#    #+#             */
/*   Updated: 2023/12/10 19:31:03 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*int	main(void)
{
	char s1[] = "ABC";
	char s2[] = "ABCDEF";
	int i = ft_strcmp(s1, s2);

	if (i < 0)
		printf(s1 is less then s2\n");
	else if (i > 0)
		printf("s2 is less than s1\n");
	else
		printf("s1 is equal to s2\n");
	return (0);
}*/
