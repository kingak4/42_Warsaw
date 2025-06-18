/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:17:47 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/18 12:43:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == 32
			|| str[i] == '+' || str[i] == '-')
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_int_range(char *str)
{
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (0);
	return (1);
}
int	is_duplicate(t_stack *head)
{
	t_stack *one;
	t_stack *two;

	one = head;
	while (one)
	{
		two = one->next; 
		while (two)
		{
			if (one->nb == two->nb)
				return (0);
			two = two->next;
		}
		one = one->next;
	}
	return (1);
}

////int	final_check()

//int main()
//{
//	//int tab[] = {42, 7, 12, 0, 0,};
//	//int size = count_number(tab);
//	char *s = "76 0 -8 57643756234598";

//	//printf("%d\n", is_duplicate(tab, size));
//	printf("%d\n", is_int_range(s));
//	//printf("%d\n", size);
//}
