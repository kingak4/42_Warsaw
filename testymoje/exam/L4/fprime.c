/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:53:25 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/09 10:23:20 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void  makeit(char *s)
{
	int i = 2;
	int rest = atoi(s);
	int first = 1;
	
	while( rest > 1)
	{
		if( rest % i == 0)
		{
			if (!first)
				printf("*"); // ważne !
			printf("%d", i);
			rest /= i;
			first = 0;
		}
		else
			i++;
	}
}

int main(int ac, char *av[])
{
	int i = 1;
	if(ac != 2)
		printf("\n");
	else
	{
		while(i < ac)
		{
			makeit(av[i]);
			i++;
		}
	}
}