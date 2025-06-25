/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 22:32:34 by root              #+#    #+#             */
/*   Updated: 2025/06/25 13:22:20 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	a;
	int	b;

	a = rra(stack_a, 0);
	b = rrb(stack_b, 0);
	if (a == 0 || b == 0)
		ft_printf("rrr\n");
}

void	sort_2(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack_a;
	second = first->next;
	if (first->nb > second->nb)
		sa(stack_a, 1);
}

void	sort_3(t_stack **stack_a)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

	a = *stack_a;
	b = a->next;
	c = b->next;
	if (a->nb > b->nb && b->nb < c->nb && a->nb < c->nb)
		sa(stack_a, 1);
	if (a->nb > b->nb && b->nb > c->nb)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (a->nb > b->nb && b->nb < c->nb && a->nb > c->nb)
		ra(stack_a, 1);
	else if (a->nb < b->nb && b->nb > c->nb && a->nb < c->nb)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (a->nb < b->nb && b->nb > c->nb && a->nb > c->nb)
		rra(stack_a, 1);
	else if (a->nb < b->nb && b->nb < c->nb)
		return ;
}

t_stack	*get_min(t_stack *stack_a)
{
	t_stack	*curr;
	t_stack	*min;

	if (!stack_a)
		return (NULL);
	curr = stack_a;
	min = stack_a;
	while (curr != NULL)
	{
		if (curr->nb < min->nb)
			min = curr;
		curr = curr->next;
	}
	return (min);
}

int	get_index(t_stack *stack, t_stack *node)
{
	int		id;
	t_stack	*curr;

	id = 0;
	if (!stack || !node)
		return (-1);
	curr = stack;
	while (curr != NULL)
	{
		if (curr == node)
			return (id);
		curr = curr->next;
		id++;
	}
	return (-1);
}
