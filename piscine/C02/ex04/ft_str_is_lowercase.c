/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:55:35 by kikwasni          #+#    #+#             */
/*   Updated: 2024/10/15 15:15:36 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	g;

	g = 0;
	while (str[g])
	{
		if (str[g] >= 97 && str[g] <= 122)
		{
			g++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
/*
int main()
{
	char	g[] = "abbbbb";
	ft_str_is_lowercase(g);
	printf("%d\n", ft_str_is_lowercase(g));
	return(0);
}
*/
