/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:28:28 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/02 17:37:33 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
	int rest = 0;
	if(a == 0 || b == 0 )
		return(0);
	if (a > b)
		rest = a;
	else
		rest = b;
	while(rest % a || rest % b)
		rest++;
	return(rest);
}
int main()
{
	unsigned int a = 4;
	unsigned int b = 5;

	printf("%u\n", lcm(a,b));
}