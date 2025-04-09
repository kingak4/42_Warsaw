/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:57:25 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/03 11:34:46 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1,&c,1);
}
int	ft_isspace(char c)
{
	if(c <= 32)
		return(1);
	return(0);
}
void capitan(char *s)
{
	int i = 0;
	while (s[i])
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		if (s[i] >= 'a' && s[i] <= 'z' && ft_isspace(s[i + 1]))
		{
			s[i] -= 32;
		}
		ft_putchar(s[i]);
		i++;
	}
	
}
int main(int ac,char *av[])
{
	int i = 0;
	if(ac == 1)
		ft_putchar('\n');
	else
	{
		while (i < ac)
		{
			capitan(av[i]);
			i++;
			ft_putchar('\n');
			
		}
	}
}