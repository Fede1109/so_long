/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:33:15 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/25 14:15:24 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//*: Asignación movimientos (arriba, abajo, dcha, izq)
#include "../include/so_long.h"

void	go_up(t_map *map, t_player *player)
{
	if (map->map[player->player_y - 1][player->player_x] == 'C')
		coin_counter(map);
	map->map[player->player_y - 1][player->player_x] = 'P';
	map->map[player->player_y][player->player_x] = '0';
	player->player_y = player->player_y - 1;
	player->movements++;
	ft_printf("\nMovimientos: %d", player->movements);
}

void	go_down(t_map *map, t_player *player)
{
	if (map->map[player->player_y + 1][player->player_x] == 'C')
		coin_counter(map);
	map->map[player->player_y + 1][player->player_x] = 'P';
	map->map[player->player_y][player->player_x] = '0';
	player->player_y = player->player_y + 1;
	player->movements++;
	ft_printf("\nMovimientos: %d", player->movements);
}

void	go_right(t_map *map, t_player *player)
{
	if (map->map[player->player_y][player->player_x + 1] == 'C')
		coin_counter(map);
	map->map[player->player_y][player->player_x + 1] = 'P';
	map->map[player->player_y][player->player_x] = '0';
	player->player_x = player->player_x + 1;
	player->movements++;
	ft_printf("\nMovimientos: %d", player->movements);
}

void	go_left(t_map *map, t_player *player)
{
	if (map->map[player->player_y][player->player_x - 1] == 'C')
		coin_counter(map);
	map->map[player->player_y][player->player_x - 1] = 'P';
	map->map[player->player_y][player->player_x] = '0';
	player->player_x = player->player_x + 1;
	player->movements++;
	ft_printf("\nMovimientos: %d", player->movements);
}

//* FUNCION PARA GANAR CUANDO RECOJA TODAS LAS MONEDAS				
int	detect_key(int key_code, t_map *map, t_player *player)
{	
	printf("%s\n","hola");
	printf("%i\nCOLUMN", player->player_y);
	printf("%i\nrow", player->player_x);
	if (key_code == ESC)
		end_game();
	if (map->coins == 0 && ((key_code == A
				&& map->map[player->player_y][player->player_x - 1] == 'E')
		|| (key_code == D && map->map[player->player_y][player->player_x + 1] == 'E')
		|| (key_code == S && map->map[player->player_y + 1][player->player_x] == 'E')
		|| (key_code == W
			&& map->map[player->player_y - 1][player->player_x] == 'E')))
		win_game(map);
	if (key_code == A && map->map[player->player_y][player->player_x - 1] != 'E'
		&& key_code == A && map->map[player->player_y][player->player_x - 1] != '1')
		go_left(map, player);
	if (key_code == D && map->map[player->player_y][player->player_x + 1] != 'E'
		&& key_code == D && map->map[player->player_y][player->player_x + 1] != '1')
		go_right(map, player);
	if (key_code == S && map->map[player->player_y + 1][player->player_x] != 'E'
		&& key_code == S && map->map[player->player_y + 1][player->player_x] != '1')
		go_down(map, player);
	if (key_code == W && map->map[player->player_y - 1][player->player_x] != 'E'
		&& key_code == W && map->map[player->player_y - 1][player->player_x] != '1')
		go_up(map, player);
	printf("%s\n", map->map[0]);
	printf("%s\n", map->map[1]);
	printf("%s\n", map->map[2]);
	printf("%s\n", map->map[3]);
	printf("%s\n", map->map[4]);
	return (1);
}
