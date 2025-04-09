/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:21:46 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/31 09:19:11 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	len(char *s)
{
	int i = 0;
	while(s[i])
	{
		i++;
	}
	return(i);
}

void make3(char *s)
{
	int i = 0;
	int space = 0;
	int last = 0;
	
	last = len(s) - 1;
	while (s[i] == 32)
	{
		i++;
	}
	while(last >= 0 && s[last] == 32)
	{
		s[last] = '\0';
		last--;
	}
	while (s[i])
	{
			if(s[i] == 32)
			{
				if (space)
				{
					i++;
					continue;
				}
				space = 1;
				while(space < 3)
				{
					write(1," ",1);
					space++;
				}
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
	char s[] = "             hello          b                                                               ";
	make3(s);
}