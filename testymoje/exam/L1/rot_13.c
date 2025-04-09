/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:04:12 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/18 11:40:26 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int makechar(char c)
{
	if(c >= 'a' && c <= 'm')
		return(c + 13 );
	if(c >= 'A' && c <= 'M')
		return(c + 13 );
	else if (c >= 'n' && c <= 'z')
		return(c - 13 );
	else if (c >= 'N' && c <= 'Z')
		return(c - 13 );
 	return (c);
}
void	did(char *str)
{
	int	i = 0;
	char r;
	while (str[i])
	{
		r = makechar(str[i]);
		write(1,&r,1);
		i++;
	}
	write(1,"\n",1);
}
int main(int ac , char *av[])
{
	if(ac > 1)
	{
		int i  = 1;
		while(i < ac )
		{
			did(av[i]);
			i++;
		}
	}
	else
	write(1,"\n",1);
	return (0);
}