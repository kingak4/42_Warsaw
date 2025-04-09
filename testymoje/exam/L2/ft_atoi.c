/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:00:15 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/20 10:59:40 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int  i = 0;
	int r = 0;
	int sg = 1;
	
	if (!str[i])
		return(-1);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' && str[i] != '-')
		i++;
	if (str[i] == '-')
	{
		sg = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	return (r * sg);
}
int main()
{ 
	const char str[] = "-123456789";
	int i = 0;

	i = ft_atoi(str);
	printf("%i\n", i);
}