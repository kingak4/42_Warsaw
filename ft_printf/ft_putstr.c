/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:15:19 by kikwasni          #+#    #+#             */
/*   Updated: 2025/01/27 17:09:32 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str != '\0')
		write(1, &str, 1);
}

int	ft_intlen(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_len_unsigned(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
