/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:35:33 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/18 16:54:25 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	checker(char c)
{
	if (c >= 'a' && c <= 'z')
		return('z' - (c - 'a'));
	if (c >= 'A'&& c <= 'Z')
		return('Z' - (c - 'A'));
	return (c);
}
void	abc(char *str)
{
	int i = 0;
	char r;
	while(str[i])
	{
		r = checker(str[i]);
		write(1, &r, 1);
		i++;
	}
	write(1,"\n",1);
}
int main(int ac, char *av[])
{
	if (ac > 1)
	{
		int i = 0;
		while (i < ac)
		{
			abc(av[i]);
			i++;
		}
	}
	else 
	write(1,"\n",1);
	return (0);
}