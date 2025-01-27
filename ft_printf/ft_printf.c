/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:13:01 by kikwasni          #+#    #+#             */
/*   Updated: 2025/01/27 16:23:38 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int count; // we need to return it 
	
	i = 0;
	count = 0;
	va_start(args, format);
	
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i++;
		else if (format[i] == 's')
		{
			char *str = va_arg(args, char *);
			ft_putstr(str);
			count += ft_strlen(str);
		}
		else if (format[i] == 'd' || format[i] == 'i')
		{
			int num = va_arg(args, int);
			ft_putnbr(num);
			count += ft_intlen(num);
		}
		else if (format[i] == 'c')
		{
			char c = va_arg(args, int); // change to int bc we will display ascii nuber of char
			ft_putchar(c);
			count += 1;
		}
		else if (format[i] == '%')
		{
			write(1, '%', 1);
			i++;
			count += 1;
		}
		else if (format[i] == 'u')
		{
			unsigned int nb = va_arg(args, unsigned int);
			ft_putnbr_unsigned(nb);
			count += ft_len_unsigned(nb);
		}
		else if (fromat[i] == 'x')
		{
			
		}
	}


	//1. zainicajlizuj liste  zmiennych va_list any name a drugi to intiger kroty policzy
	// va_list args;
	
	// va_start(args, format); 
	//2 literaujemy po formacie 
	// while (*format != '\0')
	//{
	// 	if (*format == '%')
	//	format++;
	//	if (*format == 'd' || 'i')
	//		write the function to print integer;
	//	else if (*format == 's')
	//		write the function to print string;	
	//}		
}