/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:02:25 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/02 18:14:05 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

unsigned int    pgcd(unsigned int a, unsigned int b)
{
	int rest = 0;
	if(a == 0 || b == 0)
		return(0);
	while (b)
	{
		rest = b;
		b = a % b;
		a = rest;
	}
	return(a);
}
int main()
{
	unsigned int a = 42;
	unsigned int b = 10;

	printf("%u\n", pgcd(a,b));
}