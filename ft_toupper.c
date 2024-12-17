/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:28:47 by kikwasni          #+#    #+#             */
/*   Updated: 2024/12/17 12:25:19 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
	{
		return (c - 32);
	}
	return (c);
}
/*
int main()
{
	char	c = 'a';
	c = ft_toupper(c);
	printf("%c\n", c);
	return(0);
}
*/