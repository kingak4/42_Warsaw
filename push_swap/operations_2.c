/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:02:39 by root              #+#    #+#             */
/*   Updated: 2025/06/19 22:31:17 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **stack_a, int flag)
{
	int len;
	t_stack *first;
	t_stack *last;

	first = (*stack_a);
	last = (*stack_a);
	len = count_node(last);
	if (len < 2)
		return (0);
	(*stack_a) = (*stack_a)->next;
	if (!(*stack_a) || !(*stack_a)->next)
		return (0);
	(*stack_a)->prev = NULL;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (flag == 1)
		ft_printf("ra\n");
	return (1);
}
int	rb(t_stack **stack_b, int flag)
{
	int len;
	t_stack *first;
	t_stack *last;
	
	first = (*stack_b);
	last = (*stack_b);
	len = count_node(last);
	if (len < 2)
		return (0);
	(*stack_b) = (*stack_b)->next;
	if (!(*stack_b) || !(*stack_b)->next)
		return (0);
	(*stack_b)->prev = NULL;
	while(last->next)
		last = last->next;
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
	int i;

	i = 0;
	data = stack_a;
	while(data != NULL)
	{
		data = data->next;
		i++;
	}
	return (i);
}
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	int	a;
	int b;

	a = ra(stack_a, 0);
	b = rb(stack_b, 0);
	if (a == 0 || b == 0)
		ft_printf("rr\n");
}

int	rra(t_stack **stack_a, int flag)
{
	int len;
	t_stack *first;
	t_stack *last;

	first = (*stack_a);
	last = (*stack_a);
	len = count_node(last);
	if (len < 2)
		return (0);
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = first;
	first->prev = last;
	(*stack_a) = last;
	last->prev = NULL;
	if (flag == 1)
		ft_printf("rra\n");
	return (1);
}
int	rrb(t_stack **stack_b, int flag)
{
	int len;
	t_stack *first;
	t_stack *last;

	first = (*stack_b);
	last = (*stack_b);
	len = count_node(last);
	if (len < 2)
		return (0);
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = first;
	first->prev = last;
	(*stack_b) = last;
	last->prev = NULL;
	if (flag == 1)
		ft_printf("rrb\n");
	return (1);
}