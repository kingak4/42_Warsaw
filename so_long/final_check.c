/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:28:42 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/13 15:23:39 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	other_check(t_so_long *game)
{
	if (sign_checker(game) == 0)
	{
		clean_exit(game);
		return (0);
	}
	if (coin_check(game) == 0)
	{
		ft_printf("Error: No collectibles on the map.\nclear");
		clean_exit(game);
		return (0);
	}
	if (check_top_bottom_wall(game) == 0)
	{
		ft_printf("Error: Top or bottom row is not euqal \n");
		clean_exit(game);
		return (0);
	}
	if (wall_check(game) == 0)
	{
		ft_printf("Error: Map not fully surrounded by walls.\n");
		clean_exit(game);
		return (0);
	}
	return (1);
}

int	final_check(t_so_long *game, t_point *begin)
{
	if (map_checker(game) == 0 || find_palyer(game, begin) == 0)
	{
		ft_printf("Error: Incorrect number of arguments.\n");
		clean_exit(game);
		return (0);
	}
	if (other_check(game) == 0)
		return (0);
	if (way_check(game, begin, 0, 0) == 0)
	{
		ft_printf("Error: No valid path to exit or all collectibles.\n");
		clean_exit(game);
		return (0);
	}
	return (1);
}
