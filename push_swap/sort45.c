/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort45.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:37:10 by root              #+#    #+#             */
/*   Updated: 2025/06/21 15:23:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *min;
	int id;
	
	min = *stack_a;
	min = get_min(min);
	id = get_index(*stack_a, min);
	if (id == 1)
		ra(stack_a, 1);
	else if (id == 2)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (id == 3)
		rra(stack_a, 1);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}
void	sort_1(t_stack **stack_a)
{
	int i;
	
	i = count_node(*stack_a);
	if (i == 1)
	{
		ft_printf("\n");
		free_stack(*stack_a);
		exit(0);
	}
}
void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *min;
	int id;

	min = *stack_a;
	min = get_min(min);
	id = get_index(*stack_a, min);
	if (id == 1)
		ra(stack_a, 1);
	else if (id == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (id == 3)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
	}
	else if(id == 4)
		rra(stack_a, 1);
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	
	i = count_node(*stack_a);
	if (i == 1)
		sort_1(stack_a);
	else if (i == 2)
		sort_2(stack_a);
	else if (i == 3)
		sort_3(stack_a);
	else if (i == 4)
		sort_4(stack_a, stack_b);
	else if (i == 5)
		sort_5(stack_a, stack_b);
	
}

int is_sorted(t_stack *stack)
{
	t_stack *curr;
	
	curr = stack;
	while(curr->next != NULL)
	{
		if(curr->nb > curr->next->nb)
			return (0);
		curr = curr->next;
	}
	return (1);
}