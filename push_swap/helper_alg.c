/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 11:38:15 by root              #+#    #+#             */
/*   Updated: 2025/06/22 13:41:28 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *get_node_at_index(t_stack *stack, int index)
{
	t_stack *curr;
	int i;

	if (!stack)
		return (NULL);
	curr = stack;
	i = 0;
	if (index < 0)
		return (NULL);
	while(i < index)
	{
		curr = curr->next;
		i++;
		if (curr == NULL)
			return (NULL) ;
	}
	return(curr);
}
int find_cheapest_index(t_stack *stack_a, t_stack *stack_b)
{
	int	node_nb;
	int i;
	int	curr_cost;
	int	cheap_cost;
	int	cheap_id;

	node_nb = count_node(stack_a);
	i = 0;
	cheap_cost = INT_MAX;
	cheap_id = 0;
	while (i < node_nb)
	{
		curr_cost = total_cost(stack_a, stack_b, i);
		if (curr_cost < cheap_cost)
		{
			cheap_cost = curr_cost;
			cheap_id = i;
		}
		i++;
	}
	return (cheap_id);
}
void rotate_stack_to_top(t_stack **stack, int index)
{ 
	int size;
	int i;

	size = count_node(*stack);
	if (index <= size / 2)
	{
		 i = index;
		while (i > 0)
		{
			ra(stack, 1);
			i--;
		}
	}
	if (index > size / 2)
	{
		i = size - index;
		while (i > 0)
		{
			rra(stack, 1);
			i--;
		}
	}
}
void	push_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	int	cheap_id;
	t_stack *cheap_node;
	int insert_id;

	cheap_id = find_cheapest_index(*stack_a, *stack_b);
	cheap_node = get_node_at_index(*stack_a, cheap_id);
	insert_id = get_insert_position(*stack_b, cheap_node->nb);
	rotate_stack_to_top(stack_a, cheap_id);
	rotate_stack_to_top(stack_b, insert_id);
	pb(stack_a, stack_b);
}
// 5. void push_back_to_a(t_stack **a, t_stack **b)
// Cel: przenosi wszystkie elementy z B z powrotem do A w odpowiedniej kolejności.

// Kroki:
// Dla każdego elementu w B:

// znajdź miejsce w A, gdzie powinien trafić (get_insert_position() analogiczna)

// obróć B (żeby ten element był na topie)

// obróć A (żeby zrobić miejsce)

// pa()

// 🕒 Implementacja: ~1h

// 6. void final_rotate(t_stack **a)
// Cel: obraca A tak, żeby minimalna wartość była na górze (czyli pełny sort).

// Kroki:
// Znajdź index minimalnej liczby w A

// Jeśli index <= size / 2 → ra x razy

// Inaczej → rra x razy

// 🕒 Implementacja: ~30 minut

// 7. void turk_sort(t_stack **a, t_stack **b)
// Cel: Główna funkcja sterująca algorytmem Turka.

// Kroki:
// Jeśli is_sorted(*a) → return

// pb(); pb(); (na początek)

// Dopóki count_node(*a) > 3 → push_cheapest()

// sort_3() dla pozostałych w A

// push_back_to_a()

// final_rotate()