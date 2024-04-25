/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:19:10 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/20 12:02:56 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>

int				ft_printf(const char *fromat, ...);
int				ft_printf_char(va_list args);
int				ft_printf_str(va_list args);
int				ft_printf_hexa(va_list args, char flag);
int				ft_printf_ptr(va_list args, char flag);
int				ft_printf_int(va_list args);

unsigned int	ft_printf_unsign(va_list args);

void			ft_putnbr_unsigned(unsigned int nb);
void			ft_putnbr_hexa(unsigned long long nb, char flag);
void			ft_putnbr(int n);
void			ft_putchar(char c);

int				ft_digit_count_hexa(unsigned long long n, int base);
int				ft_digit_count(int n);

#endif
