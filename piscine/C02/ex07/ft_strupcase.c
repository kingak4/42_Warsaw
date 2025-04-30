/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:08:12 by kikwasni          #+#    #+#             */
/*   Updated: 2024/10/17 09:42:33 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 97) && (str[i] <= 122))
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}
/*
int main()
{
	char	i[] = "abcdefghijkilmnoprstuwyz";
	ft_strupcase(i);
	printf("%s\n", ft_strupcase(i));
	return(0);
}
*/
