/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:19:53 by kikwasni          #+#    #+#             */
/*   Updated: 2024/10/18 11:47:29 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((i < n) && (s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i]))
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return ((unsigned char) s1[i] -(unsigned char) s2[i]);
}
/*
int main()
{
	char	s1[] = "kolor";
	char	s2[] = "kolorwy";
	unsigned int	n = 7;
	printf("%d\n", ft_strncmp(s1, s2, n));
	return(0);
}
*/
