/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:45:11 by kikwasni          #+#    #+#             */
/*   Updated: 2025/01/29 10:47:50 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nb >= 10)
		count = ft_putnbr_unsigned(nb / 10);
	ft_putchar(nb % 10 + '0');
	count++;
	return (count);
}
