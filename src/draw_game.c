/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:56:21 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/25 13:47:58 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_floor(t_map *map, t_img *images)
{
	int	column;
	int	row;

	column = 0;
	while (map->map[column])
	{
		row = 0;
		while (map->map[column][row])
		{
			mlx_put_image_to_window(map->mlx, map->mlx_win, images->floor_img,
				row * 45, column * 45);
			row++;
		}
		column++;
	}
}

void	draw_elements(int column, int row, t_map *map, t_img *images)
{
	if (map->map[column][row] == '1')
		mlx_put_image_to_window(map->mlx, map->mlx_win, images->walls_img,
			row * 45, column * 45);
	if (map->map[column][row] == 'P')
		mlx_put_image_to_window(map->mlx, map->mlx_win, images->player_img,
			row * 45, column * 45);
	if (map->map[column][row] == 'C')
		mlx_put_image_to_window(map->mlx, map->mlx_win, images->coins_img,
			row * 45, column * 45);
	if (map->map[column][row] == 'E')
		mlx_put_image_to_window(map->mlx, map->mlx_win, images->exit_img,
			row * 45, column * 45);
}

void	draw_map(t_map *map, t_img *images)
{
	int	columns;
	int	row;

	columns = 0;
	draw_floor(map, images);
	while (map->map[columns])
	{
		row = 0;
		while (map->map[columns][row])
		{
			draw_elements(columns, row, map, images);
			row++;
		}
		columns++;
	}
}
