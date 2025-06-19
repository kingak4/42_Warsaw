/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:18:37 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/19 09:46:44 by root             ###   ########.fr       */
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
	t_stack *current;
	t_stack *next_node;
	
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