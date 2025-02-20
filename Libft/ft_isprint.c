/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:27:09 by kikwasni          #+#    #+#             */
/*   Updated: 2024/12/18 11:29:23 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}
// int main()
// {
//     char str[] = "ELO320!!";
//     int i = 0;
//     while (str[i] != '\0')
//     {
//         printf("%d ", ft_isprint(str[i]));
//         i++;
//     }
//     return 0;
// }