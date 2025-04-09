/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:10:21 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/18 12:25:47 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	checker(char c)
{
	if (c >= 'a' && c <= 'z')
		return(c - 32);
	if (c >= 'A' && c <= 'Z')
		return(c + 32);
	return (0);
}
void	bigger(char *str)
{
	int i = 0;
	char r;
	while (str[i])
	{
		r = checker(str[i]);
		write(1, &r, 1);
		i++;
	}
	write(1,"\n",1);
}
int main (int ac, char *av[])
{
	if (ac > 1)
	{
		int i = 1;
		while (i < ac)
		{
			bigger(av[i]);
			i++;
		}
	}
	else
		write(1,"\n",1);	
}