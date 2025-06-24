/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:33:04 by root              #+#    #+#             */
/*   Updated: 2025/06/24 09:17:30 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_to_top(t_stack *stack, int index)
{
	int	size;

	size = count_node(stack);
	if (index <= size / 2)
		return (index);
	if (index > size / 2)
		return (size - index);
	return (0);
}

int	get_insert_position(t_stack *stack_a, int value)
{
	t_stack	*curr;
	int		curr_index;
	int		size;
	int		curr_val;
	int		next_val;

	if (!stack_a)
		return (0);
	curr = stack_a;
	curr_index = 0;
	size = count_node(stack_a);
	while (curr)
	{
		curr_val = curr->nb;
		if (curr->next)
			next_val = curr->next->nb;
		else
			next_val = stack_a->nb;
		if ((curr_val < value && value < next_val)
			|| (curr_val > next_val
				&& (value > curr_val || value < next_val)))
		{
			if (curr_index + 1 >= size)
				return (0);
			else
				return (curr_index + 1);
		}
		curr = curr->next;
		curr_index++;
	}
	return (0);
}

int	max_min(int value, t_stack *min, t_stack *max, t_stack *stack_b)
{
	int	id;

	id = 0;
	if (value > max->nb)
	{
		id = get_index(stack_b, max);
		return (id);
	}
	if (value < min->nb)
	{
		id = get_index(stack_b, min);
		return (id);
	}
	return (0);
}

t_stack	*get_max(t_stack *stack_a)
{
	t_stack	*curr;
	t_stack	*max;

	if (!stack_a)
		return (NULL);
	curr = stack_a;
	max = stack_a;
	while (curr != NULL)
	{
		if (curr->nb > max->nb)
			max = curr;
		curr = curr->next;
	}
	return (max);
}

int	total_cost(t_stack *stack_a, t_stack *stack_b, int index_b)
{
	int		cost_a;
	int		cost_b;
	int		insert_pos;
	t_stack	*node_b;

	node_b = get_node_at_index(stack_b, index_b);
	insert_pos = get_insert_position(stack_a, node_b->nb);
	cost_a = cost_to_top(stack_a, insert_pos);
	cost_b = cost_to_top(stack_b, index_b);
	return (cost_a + cost_b);
}
int	should_insert_here(int curr_val, int next_val, int value)
{
	if ((curr_val < value && value < next_val)
		|| (curr_val > next_val
			&& (value > curr_val || value < next_val)))
		return (1);
	return (0);
}
