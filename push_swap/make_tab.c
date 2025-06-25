/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 09:51:44 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/25 17:03:06 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**take_split(char *s)
{
	char	**tab_rest;
	int		i;

	if (!s)
		return (NULL);
	tab_rest = ft_split(s, 32);
	i = 0;
	if (!tab_rest)
		return (NULL);
	while (tab_rest[i])
	{
		if (!is_valid_number(tab_rest[i])
			|| !is_int_range(tab_rest[i]))
		{
			free_tab(tab_rest);
			ft_printf("Error\n");
			return (NULL);
		}
		i++;
	}
	return (tab_rest);
}

void	append_node(t_stack **head, t_stack *new_node)
{
	t_stack	*tmp;

	if (!head || !*head)
	{
		*head = new_node;
		return ;
	}
	tmp = *head;
	while ((*head)->next)
		*head = (*head)->next;
	(*head)->next = new_node;
	new_node->next = NULL;
	new_node->prev = *head;
	*head = tmp;
}

t_stack	*make_stack(char *s, int i)
{
	char	**tab_rest;
	size_t	len;
	t_stack	*head;
	t_stack	*new_node;

	head = NULL;
	len = count_token(s, 32);
	tab_rest = take_split(s);
	if (!tab_rest)
		return (NULL);
	while (i < (int)len)
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->nb = ft_atoi(tab_rest[i]);
		append_node(&head, new_node);
		new_node->next = NULL;
		i++;
	}
	free_tab(tab_rest);
	head = clear_duplicate(head);
	if (!head)
		return (NULL);
	return (head);
}

t_stack	*make_int_arg(int ac, char **av)
{
	t_stack	*head;
	t_stack	*new_node;
	int		i;

	i = 1;
	head = NULL;
	while (i < ac)
	{
		if (!is_valid_input(av[i], head))
			return (NULL);
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->nb = ft_atoi(av[i]);
		append_node(&head, new_node);
		new_node->next = NULL;
		i++;
	}
	head = clear_duplicate(head);
	if (!head)
		return (NULL);
	return (head);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	i = 0;
	if (argc < 2)
		return (0);
	if (argc > 2)
	{
		stack_a = make_int_arg(argc, argv);
		if (!stack_a)
			return (1);
		sort(&stack_a, &stack_b);
	}
	else
	{
		stack_a = make_stack(argv[1], i);
		if (!stack_a)
			return (1);
		sort(&stack_a, &stack_b);
	}
	free_stack(stack_a);
	return (0);
}
