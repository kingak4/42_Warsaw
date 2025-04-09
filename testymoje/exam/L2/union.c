/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:49:37 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/24 16:38:25 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	unio(char *s1,char *s2)
{
	int	tab[256] = {0};
	int i = 0;
	
	while (s1[i])
	{
		int var = tab[s1[i]];
		if(var == 0)
		{
			write(1,&s1[i],1);
			var = 1;
			tab[s1[i]] = var;
		}
			i++;
	}
	i = 0;
	while (s2[i])
	{
		int var = tab[s2[i]];
		if(var == 0)
		{
			write(1,&s2[i],1);
			var = 1;
			tab[s2[i]] = var;
		}
		i++;
	}	
}
int main(int ac, char *av[])
{
	if(ac == 3)
	{
		unio(av[1],av[2]);
	}
	else
		write(1,"\n",1);
}