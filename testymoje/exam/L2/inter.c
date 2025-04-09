/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:30:52 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/25 10:35:43 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	duble(char *s1,char *s2)
{
	int	tab[256] = {0};
	int i = 0;
	while (s2[i])
	{
		int var = tab[s2[i]];
		if(tab[s2[i]] == 1)
		{
			var = 0;
			tab[s2[i]] = var;
		}
		i++;
	}
	i = 0;
	while (s1[i])
	{
		int var = tab[s1[i]];
		if(var == 0)
		{
			var = 3;
			tab[s1[i]] = var;
			write(1,&s1[i],1);
		}
		i++;
	}
	
}
int main(int ac,char *av[])
{
	if(ac == 3)
	{
		duble(av[1],av[2]);
	}
	//else
		//write(1,"\n",1);
}