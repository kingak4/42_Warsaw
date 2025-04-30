/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:37:18 by kikwasni          #+#    #+#             */
/*   Updated: 2024/10/10 16:26:41 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	swp;

	if (*b)
	{
		swp = *a;
		*a = *a / *b;
		*b = swp % *b;
	}
}
/*
int main()
{
	int	a;
	int	b;
	a = 42;
	b = 21;
	ft_ultimate_div_mod(&a , &b);
	printf("%d,%d\n", a , b);
	return(0);
}
*/
