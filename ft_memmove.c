/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:27:31 by kikwasni          #+#    #+#             */
/*   Updated: 2024/12/17 12:23:15 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d = (unsigned char	*)dest;
	const unsigned char	*s = (const unsigned char	*)src;
	
	if(d == s || n == 0)
	{
		return(dest);
	}
	if(d < s)
	{
		while(n--)
		{
			*d = *s;
			*d++;
			*s++;
		}
	}
		else
		{
			d += n;
			s += n;
			while(n--)
			{
				*--d = *--s;
			}

		}

	
	return(dest);
}
int mian ()
{
	char	src[] = "abcdefg";
	char	dest[] = "abc";

	ft_memmove(dest, src, 7);
	printf("%s\n", dest);
	return(0);
}