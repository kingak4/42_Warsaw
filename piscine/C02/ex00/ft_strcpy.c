/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:41:29 by kikwasni          #+#    #+#             */
/*   Updated: 2024/10/17 09:03:15 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	k;

	k = 0;
	while (src [k])
	{
		dest[k] = src[k];
		k++;
	}
	dest[k] = '\0';
	return (dest);
}
/*
int main()
{
	char src[]  = "hi";
	char dest[10];
	ft_strcpy(dest, src);
	printf("%s\n", dest);
	return(0);
}
*/
