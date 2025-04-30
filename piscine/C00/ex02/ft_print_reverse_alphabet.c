/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:13:55 by kikwasni          #+#    #+#             */
/*   Updated: 2024/10/07 17:42:01 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 123;
	while (--c >= 97)
		write(1, &c, 1);
}
/*
int main (void)
{
	ft_print_reverse_alphabet();
	return(0);
}
*/
