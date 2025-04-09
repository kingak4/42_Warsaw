/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:15:30 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/20 12:01:00 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	int i = 1;
	while (i <= n)
	{
		if (i == n)
			return(1);
		i = i * 2;
	}
	return(0);
}
int main()
{
	unsigned int n = 6;
	int i = 0;
	i = is_power_of_2(n);
	printf("%i\n", i);
	
}