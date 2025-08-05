/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:33:20 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/05 13:11:47 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(const char *nptr)
{
	long	result;
	int		sign;
	int		a;

	if (!nptr)
		return (-1);
	sign = 1;
	result = 0;
	a = 0;
	while (nptr[a] && ((nptr[a] == ' ') || (nptr[a] >= 9 && nptr[a] <= 13)))
		a++;
	if (nptr[a] == '+')
		a++;
	else if (nptr[a] == '-')
	{
		sign = -1;
		a++;
	}
	while ((nptr[a] >= '0') && (nptr[a] <= '9'))
	{
		result = result * 10 + nptr[a] - '0';
		a++;
	}
	return (sign * result);
}
//int main()
//{
//	const char *n = "03";
//	printf("%ld\n",ft_atol(n));
//	return(0);
//}