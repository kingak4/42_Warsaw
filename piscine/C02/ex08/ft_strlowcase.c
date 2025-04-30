/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:47:33 by kikwasni          #+#    #+#             */
/*   Updated: 2024/10/17 10:05:00 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 65) && (str[i] <= 90))
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}
/*
int main()
{
	char	i[] = "ABCDEFGHIJKLNMOPRSTUWYZ";
	ft_strlowcase(i);
	printf("%s\n", ft_strlowcase(i));
	return(0);
}
*/
