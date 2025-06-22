/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:33:04 by root              #+#    #+#             */
/*   Updated: 2025/06/22 12:09:44 by root             ###   ########.fr       */
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
int	get_insert_position(t_stack *stack_b, int value)
{
	t_stack *curr;
	int id;
	t_stack *min;
	t_stack *max;
	int rest;

	if (!stack_b)
		return (-1);
	curr = stack_b;
	min = get_min(stack_b);
	max = get_max(stack_b);
	id = 0;
	while (curr->next != NULL)
	{
		if (curr->nb > value && value > curr->next->nb)
			return (id + 1);
		id++;
		curr = curr->next;
	}
	if (curr->nb > value && value > stack_b->nb)
		return (0);
	rest = max_min(value, min, max , stack_b);
	if (rest == 0)
		return(rest);
	return (0);
}
int	max_min(int value, t_stack *min, t_stack *max, t_stack *stack_b)
{
	int id;

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

t_stack *get_max(t_stack *stack_a)
{
	t_stack	*curr;
	t_stack *max;

	if (!stack_a)
		return (NULL);
	curr = stack_a;
	max = stack_a;
	while (curr != NULL)
	{
		if(curr->nb > max->nb)
			max = curr;
		curr = curr->next;
	}
	return(max);
}
int	total_cost(t_stack *stack_a, t_stack *stack_b, int index_a)
{
	int	cost_a;
	int cost_b;
	int	insert_pos;
	t_stack *node_a;
	
	node_a = get_node_at_index(stack_a, index_a);
	insert_pos = get_insert_position(stack_b, node_a->nb);
	cost_a = cost_to_top(stack_a, index_a);
	cost_b = cost_to_top(stack_b, insert_pos);
	return(cost_a + cost_b);
}
