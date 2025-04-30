/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:21:32 by kikwasni          #+#    #+#             */
/*   Updated: 2024/10/07 17:08:01 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	c;

	c = 96;
	while (++c < 123)
		write(1, &c, 1);
}
/*int main(void)
{
	ft_print_alphabet();
	write(1, "\n", 1);
        return(0);
}
*/
