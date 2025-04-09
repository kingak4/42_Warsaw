/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:52:35 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/03 12:41:09 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int c)
{
	if( c >= 10)
		ft_putnbr(c /10);
	write(1,&"0123456789"[c % 10],1);
}
int	ft_atoi(char *s)
{
	int i = 0;
	int rest = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		rest = rest * 10 + (s[i] - 48);
		i++;
	}
	return(rest);
}

void	tab_mult(char *s)
{
	int a = 1;
	int rest = 0;
	int b = 0;

	rest = ft_atoi(s);
	while (a < 10)
	{
		b = rest * a;
		ft_putnbr(a);
		write(1," * ",3);
		ft_putnbr(rest);
		write(1," = ",3);
		ft_putnbr(b);
		write(1,"\n",1);
		a++;
	}

}
int main(int ac, char *av[])
{
	int i = 1;
	if(ac != 2)
		write(1,"\n",1);
	else
	{
		while(i < ac)
		{
			tab_mult(av[i]);
			i++;
			write(1,"\n",1);
		}
	}
}