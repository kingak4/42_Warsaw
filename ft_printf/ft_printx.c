/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:29:00 by kikwasni          #+#    #+#             */
/*   Updated: 2025/01/28 13:02:06 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printx(int nb)
{
	const char	*tmp;
	int			count;

	count = 0;
	tmp = "0123456789abcdef";
	if (nb == 0)
		return (1);
	count = ft_printx(nb / 16);
	write(1, &tmp[nb % 16], 1);
	count++;
	return(count);
}

//int main()
//{
//	int	nb = 12848234;

//	ft_printx(nb);
//	return(0);
//}