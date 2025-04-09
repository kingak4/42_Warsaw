/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:40:04 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/04 13:32:18 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	wrordcount(char *s)
{
	int i = 0;
	int count = 0;
	
	while (s[i])
	{
		if(s[i] > 32)
			count += 1;
		i++;
	}
	return(count);
}
char *filer(char *s, int start,int end)
{
	char *rest;
	int len = end - start;
	int i = 0;

	rest = malloc(len + 1);
	while (i < len)
	{
		rest[i] = s[start + i];
		i++;
	}
	rest[i] = '\0';
	return(rest);
}
char **ft_split( char *s)
{
	int start = 0;
	int end = 0;
	int wrord = wrordcount(s);
	char **rest;
	int i = 0;
	
	rest = malloc((wrord + 1) * sizeof(char *));
	if(!rest)
		return(NULL);
	while (s[start] != '\0')
	{
		while (s[start] != '\0' && s[start] <= 32)
		{
			start++;
		}
		end = start;
		if (s[start] == '\0')
			break ;
		while (s[end] != '\0' && s[end] > 32)
			end++;
		if(start < end)
		{
			rest[i] = filer(s, start,end);
			i++;
		}
		start = end;
	}
	rest[i] = NULL;
	return(rest);
}
int main() {
    char s[] = "h e l o w r o l d";
    char **rest = ft_split(s);  // Dzielimy napis na słowa

    int i = 0;
    while (rest[i] ) {
        printf("%s\n", rest[i]);  // Wypisujemy każde słowo
        //free(rest[i]);  // Zwolnienie pamięci dla słowa
        i++;
    }

   // free(rest);  // Zwolnienie pamięci dla tablicy wskaźników
    return 0;
}