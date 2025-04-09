/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:32:16 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/17 14:48:44 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*rev(char *str)
{
	int a =0;
	int b = 0;
	char wynik;
	
	if (!str)
	{
		write(1,"\n",1);
	}
	while (str[a] != '\0')
		a++;
	a--;
	while(b < a)
	{
		wynik = str[a];
		str[a] = str[b];
		str[b] = wynik;
		b++;
		a--;
	}
	return(str);
}

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    
    rev(av[1]);

    int i = 0;
    while (av[1][i])
    {
        write(1, &av[1][i], 1); 
        i++;
    }
    
    return 0;
}