/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:31:54 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/28 19:13:46 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_variables(t_map *map)
{
	map->coins = 0;
	map->exit = 0;
	map->n_players = 0;
	map->movements = 0;
}
void	assign_exit(int column, int row, t_map *map)
{
	map->exit_x = row;
	map->exit_y = column;
	map->exit++;
}
void	map_init(t_map *map)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, map->map_height * 56,
			map->map_width * 56, "So_Long");
	map->player_img = mlx_xpm_file_to_image(map->mlx, PLAYER,
			&map->img_width, &map->img_height);
	if (map->player_img == NULL)
		ft_error(10);
	map->coins_img = mlx_xpm_file_to_image(map->mlx, COIN,
			&map->img_width, &map->img_height);
	if (map->coins_img == NULL)
		ft_error(10);
	map->walls_img = mlx_xpm_file_to_image(map->mlx, WALL,
			&map->img_width, &map->img_height);
	if (map->walls_img == NULL)
		ft_error(10);
	map->exit_img = mlx_xpm_file_to_image(map->mlx, EXIT,
			&map->img_width, &map->img_height);
	if (map->exit_img == NULL)
		ft_error(10);
	map->floor_img = mlx_xpm_file_to_image(map->mlx, FLOOR,
			&map->img_width, &map->img_height);
	if (map->floor_img == NULL)
		ft_error(10);
}

int	main(int argc, char **argv)
{
	t_map		map;
	
	check_arguments(argc, argv[1]);
	read_map(argv[1], &map);
	init_variables(&map);
	check_char_map(&map);
	count_elements(&map);
	check_rectangle(&map);
	check_border(&map);
	flood_fill_from_player(&map, map.player_y, map.player_x);	
	flood_fill_from_exit(&map, map.exit_y, map.exit_x);
	check_path_from_exit(&map);
	map_init(&map);
	draw_map(&map);
	mlx_key_hook(map.mlx_win, detect_key, &map);	
	mlx_hook(map.mlx_win, 17, 0, end_game, &map);
	mlx_loop(map.mlx);
	return (0);
}
