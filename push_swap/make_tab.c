/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 09:51:44 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/17 11:40:28 by kikwasni         ###   ########.fr       */
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
	return(tab_rest); // zrob linked liste 
}
int	*tab_make(char *s)
{
	char	**tab_rest;
	int		i;
	size_t	len;
	int		*tab;

	len = count_token(s, 32);
	tab_rest = take_split(s);
	if (!tab_rest)
	{
		free_tab(tab_rest);
		return (NULL);
	}
	tab = malloc(len * sizeof(int));
	if (!tab)
		return (0);
	i = 0;
	while (i < (int)len)
	{
		tab[i] = ft_atoi(tab_rest[i]);
		i++;
	}
	free_tab(tab_rest);
	if (!is_duplicate(tab, len))
	{
		free(tab);
		ft_printf("ERROR");
		return (0);
	}
	return (tab);
}
int main()
{
	char *s = "3 5 10 1j";

    if (!s)
    {
        ft_printf("Error: invalid input or memory allocation failed\n");
        return 1;
    }
	int *result;
 	int i = 0;
 	result = tab_make(s);
 	if (result == NULL)
 	{
 		return 1;
 	}
 	while (result[i])
 	{
 		printf("%i\n", result[i]);
 		//free(result[i]);
 		i++;
 	}
 	//free(result);
 	return 0;
}

