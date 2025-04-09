/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:18:48 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/07 12:15:43 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_len(char *s)
{
	int i  = 0;
	while (s[i])
	{
		i++;
	}
	return(i);
}

char *ft_space(char *s)
{
	int i = 0;
	int space = 0;
	int len = ft_len(s);

	while(s[i] == 32)
		i++;
	while (len >= 0 && s[len] == 32)
	{
		s[len] = '\0';
		len--;
	}
	
	while (s[i])
	{
		if (s[i] == 32)
		{
			if (space > 0)
			{
				i++;
				continue;
			}
			space = 1;
		}
		else
		{
			space = 0;
			//write(1,&s[i],1);
		}
		if (space == 1)
		{
			write(1," ",1);
		}
		i++;
	}
	return(s);
}
char *rem(char *s)
{
	int i = 0;
	int len = ft_len(s);
	char *s1;
	while (s[i] > 32)
	{
		i++;
	}
	if (s[i] == 32)
	{
		i+= 1;
	}
	s1 = malloc(len -i +1);
	int j = 0;
	while(s[i])
	{
		s1[j] = s[i];
		j++;
		i++;
	}
	s[j] = '\0';
	return(s1);
	
}
char *rostr(char *s)
{
    char buf[100]; 
    int i = 0;
    int j = 0;
    char *s1 = ft_space(s);
    char *s2 = rem(s1);

    return result;
}
int main()
{
    char s[] = "test spacji";
    char *result = rostr(s);
    printf("%s\n", result);
    return 0;
}
