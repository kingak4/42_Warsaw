/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:34:34 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/18 12:12:18 by root             ###   ########.fr       */
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
int		is_duplicate(t_stack *head);
void	free_tab(char **splited);
char	**take_split(char *s);
t_stack	*make_stack(char *s);
void	free_stack(t_stack *head);
#endif
