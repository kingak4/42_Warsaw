/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:29:12 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/09 12:51:47 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list tmp;
	
	if((*begin_list == NULL) || begin_list == NULL)
		return ;
	if (cmp(*begin_list -> data),data_ref == 0x0)
	{
		tmp = *begin_list;
		*begin_list = *begin_list -> next;
		free(tmp);
		ft_list_remove_if(begin_list,data_ref,cmp);
	}
	else
		ft_list_remove_if((&(*begin_list) -> next),data_ref,cmp);
}