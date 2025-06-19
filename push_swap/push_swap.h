/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:34:34 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/19 22:35:39 by root             ###   ########.fr       */
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
t_stack	*clear_duplicate(t_stack *head);
int		sa(t_stack *stack_a, int flag);
int		sb(t_stack *stack_b, int falg);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
int		ra(t_stack **stack_a, int flag);
int		count_node(t_stack *stack_a);
int		rb(t_stack **stack_b, int flag);
int		rra(t_stack **stack_a, int flag);
int		rrb(t_stack **stack_b, int flag);
void	rrr(t_stack **stack_a, t_stack **stack_b);
#endif
