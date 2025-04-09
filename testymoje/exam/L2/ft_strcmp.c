/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:25:28 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/18 16:34:03 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	
	while((s1[i] || s2[i]) && s1[i] == s2[i])
	{
		i++;
	}
	return(s1[i] - s2[i]);
}
//int main()
//{
//	char	s1[] = "he";
//	char	s2[] = "hj";
	
//	int 	i;
//	i = ft_strcmp(s1,s2);
//	printf("%i\n", i);
//	return (0);
//}