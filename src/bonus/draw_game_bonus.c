/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:56:21 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/30 11:12:24 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	draw_floor(t_map *map)
{
	int	column;
	int	row;

	column = 0;
	while (map->map[column])
	{
		row = 0;
		while (map->map[column][row])
		{
			mlx_put_image_to_window(map->mlx, map->mlx_win, map->floor_img,
				row * 56, column * 56);
			row++;
		}
		column++;
	}
}

void	draw_elements(int column, int row, t_map *map)
{
	if (map->map[column][row] == '1')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->walls_img,
			row * 56, column * 56);
	if (map->map[column][row] == 'P')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->player_img,
			row * 56, column * 56);
	if (map->map[column][row] == 'C')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->coins_img,
			row * 56, column * 56);
	if (map->map[column][row] == 'E')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->exit_img,
			row * 56, column * 56);
}

void	draw_map(t_map *map)
{
	int	columns;
	int	row;

	columns = 0;
	draw_floor(map);
	while (map->map[columns])
	{
		row = 0;
		while (map->map[columns][row])
		{
			draw_elements(columns, row, map);
			row++;
		}
		columns++;
	}
}
