/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:50:08 by root              #+#    #+#             */
/*   Updated: 2025/06/24 11:26:26 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotate(t_stack **stack_a)
{
	t_stack	*min;
	int		min_id;

	min = get_min(*stack_a);
	min_id = get_index(*stack_a, min);
	rotate_stack_to_top(stack_a, min_id);
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a) == 1)
		return ;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (count_node(*stack_a) > 3)
		push_cheapest(stack_a, stack_b);
	sort_3(stack_a);
	push_back_to_a(stack_a, stack_b);
	final_rotate(stack_a);
}

int	rrb(t_stack **stack_b, int flag)
{
	int		len;
	t_stack	*first;
	t_stack	*last;
	t_stack	*second_last;

	first = (*stack_b);
	last = (*stack_b);
	len = count_node(last);
	if (len < 2)
		return (0);
	while (last->next)
		last = last->next;
	second_last = last->prev;
	if (second_last)
		second_last->next = NULL;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	*stack_b = last;
	if (flag == 1)
		ft_printf("rra\n");
	return (1);
}

int	get_pa_cost(t_stack *stack_a, t_stack *stack_b, int b_index)
{
	int		cost_b;
	int		insert_pos;
	int		cost_a;
	t_stack	*node_b;

	node_b = get_node_at_index(stack_b, b_index);
	cost_b = cost_to_top(stack_b, b_index);
	insert_pos = get_insert_position(stack_a, node_b->nb);
	cost_a = cost_to_top(stack_a, insert_pos);
	return (cost_a + cost_b);
}

int	find_best_pa_index(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	cheapest;
	int	best_index;
	int	len;
	int	total;

	i = 0;
	cheapest = INT_MAX;
	best_index = 0;
	len = count_node(stack_b);
	while (i < len)
	{
		total = get_pa_cost(stack_a, stack_b, i);
		if (total < cheapest)
		{
			cheapest = total;
			best_index = i;
		}
		i++;
	}
	return (best_index);
}
