/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:43:01 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/31 12:01:35 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_atoi_base(const char *s, int str_base)
{
	int	i = 0;
	int	sign = 1;
	int	rest = 0;
	if (!s)
		return(0);
	if(str_base < 2 || str_base > 16)
		return(0);
	while (s[i] == 32)
		i++;
	if (s[i] == '+')
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i])
	{
		char c = s[i];
		int val = 0;
		if (c >= '0' && c <= '9')
			val = c - 48;
		else if (c >= 'a' && c <= 'f')
			val = c -'a' + 10;
		else if (c >= 'A' && c <= 'F')
			val = c -'A' + 10;
		else
			break ;
		rest = rest * str_base + val;
		i++;
	}
	return(rest * sign);
}
int main()
{
	const char str[] = "1f";
	int str_base = 2;
	
	printf("%d\n", ft_atoi_base(str, str_base));
}