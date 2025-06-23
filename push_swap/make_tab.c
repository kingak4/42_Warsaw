/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 09:51:44 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/23 18:34:21 by root             ###   ########.fr       */
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
				ft_printf("ERROR\n");
				return (NULL);
			}
		i++; 
	}
	return(tab_rest);
} 

void	append_node(t_stack **head, t_stack **current, t_stack *new_node)
{
	if (!*head)
	{
		*head = new_node;
		*current = new_node;
		new_node->prev = NULL;
	}
	else
	{
		(*current)->next = new_node;
		new_node->prev = *current;
		*current = new_node;
	}
}
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
		append_node(&head, &current, new_node);
		new_node->next = NULL;
		i++;
	}
	free_tab(tab_rest);
	head = clear_duplicate(head);
	return (head);
}
t_stack	*make_int_arg(int ac, char **av)
{
	t_stack *head = NULL;
	t_stack *current;
	t_stack *new_node;
	int i;

	i = 1;
	current = NULL;
	while (i < ac)
	{
		if (!is_valid_number(av[i]) ||
			!is_int_range(av[i]))
			{
				ft_printf("ERROR\n");
				return (NULL);
			}
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->nb = ft_atoi(av[i]);
		append_node(&head, &current, new_node);
		new_node->next = NULL;
		i++;
	}
	head = clear_duplicate(head);
	return (head);
}
void print_stack(t_stack *head)
{
	while (head)
	{
		printf("%d\n", head->nb);
		head = head->next;
	}
}
void appen_node(t_stack **stack, t_stack *new_node)
{
    if (!*stack)
        *stack = new_node;
    else
    {
        t_stack *tmp = *stack;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_node;
        new_node->prev = tmp;
    }
}
t_stack *new_node(int nb)
{
    t_stack *node = malloc(sizeof(t_stack));
    if (!node) return NULL;
    node->nb = nb;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b = NULL;

	stack_a = make_int_arg(argc, argv);
	if (!stack_a)
		return (1);
	turk_sort(&stack_a, &stack_b);
	//sort_2(&stack_a);
  	print_stack(stack_a);
	// printf("\n");
    // print_stack(stack_b);
	free_stack(stack_a);
	// free_stack(stack_b);
	return (0);
}
// int main(void)
// {
//     char *input = "3 5 8 12 -9 -21637"; // <- testuj inne przypadki
//     t_stack *stack = make_stack(input);

//     if (!stack)
//     {
//         ft_printf("make_stack failed!\n");
//         return (1); // ⛔️ KONIEC – nie wypisuj dalej!
//     }

//     t_stack *current = stack;
//     while (current)
//     {
//         printf("nb: %d\n", current->nb);
//         current = current->next;
//     }

//     free_stack(stack);
//     return (0);
// }
// int main(void)
// {
//     t_stack *stack_a = NULL;
//     t_stack *stack_b = NULL;
//     int insert_pos, cost;
//     int total;
    
//     // Tworzymy stos B: [6] -> [4] -> [2]
//     appen_node(&stack_b, new_node(6));
//     appen_node(&stack_b, new_node(4));
//     appen_node(&stack_b, new_node(5));

//     // Tworzymy stos A: [3] -> [5] -> [7] (przykładowo)
//     appen_node(&stack_a, new_node(3));
//     appen_node(&stack_a, new_node(2));
//     appen_node(&stack_a, new_node(1));

//     printf("Stos B:\n");
//     print_stack(stack_b);

//     printf("Stos A:\n");
//     print_stack(stack_a);

//     // TEST: get_insert_position
//     printf("\nTest get_insert_position:\n");
//     int test_values[] = {7, 5, 3, 1};
//     for (int i = 0; i < 4; i++)
//     {
//         insert_pos = get_insert_position(stack_b, test_values[i]);
//         printf("value = %d → insert_pos = %d\n", test_values[i], insert_pos);
//     }

//     // TEST: cost_to_top
//     printf("\nTest cost_to_top (stos B):\n");
//     int size_b = count_node(stack_b);
//     for (int i = 0; i < size_b; i++)
//     {
//         cost = cost_to_top(stack_b, i);
//         printf("index = %d → cost = %d\n", i, cost);
//     }

//     // TEST: total_cost (dla każdego elementu w A)
//     printf("\nTest total_cost (dla stosu A):\n");
//     int size_a = count_node(stack_a);
//     for (int i = 0; i < size_a; i++)
//     {
//         total = total_cost(stack_a, stack_b, i);
//         printf("index_a = %d → total_cost = %d\n", i, total);
//     }
// 	printf("\nTest push_cheapest:\n");
//     push_cheapest(&stack_a, &stack_b);

//     printf("Po push_cheapest:\n");

//     printf("Stos A:\n");
//     print_stack(stack_a);

//     printf("Stos B:\n");
//     print_stack(stack_b);

// 	printf("\nTest push_back:\n");
//     push_back_to_a(&stack_a, &stack_b);

//     printf("Po push_back:\n");

//      print_stack(stack_a);

//     printf("Stos B:\n");
//     print_stack(stack_b);

// 	printf("\nTest final rot:\n");
//     final_rotate(&stack_a);

//     printf("Po final rot:\n");

//      print_stack(stack_a);

//     printf("Stos B:\n");
//     print_stack(stack_b);
//     // Sprzątanie
//     free_stack(stack_a);
//     free_stack(stack_b);
// 	 printf("Stos A:\n");
//     return (0);
// }

  
// int main(void)
// {
//     t_stack *stack_a = NULL;
//     t_stack *stack_b = NULL;

//     // Ręczne tworzenie stosów (zakładam, że masz funkcję make_stack albo inną do tworzenia węzłów)
//     // Jeśli masz tylko make_stack z stringiem, możesz przygotować stringi i wywołać ją

//     // Tworzymy stos B (6 4 2) - załóżmy, że masz funkcję make_stack z łańcuchem "6 4 2"
//     stack_b = make_stack("6 4 2");
//     // Tworzymy stos A (3 5 7)
//     stack_a = make_stack("3 5 7");

//     printf("Start:\nStos A:\n");
//     print_stack(stack_a);

//     printf("Stos B:\n");
//     print_stack(stack_b);

//     // Test push_cheapest - przenosi z A do B najtańszy element
//     push_cheapest(&stack_a, &stack_b);

//     printf("\nPo push_cheapest:\nStos A:\n");
//     print_stack(stack_a);

//     printf("Stos B:\n");
//     print_stack(stack_b);

//     // Test push_back_to_a - przenosi wszystko z B do A
//     push_back_to_a(&stack_a, &stack_b);

//     // Teraz rotujemy stos A tak, żeby minimalny element był na górze:
//     t_stack *min_node = get_min(stack_a);
//     int min_idx = get_index(stack_a, min_node);
//     rotate_stack_to_top(&stack_a, min_idx);

//     printf("\nPo push_back i rotacji min elementu:\nStos A:\n");
//     print_stack(stack_a);

//     printf("Stos B:\n");
//     print_stack(stack_b);

//     free_stack(stack_a);
//     free_stack(stack_b);

//     return 0;
