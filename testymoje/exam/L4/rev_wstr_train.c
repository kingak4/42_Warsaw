/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr_train.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:33:19 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/09 15:41:05 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int ft_isspace(char c)
{
	if( c == 32 || c == '\t')
		return(1);
	return(0);
}
void rev(char *s)
{
	int start = 0;
	int end = 0;
	int first = 1;
	
	while(s[start] != '\0')
		start++;
	while(start >= 0)
	{
		while(start >=0 &&( s[start] == '\0' || ft_isspace(s[start])))
			start--;
		end = start;
		while (end >= 0 && !ft_isspace(s[end]))
			end--;
		if (first == 0)
		{
			
			write(1," ",1);
		}
		write(1,s + end +1,start - end);
		first = 0;
		start = end;
	}
	
}
int main(int ac,char *av[])
{
	if ( ac > 1)
	{
		rev(av[1]);
	}
	else
		write(1,"\n",1);
	
	
}
