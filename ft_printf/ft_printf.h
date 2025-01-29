/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:15:43 by kikwasni          #+#    #+#             */
/*   Updated: 2025/01/28 14:25:06 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include "./libft/libft.h"

int				ft_printf(const char *format, ...);
void			ft_putstr(char *str);
void			ft_putchar(char c);
int				ft_intlen(int nbr);
void			ft_putnbr(int nb);
int				ft_putnbr_unsigned(unsigned int nb);
int				ft_print_upperx(int nb);
int				ft_printx(int nb);
int				ft_print_pointer(char *p);

#endif