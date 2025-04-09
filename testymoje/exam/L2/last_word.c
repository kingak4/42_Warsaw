/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:59:01 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/19 14:21:41 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	lastchars(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i] > ' ')
		i--;
	i++;
	while (str[i])
	{
		write(1,&str[i],1);
		i++;
	}
}
int main(int ac, char *av[])
{
	if (ac > 1)
	{
		int i = 1;
		while (i < ac)
		{
			lastchars(av[i]);
			i++;
		}
	}
	write (1,"\n",1);
}