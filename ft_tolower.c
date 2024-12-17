/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:28:41 by kikwasni          #+#    #+#             */
/*   Updated: 2024/12/17 12:25:12 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
	{
		return (c + 32);
	}
	return (c);
}
/*
int main()
{
	char	c = 'A';
	c = ft_toupper(c);
	printf("%c\n", c);
	return(0);
}
*/