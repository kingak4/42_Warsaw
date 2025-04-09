/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:34:47 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/18 11:34:37 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int charchecker(char c)
{
	if( c == ' ')
		return (c);
	if (c >= 'a' && c < 'z')
		return (c + 1);
	if (c >= 'A' && c <'Z')
		return (c + 1);
	else if (c =='Z'|| c == 'z')
		return(c - 25 );
	return(c);
}
void	abc(char *str)
{
	int i = 0;
	char r;
	while (str[i])
	{
		r = charchecker(str[i]);
		write(1,&r,1);
		i++;
	}
	write(1,"\n",1);
}

int main(int ac, char *av[])
{
	if (ac > 1)
	{
		int i = 1;
		while (i < ac)
		{
			abc(av[i]);
			i++;
		}
	}
	else
		write(1,"\n",1);
	return(0);
}
