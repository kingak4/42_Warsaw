/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:55:15 by kikwasni          #+#    #+#             */
/*   Updated: 2025/08/04 11:48:09 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	final(t_pars *read)
{
	t_pars	*curr;

	curr = read;
	while (curr)
	{
		pars_here_doc(curr);
		pars_files(curr);
		is_redi(curr);
		if (!flag_pars(curr, 0) || !dolar_pars(curr))
			return (0);
		curr = curr->next;
	}
	return (1);
}
