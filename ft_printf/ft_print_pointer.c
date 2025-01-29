/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:29:53 by kikwasni          #+#    #+#             */
/*   Updated: 2025/01/28 12:57:42 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(char *p)
{
	int	count;
	
	count = 0;
	if (!p)
	{
		ft_putstr("NULL");
		return (4);
	}
	ft_putstr("0x");
	count += 2;
	count += ft_printx((uintptr_t)p);
	return (count);
}