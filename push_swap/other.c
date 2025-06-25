/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:18:29 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/25 17:03:15 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_spot(t_stack *curr, t_stack *head, int value)
{
	int	curr_val;
	int	next_val;

	curr_val = curr->nb;
	if (curr->next)
		next_val = curr->next->nb;
	else
		next_val = head->nb;
	if ((curr_val < value && value < next_val)
		|| (curr_val > next_val && (value > curr_val || value < next_val)))
		return (1);
	return (0);
}

int	get_insert_position(t_stack *stack_a, int value)
{
	t_stack	*curr;
	int		curr_index;
	int		size;

	if (!stack_a)
		return (0);
	curr_index = 0;
	curr = stack_a;
	size = count_node(stack_a);
	while (curr)
	{
		if (is_valid_spot(curr, stack_a, value))
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

int	is_valid_input(char *arg, t_stack *head)
{
	if (!is_valid_number(arg) || !is_int_range(arg))
	{
		ft_printf("Error\n");
		free_stack(head);
		return (0);
	}
	return (1);
}

void	rotate_stack_b_to_top(t_stack **stack, int index)
{
	int	size;
	int	i;

	size = count_node(*stack);
	if (index < 0 || index >= size)
		return ;
	if (index <= size / 2)
	{
		i = index;
		while (i > 0)
		{
			rb(stack, 1);
			i--;
		}
	}
	else
	{
		i = size - index;
		while (i > 0)
		{
			rrb(stack, 1);
			i--;
		}
	}
}
