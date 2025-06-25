/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:45:10 by root              #+#    #+#             */
/*   Updated: 2025/06/24 08:38:17 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack **stack_a, int flag )
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	first = *stack_a;
	second = first->next;
	if (!first || !second)
		return (0);
	tmp = first->nb;
	first->nb = second->nb;
	second->nb = tmp;
	if (flag == 1)
		ft_printf("sa\n");
	return (1);
}

int	sb(t_stack **stack_b, int flag )
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	first = *stack_b;
	second = first->next;
	if (!first || !second)
		return (0);
	tmp = first->nb;
	first->nb = second->nb;
	second->nb = tmp;
	if (flag == 1)
		ft_printf("sb\n");
	return (1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	int	a;
	int	b;

	a = sa(stack_a, 0);
	b = sb(stack_b, 0);
	if (a == 1 || b == 1)
		ft_printf("ss\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*moved_nb;

	if (!*stack_b ||!stack_a || !stack_b)
		return ;
	moved_nb = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	moved_nb->prev = NULL;
	moved_nb->next = (*stack_a);
	if (*stack_a)
		(*stack_a)->prev = moved_nb;
	(*stack_a) = moved_nb;
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*moved_nb;

	if (!stack_b || !(*stack_a) || !stack_a)
		return ;
	moved_nb = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	moved_nb->prev = NULL;
	moved_nb->next = (*stack_b);
	if (*stack_b)
		(*stack_b)->prev = moved_nb;
	(*stack_b) = moved_nb;
	ft_printf("pb\n");
}
