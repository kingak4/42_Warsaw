/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:15:43 by kikwasni          #+#    #+#             */
/*   Updated: 2025/02/03 10:36:25 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int				ft_printf(const char *format, ...);
int				ft_putstr(char *str);
void			ft_putchar(char c);
int				ft_putnbr(int nb);
int				ft_putnbr_unsigned(unsigned int nb);
int				ft_print_upperx(unsigned int nb);
int				ft_printx(unsigned int n);
int				ft_print_pointer(void *p);

#endif