/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 11:38:15 by root              #+#    #+#             */
/*   Updated: 2025/06/23 18:04:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *get_node_at_index(t_stack *stack, int index)
{
	t_stack *curr;
	int i;

	if (!stack)
		return (NULL);
	curr = stack;
	i = 0;
	if (index < 0)
		return (NULL);
	while(i < index)
	{
		curr = curr->next;
		i++;
		if (curr == NULL)
			return (NULL) ;
	}
	return(curr);
}
int	find_cheapest_index(t_stack *stack_a, t_stack *stack_b)
{
	int	node_nb;
	int i;
	int	curr_cost;
	int	cheap_cost;
	int	cheap_id;

	node_nb = count_node(stack_b);
	i = 0;
	cheap_cost = INT_MAX;
	cheap_id = 0;
	while (i < node_nb)
	{
		curr_cost = total_cost(stack_a, stack_b, i);
		if (curr_cost < cheap_cost)
		{
			cheap_cost = curr_cost;
			cheap_id = i;
		}
		i++;
	}
	return (cheap_id);
}
void rotate_stack_to_top(t_stack **stack, int index)
{ 
	int size;
	int i;

	size = count_node(*stack);
	if (index < 0 || index >= size)
        return;
	if (index <= size / 2)
	{
		 i = index;
		while (i > 0)
		{
			ra(stack, 1);
			i--;
		}
	}
	else
	{
		i = size - index;
		while (i > 0)
		{
			rra(stack, 1);
			i--;
		}
	}
}
void	push_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	int	cheap_id;
	t_stack *cheap_node;
	int insert_id;

	cheap_id = find_cheapest_index(*stack_a, *stack_b);
	cheap_node = get_node_at_index(*stack_b, cheap_id);
	insert_id = get_insert_position(*stack_b, cheap_node->nb);
	rotate_stack_to_top(stack_a, cheap_id);
	rotate_stack_to_top(stack_b, insert_id);
	pb(stack_a, stack_b);
}
int find_best_pa_index(t_stack *stack_a, t_stack *stack_b)
{
	int i = 0;
	int cheapest = INT_MAX;
	int best_index = 0;
	int total;

	int len = count_node(stack_b);
	while (i < len)
	{
		int cost_b = cost_to_top(stack_b, i);
		int insert_pos = get_insert_position(stack_a, get_node_at_index(stack_b, i)->nb);
		int cost_a = cost_to_top(stack_a, insert_pos);
		total = cost_b + cost_a;

		if (total < cheapest)
		{
			cheapest = total;
			best_index = i;
		}
		i++;
	}
	return best_index;
}
void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
    int best_id;
    int best_in;
    int val;

    while (*stack_b != NULL)
    {
        best_id = find_best_pa_index(*stack_a, *stack_b);
        if (best_id < 0)
            break;
        rotate_stack_to_top(stack_b, best_id);
        val = (*stack_b)->nb;
        best_in = get_insert_position(*stack_a, val);
        if (best_in >= 0)
            rotate_stack_to_top(stack_a, best_in);
        pa(stack_a, stack_b);
    }
}