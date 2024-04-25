/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf_unsign.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: andjenna <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/11/18 17:42:03 by andjenna		  #+#	#+#			 */
/*   Updated: 2023/11/18 17:42:16 by andjenna		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_int(va_list args)
{
	int	num;

	num = va_arg(args, int);
	ft_putnbr(num);
	return (ft_digit_count(num));
}

int	ft_digit_count(int n)
{
	int	digit;

	digit = 0;
	if (n < 0)
	{
		digit++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(48 + (nb % 10));
}
