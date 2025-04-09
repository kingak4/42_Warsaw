/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizz_buzz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:50:59 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/17 13:44:06 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int i)
{
	if(i > 9)
		ft_putnbr(i /10);
	write(1,&"0123456789"[i % 10], 1);
}
int main()
{
	int	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			write(1,&"fizbuzz",8);
		}
		else if (i % 3 == 0)
			write(1,&"fizz",4);
		else if (i % 5 == 0)
			write(1,&"buzz",4);
		else
			ft_putnbr(i);
			i++;
		write(1, "\n", 1);
	}
	
}