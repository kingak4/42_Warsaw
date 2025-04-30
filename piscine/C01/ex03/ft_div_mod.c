/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:42:00 by kikwasni          #+#    #+#             */
/*   Updated: 2024/10/10 13:32:50 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b)
	{
		*div = a / b;
		*mod = a % b;
	}
}
/*
int main()
{
	int	c;
	int	d;
	int	div;
	int	mod;
	c = 9;
	d = 3;
	ft_div_mod(c, d, &div, &mod);
	printf("div: %d, mod: %d\n", div, mod);
	return(0);
}
*/
