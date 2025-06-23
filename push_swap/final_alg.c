/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:50:08 by root              #+#    #+#             */
/*   Updated: 2025/06/23 18:08:41 by root             ###   ########.fr       */
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