/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_train.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:34:30 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/09 11:12:54 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	whats(int nb)
{
	int sign = 1;
	if( nb < 0 )
		sign = -1;
	else if(nb == 0)
		sign = 0;
	return(sign);
}
int	ft_len(int nb)
{
	int len = 0;
	int sign = whats(nb);
	if(nb == 0)
		len +=1;
	if(sign < 0)
		len +=1;
	while (nb > 0)
	{
		nb = nb /10;
		len++;
	}
	while (nb < 0)
	{
		nb = nb /10;
		len++;
		
	}
	return(len);
}
char	*ft_itoa(int nbr)
{
	int sign = whats(nbr);
	int	len = ft_len(nbr);
	char *rest;
	int i = len - 1;

	if(sign < 0)
		nbr = -nbr;
	rest = malloc(len + 1);
	if (!rest)
		return(NULL);
	if(sign < 0 )
		rest[0] = '-';
	while (nbr >= 10 )
	{
		rest[i] = (nbr % 10) + 48;
		nbr = nbr / 10;
		i--;
	}
	rest[i] = nbr + 48;
	rest[len] = '\0';
	return(rest);
}
int main()
{
	int nb = -112;
	printf("%s\n", ft_itoa(nb));
}