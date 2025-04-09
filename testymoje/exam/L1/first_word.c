/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:38:22 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/17 11:44:35 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	first_word(char *s)
{
	int c = 0;

	if (!s[c])
	{
		write(1, "\n",1);
	}
	while (s[c] == 32 || s[c] == 9)
		c++;
	if (s[c] == '\0')
	{
		write(1, "\n",1);
	}
	while (s[c] != 32 && s[c] != 9 && s[c] != '\0')
	{
		write(1, &s[c],1);
		c++;
	}
	write(1, "\n",1);
}
int main(int argc, char *argv[])
{
	if(argc == 1 || argc < 2)
		return(1);
	first_word(argv[1]);
	return(0);
}
