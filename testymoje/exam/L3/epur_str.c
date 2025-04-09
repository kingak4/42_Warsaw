/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:37:36 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/25 13:11:07 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	make1(char *s)
{
	int i = 0;
	int space = 0;
	while (s[i])
	{
		if(s[i] == 32)
		{
			if(space)
			{
				i++;
				continue;
			}
			write(1," ",1);
			space = 1;
		}
		else
		{
			space = 0;
			write(1,&s[i],1);
		}
		i++;
	}
}
int main()
{
	char s[]= "he l                           lo   maciek";
	make1(s);
}