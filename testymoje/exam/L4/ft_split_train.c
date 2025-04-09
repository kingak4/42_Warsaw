/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_train.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:52:44 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/09 13:18:32 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		conuter(char *s)
{
	int count = 0;
	int i = 0;
	
	while (s[i])
	{
		if (s[i] > 32)
		{
			count += 1;
		}
		i++;
	}
	return(count);
}
char *filler(char *s, int sart, int end)
{
	int len = start - end;
	char *rest;
	int i = 0;
	
	rest = malloc(len +1);
	while (i < len)
	{
		rest[i] = s[start +1];
		i++;
	}
	rest[i] = '\0';
	return(rest);
}
char **ft_split(char *s)
{
	int start = 0;
	int end = 0;
	int i = 0;
	char *rest;
	int len = conuter(s);
	
	rest = malloc((len + 1) * sizeof(char *));
	if(!rest)
		return(NULL);
	while (s[start] != '\0')
	{
		while (s[start] && s[start] <= 32)
		{
			start++;;
		}
		end = start;
		if (s[start] == '\0')
		{
			break ;
		}
		while (s[end] && s[end] > 32)
		{
			end++;;
		}
		if (start < end)
		{
			rest[i] = filler(s,start,end);
			i++;
		}
		start = end;
	}
	rest[i] = NULL;
	return(rest);
}