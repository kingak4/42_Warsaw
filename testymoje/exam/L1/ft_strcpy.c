/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:49:29 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/17 14:02:26 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int	c = 0;

	while (s2[c])
	{
		s1[c] = s2[c];
		c++;
	}
	s1[c] = '\0';
	return(s1);
}
//int main ()
//{
//	char s1[5];
//	char s2[4] = "hey";
	
//	ft_strcpy(s1, s2);
//	printf("%s\n", s);
//}