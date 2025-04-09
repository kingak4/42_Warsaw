/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:38:00 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/03 11:46:27 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_isspace(char c)
{
	if (c <= 32)
		return(1);
	return(0);
}
void ft_puctchar(char c)
{
	write(1,&c,1);
}
void capit(char *s)
{
	int i = 0;
	while(s[i])
	{
		if(s[i] >= 'A' && s[i] <= 'Z' )
			s[i] += 32;
		if(s[i] >= 'a' && s[i] <= 'z' && ft_isspace(s[i -1]))
			s[i] -= 32;
		ft_puctchar(s[i]);
		i++;
	}
}
int main(int ac, char *av[])
{
	int i = 1;
	if(ac == 1)
		ft_puctchar('\n');
	else
	{
		while( i < ac)
		{
			capit(av[i]);
			i++;
			ft_puctchar('\n');
		}
	}
}
