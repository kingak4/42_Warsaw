/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:35:40 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/09 18:57:35 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_int_tab(int *tab,unsigned int size)
{
	unsigned int i = 0;
	unsigned int j;
	int temp;

	if (size < 2)
		return ;
	while( i < size - 1 )
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j +1])
			{
				temp = tab[j];
				tab[j] = tab[j +1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	
}