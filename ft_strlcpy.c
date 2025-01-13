/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:28:16 by kikwasni          #+#    #+#             */
/*   Updated: 2024/12/18 11:21:47 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	len;

	len = 0;
	while (*(src + len) && (--size))
	{
		*dest++ = *(src + len++);
	}
	*dest = '\0';
	while (*(src + len))
	{
		++len;
	}
	return (len);
}

int main()
{
	unsigned int	len;
	const char	src[] = "hej, jak się masz?";
	char	dest[4];

	len = ft_strlcpy(dest, src, sizeof(dest));
	printf("%u\n", len);
	printf("%s\n", dest);
	return(0);
}
