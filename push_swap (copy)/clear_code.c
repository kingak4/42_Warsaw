/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:18:37 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/24 08:42:03 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **splited)
{
	int	i;

	i = 0;
	while (splited[i] != NULL)
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

void	free_stack(t_stack *head)
{
	t_stack	*current;
	t_stack	*next_node;

	current = head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

t_stack	*clear_duplicate(t_stack *head)
{
	if (is_duplicate(head) == 0)
	{
		ft_printf("ERROR");
		free_stack(head);
		return (NULL);
	}
	return (head);
}
