/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:59:39 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/10 15:12:49 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_checker(char **map)
{
	int	palyer;
	int	exit;
	int	x;
	int	y;

	palyer = 0;
	exit = 0;
	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if(map[y][x] == 'P')
				palyer++;
			if(map[y][x] == 'E')
				exit++;
			x++;
		}
		y++;
	}
	if (palyer == 1 && exit == 1)
		return(1);
	return(0);
}
int	coin_check(char **map)
{
	int	x;
	int	y;
	int	colect;
	y = 0;
	colect = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if(map[y][x] == 'C')
				colect++;
			x++;
		}
		y++;
	}
	if (colect >= 1)
		return(1);
	return(0);
}
int	 wall_check(char **map)
{
	int	x;
	int	y;
	int	last;
	int	lastx;

	y = 0;
	last = 0;
	while (map[y])
		y++;
	last = y;
	y = 0;
	lastx = 0;
	lastx = ft_strlen(map[y]);
	if (map[y][lastx - 1] == '\n')
		lastx--;
	x = 0;
	while (map[0][x] != '\n')
	{
		if(map[0][x] != '1')
		{
				ft_printf("Error: top row at index %d is '%c'\n", x, map[0][x]);
				return(0);
		}
		x++;
	}
	x = 0;
	while (map[last -1 ][x])
	{
		if(map[last -1 ][x] != '1')
		{
			ft_printf("Error: bottom row at index %d is '%c'\n", x, map[last - 1][x]);
			return(0);
		}
		x++;
	}
	printf("%d\n", lastx);		
	printf("%d\n", last);
	while (map[y])
	{
		x = 0;
		if(map[y][0] != '1')
			return(0);
		if (map[y][lastx -1] != '1')
		{
			ft_printf("Error: last column at line %d (char: '%c')\n", y, map[y][lastx - 1]);
			return(0);
		}
		y++;
	}
	return(1);
}
void	filler(char **map,t_point size,int y, int x)
{
	if(y < 0 || x < 0 || y >= size.y || x >= size.x)
		return ;
	if(map[y][x] == 'D'  || map[y][x] == '1')
		return ;
	if(map[y][x] != '0' && map[y][x] != 'C' && map[y][x] != 'E' && map[y][x] != 'P')
		return ;
	map[y][x] = 'D';
	filler(map, size, y + 1, x);
	filler(map, size, y - 1, x);
	filler(map, size, y, x + 1);
	filler(map, size, y, x - 1);
}
void flood_fill(char **map, t_point size, t_point begin)
{
	filler(map, size, begin.y, begin.x);
}
t_point	map_len(char **map)
{
	int x;
	int y;
	t_point size;

	x = 0;
	y = 0;
	while(map[y] != NULL)
		y++;
	while(map[0][x] != '\0' && map[0][x] != '\n')
			x++;
			
	size.y = y;
	size.x = x;
	
	return(size);
}
void print_map(char **map)
{
	int y = 0;
	while (map[y])
	{
		ft_printf("%s", map[y]);
		y++;
	}
}
int	way_check(char **map)
{
	int y;
	int x;
	t_point size;
	t_point begin;
	int flag = 0;
	
	x = 0;
	y = 0;
	size = map_len(map);
	while (map[y])
	{
		if(!flag)
		{
			x = 0;
			while(map[y][x] != '\0')
			{
				if(map[y][x] == 'P')
				{
					begin.x = x;
					begin.y = y;
					flag = 1;
					
				}
				x++;
			}
			y++;
		}
		else
			break;
	
	}
	flood_fill(map, size, begin);
	print_map(map);
	begin.y = 0;
	while(map[begin.y])
	{
		begin.x = 0;
		while(map[begin.y][begin.x] != '\0' && map[begin.y][begin.x] != '\n')
		{
			if(map[begin.y][begin.x] == 'E'|| map[begin.y][begin.x] == 'C' ||map[begin.y][begin.x] == '0' )
				return(0);
			begin.x++;	
		}
		begin.y++;
	}
	if(map_checker(map))	
		return(0);
	return(1);
}
int	find_palyer(char **map,t_so_long *game)
{
	int x;
	int y;

	y = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if(map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return(1);
			}
			x++;
		}
		y++;
	}
	return(0);
}
int	final_check(char **map)
{
	if(map_checker(map) == 0)
	{
		ft_printf("Error: Incorrect number of arguments.");
		exit(1);
		return(0);
	}
	if(coin_check(map) == 0)
	{
		ft_printf("Error: No collectibles on the map.");
		exit(1);
		return(0);
	}
	if(wall_check(map) == 0)
	{
		ft_printf("Error: Map not fully surrounded by walls.");
		exit(1);
		return(0);
	}
	if(way_check(map) == 0)
	{
		ft_printf("Error: No valid path to exit or all collectibles.");
		exit(1);
		return(0);
	}
	return(1);
}
//int main()
//{
//	int w = 0, s = 0;
//    char **map = readmap(&w, &s);
//	int d = 0;
//	d = way_check(map);
//	ft_printf("%d\n", d);
//}
//int main()
//{
//    int w = 0, s = 0;
//	int d = 0;
//    char **map = readmap(&w, &s);
//    if (!map)
//    {
//        ft_printf("Error: map loading failed\n");
//        return 1;
//    }
//	d = way_check(map);
//	ft_printf("\n%d\n", d);
//}
//gcc -no-pie map_check.c start.c libft.a libmlx.a -lXext -lX11 -lm -lz -o so_long 
//./so_long tak odpalasz 
// zrob jesli nie znajdzie drogi do E to wtedy wywala 0 czyli przeszukaj mape jesli jest e wywal ) 
