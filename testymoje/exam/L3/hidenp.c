/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:33:31 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/02 17:25:36 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	hiden(char *s1,char *s2)
{
	int i = 0;
	int j = 0;

	while (s1[i] && s2[j])
	{
		if(s1[i] == s2[j])
			i++;
		j++;
	}
	if(s1[i] == '\0')	
		write(1,"1\n",2);
	else
		write(1,"0\n",2);
}
int main(int ac, char*av[])
{
	if (ac == 3)
	{
		hiden(av[1], av[2]);
	}
	else
		write(1,"\n",1);
}