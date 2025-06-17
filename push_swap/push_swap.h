/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:34:34 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/17 15:48:48 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct stack
{
	struct stack	*next;
	struct stack	*prev;
	int				nb;
}		t_stack;

int		is_valid_number(char *str);
int		is_int_range(char *str);
int		is_duplicate(int *tab, size_t size);
void	free_tab(char **splited);
char	**take_split(char *s);
t_Node	*make_stack(char *s);

#endif
