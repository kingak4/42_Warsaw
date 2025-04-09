/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:16:09 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/19 12:04:43 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	changeletter(char c)
{
	if (c >= 'A'&& c <= 'Z')
		return(c + 32 );
	return (c);
}
void	get1word(char *str)
{
	int i = 0;
	char r;
	
	while (str[i])
	{
		if (str[i] >= 'A'&& str[i] <= 'Z')
		{
			r =changeletter(str[i]);
			write(1, "_",1);
			write(1, &r, 1);
		}
		else
			write(1,&str[i],1);
		i++;
	}
	write(1,"\n",1);
}


int main(int ac, char *av[])
{
	if(ac > 1)
	{
		int i = 1;
		while (i < ac)
		{
			get1word(av[i]);
			i++;
		}
	}
	else
		write(1,"\n",1);
}