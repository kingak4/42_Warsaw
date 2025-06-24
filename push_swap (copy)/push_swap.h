/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:34:34 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/24 12:28:36 by kikwasni         ###   ########.fr       */
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
t_stack	*make_stack(char *s, int i);
void	free_stack(t_stack *head);
t_stack	*clear_duplicate(t_stack *head);
int		sa(t_stack **stack_a, int flag);
int		sb(t_stack **stack_b, int falg);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
int		ra(t_stack **stack_a, int flag);
int		count_node(t_stack *stack_a);
int		rb(t_stack **stack_b, int flag);
int		rra(t_stack **stack_a, int flag);
int		rrb(t_stack **stack_b, int flag);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	sort_1(t_stack **stack_a);
void	sort_2(t_stack **stack_a);
void	sort_3(t_stack **stack_a);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
t_stack	*get_min(t_stack *stack_a);
t_stack	*get_max(t_stack *stack_a);
int		max_min(int value, t_stack *min, t_stack *max, t_stack *stack_b);
int		get_index(t_stack *stack, t_stack *node);
void	sort(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack *stack);
int		cost_to_top(t_stack *stack, int index);
int		get_insert_position(t_stack *stack_a, int value);
int		total_cost(t_stack *stack_a, t_stack *stack_b, int index_b);
t_stack	*get_node_at_index(t_stack *stack, int index);
int		find_cheapest_index(t_stack *stack_a, t_stack *stack_b);
void	rotate_stack_to_top(t_stack **stack, int index);
void	push_cheapest(t_stack **stack_a, t_stack **stack_b);
void	push_back_to_a(t_stack **stack_a, t_stack **stack_b);
void	final_rotate(t_stack **stack_a);
void	turk_sort(t_stack **stack_a, t_stack **stack_b);
void	print_stack(t_stack *head);
int		find_best_pa_index(t_stack *stack_a, t_stack *stack_b);
int		is_valid_input(char *arg, t_stack *head);
#endif
