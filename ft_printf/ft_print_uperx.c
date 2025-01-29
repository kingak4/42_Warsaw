/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uperx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:29:15 by kikwasni          #+#    #+#             */
/*   Updated: 2025/01/28 13:50:21 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_upperx(int nb)
{
	const char	*tmp;
	int			count;
	
	count = 0;
	tmp = "0123456789ABCDEF";
	if (nb == 0)
		return (1);
	count = ft_printx(nb / 16);
	write(1, &tmp[nb % 16], 1);
	count++;
	return (count);
}

//int main()
//{
//	int	nb = 1;
//	ft_printX(nb);
//	return(0);
//}
//write(1, &tmp[7 % 16], 1);
//i wtedy mamy tmp[7]