/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wd_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:31:44 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/24 10:51:49 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*match(char *s1, char *s2)
{
	int i = 0;
	int j =0;
	
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				i++;
				break ;
			}
			j++;
		}
		if (!s2[j])
		{
			write(1,"\n",1);
		}
	}
		write(1, s1, i);
		write(1, "\n", 1);
	return(NULL);
}
int main(int ac, char *av[])
{
	char *rest;
	if(ac == 3)
	{
		rest = match(av[1],av[2]);
		if (rest)
		{
			write(1,&rest,1);
		}
	}
	else	
		write(1,"\n",1);
}