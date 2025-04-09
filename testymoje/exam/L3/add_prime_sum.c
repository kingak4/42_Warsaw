/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:18:28 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/25 11:37:26 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>


void	ft_putchar(char c)
{
	write(1,&c,1);
}
int ft_atoi(char *nb)
{
	int i = 0;
	int	sign = 1;
	int r = 0;

	if(nb[i] == '-')
	{
		sign = -1;
		i++;
	}
	while(nb[i] >= 48 && nb[i] <= 57)
	{
		r = r * 10 + (nb[i] - 48);
		i++;
	}
	return(r * sign);
}

void	putbr(int i)
{
	if( i > 9)
		putbr(i/10);
	write(1,&"0123456789"[i %10],1);
}

int		is_p(int rest)
{
	int i = 2;
	
	if (rest < 2)
		return(0);
	while (i <= rest / 2)
	{
		if (rest % i == 0)
		{
			return(0);
		}
		i++;
	}
	return(1);
}
int	sum_up(char *n)
{
	int sum = 0;
	int g = 0;
	g = ft_atoi(n);
	while (g > 1)
	{
		if(is_p(g))
		{
			sum += g;
		}
		g--;
	}
	
	putbr(sum);
	return(sum);
	
}

int main(int ac, char *av[])
{
	if (ac != 2 || ft_atoi(av[1]) == 0)
	{
		write(1,"0\n",1);
		return(0);
	}
	else
		sum_up(av[1]);
}