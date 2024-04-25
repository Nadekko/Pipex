/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_utils.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: andjenna <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/11/18 17:47:22 by andjenna		  #+#	#+#			 */
/*   Updated: 2023/11/18 17:47:25 by andjenna		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_digit_count_hexa(unsigned long long n, int base)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= base;
		digit++;
	}
	return (digit);
}

void	ft_putnbr_hexa(unsigned long long n, char flag)
{
	char	*hex_digit;

	if (flag == 'x' || flag == 'p')
		hex_digit = "0123456789abcdef";
	else
		hex_digit = "0123456789ABCDEF";
	if (n >= 16)
		ft_putnbr_hexa(n / 16, flag);
	ft_putchar(hex_digit[n % 16]);
}

void	ft_putnbr_unsigned(unsigned int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(48 + (nb % 10));
}
