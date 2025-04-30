/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:41:46 by kikwasni          #+#    #+#             */
/*   Updated: 2024/10/08 13:29:44 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_numbers(void)
{
	char	c;

	c = 47;
	while (++c < 58)
		write(1, &c, 1);
}
/*
int main(void)
{
	ft_print_numbers();
	return(0);
}
*/
