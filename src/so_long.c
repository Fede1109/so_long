/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:31:54 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/23 16:46:08 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    map_init(t_map *map)
{
    map->mlx = mlx_init();
    map->mlx_win = mlx_new_window(map->mlx, map->map_width * 45, map->map_height * 45,
    "So_Long");
    map->test = mlx_xpm_file_to_image(map->mlx, TEST, &map->img_width, &map->img_height);
    if(map->test == NULL)
        ft_error(10);    
}

int main(int argc, char **argv)
{
    t_map   map;
    
    check_arguments(argc, argv[1]);
    read_map(argv[1], &map);
    check_char_map(&map);
    check_elements_number(&map);
    check_rectangle(&map);
    check_border(&map);
    flood_fill(&map, map.player_y, map.player_x);
    check_path(&map);
    map_init(&map);
    mlx_key_hook(map.mlx_win, detect_key, &map); 
    mlx_loop(map.mlx);
    return (0);
}
