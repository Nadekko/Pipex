/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: andjenna <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/11/18 17:43:04 by andjenna		  #+#	#+#			 */
/*   Updated: 2023/11/20 11:54:39 by andjenna         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_parse(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_printf_char(args);
	else if (c == 's')
		count += ft_printf_str(args);
	else if (c == 'u')
		count += ft_printf_unsign(args);
	else if (c == 'x' || c == 'X')
		count += ft_printf_hexa(args, c);
	else if (c == 'p')
		count += ft_printf_ptr(args, c);
	else if (c == 'd' || c == 'i')
		count += ft_printf_int(args);
	else if (c == '%')
		return ((int)write(1, "%", 1));
	else
		count = -1;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (format == NULL)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			count += write(1, &*format, 1);
		else if (*format == '%')
		{
			count += ft_parse(*(format + 1), args);
			format++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	char	*str;

	str = "salut";
	ft_printf("valeur de retour  = %d\n", ft_printf
		("my printf >> %c\t%s\t%%%%\t%p\t%d\t%i\t%x\t%X\t%p\n",
			0, str, str, INT_MIN, INT_MAX, 3234763, 3234763, NULL));
	printf("valeur de retour  = %d\n", printf
		("rl printf >> %c\t%s\t%%%%\t%p\t%d\t%i\t%x\t%X\t%p\n",
			0, str, str, INT_MIN, INT_MAX, 3234763, 3234763, NULL));
	return (0);
}*/
