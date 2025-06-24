/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:50:08 by root              #+#    #+#             */
/*   Updated: 2025/06/24 09:06:04 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotate(t_stack **stack_a)
{
	t_stack *min;
	int	min_id;
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
	//print_stack(*stack_b);
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
int	find_best_pa_index(t_stack *stack_a, t_stack *stack_b)
{
	int	i = 0;
	int	cheapest = INT_MAX;
	int	best_index = 0;
	int	total;
	int	len;

	len = count_node(stack_b);
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
	return (best_index);
}