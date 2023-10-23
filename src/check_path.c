/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:39 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/23 16:29:58 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill(t_map *map, int column, int row)
{	
	if (map->map_copy[column][row] != '1')
	{
		if(map->map_copy[column][row] == 'E')
			map->exit_copy--;		
		if(map->map_copy[column][row] == 'C')
			map->coins_copy--;
		map->map_copy[column][row] = '1';
		if (map->map_copy[column][row + 1] != '1')
			flood_fill(map, column, row + 1);
		if (map->map_copy[column][row - 1] != '1')
			flood_fill(map, column, row - 1);
		if (map->map_copy[column + 1][row] != '1')
			flood_fill(map, column + 1, row);
		if (map->map_copy[column - 1][row] != '1')
			flood_fill(map, column - 1, row);
	}
}
void    check_path(t_map *map)
{
    ft_printf("%s\n", "check_map");
    ft_printf("%d\n",map->coins_copy);
    ft_printf("%d\n",map->exit_copy);
    ft_printf("%d\n",map->coins);
    ft_printf("%d\n",map->exit);
    if (map->exit_copy > 0 || map->coins_copy > 0)
        ft_error(9);
}