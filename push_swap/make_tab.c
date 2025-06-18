/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 09:51:44 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/18 12:52:03 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**take_split(char *s)
{
	char **tab_rest;
	int	i;

	if (!s)
		return (NULL);
	tab_rest = ft_split(s, 32);
	i = 0;
	if (!tab_rest)
		return (NULL) ;
	while (tab_rest[i])
	{
		if (!is_valid_number(tab_rest[i]) ||
			!is_int_range(tab_rest[i]))
			{
				free_tab(tab_rest);
				ft_printf("ERROR\n"); //napraw segfalut
				return (NULL);
			}
		i++; 
	}
	return(tab_rest);
} 
// ogarnij aby dzialo 
// napraw ten makce stack 
// debaguj 
// zrob dal liczb 8 9 7 bez stringa
// napraw segfalut w take split 
// sprawdz valgrind
// zrob aby dzialo  bez stringa 
// norsma 
//  tesy 

t_stack *make_stack(char *s)
{
	char	**tab_rest;
	int		i;
	size_t	len;
	t_stack	*head = NULL;
	t_stack *current = NULL;
	t_stack *new_node;

	len = count_token(s, 32);
	tab_rest = take_split(s);
	if (!tab_rest)
		return (NULL);
	i = 0;
	while (i < (int)len)
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->nb = ft_atoi(tab_rest[i]);
		if (i == 0)
		{
			head = new_node;
			current = head;
			current->prev = NULL;
		}
		else
		{
			current->next = new_node;
			new_node->prev = current;
			current = new_node;
		}
		new_node->next = NULL;
		i++;
	}
	free_tab(tab_rest);
	if (is_duplicate(head) == 0)
	{
		ft_printf("ERROR");
		free_stack(head);
		return (NULL);
	}
	return (head);
}
int main(void)
{
    char *input = "3 5 8"; // <- testuj inne przypadki
    t_stack *stack = make_stack(input);

    if (!stack)
    {
        ft_printf("make_stack failed!\n");
        return (1); // ⛔️ KONIEC – nie wypisuj dalej!
    }

    t_stack *current = stack;
    while (current)
    {
        printf("nb: %d\n", current->nb);
        current = current->next;
    }

    free_stack(stack);
    return (0);
}

