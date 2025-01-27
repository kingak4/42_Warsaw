/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:15:43 by kikwasni          #+#    #+#             */
/*   Updated: 2025/01/27 13:17:46 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

int				ft_printf(const char *format, ...);
void			ft_putstr(char *str);
void			ft_putchar(char c);
int				ft_intlen(int nbr);
void			ft_putnbr(int nb);
void			ft_putnbr_unsigned(unsigned int nb);
unsigned int	ft_len_unsigned(unsigned int nb);

#endif