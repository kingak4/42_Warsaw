/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:13:01 by kikwasni          #+#    #+#             */
/*   Updated: 2025/01/29 11:27:53 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int count; 
	
	i = 0;
	count = 0;
	va_start(args, format);
	
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (count);
			if (format[i] == 's')
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
				char c = va_arg(args, int);
				ft_putchar(c);
				count += 1;
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				count += 1;
			}
			else if (format[i] == 'u')
			{
				unsigned int nb = va_arg(args, unsigned int);
				ft_putnbr_unsigned(nb);
			}
			else if (format[i] == 'x')
			{
				unsigned int nb = va_arg(args, unsigned int);
				ft_printx(nb);
			}
			else if (format[i] == 'X')
			{
				unsigned int nb = va_arg(args, unsigned int);
				ft_print_upperx(nb);
			}
			else if (format[i] == 'p')
			{
				char *p = va_arg(args, char *);
				ft_print_pointer(p);
			}
		}	
		else
		{
			write(1, &format[i], 1);
			count += 1;
		}
		i++;
	}
	va_end(args);
	return(count);
}


//#include <stdio.h>
//int main()
//{
//	printf("%d", ft_printf("tak"));
//	printf("\n");
//	ft_printf("tak");
//	printf("\n\n");

//	printf("tak%s", "tak");
//	printf("\n");
//	ft_printf("tak%s", "tak");
//	printf("\n\n");

//	printf("tak%ldtak", -2147483648);
//	printf("\n");
//	printf( "%d", ft_printf("%d", -2147483644));
//	printf("\n\n");

//	printf("%c", 'b');
//	printf("\n");
//	printf( "%d", ft_printf("%c", 'b'));
//	printf("\n\n");

//	printf("%%");
//	printf("\n");
//	ft_printf("%%");
//	printf("\n\n");

//	printf("tak");
//	printf("\n");
//	ft_printf("tak");
//	printf("\n\n");

//	printf("%x", 20000);
//	printf("\n");
//	ft_printf("%x", 20000);
//	printf("\n\n");
	
//	printf("%x", 20000);
//	printf("\n");
//	ft_printf("%x", 20000);
//	printf("\n\n");
	
//	void *ptr = (void*)0x12345678;
//	printf("12. Wskaźnik: %p\n", ptr);
//	printf( "%d",ft_printf("12. Wskaźnik: %p\n\n", ptr));
//	return (0);
//}