/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:19:11 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/20 14:32:13 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	int	len = 0;
	int i = 0;
	char *new_str;
	while (src[len])
	{
		len++;
	}
	new_str = malloc(len + 1);
	if (!new_str)
		return(NULL);
	while (src[i])
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return(new_str);
}

//int main ()
//{
//	char	src[] = "kinga";
//	char	*rest;

//	rest = ft_strdup(src);
//	printf("%s\n", rest);
//}
