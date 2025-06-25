/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:02:39 by root              #+#    #+#             */
/*   Updated: 2025/06/24 11:29:16 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **stack_a, int flag)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	first = (*stack_a);
	last = (*stack_a);
	while (last->next)
		last = last->next;
	*stack_a = first->next;
	(*stack_a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (flag == 1)
		ft_printf("ra\n");
	return (1);
}

int	rb(t_stack **stack_b, int flag)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return (0);
	first = *stack_b;
	last = *stack_b;
	while (last->next)
		last = last->next;
	*stack_b = first->next;
	(*stack_b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (flag == 1)
		ft_printf("rb\n");
	return (1);
}

int	count_node(t_stack *stack_a)
{
	t_stack	*data;
	int		i;

	i = 0;
	data = stack_a;
	while (data != NULL)
	{
		data = data->next;
		i++;
	}
	return (i);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	int	a;
	int	b;

	a = ra(stack_a, 0);
	b = rb(stack_b, 0);
	if (a == 0 || b == 0)
		ft_printf("rr\n");
}

int	rra(t_stack **stack_a, int flag)
{
	int		len;
	t_stack	*first;
	t_stack	*last;
	t_stack	*second_last;

	first = (*stack_a);
	last = (*stack_a);
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
	*stack_a = last;
	if (flag == 1)
		ft_printf("rra\n");
	return (1);
}
