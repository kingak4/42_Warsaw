/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:16:25 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/18 09:58:22 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <unistd.h>

int		makenum(char s)
{

	if (s >= 'a' && s <= 'z')
		return(s - 'a' + 1);
	if (s >= 'A' && s <= 'A')
		return(s- 'Z' + 1);
	return(0);
	
}
void 	repeat_a(char *str)
{
	int	i = 0;
	int r = 0;
	while (str[i])
	{
		r = makenum(str[i]);
		while(r--)
		{
			write(1,&str[i],1);
			
		}
		i++;
	}
	write(1,"\n",1);
}
int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		repeat_a(argv[1]);
	}
	else
	{
		write(1,"\n",1);
	}
	return (0);
}
