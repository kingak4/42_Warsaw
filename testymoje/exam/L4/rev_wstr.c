/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:34:26 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/09 15:38:04 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_isspace(char c)
{
	if (c == 32 || c == '\t')
		return(1);
	return(0);
	
}
void rev(char *str)
{
	int start = 0;
	int end = 0;
	int first = 1;
	
	while (str[start] != '\0')
		start++;
	while (start >= 0)
	{
		while ((start >= 0 && str[start] == '\0') || ft_isspace(str[start]))
		{
			start--;
		}
		end = start;
		while (end >= 0 && !ft_isspace(str[end]))
		{
			end--;
		}
		if (first == 0)
		{
			write(1," ",1);
		}
		write(1,str + end +1, start - end);
		first = 0;
		start = end;
	}
	

}

int main()
{
    char s[] = "maciek lubi kaczki chodzic do 42 codzienie upuje kwiaty mamie  ";
    rev(s);
    return 0;
}
