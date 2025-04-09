/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:06:29 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/09 10:33:34 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"
void	fill(char **tab,t_point size,char target, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	if (tab[row][col] == 'F' || tab[row][col] != target)
		return ;
	tab[row][col] = 'F';
	fill(tab,size,target,row+1,col);
	fill(tab,size,target,row-1,col);
	fill(tab,size,target,row,col + 1);
	fill(tab,size,target,row,col -1);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char 	target = tab[begin.y][begin.x];
	fill(tab,size,target,begin.y,begin.x);
}
// #include <stdio.h>
// #include <stdlib.h>

// char	**make_area(char **zone, t_point size)
// {
// 	char	**new;

// 	new = malloc(sizeof(char *) * size.y);
// 	for (int i = 0; i < size.y; ++i)
// 	{
// 		new[i] = malloc(size.x + 1);
// 		for (int j = 0; j < size.x; ++j)
// 			new[i][j] = zone[i][j];
// 		new[i][size.x] = '\0';
// 	}
// 	return (new);
// }

// int	main(void)
// {
// 	t_point	size;
// 	t_point	begin;
// 	char	**area;

// 	size.x = 8;
// 	size.y = 5;
// 	begin.x = 7;
// 	begin.y = 4;
// 	char *zone[] = {
// 		"11111111",
// 		"10001001",
// 		"10010001",
// 		"10110001",
// 		"11100001",
// 	};
// 	area = make_area(zone, size);
// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	printf("\n");
// 	flood_fill(area, size, begin);
// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	return (0);
// }
 
