/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:45:10 by root              #+#    #+#             */
/*   Updated: 2025/06/19 19:17:55 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *stack_a, int flag )
{
	t_stack *first;
	t_stack *second;
	int tmp;

	first = stack_a;
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

int	sb(t_stack *stack_b, int flag )
{
	t_stack *first;
	t_stack *second;
	int tmp;

	first = stack_b;
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
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	a;
	int b;
	a = sa(stack_a, 0);          
	b = sb(stack_b, 0);
	if (a == 1 || b == 1)
		ft_printf("ss\n");
}
void pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *moved_nb;

	if(!*stack_b ||!stack_a || !stack_b)
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
// Sprawdzasz, czy stack_b istnieje i nie jest puste.
// Zabierasz pierwszy element stack_b.
// Przesuwasz stack_b do przodu.
// Jeśli zostały tam elementy, poprawiasz im prev.
// Przygotowujesz przenoszony element (czyści prev, ustawia next).
// Łączysz go z stack_a.
//Ustawiasz go jako nowy head stosu A.

void pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *moved_nb;

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
