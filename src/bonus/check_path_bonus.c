/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:39 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/02 10:42:48 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	check_path(t_map *map)
{
	if (map->coins_copy > 0 || map->coins_copy_2 > 0)
		ft_error(9, map);
}

void	flood_fill_from_player(t_map *map, int column, int row)
{	
	if (map->map_copy[column][row] != '1'
		&& map->map_copy_2[column][row] != 'X')
	{		
		if (map->map_copy[column][row] == 'C')
			map->coins_copy--;
		map->map_copy[column][row] = '1';
		if (map->map_copy[column][row + 1] != '1'
			&& map->map_copy[column][row + 1] != 'E')
			flood_fill_from_player(map, column, row + 1);
		if (map->map_copy[column][row - 1] != '1'
			&& map->map_copy[column][row - 1] != 'E')
			flood_fill_from_player(map, column, row - 1);
		if (map->map_copy[column + 1][row] != '1'
			&& map->map_copy[column + 1][row] != 'E')
			flood_fill_from_player(map, column + 1, row);
		if (map->map_copy[column - 1][row] != '1'
			&& map->map_copy[column - 1][row] != 'E')
			flood_fill_from_player(map, column - 1, row);
	}
}

void	flood_fill_from_exit(t_map *map, int column, int row)
{
	if (map->map_copy_2[column][row] != '1'
		&& map->map_copy_2[column][row] != 'X')
	{
		if (map->map_copy_2[column][row] == 'C')
			map->coins_copy_2--;
		map->map_copy_2[column][row] = '1';
		if (map->map_copy_2[column][row + 1] != '1')
			flood_fill_from_exit(map, column, row + 1);
		if (map->map_copy_2[column][row - 1] != '1')
			flood_fill_from_exit(map, column, row - 1);
		if (map->map_copy_2[column + 1][row] != '1')
			flood_fill_from_exit(map, column + 1, row);
		if (map->map_copy_2[column - 1][row] != '1')
			flood_fill_from_exit(map, column - 1, row);
	}	
}
