/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:52:18 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/08 13:22:12 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int i = 0;
	while (begin_list ->next)
	{
		begin_list = begin_list -> next;
		i++;
	}
	return(i);
}
//int main()
//{
//    // Tworzymy trzy elementy listy
//    t_list *head = malloc(sizeof(t_list));  // Pierwszy element
//    t_list *second = malloc(sizeof(t_list)); // Drugi element
//    t_list *third = malloc(sizeof(t_list));  // Trzeci element

//    // Przypisujemy dane do każdego elementu
//    int *data1 = malloc(sizeof(int));
//    *data1 = 10;
//    head->data = data1;

//    int *data2 = malloc(sizeof(int));
//    *data2 = 20;
//    second->data = data2;

//    int *data3 = malloc(sizeof(int));
//    *data3 = 30;
//    third->data = data3;

//    // Łączymy elementy w listę
//    head->next = second;
//    second->next = third;
//    third->next = NULL;  // Ostatni element wskazuje na NULL (koniec listy)

//    // Wywołujemy funkcję, aby uzyskać rozmiar listy
//    int size = ft_list_size(head);

//    // Wyświetlamy wynik
//    printf("Rozmiar listy: %d\n", size);

//    // Zwolnienie pamięci
//    free(data1);
//    free(data2);
//    free(data3);
//    free(head);
//    free(second);
//    free(third);

//    return 0;
//}