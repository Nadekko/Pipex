/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf_aff.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: andjenna <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/11/18 17:42:31 by andjenna		  #+#	#+#			 */
/*   Updated: 2023/11/18 17:42:38 by andjenna		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(va_list args)
{
	int	c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}

int	ft_printf_str(va_list args)
{
	char	*str;
	int		len;

	len = 0;
	str = va_arg(args, char *);
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[len] != '\0')
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}
