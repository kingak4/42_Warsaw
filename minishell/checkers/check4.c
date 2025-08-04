/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:26:23 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/04 11:00:09 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	wr(char c)
{
	write(2, "minishell: syntax error near unexpected token `", 48);
	write(2, &c, 1);
	write(2, "'\n", 2);
	return (0);
}

int	is_double_redi2(t_pars *read, int i, char first, int j)
{
	while (read->line[i])
	{
		while (ft_isspace(read->line[i]))
			i++;
		if (read->line[i] == '>' || read->line[i] == '<')
		{
			first = read->line[i];
			i++;
			if (read->line[i] == first)
			{
				i++;
				continue ;
			}
			j = i;
			while (ft_isspace(read->line[j]))
				j++;
			if (read->line[j] == first)
				return (wr(first));
		}
		if (read->line[i])
			i++;
	}
	return (1);
}
