/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:44:44 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/17 13:50:12 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	unsigned int	c;

	c = 0;
	while (str[c] != '\0')
	{
		write(1, &str[c],1);
		c++;
	}
}
//int main()
//{
//	char str[] = "hello0000000000000000000000000000000000";

//	ft_putstr(str);
//}