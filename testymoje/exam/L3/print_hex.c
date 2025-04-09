/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:22:37 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/02 20:21:41 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1,&c,1);
}

int	hex(unsigned int nb)
{
	if(nb >= 16)
	{
		nb = hex(nb /16);
		nb = hex(nb % 16);
	}
	else
	{
		if(nb >= 10)
		{
			ft_putchar("abcdef"[nb % 16 - 10]);
		}
		else
		{
			nb += 48;
			ft_putchar(nb);
		}
	}
	return(nb);

}
int main()
{
	unsigned int i = 255;

	hex(i);
}