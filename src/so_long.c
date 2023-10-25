/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:31:54 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/25 15:28:26 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
//TODO: VER XQ NO SE MUEVE LA IMAGEN DEL PERSONAJE NI DESAPARECEN LAS MONEDAS
//*: FUCNION PARA INICIALIZAR VARIABLES A 0 (MONEDAS, nº player, nº salidas)

void	init_variables(t_map *map)
{
	map->coins = 0;
	map->exit = 0;
	map->n_players = 0;
	map->movements = 0;
}

void	map_init(t_map *map, t_img *images)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, 1400, 1080,
			"So_Long");
	images->player_img = mlx_xpm_file_to_image(map->mlx, PLAYER,
			&map->img_width, &map->img_height);
	if (images->player_img == NULL)
		ft_error(10);
	images->coins_img = mlx_xpm_file_to_image(map->mlx, COIN,
			&map->img_width, &map->img_height);
	if (images->coins_img == NULL)
		ft_error(10);
	images->walls_img = mlx_xpm_file_to_image(map->mlx, WALL,
			&map->img_width, &map->img_height);
	if (images->walls_img == NULL)
		ft_error(10);
	images->exit_img = mlx_xpm_file_to_image(map->mlx, EXIT,
			&map->img_width, &map->img_height);
	if (images->exit_img == NULL)
		ft_error(10);
	images->floor_img = mlx_xpm_file_to_image(map->mlx, FLOOR,
			&map->img_width, &map->img_height);
	if (images->floor_img == NULL)
		ft_error(10);
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_img		images;
	
	check_arguments(argc, argv[1]);
	read_map(argv[1], &map);
	init_variables(&map);
	check_char_map(&map);
	count_elements(&map);
	check_rectangle(&map);
	check_border(&map);
	flood_fill(&map, map.player_y, map.player_x);
	check_path(&map);
	map_init(&map, &images);
	draw_map(&map, &images);
	mlx_key_hook(map.mlx_win, detect_key, &map);
	// mlx_hook(map.mlx_win, 17, 0, end_game, &map);
	mlx_loop(map.mlx);
	return (0);
}
