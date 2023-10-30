/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:45:10 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/30 11:18:46 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_char_map(t_map *map)
{
	char	**aux_map;
	int		row;
	int		column;

	aux_map = map->map;
	column = 0;
	while (aux_map[column])
	{
		row = 0;
		while (aux_map[column][row])
		{
			if (aux_map[column][row] != '0' && aux_map[column][row] != '1' &&
				aux_map[column][row] != 'C' && aux_map[column][row] != 'E' &&
				aux_map[column][row] != 'P')
				ft_error(4);
			row++;
		}
		column++;
	}
	return (1);
}

void	check_rectangle(t_map *map)
{
	size_t	columns;

	columns = 0;
	map->map_width = 0;
	map->map_height = ft_strlen(map->map[columns]);
	while (map->map[columns])
	{
		map->map_width++;
		columns++;
	}
	columns = 0;
	while (map->map_width > columns)
	{
		if (map->map_height != ft_strlen(map->map[columns]))
			ft_error(5);
		columns++;
	}
}

void	count_elements(t_map *map)
{
	int		column;
	int		row;	

	column = -1;
	while (map->map[++column])
	{
		row = -1;
		while (map->map[column][++row])
		{
			if (map->map[column][row] == 'C')
				map->coins++;
			else if (map->map[column][row] == 'E')
				assign_exit(column, row, map);
			else if (map->map[column][row] == 'P')
			{
				map->player_y = column;
				map->player_x = row;
				map->n_players++;
			}			
		}		
	}
	check_elements_number(map);
}

int	check_border(t_map *map)
{
	int		column;
	int		row;	

	column = 0;
	while (map->map[column])
	{
		row = 0;
		while (map->map[column][row])
		{
			if (map->map[0][row] != '1'
				|| map->map[column][0] != '1'
				|| map->map[map->map_width - 1][row] != '1'
				|| map->map[column][map->map_height - 1] != '1')
				ft_error(6);
			row++;
		}
		column++;
	}
	return (1);
}

void	check_elements_number(t_map *map)
{
	map->coins_copy = map->coins;
	map->coins_copy_2 = map->coins;
	map->player_copy = map->n_players;
	if (map->coins < 1 || map->exit != 1 || map->n_players != 1)
		ft_error(7);
}
