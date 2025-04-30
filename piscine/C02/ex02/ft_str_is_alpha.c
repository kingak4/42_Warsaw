/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:34:59 by kikwasni          #+#    #+#             */
/*   Updated: 2024/10/16 11:05:58 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (((str[i] >= 65) && (str[i] <= 90))
			|| ((str[i] >= 97) && (str[i] <= 122)))
		{
			i++;
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
	char	g[] = "aABcBc";
	ft_str_is_alpha(g);
	printf("%d\n", ft_str_is_alpha(g));
	return(0);
}
*/
