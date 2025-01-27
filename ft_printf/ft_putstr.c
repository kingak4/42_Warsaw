/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:15:19 by kikwasni          #+#    #+#             */
/*   Updated: 2025/01/23 18:09:06 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void ft_putstr(char *str)
{
	if (!str)
		return ;
	while(str != '\0')
		write(1, &str, 1);
}

int	ft_intlen(int nbr)
{
	int i;
	
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