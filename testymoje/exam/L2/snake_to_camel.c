/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:09:10 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/19 12:26:19 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	charsmall(char c)
{
	if (c >= 'a' && c <= 'z')
		return(c - 32);
	return (c);
}
void	makebetter(char *str)
{
	int	i = 0;
	char	r;
	while (str[i])
	{
		if (str[i] == '_')
		{
			i++;
			r = charsmall(str[i]);
			write(1,&r,1);
		}
		else
			write(1,&str[i],1);
		i++;
	}
	write(1,"\n",1);
}
int main (int ac, char *av[])
{
	if ( ac > 1)
	{
		int  i = 1;
		while (i < ac)
		{
			makebetter(av[i]);
			i++;
		}
	}
	else
		write(1,"\n",1);
}