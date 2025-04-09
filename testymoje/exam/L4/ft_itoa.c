/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:31:24 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/03 17:58:28 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	whats(int n)
{
	int sign = 0;
	if (n > 0)
		sign = 1;
	else if(n == 0)
		sign = 0;
	else 
		sign = -1;
	return(sign);
}
int	counter(int nb)
{
	int len = 0;
	int sign = whats(nb);
	if(sign < 0)
		len += 1;
	if( nb == 0)
		return(1);
	while(nb > 0)
	{
		nb = nb /10 ;
		len++;
	}
	while(nb < 0)
	{
		nb = nb /10 ;
		len++;
	}
	return(len);
}
char	*ft_itoa(int nbr)
{
	char *rest;
	int len = counter(nbr);
	int	sign = whats(nbr);
	
	if(sign < 0)
		nbr = -nbr;
	rest = malloc(len + 1);
	if(!rest)
		return(NULL);
	if(sign < 0)
		rest[0] ='-';
	int i = len - 1;
	while(nbr >= 10)
	{
		rest[i]= (nbr % 10) + 48;
		nbr = nbr / 10;
		i--;
	}
	rest[i] = nbr + 48;
	rest[len] = '\0';
	
	return (rest);

}
int main()
{
	int n = -444;
	printf("%s\n", ft_itoa(n));
}