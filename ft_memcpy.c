/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:27:24 by kikwasni          #+#    #+#             */
/*   Updated: 2025/01/03 15:00:41 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if ((!dest) || (!src))
	{
		return (NULL);
	}
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}
//int main()
//{
//	char	src[] = "czesc";
//	char	dest[6];
//	ft_memcpy(dest, src, 6);
//	printf("%s\n", dest);
//	return(0);
//}